//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_ComputerSystem_v1_3_1_CS.h"
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

static RedfishCS_status GenOemCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
static RedfishCS_status GenidRef_ArrayCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, Redfishodata_V4_0_0_idRef_Array_CS **Dst);
static RedfishCS_status GenStatusCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst);
//
//Generate C structure for #ComputerSystem.Reset
//
static RedfishCS_status GenResetCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_Reset_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_Reset_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActions_OemCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_ComputerSystem_Actions_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_ComputerSystem_Actions_Oem_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActionsCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_ComputerSystem_Actions_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_ComputerSystem_Actions_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // #ComputerSystem.Reset
  Status = GenResetCs (Cs, TempJsonObj, "#ComputerSystem.Reset", &(*Dst)->ComputerSystem_Reset);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenActions_OemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Boot
//
static RedfishCS_status GenBootCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_Boot_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_Boot_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // BootSourceOverrideEnabled
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "BootSourceOverrideEnabled", &(*Dst)->BootSourceOverrideEnabled);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // BootSourceOverrideMode
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "BootSourceOverrideMode", &(*Dst)->BootSourceOverrideMode);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // BootSourceOverrideTarget
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "BootSourceOverrideTarget", &(*Dst)->BootSourceOverrideTarget);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UefiTargetBootSourceOverride
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "UefiTargetBootSourceOverride", &(*Dst)->UefiTargetBootSourceOverride);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
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
//Generate C structure for HostedServices
//
static RedfishCS_status GenHostedServicesCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_HostedServices_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_HostedServices_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // StorageServices
  InitializeLinkHead (&(*Dst)->StorageServices);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "StorageServices", Cs->Header.ThisUri, &(*Dst)->StorageServices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Redfish_char_Array.
//
static RedfishCS_status GenRedfishCS_char_Array_Element (void *Cs, json_t *JsonArrayObj, RedfishCS_uint64 ArraySize, RedfishCS_char_Array *DstBuffer)
{
  json_t *TempJsonObj;
  RedfishCS_uint64 Index;
  RedfishCS_status Status;
  RedfishCS_char_Array *ThisElement;

  if (DstBuffer == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  ThisElement = DstBuffer;
  for (Index = 0; Index < ArraySize; Index ++) {
    TempJsonObj = json_array_get (JsonArrayObj, (RedfishCS_int)Index);
    Status = allocateDuplicateStr (Cs, (char *)json_string_value(TempJsonObj), (RedfishCS_void **)&ThisElement->ArrayValue);
    if (Status != RedfishCS_status_success){
      goto Error;
    }
    ThisElement = ThisElement->Next;
  }
Error:;
  return Status;
}
//
//Generate C structure for RedfishCS_char_Array
//
static RedfishCS_status GenRedfishCS_char_ArrayCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishCS_char_Array **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishCS_char_Array), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  Status = GenRedfishCS_char_Array_Element (Cs, TempJsonObj, ArraySize, *Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
Error:;
  return Status;
}
static RedfishCS_status GenidRef_Array_ElementCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  Redfishodata_V4_0_0_idRef_CS **Dst)
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
static RedfishCS_status GenidRef_ArrayCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, Redfishodata_V4_0_0_idRef_Array_CS **Dst)
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
//Generate C structure for Links
//
static RedfishCS_status GenLinksCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_ComputerSystem_Links_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_ComputerSystem_Links_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Chassis
  InitializeLinkHead (&(*Dst)->Chassis);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Chassis", Cs->Header.ThisUri, &(*Dst)->Chassis);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Chassis@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Chassis@odata.count", &(*Dst)->Chassisodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Chassis@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Chassis@odata.navigationLink", &(*Dst)->Chassisodata_navigationLink);
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

  // Endpoints
  InitializeLinkHead (&(*Dst)->Endpoints);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Endpoints", Cs->Header.ThisUri, &(*Dst)->Endpoints);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Endpoints@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Endpoints@odata.count", &(*Dst)->Endpointsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Endpoints@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Endpoints@odata.navigationLink", &(*Dst)->Endpointsodata_navigationLink);
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

Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
//
//Generate C structure for MemorySummary
//
static RedfishCS_status GenMemorySummaryCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_MemorySummary_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_MemorySummary_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // MemoryMirroring
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "MemoryMirroring", &(*Dst)->MemoryMirroring);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, TempJsonObj, "Status", &(*Dst)->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // TotalSystemMemoryGiB
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "TotalSystemMemoryGiB", &(*Dst)->TotalSystemMemoryGiB);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for ProcessorSummary
//
static RedfishCS_status GenProcessorSummaryCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_ProcessorSummary_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_ProcessorSummary_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Count", &(*Dst)->Count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Model
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Model", &(*Dst)->Model);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, TempJsonObj, "Status", &(*Dst)->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
static RedfishCS_status GenTrustedModules_Array_ElementCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  RedfishComputerSystem_V1_3_1_TrustedModules_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(RedfishComputerSystem_V1_3_1_TrustedModules_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // FirmwareVersion
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "FirmwareVersion", &(*Dst)->FirmwareVersion);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // FirmwareVersion2
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "FirmwareVersion2", &(*Dst)->FirmwareVersion2);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // InterfaceType
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "InterfaceType", &(*Dst)->InterfaceType);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // InterfaceTypeSelection
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "InterfaceTypeSelection", &(*Dst)->InterfaceTypeSelection);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, TempJsonObj, "Status", &(*Dst)->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for RedfishComputerSystem_V1_3_1_TrustedModules_Array_CS
//
static RedfishCS_status GenTrustedModules_ArrayCs(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs, json_t *JsonObj, char *Key, RedfishComputerSystem_V1_3_1_TrustedModules_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  RedfishComputerSystem_V1_3_1_TrustedModules_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishComputerSystem_V1_3_1_TrustedModules_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenTrustedModules_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
    if (Status != RedfishCS_status_success){
      goto Error;
    }
    ThisElement = ThisElement->Next;
  }
Error:;
  return Status;
}
static RedfishCS_status CS_To_JSON_ActionsComputerSystem_Reset(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_Reset_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_ActionsOem(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_ComputerSystem_Actions_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Actions(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_ComputerSystem_Actions_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // #ComputerSystem.Reset
  if (CS_To_JSON_ActionsComputerSystem_Reset(CsJson, "#ComputerSystem.Reset", CSPtr->ComputerSystem_Reset) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_ActionsOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Boot(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_Boot_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // BootSourceOverrideEnabled 
  if (InsertJsonStringObj (CsJson, "BootSourceOverrideEnabled", CSPtr->BootSourceOverrideEnabled) != RedfishCS_status_success) {goto Error;}

  // BootSourceOverrideMode 
  if (InsertJsonStringObj (CsJson, "BootSourceOverrideMode", CSPtr->BootSourceOverrideMode) != RedfishCS_status_success) {goto Error;}

  // BootSourceOverrideTarget 
  if (InsertJsonStringObj (CsJson, "BootSourceOverrideTarget", CSPtr->BootSourceOverrideTarget) != RedfishCS_status_success) {goto Error;}

  // UefiTargetBootSourceOverride 
  if (InsertJsonStringObj (CsJson, "UefiTargetBootSourceOverride", CSPtr->UefiTargetBootSourceOverride) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_HostedServicesOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_HostedServices(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_HostedServices_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Oem
  if (CS_To_JSON_HostedServicesOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // StorageServices 
  if (InsertJsonLinkObj (CsJson, "StorageServices", &CSPtr->StorageServices) != RedfishCS_status_success) {goto Error;}

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
static RedfishCS_status CS_To_JSON_Links(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_ComputerSystem_Links_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Chassis 
  if (InsertJsonLinkArrayObj (CsJson, "Chassis", &CSPtr->Chassis) != RedfishCS_status_success) {goto Error;}

  // Chassis@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Chassis@odata.count", CSPtr->Chassisodata_count) != RedfishCS_status_success) {goto Error;}

  // Chassis@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Chassis@odata.navigationLink", CSPtr->Chassisodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // CooledBy
  if (CS_To_JSON_LinksCooledBy(CsJson, "CooledBy", CSPtr->CooledBy) != RedfishCS_status_success) {goto Error;}

  // CooledBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "CooledBy@odata.count", CSPtr->CooledByodata_count) != RedfishCS_status_success) {goto Error;}

  // CooledBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "CooledBy@odata.navigationLink", CSPtr->CooledByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Endpoints 
  if (InsertJsonLinkArrayObj (CsJson, "Endpoints", &CSPtr->Endpoints) != RedfishCS_status_success) {goto Error;}

  // Endpoints@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Endpoints@odata.count", CSPtr->Endpointsodata_count) != RedfishCS_status_success) {goto Error;}

  // Endpoints@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Endpoints@odata.navigationLink", CSPtr->Endpointsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // ManagedBy 
  if (InsertJsonLinkArrayObj (CsJson, "ManagedBy", &CSPtr->ManagedBy) != RedfishCS_status_success) {goto Error;}

  // ManagedBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ManagedBy@odata.count", CSPtr->ManagedByodata_count) != RedfishCS_status_success) {goto Error;}

  // ManagedBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ManagedBy@odata.navigationLink", CSPtr->ManagedByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_LinksOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PoweredBy
  if (CS_To_JSON_LinksPoweredBy(CsJson, "PoweredBy", CSPtr->PoweredBy) != RedfishCS_status_success) {goto Error;}

  // PoweredBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "PoweredBy@odata.count", CSPtr->PoweredByodata_count) != RedfishCS_status_success) {goto Error;}

  // PoweredBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "PoweredBy@odata.navigationLink", CSPtr->PoweredByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_MemorySummaryStatus(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_MemorySummary(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_MemorySummary_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // MemoryMirroring 
  if (InsertJsonStringObj (CsJson, "MemoryMirroring", CSPtr->MemoryMirroring) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_MemorySummaryStatus(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // TotalSystemMemoryGiB 
  if (InsertJsonInt64Obj (CsJson, "TotalSystemMemoryGiB", CSPtr->TotalSystemMemoryGiB) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Oem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_ProcessorSummaryStatus(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_ProcessorSummary(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_ProcessorSummary_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Count 
  if (InsertJsonInt64Obj (CsJson, "Count", CSPtr->Count) != RedfishCS_status_success) {goto Error;}

  // Model 
  if (InsertJsonStringObj (CsJson, "Model", CSPtr->Model) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_ProcessorSummaryStatus(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

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
static RedfishCS_status CS_To_JSON_TrustedModulesOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_TrustedModulesStatus(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_TrustedModules(json_t *CsJson, char *Key, RedfishComputerSystem_V1_3_1_TrustedModules_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishComputerSystem_V1_3_1_TrustedModules_Array_CS *NextArray;
  RedfishComputerSystem_V1_3_1_TrustedModules_CS *NextArrayItem;

  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  ArrayJson = json_array();
  if (ArrayJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  NextArray = CSPtr;
  do {
    ArrayMember = json_object();
    if (ArrayMember == NULL) {
      return RedfishCS_status_unsupported;
    }

    NextArrayItem = NextArray->ArrayValue;
    // FirmwareVersion 
    if (InsertJsonStringObj (ArrayMember, "FirmwareVersion", NextArrayItem->FirmwareVersion) != RedfishCS_status_success) {goto Error;}

    // FirmwareVersion2 
    if (InsertJsonStringObj (ArrayMember, "FirmwareVersion2", NextArrayItem->FirmwareVersion2) != RedfishCS_status_success) {goto Error;}

    // InterfaceType 
    if (InsertJsonStringObj (ArrayMember, "InterfaceType", NextArrayItem->InterfaceType) != RedfishCS_status_success) {goto Error;}

    // InterfaceTypeSelection 
    if (InsertJsonStringObj (ArrayMember, "InterfaceTypeSelection", NextArrayItem->InterfaceTypeSelection) != RedfishCS_status_success) {goto Error;}

    // Oem
    if (CS_To_JSON_TrustedModulesOem(ArrayMember, "Oem", NextArrayItem->Oem) != RedfishCS_status_success) {goto Error;}

    // Status
    if (CS_To_JSON_TrustedModulesStatus(ArrayMember, "Status", NextArrayItem->Status) != RedfishCS_status_success) {goto Error;}

    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {goto Error;}
    NextArray = NextArray->Next;
  } while (NextArray != NULL);
  json_object_set_new (CsJson, Key, ArrayJson);

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}

//
// C structure to JSON for ComputerSystem.V1_3_1.ComputerSystem
//
RedfishCS_status CS_To_ComputerSystem_V1_3_1_JSON(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *CSPtr, RedfishCS_char **JsonText)
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

  // Bios 
  if (InsertJsonLinkObj (CsJson, "Bios", &CSPtr->Bios) != RedfishCS_status_success) {goto Error;}

  // BiosVersion 
  if (InsertJsonStringObj (CsJson, "BiosVersion", CSPtr->BiosVersion) != RedfishCS_status_success) {goto Error;}

  // Boot
  if (CS_To_JSON_Boot(CsJson, "Boot", CSPtr->Boot) != RedfishCS_status_success) {goto Error;}

  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // EthernetInterfaces 
  if (InsertJsonLinkObj (CsJson, "EthernetInterfaces", &CSPtr->EthernetInterfaces) != RedfishCS_status_success) {goto Error;}

  // HostName 
  if (InsertJsonStringObj (CsJson, "HostName", CSPtr->HostName) != RedfishCS_status_success) {goto Error;}

  // HostedServices
  if (CS_To_JSON_HostedServices(CsJson, "HostedServices", CSPtr->HostedServices) != RedfishCS_status_success) {goto Error;}

  // HostingRoles 
  if (InsertJsonStringArrayObj (CsJson, "HostingRoles", CSPtr->HostingRoles) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // IndicatorLED 
  if (InsertJsonStringObj (CsJson, "IndicatorLED", CSPtr->IndicatorLED) != RedfishCS_status_success) {goto Error;}

  // Links
  if (CS_To_JSON_Links(CsJson, "Links", CSPtr->Links) != RedfishCS_status_success) {goto Error;}

  // LogServices 
  if (InsertJsonLinkObj (CsJson, "LogServices", &CSPtr->LogServices) != RedfishCS_status_success) {goto Error;}

  // Manufacturer 
  if (InsertJsonStringObj (CsJson, "Manufacturer", CSPtr->Manufacturer) != RedfishCS_status_success) {goto Error;}

  // Memory 
  if (InsertJsonLinkObj (CsJson, "Memory", &CSPtr->Memory) != RedfishCS_status_success) {goto Error;}

  // MemoryDomains 
  if (InsertJsonLinkObj (CsJson, "MemoryDomains", &CSPtr->MemoryDomains) != RedfishCS_status_success) {goto Error;}

  // MemorySummary
  if (CS_To_JSON_MemorySummary(CsJson, "MemorySummary", CSPtr->MemorySummary) != RedfishCS_status_success) {goto Error;}

  // Model 
  if (InsertJsonStringObj (CsJson, "Model", CSPtr->Model) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // NetworkInterfaces 
  if (InsertJsonLinkObj (CsJson, "NetworkInterfaces", &CSPtr->NetworkInterfaces) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PCIeDevices 
  if (InsertJsonLinkArrayObj (CsJson, "PCIeDevices", &CSPtr->PCIeDevices) != RedfishCS_status_success) {goto Error;}

  // PCIeDevices@odata.count 
  if (InsertJsonInt64Obj (CsJson, "PCIeDevices@odata.count", CSPtr->PCIeDevicesodata_count) != RedfishCS_status_success) {goto Error;}

  // PCIeDevices@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "PCIeDevices@odata.navigationLink", CSPtr->PCIeDevicesodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // PCIeFunctions 
  if (InsertJsonLinkArrayObj (CsJson, "PCIeFunctions", &CSPtr->PCIeFunctions) != RedfishCS_status_success) {goto Error;}

  // PCIeFunctions@odata.count 
  if (InsertJsonInt64Obj (CsJson, "PCIeFunctions@odata.count", CSPtr->PCIeFunctionsodata_count) != RedfishCS_status_success) {goto Error;}

  // PCIeFunctions@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "PCIeFunctions@odata.navigationLink", CSPtr->PCIeFunctionsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // PartNumber 
  if (InsertJsonStringObj (CsJson, "PartNumber", CSPtr->PartNumber) != RedfishCS_status_success) {goto Error;}

  // PowerState 
  if (InsertJsonStringObj (CsJson, "PowerState", CSPtr->PowerState) != RedfishCS_status_success) {goto Error;}

  // ProcessorSummary
  if (CS_To_JSON_ProcessorSummary(CsJson, "ProcessorSummary", CSPtr->ProcessorSummary) != RedfishCS_status_success) {goto Error;}

  // Processors 
  if (InsertJsonLinkObj (CsJson, "Processors", &CSPtr->Processors) != RedfishCS_status_success) {goto Error;}

  // SKU 
  if (InsertJsonStringObj (CsJson, "SKU", CSPtr->SKU) != RedfishCS_status_success) {goto Error;}

  // SecureBoot 
  if (InsertJsonLinkObj (CsJson, "SecureBoot", &CSPtr->SecureBoot) != RedfishCS_status_success) {goto Error;}

  // SerialNumber 
  if (InsertJsonStringObj (CsJson, "SerialNumber", CSPtr->SerialNumber) != RedfishCS_status_success) {goto Error;}

  // SimpleStorage 
  if (InsertJsonLinkObj (CsJson, "SimpleStorage", &CSPtr->SimpleStorage) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // Storage 
  if (InsertJsonLinkObj (CsJson, "Storage", &CSPtr->Storage) != RedfishCS_status_success) {goto Error;}

  // SystemType 
  if (InsertJsonStringObj (CsJson, "SystemType", CSPtr->SystemType) != RedfishCS_status_success) {goto Error;}

  // TrustedModules
  if (CS_To_JSON_TrustedModules(CsJson, "TrustedModules", CSPtr->TrustedModules) != RedfishCS_status_success) {goto Error;}

  // UUID 
  if (InsertJsonStringObj (CsJson, "UUID", CSPtr->UUID) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for ComputerSystem.V1_3_1.ComputerSystem
//
RedfishCS_status DestroyComputerSystem_V1_3_1_CS(RedfishComputerSystem_V1_3_1_ComputerSystem_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for ComputerSystem.V1_3_1.ComputerSystem
//
RedfishCS_status DestroyComputerSystem_V1_3_1_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for ComputerSystem.V1_3_1.ComputerSystem
//
RedfishCS_status
Json_ComputerSystem_V1_3_1_To_CS(RedfishCS_char *JsonRawText, RedfishComputerSystem_V1_3_1_ComputerSystem_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishComputerSystem_V1_3_1_ComputerSystem_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "ComputerSystem", "v1_3_1", "ComputerSystem", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishComputerSystem_V1_3_1_ComputerSystem_CS));
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

  // Bios
  InitializeLinkHead (&Cs->Bios);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Bios", Cs->Header.ThisUri, &Cs->Bios);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // BiosVersion
  Status = GetRedfishPropertyStr (Cs, JsonObj, "BiosVersion", &Cs->BiosVersion);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Boot
  Status = GenBootCs (Cs, JsonObj, "Boot", &Cs->Boot);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Description
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Description", &Cs->Description);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // EthernetInterfaces
  InitializeLinkHead (&Cs->EthernetInterfaces);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "EthernetInterfaces", Cs->Header.ThisUri, &Cs->EthernetInterfaces);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HostName
  Status = GetRedfishPropertyStr (Cs, JsonObj, "HostName", &Cs->HostName);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HostedServices
  Status = GenHostedServicesCs (Cs, JsonObj, "HostedServices", &Cs->HostedServices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HostingRoles
  Status = GenRedfishCS_char_ArrayCs (Cs, JsonObj, "HostingRoles", &Cs->HostingRoles);
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

  // LogServices
  InitializeLinkHead (&Cs->LogServices);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "LogServices", Cs->Header.ThisUri, &Cs->LogServices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Manufacturer
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Manufacturer", &Cs->Manufacturer);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Memory
  InitializeLinkHead (&Cs->Memory);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Memory", Cs->Header.ThisUri, &Cs->Memory);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MemoryDomains
  InitializeLinkHead (&Cs->MemoryDomains);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "MemoryDomains", Cs->Header.ThisUri, &Cs->MemoryDomains);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MemorySummary
  Status = GenMemorySummaryCs (Cs, JsonObj, "MemorySummary", &Cs->MemorySummary);
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

  // NetworkInterfaces
  InitializeLinkHead (&Cs->NetworkInterfaces);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "NetworkInterfaces", Cs->Header.ThisUri, &Cs->NetworkInterfaces);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, JsonObj, "Oem", &Cs->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeDevices
  InitializeLinkHead (&Cs->PCIeDevices);
  Status = CreateCsUriOrJsonByNodeArray (Cs, JsonObj, "PCIeDevices", Cs->Header.ThisUri, &Cs->PCIeDevices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeDevices@odata.count
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "PCIeDevices@odata.count", &Cs->PCIeDevicesodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeDevices@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PCIeDevices@odata.navigationLink", &Cs->PCIeDevicesodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeFunctions
  InitializeLinkHead (&Cs->PCIeFunctions);
  Status = CreateCsUriOrJsonByNodeArray (Cs, JsonObj, "PCIeFunctions", Cs->Header.ThisUri, &Cs->PCIeFunctions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeFunctions@odata.count
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "PCIeFunctions@odata.count", &Cs->PCIeFunctionsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeFunctions@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PCIeFunctions@odata.navigationLink", &Cs->PCIeFunctionsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PartNumber
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PartNumber", &Cs->PartNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PowerState
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PowerState", &Cs->PowerState);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ProcessorSummary
  Status = GenProcessorSummaryCs (Cs, JsonObj, "ProcessorSummary", &Cs->ProcessorSummary);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Processors
  InitializeLinkHead (&Cs->Processors);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Processors", Cs->Header.ThisUri, &Cs->Processors);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SKU
  Status = GetRedfishPropertyStr (Cs, JsonObj, "SKU", &Cs->SKU);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SecureBoot
  InitializeLinkHead (&Cs->SecureBoot);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "SecureBoot", Cs->Header.ThisUri, &Cs->SecureBoot);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SerialNumber
  Status = GetRedfishPropertyStr (Cs, JsonObj, "SerialNumber", &Cs->SerialNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SimpleStorage
  InitializeLinkHead (&Cs->SimpleStorage);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "SimpleStorage", Cs->Header.ThisUri, &Cs->SimpleStorage);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, JsonObj, "Status", &Cs->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Storage
  InitializeLinkHead (&Cs->Storage);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Storage", Cs->Header.ThisUri, &Cs->Storage);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SystemType
  Status = GetRedfishPropertyStr (Cs, JsonObj, "SystemType", &Cs->SystemType);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // TrustedModules
  Status = GenTrustedModules_ArrayCs (Cs, JsonObj, "TrustedModules", &Cs->TrustedModules);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UUID
  Status = GetRedfishPropertyStr (Cs, JsonObj, "UUID", &Cs->UUID);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyComputerSystem_V1_3_1_CS (Cs);
  return Status;
}
