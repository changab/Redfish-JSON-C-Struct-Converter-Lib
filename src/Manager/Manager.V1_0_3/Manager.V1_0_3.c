//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_Manager_v1_0_3_CS.h"
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

static RedfishCS_status GenRedfishCS_char_ArrayCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishCS_char_Array **Dst);
static RedfishCS_status GenOemCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
//
//Generate C structure for #Manager.ForceFailover
//
static RedfishCS_status GenForceFailoverCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_ForceFailover_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_ForceFailover_CS), (RedfishCS_void **)Dst);
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
//Generate C structure for #Manager.ModifyRedundancySet
//
static RedfishCS_status GenModifyRedundancySetCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_ModifyRedundancySet_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_ModifyRedundancySet_CS), (RedfishCS_void **)Dst);
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
//Generate C structure for #Manager.Reset
//
static RedfishCS_status GenResetCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_Reset_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_Reset_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActions_OemCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_Manager_Actions_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_Manager_Actions_Oem_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActionsCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_Manager_Actions_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_Manager_Actions_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // #Manager.ForceFailover
  Status = GenForceFailoverCs (Cs, TempJsonObj, "#Manager.ForceFailover", &(*Dst)->Manager_ForceFailover);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // #Manager.ModifyRedundancySet
  Status = GenModifyRedundancySetCs (Cs, TempJsonObj, "#Manager.ModifyRedundancySet", &(*Dst)->Manager_ModifyRedundancySet);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // #Manager.Reset
  Status = GenResetCs (Cs, TempJsonObj, "#Manager.Reset", &(*Dst)->Manager_Reset);
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
static RedfishCS_status GenRedfishCS_char_ArrayCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishCS_char_Array **Dst)
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
//
//Generate C structure for CommandShell
//
static RedfishCS_status GenCommandShellCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_CommandShell_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_CommandShell_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // ConnectTypesSupported
  Status = GenRedfishCS_char_ArrayCs (Cs, TempJsonObj, "ConnectTypesSupported", &(*Dst)->ConnectTypesSupported);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MaxConcurrentSessions
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxConcurrentSessions", &(*Dst)->MaxConcurrentSessions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ServiceEnabled
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "ServiceEnabled", &(*Dst)->ServiceEnabled);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for GraphicalConsole
//
static RedfishCS_status GenGraphicalConsoleCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_GraphicalConsole_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_GraphicalConsole_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // ConnectTypesSupported
  Status = GenRedfishCS_char_ArrayCs (Cs, TempJsonObj, "ConnectTypesSupported", &(*Dst)->ConnectTypesSupported);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MaxConcurrentSessions
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxConcurrentSessions", &(*Dst)->MaxConcurrentSessions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ServiceEnabled
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "ServiceEnabled", &(*Dst)->ServiceEnabled);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
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
static RedfishCS_status GenLinksCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_Manager_Links_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_Manager_Links_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // ManagerForChassis
  InitializeLinkHead (&(*Dst)->ManagerForChassis);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "ManagerForChassis", Cs->Header.ThisUri, &(*Dst)->ManagerForChassis);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagerForChassis@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "ManagerForChassis@odata.count", &(*Dst)->ManagerForChassisodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagerForChassis@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "ManagerForChassis@odata.navigationLink", &(*Dst)->ManagerForChassisodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagerForServers
  InitializeLinkHead (&(*Dst)->ManagerForServers);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "ManagerForServers", Cs->Header.ThisUri, &(*Dst)->ManagerForServers);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagerForServers@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "ManagerForServers@odata.count", &(*Dst)->ManagerForServersodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagerForServers@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "ManagerForServers@odata.navigationLink", &(*Dst)->ManagerForServersodata_navigationLink);
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
//Generate C structure for SerialConsole
//
static RedfishCS_status GenSerialConsoleCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishManager_V1_0_3_SerialConsole_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManager_V1_0_3_SerialConsole_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // ConnectTypesSupported
  Status = GenRedfishCS_char_ArrayCs (Cs, TempJsonObj, "ConnectTypesSupported", &(*Dst)->ConnectTypesSupported);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MaxConcurrentSessions
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxConcurrentSessions", &(*Dst)->MaxConcurrentSessions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ServiceEnabled
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "ServiceEnabled", &(*Dst)->ServiceEnabled);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishManager_V1_0_3_Manager_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
static RedfishCS_status CS_To_JSON_ActionsManager_ForceFailover(json_t *CsJson, char *Key, RedfishManager_V1_0_3_ForceFailover_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_ActionsManager_ModifyRedundancySet(json_t *CsJson, char *Key, RedfishManager_V1_0_3_ModifyRedundancySet_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_ActionsManager_Reset(json_t *CsJson, char *Key, RedfishManager_V1_0_3_Reset_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_ActionsOem(json_t *CsJson, char *Key, RedfishManager_V1_0_3_Manager_Actions_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Actions(json_t *CsJson, char *Key, RedfishManager_V1_0_3_Manager_Actions_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // #Manager.ForceFailover
  if (CS_To_JSON_ActionsManager_ForceFailover(CsJson, "#Manager.ForceFailover", CSPtr->Manager_ForceFailover) != RedfishCS_status_success) {goto Error;}

  // #Manager.ModifyRedundancySet
  if (CS_To_JSON_ActionsManager_ModifyRedundancySet(CsJson, "#Manager.ModifyRedundancySet", CSPtr->Manager_ModifyRedundancySet) != RedfishCS_status_success) {goto Error;}

  // #Manager.Reset
  if (CS_To_JSON_ActionsManager_Reset(CsJson, "#Manager.Reset", CSPtr->Manager_Reset) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_ActionsOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_CommandShell(json_t *CsJson, char *Key, RedfishManager_V1_0_3_CommandShell_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // ConnectTypesSupported 
  if (InsertJsonStringArrayObj (CsJson, "ConnectTypesSupported", CSPtr->ConnectTypesSupported) != RedfishCS_status_success) {goto Error;}

  // MaxConcurrentSessions 
  if (InsertJsonInt64Obj (CsJson, "MaxConcurrentSessions", CSPtr->MaxConcurrentSessions) != RedfishCS_status_success) {goto Error;}

  // ServiceEnabled 
  if (InsertJsonBoolObj (CsJson, "ServiceEnabled", CSPtr->ServiceEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_GraphicalConsole(json_t *CsJson, char *Key, RedfishManager_V1_0_3_GraphicalConsole_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // ConnectTypesSupported 
  if (InsertJsonStringArrayObj (CsJson, "ConnectTypesSupported", CSPtr->ConnectTypesSupported) != RedfishCS_status_success) {goto Error;}

  // MaxConcurrentSessions 
  if (InsertJsonInt64Obj (CsJson, "MaxConcurrentSessions", CSPtr->MaxConcurrentSessions) != RedfishCS_status_success) {goto Error;}

  // ServiceEnabled 
  if (InsertJsonBoolObj (CsJson, "ServiceEnabled", CSPtr->ServiceEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_LinksOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Links(json_t *CsJson, char *Key, RedfishManager_V1_0_3_Manager_Links_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // ManagerForChassis 
  if (InsertJsonLinkArrayObj (CsJson, "ManagerForChassis", &CSPtr->ManagerForChassis) != RedfishCS_status_success) {goto Error;}

  // ManagerForChassis@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ManagerForChassis@odata.count", CSPtr->ManagerForChassisodata_count) != RedfishCS_status_success) {goto Error;}

  // ManagerForChassis@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ManagerForChassis@odata.navigationLink", CSPtr->ManagerForChassisodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // ManagerForServers 
  if (InsertJsonLinkArrayObj (CsJson, "ManagerForServers", &CSPtr->ManagerForServers) != RedfishCS_status_success) {goto Error;}

  // ManagerForServers@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ManagerForServers@odata.count", CSPtr->ManagerForServersodata_count) != RedfishCS_status_success) {goto Error;}

  // ManagerForServers@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ManagerForServers@odata.navigationLink", CSPtr->ManagerForServersodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_LinksOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

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
static RedfishCS_status CS_To_JSON_SerialConsole(json_t *CsJson, char *Key, RedfishManager_V1_0_3_SerialConsole_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // ConnectTypesSupported 
  if (InsertJsonStringArrayObj (CsJson, "ConnectTypesSupported", CSPtr->ConnectTypesSupported) != RedfishCS_status_success) {goto Error;}

  // MaxConcurrentSessions 
  if (InsertJsonInt64Obj (CsJson, "MaxConcurrentSessions", CSPtr->MaxConcurrentSessions) != RedfishCS_status_success) {goto Error;}

  // ServiceEnabled 
  if (InsertJsonBoolObj (CsJson, "ServiceEnabled", CSPtr->ServiceEnabled) != RedfishCS_status_success) {goto Error;}

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
// C structure to JSON for Manager.V1_0_3.Manager
//
RedfishCS_status CS_To_Manager_V1_0_3_JSON(RedfishManager_V1_0_3_Manager_CS *CSPtr, RedfishCS_char **JsonText)
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

  // CommandShell
  if (CS_To_JSON_CommandShell(CsJson, "CommandShell", CSPtr->CommandShell) != RedfishCS_status_success) {goto Error;}

  // DateTime 
  if (InsertJsonStringObj (CsJson, "DateTime", CSPtr->DateTime) != RedfishCS_status_success) {goto Error;}

  // DateTimeLocalOffset 
  if (InsertJsonStringObj (CsJson, "DateTimeLocalOffset", CSPtr->DateTimeLocalOffset) != RedfishCS_status_success) {goto Error;}

  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // EthernetInterfaces 
  if (InsertJsonLinkObj (CsJson, "EthernetInterfaces", &CSPtr->EthernetInterfaces) != RedfishCS_status_success) {goto Error;}

  // FirmwareVersion 
  if (InsertJsonStringObj (CsJson, "FirmwareVersion", CSPtr->FirmwareVersion) != RedfishCS_status_success) {goto Error;}

  // GraphicalConsole
  if (CS_To_JSON_GraphicalConsole(CsJson, "GraphicalConsole", CSPtr->GraphicalConsole) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // Links
  if (CS_To_JSON_Links(CsJson, "Links", CSPtr->Links) != RedfishCS_status_success) {goto Error;}

  // LogServices 
  if (InsertJsonLinkObj (CsJson, "LogServices", &CSPtr->LogServices) != RedfishCS_status_success) {goto Error;}

  // ManagerType 
  if (InsertJsonStringObj (CsJson, "ManagerType", CSPtr->ManagerType) != RedfishCS_status_success) {goto Error;}

  // Model 
  if (InsertJsonStringObj (CsJson, "Model", CSPtr->Model) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // NetworkProtocol 
  if (InsertJsonLinkObj (CsJson, "NetworkProtocol", &CSPtr->NetworkProtocol) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // Redundancy 
  if (InsertJsonLinkArrayObj (CsJson, "Redundancy", &CSPtr->Redundancy) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Redundancy@odata.count", CSPtr->Redundancyodata_count) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Redundancy@odata.navigationLink", CSPtr->Redundancyodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // SerialConsole
  if (CS_To_JSON_SerialConsole(CsJson, "SerialConsole", CSPtr->SerialConsole) != RedfishCS_status_success) {goto Error;}

  // SerialInterfaces 
  if (InsertJsonLinkObj (CsJson, "SerialInterfaces", &CSPtr->SerialInterfaces) != RedfishCS_status_success) {goto Error;}

  // ServiceEntryPointUUID 
  if (InsertJsonStringObj (CsJson, "ServiceEntryPointUUID", CSPtr->ServiceEntryPointUUID) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // UUID 
  if (InsertJsonStringObj (CsJson, "UUID", CSPtr->UUID) != RedfishCS_status_success) {goto Error;}

  // VirtualMedia 
  if (InsertJsonLinkObj (CsJson, "VirtualMedia", &CSPtr->VirtualMedia) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for Manager.V1_0_3.Manager
//
RedfishCS_status DestroyManager_V1_0_3_CS(RedfishManager_V1_0_3_Manager_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for Manager.V1_0_3.Manager
//
RedfishCS_status DestroyManager_V1_0_3_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for Manager.V1_0_3.Manager
//
RedfishCS_status
Json_Manager_V1_0_3_To_CS(RedfishCS_char *JsonRawText, RedfishManager_V1_0_3_Manager_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishManager_V1_0_3_Manager_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "Manager", "v1_0_3", "Manager", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishManager_V1_0_3_Manager_CS));
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

  // CommandShell
  Status = GenCommandShellCs (Cs, JsonObj, "CommandShell", &Cs->CommandShell);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // DateTime
  Status = GetRedfishPropertyStr (Cs, JsonObj, "DateTime", &Cs->DateTime);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // DateTimeLocalOffset
  Status = GetRedfishPropertyStr (Cs, JsonObj, "DateTimeLocalOffset", &Cs->DateTimeLocalOffset);
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

  // FirmwareVersion
  Status = GetRedfishPropertyStr (Cs, JsonObj, "FirmwareVersion", &Cs->FirmwareVersion);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // GraphicalConsole
  Status = GenGraphicalConsoleCs (Cs, JsonObj, "GraphicalConsole", &Cs->GraphicalConsole);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Id", &Cs->Id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // Links
  Status = GenLinksCs (Cs, JsonObj, "Links", &Cs->Links);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LogServices
  InitializeLinkHead (&Cs->LogServices);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "LogServices", Cs->Header.ThisUri, &Cs->LogServices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ManagerType
  Status = GetRedfishPropertyStr (Cs, JsonObj, "ManagerType", &Cs->ManagerType);
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

  // NetworkProtocol
  InitializeLinkHead (&Cs->NetworkProtocol);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "NetworkProtocol", Cs->Header.ThisUri, &Cs->NetworkProtocol);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, JsonObj, "Oem", &Cs->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Redundancy
  InitializeLinkHead (&Cs->Redundancy);
  Status = CreateCsUriOrJsonByNodeArray (Cs, JsonObj, "Redundancy", Cs->Header.ThisUri, &Cs->Redundancy);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Redundancy@odata.count
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "Redundancy@odata.count", &Cs->Redundancyodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Redundancy@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Redundancy@odata.navigationLink", &Cs->Redundancyodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SerialConsole
  Status = GenSerialConsoleCs (Cs, JsonObj, "SerialConsole", &Cs->SerialConsole);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SerialInterfaces
  InitializeLinkHead (&Cs->SerialInterfaces);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "SerialInterfaces", Cs->Header.ThisUri, &Cs->SerialInterfaces);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ServiceEntryPointUUID
  Status = GetRedfishPropertyStr (Cs, JsonObj, "ServiceEntryPointUUID", &Cs->ServiceEntryPointUUID);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, JsonObj, "Status", &Cs->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UUID
  Status = GetRedfishPropertyStr (Cs, JsonObj, "UUID", &Cs->UUID);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // VirtualMedia
  InitializeLinkHead (&Cs->VirtualMedia);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "VirtualMedia", Cs->Header.ThisUri, &Cs->VirtualMedia);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyManager_V1_0_3_CS (Cs);
  return Status;
}
