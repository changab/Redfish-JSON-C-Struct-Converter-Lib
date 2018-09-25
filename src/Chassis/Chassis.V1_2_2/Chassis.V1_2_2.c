//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_Chassis_v1_2_2_CS.h"
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

RedfishCS_bool SupportedRedfishResource (RedfishCS_char *Odata_Type, RedfishCS_char *NameSpace, RedfishCS_char *Version, RedfishCS_char *DataType);
RedfishCS_status CreateCsUriByNode (RedfishCS_void *Cs, json_t *JsonOj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Type_Uri_Data **CsTypeUriData);
RedfishCS_status CreateCsJsonByNode (RedfishCS_void *Cs, json_t *JsonOj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Type_JSON_Data **CsTypeJsonData);
RedfishCS_status CreateCsUriOrJsonByNode (RedfishCS_void *Cs, json_t *JsonObj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Link *LinkHead);
RedfishCS_status CreateCsUriOrJsonByNodeArray (RedfishCS_void *Cs, json_t *JsonObj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Link *LinkHead);
RedfishCS_status CreateJsonPayloadAndCs (char *JsonRawText, char *ResourceType, char *ResourceVersion, char *TypeName, json_t **JsonObjReturned, void **Cs, int size);
RedfishCS_status GetRedfishPropertyStr (RedfishCS_void *Cs, json_t *JsonObj, char *Key, RedfishCS_char **DstBuffer);
RedfishCS_status GetRedfishPropertyBoolean (RedfishCS_void *Cs, json_t *JsonObj, char *Key, RedfishCS_bool **DstBuffer);
RedfishCS_status GetRedfishPropertyVague (RedfishCS_void *Cs, json_t *JsonObj, char *Key, RedfishCS_Vague **DstBuffer);
RedfishCS_status DestoryCsMemory (RedfishCS_void *rootCs);
RedfishCS_status GetRedfishPropertyInt64 (RedfishCS_void *Cs, json_t *JsonObj, char *Key, RedfishCS_int64 **Dst);
RedfishCS_status InsertJsonStringObj (json_t *JsonObj, char *Key, char *StringValue);
RedfishCS_status InsertJsonLinkObj (json_t *JsonObj, char *Key, RedfishCS_Link *Link);
RedfishCS_status InsertJsonInt64Obj (json_t *ParentJsonObj, char *Key, RedfishCS_int64 *Int64Value);
RedfishCS_status InsertJsonBoolObj (json_t *ParentJsonObj, char *Key, RedfishCS_bool *BoolValue);
RedfishCS_status InsertJsonStringArrayObj (json_t *JsonObj, char *Key, RedfishCS_char_Array *StringValueArray);
RedfishCS_status InsertJsonLinkArrayObj (json_t *JsonObj, char *Key, RedfishCS_Link *LinkArray);
RedfishCS_status InsertJsonInt64ArrayObj (json_t *ParentJsonObj, char *Key, RedfishCS_int64_Array *Int64ValueArray);
RedfishCS_status InsertJsonBoolArrayObj (json_t *ParentJsonObj, char *Key, RedfishCS_bool_Array *BoolValueArray);
RedfishCS_status InsertJsonVagueObj (json_t *ParentJsonObj, char *Key, RedfishCS_Vague *VagueValue);

static RedfishCS_status GenidRef_ArrayCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, Redfishodata_V4_0_0_idRef_Array_CS **Dst);
static RedfishCS_status GenOemCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
//
//Generate C structure for #Chassis.Reset
//
static RedfishCS_status GenResetCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishChassis_V1_2_2_Reset_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishChassis_V1_2_2_Reset_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // target
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "target", &(*Dst)->target);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // title
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "title", &(*Dst)->title);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Oem
//
static RedfishCS_status GenActions_OemCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishChassis_V1_2_2_Chassis_Actions_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishChassis_V1_2_2_Chassis_Actions_Oem_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  InitializeLinkHead (&(*Dst)->Prop);
  Status = CreateCsJsonByNode (Cs, JsonObj, Key, Cs->Header.ThisUri, &CsTypeJson);
  if (Status != RedfishCS_status_success) {
    goto Error;
  }
  InsertTailLink(&(*Dst)->Prop, &CsTypeJson->Header.LinkEntry);
Error:;
  return Status;
}
//
//Generate C structure for Actions
//
static RedfishCS_status GenActionsCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishChassis_V1_2_2_Chassis_Actions_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishChassis_V1_2_2_Chassis_Actions_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // #Chassis.Reset
  Status = GenResetCs (Cs, TempJsonObj, "#Chassis.Reset", &(*Dst)->Chassis_Reset);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenActions_OemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
static RedfishCS_status GenidRef_Array_ElementCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  Redfishodata_V4_0_0_idRef_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(Redfishodata_V4_0_0_idRef_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // @odata.id
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "@odata.id", &(*Dst)->odata_id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for Redfishodata_V4_0_0_idRef_Array_CS
//
static RedfishCS_status GenidRef_ArrayCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, Redfishodata_V4_0_0_idRef_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  Redfishodata_V4_0_0_idRef_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (Redfishodata_V4_0_0_idRef_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenidRef_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
    if (Status != RedfishCS_status_success){
      goto Error;
    }
    ThisElement = ThisElement->Next;
  }
Error:;
  return Status;
}
//
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishResource_Oem_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  InitializeLinkHead (&(*Dst)->Prop);
  Status = CreateCsJsonByNode (Cs, JsonObj, Key, Cs->Header.ThisUri, &CsTypeJson);
  if (Status != RedfishCS_status_success) {
    goto Error;
  }
  InsertTailLink(&(*Dst)->Prop, &CsTypeJson->Header.LinkEntry);
Error:;
  return Status;
}
//
//Generate C structure for Links
//
static RedfishCS_status GenLinksCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishChassis_V1_2_2_Chassis_Links_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishChassis_V1_2_2_Chassis_Links_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // ComputerSystems
  InitializeLinkHead (&(*Dst)->ComputerSystems);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "ComputerSystems", Cs->Header.ThisUri, &(*Dst)->ComputerSystems);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ComputerSystems@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "ComputerSystems@odata.count", &(*Dst)->ComputerSystemsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ComputerSystems@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "ComputerSystems@odata.navigationLink", &(*Dst)->ComputerSystemsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ContainedBy
  InitializeLinkHead (&(*Dst)->ContainedBy);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "ContainedBy", Cs->Header.ThisUri, &(*Dst)->ContainedBy);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Contains
  InitializeLinkHead (&(*Dst)->Contains);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Contains", Cs->Header.ThisUri, &(*Dst)->Contains);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Contains@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Contains@odata.count", &(*Dst)->Containsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Contains@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Contains@odata.navigationLink", &(*Dst)->Containsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // CooledBy
  Status = GenidRef_ArrayCs (Cs, TempJsonObj, "CooledBy", &(*Dst)->CooledBy);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // CooledBy@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "CooledBy@odata.count", &(*Dst)->CooledByodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // CooledBy@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "CooledBy@odata.navigationLink", &(*Dst)->CooledByodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Drives
  InitializeLinkHead (&(*Dst)->Drives);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Drives", Cs->Header.ThisUri, &(*Dst)->Drives);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Drives@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Drives@odata.count", &(*Dst)->Drivesodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Drives@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Drives@odata.navigationLink", &(*Dst)->Drivesodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagedBy
  InitializeLinkHead (&(*Dst)->ManagedBy);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "ManagedBy", Cs->Header.ThisUri, &(*Dst)->ManagedBy);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagedBy@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "ManagedBy@odata.count", &(*Dst)->ManagedByodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagedBy@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "ManagedBy@odata.navigationLink", &(*Dst)->ManagedByodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagersInChassis
  InitializeLinkHead (&(*Dst)->ManagersInChassis);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "ManagersInChassis", Cs->Header.ThisUri, &(*Dst)->ManagersInChassis);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagersInChassis@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "ManagersInChassis@odata.count", &(*Dst)->ManagersInChassisodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagersInChassis@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "ManagersInChassis@odata.navigationLink", &(*Dst)->ManagersInChassisodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PoweredBy
  Status = GenidRef_ArrayCs (Cs, TempJsonObj, "PoweredBy", &(*Dst)->PoweredBy);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PoweredBy@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "PoweredBy@odata.count", &(*Dst)->PoweredByodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PoweredBy@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "PoweredBy@odata.navigationLink", &(*Dst)->PoweredByodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Storage
  InitializeLinkHead (&(*Dst)->Storage);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Storage", Cs->Header.ThisUri, &(*Dst)->Storage);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Storage@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Storage@odata.count", &(*Dst)->Storageodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Storage@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Storage@odata.navigationLink", &(*Dst)->Storageodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Location
//
static RedfishCS_status GenLocationCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_V1_1_0_Location_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishResource_V1_1_0_Location_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Info
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Info", &(*Dst)->Info);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // InfoFormat
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "InfoFormat", &(*Dst)->InfoFormat);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for PhysicalSecurity
//
static RedfishCS_status GenPhysicalSecurityCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishChassis_V1_2_2_PhysicalSecurity_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishChassis_V1_2_2_PhysicalSecurity_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // IntrusionSensor
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "IntrusionSensor", &(*Dst)->IntrusionSensor);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // IntrusionSensorNumber
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "IntrusionSensorNumber", &(*Dst)->IntrusionSensorNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // IntrusionSensorReArm
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "IntrusionSensorReArm", &(*Dst)->IntrusionSensorReArm);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishChassis_V1_2_2_Chassis_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishResource_Status_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Health
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Health", &(*Dst)->Health);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HealthRollup
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "HealthRollup", &(*Dst)->HealthRollup);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // State
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "State", &(*Dst)->State);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
static RedfishCS_status CS_To_JSON_ActionsChassis_Reset(json_t *CsJson, char *Key, RedfishChassis_V1_2_2_Reset_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // target 
  if (InsertJsonStringObj (CsJson, "target", CSPtr->target) != RedfishCS_status_success) {goto Error;}

  // title 
  if (InsertJsonStringObj (CsJson, "title", CSPtr->title) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ActionsOem(json_t *CsJson, char *Key, RedfishChassis_V1_2_2_Chassis_Actions_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Actions(json_t *CsJson, char *Key, RedfishChassis_V1_2_2_Chassis_Actions_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // #Chassis.Reset
  if (CS_To_JSON_ActionsChassis_Reset(CsJson, "#Chassis.Reset", CSPtr->Chassis_Reset) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_ActionsOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_LinksCooledBy(json_t *CsJson, char *Key, Redfishodata_V4_0_0_idRef_Array_CS *CSPtr)
{
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_LinksOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_LinksPoweredBy(json_t *CsJson, char *Key, Redfishodata_V4_0_0_idRef_Array_CS *CSPtr)
{
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Links(json_t *CsJson, char *Key, RedfishChassis_V1_2_2_Chassis_Links_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // ComputerSystems 
  if (InsertJsonLinkArrayObj (CsJson, "ComputerSystems", &CSPtr->ComputerSystems) != RedfishCS_status_success) {goto Error;}

  // ComputerSystems@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ComputerSystems@odata.count", CSPtr->ComputerSystemsodata_count) != RedfishCS_status_success) {goto Error;}

  // ComputerSystems@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ComputerSystems@odata.navigationLink", CSPtr->ComputerSystemsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // ContainedBy 
  if (InsertJsonLinkObj (CsJson, "ContainedBy", &CSPtr->ContainedBy) != RedfishCS_status_success) {goto Error;}

  // Contains 
  if (InsertJsonLinkArrayObj (CsJson, "Contains", &CSPtr->Contains) != RedfishCS_status_success) {goto Error;}

  // Contains@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Contains@odata.count", CSPtr->Containsodata_count) != RedfishCS_status_success) {goto Error;}

  // Contains@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Contains@odata.navigationLink", CSPtr->Containsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // CooledBy
  if (CS_To_JSON_LinksCooledBy(CsJson, "CooledBy", CSPtr->CooledBy) != RedfishCS_status_success) {goto Error;}

  // CooledBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "CooledBy@odata.count", CSPtr->CooledByodata_count) != RedfishCS_status_success) {goto Error;}

  // CooledBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "CooledBy@odata.navigationLink", CSPtr->CooledByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Drives 
  if (InsertJsonLinkArrayObj (CsJson, "Drives", &CSPtr->Drives) != RedfishCS_status_success) {goto Error;}

  // Drives@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Drives@odata.count", CSPtr->Drivesodata_count) != RedfishCS_status_success) {goto Error;}

  // Drives@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Drives@odata.navigationLink", CSPtr->Drivesodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // ManagedBy 
  if (InsertJsonLinkArrayObj (CsJson, "ManagedBy", &CSPtr->ManagedBy) != RedfishCS_status_success) {goto Error;}

  // ManagedBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ManagedBy@odata.count", CSPtr->ManagedByodata_count) != RedfishCS_status_success) {goto Error;}

  // ManagedBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ManagedBy@odata.navigationLink", CSPtr->ManagedByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // ManagersInChassis 
  if (InsertJsonLinkArrayObj (CsJson, "ManagersInChassis", &CSPtr->ManagersInChassis) != RedfishCS_status_success) {goto Error;}

  // ManagersInChassis@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ManagersInChassis@odata.count", CSPtr->ManagersInChassisodata_count) != RedfishCS_status_success) {goto Error;}

  // ManagersInChassis@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ManagersInChassis@odata.navigationLink", CSPtr->ManagersInChassisodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_LinksOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PoweredBy
  if (CS_To_JSON_LinksPoweredBy(CsJson, "PoweredBy", CSPtr->PoweredBy) != RedfishCS_status_success) {goto Error;}

  // PoweredBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "PoweredBy@odata.count", CSPtr->PoweredByodata_count) != RedfishCS_status_success) {goto Error;}

  // PoweredBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "PoweredBy@odata.navigationLink", CSPtr->PoweredByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Storage 
  if (InsertJsonLinkArrayObj (CsJson, "Storage", &CSPtr->Storage) != RedfishCS_status_success) {goto Error;}

  // Storage@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Storage@odata.count", CSPtr->Storageodata_count) != RedfishCS_status_success) {goto Error;}

  // Storage@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Storage@odata.navigationLink", CSPtr->Storageodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Location(json_t *CsJson, char *Key, RedfishResource_V1_1_0_Location_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Oem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_PhysicalSecurity(json_t *CsJson, char *Key, RedfishChassis_V1_2_2_PhysicalSecurity_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // IntrusionSensor 
  if (InsertJsonStringObj (CsJson, "IntrusionSensor", CSPtr->IntrusionSensor) != RedfishCS_status_success) {goto Error;}

  // IntrusionSensorNumber 
  if (InsertJsonInt64Obj (CsJson, "IntrusionSensorNumber", CSPtr->IntrusionSensorNumber) != RedfishCS_status_success) {goto Error;}

  // IntrusionSensorReArm 
  if (InsertJsonStringObj (CsJson, "IntrusionSensorReArm", CSPtr->IntrusionSensorReArm) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Status(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}

//
// C structure to JSON for Chassis.V1_2_2.Chassis
//
RedfishCS_status CS_To_Chassis_V1_2_2_JSON(RedfishChassis_V1_2_2_Chassis_CS *CSPtr, RedfishCS_char **JsonText)
{
  json_t  *CsJson;

  if (CSPtr == NULL || JsonText == NULL || CSPtr->Header.ResourceType != RedfishCS_Type_CS) {
    return RedfishCS_status_invalid_parameter;
  }
  CsJson = json_object();
  if (CsJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  // Actions
  if (CS_To_JSON_Actions(CsJson, "Actions", CSPtr->Actions) != RedfishCS_status_success) {goto Error;}

  // AssetTag 
  if (InsertJsonStringObj (CsJson, "AssetTag", CSPtr->AssetTag) != RedfishCS_status_success) {goto Error;}

  // ChassisType 
  if (InsertJsonStringObj (CsJson, "ChassisType", CSPtr->ChassisType) != RedfishCS_status_success) {goto Error;}

  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // IndicatorLED 
  if (InsertJsonStringObj (CsJson, "IndicatorLED", CSPtr->IndicatorLED) != RedfishCS_status_success) {goto Error;}

  // Links
  if (CS_To_JSON_Links(CsJson, "Links", CSPtr->Links) != RedfishCS_status_success) {goto Error;}

  // Location
  if (CS_To_JSON_Location(CsJson, "Location", CSPtr->Location) != RedfishCS_status_success) {goto Error;}

  // LogServices 
  if (InsertJsonLinkObj (CsJson, "LogServices", &CSPtr->LogServices) != RedfishCS_status_success) {goto Error;}

  // Manufacturer 
  if (InsertJsonStringObj (CsJson, "Manufacturer", CSPtr->Manufacturer) != RedfishCS_status_success) {goto Error;}

  // Model 
  if (InsertJsonStringObj (CsJson, "Model", CSPtr->Model) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PartNumber 
  if (InsertJsonStringObj (CsJson, "PartNumber", CSPtr->PartNumber) != RedfishCS_status_success) {goto Error;}

  // PhysicalSecurity
  if (CS_To_JSON_PhysicalSecurity(CsJson, "PhysicalSecurity", CSPtr->PhysicalSecurity) != RedfishCS_status_success) {goto Error;}

  // Power 
  if (InsertJsonLinkObj (CsJson, "Power", &CSPtr->Power) != RedfishCS_status_success) {goto Error;}

  // PowerState 
  if (InsertJsonStringObj (CsJson, "PowerState", CSPtr->PowerState) != RedfishCS_status_success) {goto Error;}

  // SKU 
  if (InsertJsonStringObj (CsJson, "SKU", CSPtr->SKU) != RedfishCS_status_success) {goto Error;}

  // SerialNumber 
  if (InsertJsonStringObj (CsJson, "SerialNumber", CSPtr->SerialNumber) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // Thermal 
  if (InsertJsonLinkObj (CsJson, "Thermal", &CSPtr->Thermal) != RedfishCS_status_success) {goto Error;}

  // @odata.context 
  if (InsertJsonStringObj (CsJson, "@odata.context", CSPtr->odata_context) != RedfishCS_status_success) {goto Error;}

  // @odata.id 
  if (InsertJsonStringObj (CsJson, "@odata.id", CSPtr->odata_id) != RedfishCS_status_success) {goto Error;}

  // @odata.type 
  if (InsertJsonStringObj (CsJson, "@odata.type", CSPtr->odata_type) != RedfishCS_status_success) {goto Error;}

  *JsonText = (RedfishCS_char *)json_dumps(CsJson, JSON_INDENT(2 * 1) | JSON_ENSURE_ASCII);
  json_decref(CsJson);
  return RedfishCS_status_success;
Error:;
  json_decref(CsJson);
  return RedfishCS_status_unsupported;
}

//
// Destory C Structure for Chassis.V1_2_2.Chassis
//
RedfishCS_status DestroyChassis_V1_2_2_CS(RedfishChassis_V1_2_2_Chassis_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for Chassis.V1_2_2.Chassis
//
RedfishCS_status DestroyChassis_V1_2_2_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for Chassis.V1_2_2.Chassis
//
RedfishCS_status
Json_Chassis_V1_2_2_To_CS(RedfishCS_char *JsonRawText, RedfishChassis_V1_2_2_Chassis_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishChassis_V1_2_2_Chassis_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "Chassis", "v1_2_2", "Chassis", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishChassis_V1_2_2_Chassis_CS));
  if (Status != RedfishCS_status_success) {
    goto Error;
  }

  // @odata.context
  Status = GetRedfishPropertyStr (Cs, JsonObj, "@odata.context", &Cs->odata_context);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // @odata.id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "@odata.id", &Cs->odata_id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // @odata.type
  Status = GetRedfishPropertyStr (Cs, JsonObj, "@odata.type", &Cs->odata_type);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // Actions
  Status = GenActionsCs (Cs, JsonObj, "Actions", &Cs->Actions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // AssetTag
  Status = GetRedfishPropertyStr (Cs, JsonObj, "AssetTag", &Cs->AssetTag);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ChassisType
  Status = GetRedfishPropertyStr (Cs, JsonObj, "ChassisType", &Cs->ChassisType);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // Description
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Description", &Cs->Description);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Id", &Cs->Id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // IndicatorLED
  Status = GetRedfishPropertyStr (Cs, JsonObj, "IndicatorLED", &Cs->IndicatorLED);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Links
  Status = GenLinksCs (Cs, JsonObj, "Links", &Cs->Links);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Location
  Status = GenLocationCs (Cs, JsonObj, "Location", &Cs->Location);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LogServices
  InitializeLinkHead (&Cs->LogServices);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "LogServices", Cs->Header.ThisUri, &Cs->LogServices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Manufacturer
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Manufacturer", &Cs->Manufacturer);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Model
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Model", &Cs->Model);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Name
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Name", &Cs->Name);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // Oem
  Status = GenOemCs (Cs, JsonObj, "Oem", &Cs->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PartNumber
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PartNumber", &Cs->PartNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PhysicalSecurity
  Status = GenPhysicalSecurityCs (Cs, JsonObj, "PhysicalSecurity", &Cs->PhysicalSecurity);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Power
  InitializeLinkHead (&Cs->Power);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Power", Cs->Header.ThisUri, &Cs->Power);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PowerState
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PowerState", &Cs->PowerState);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SKU
  Status = GetRedfishPropertyStr (Cs, JsonObj, "SKU", &Cs->SKU);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SerialNumber
  Status = GetRedfishPropertyStr (Cs, JsonObj, "SerialNumber", &Cs->SerialNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, JsonObj, "Status", &Cs->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Thermal
  InitializeLinkHead (&Cs->Thermal);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Thermal", Cs->Header.ThisUri, &Cs->Thermal);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyChassis_V1_2_2_CS (Cs);
  return Status;
}
