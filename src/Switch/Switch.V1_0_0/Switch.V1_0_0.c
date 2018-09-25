//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_Switch_v1_0_0_CS.h"
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

static RedfishCS_status GenOemCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
//
//Generate C structure for #Switch.Reset
//
static RedfishCS_status GenResetCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishSwitch_V1_0_0_Reset_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishSwitch_V1_0_0_Reset_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActions_OemCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishSwitch_V1_0_0_Switch_Actions_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishSwitch_V1_0_0_Switch_Actions_Oem_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActionsCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishSwitch_V1_0_0_Switch_Actions_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishSwitch_V1_0_0_Switch_Actions_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // #Switch.Reset
  Status = GenResetCs (Cs, TempJsonObj, "#Switch.Reset", &(*Dst)->Switch_Reset);
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
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
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
static RedfishCS_status GenLinksCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishSwitch_V1_0_0_Switch_Links_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishSwitch_V1_0_0_Switch_Links_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Chassis
  InitializeLinkHead (&(*Dst)->Chassis);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "Chassis", Cs->Header.ThisUri, &(*Dst)->Chassis);
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

Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishSwitch_V1_0_0_Switch_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
static RedfishCS_status CS_To_JSON_ActionsOem(json_t *CsJson, char *Key, RedfishSwitch_V1_0_0_Switch_Actions_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_ActionsSwitch_Reset(json_t *CsJson, char *Key, RedfishSwitch_V1_0_0_Reset_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_Actions(json_t *CsJson, char *Key, RedfishSwitch_V1_0_0_Switch_Actions_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Oem
  if (CS_To_JSON_ActionsOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // #Switch.Reset
  if (CS_To_JSON_ActionsSwitch_Reset(CsJson, "#Switch.Reset", CSPtr->Switch_Reset) != RedfishCS_status_success) {goto Error;}

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
static RedfishCS_status CS_To_JSON_Links(json_t *CsJson, char *Key, RedfishSwitch_V1_0_0_Switch_Links_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Chassis 
  if (InsertJsonLinkObj (CsJson, "Chassis", &CSPtr->Chassis) != RedfishCS_status_success) {goto Error;}

  // ManagedBy 
  if (InsertJsonLinkArrayObj (CsJson, "ManagedBy", &CSPtr->ManagedBy) != RedfishCS_status_success) {goto Error;}

  // ManagedBy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "ManagedBy@odata.count", CSPtr->ManagedByodata_count) != RedfishCS_status_success) {goto Error;}

  // ManagedBy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "ManagedBy@odata.navigationLink", CSPtr->ManagedByodata_navigationLink) != RedfishCS_status_success) {goto Error;}

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
static RedfishCS_status CS_To_JSON_Status(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}

//
// C structure to JSON for Switch.V1_0_0.Switch
//
RedfishCS_status CS_To_Switch_V1_0_0_JSON(RedfishSwitch_V1_0_0_Switch_CS *CSPtr, RedfishCS_char **JsonText)
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

  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // DomainID 
  if (InsertJsonInt64Obj (CsJson, "DomainID", CSPtr->DomainID) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // IndicatorLED 
  if (InsertJsonStringObj (CsJson, "IndicatorLED", CSPtr->IndicatorLED) != RedfishCS_status_success) {goto Error;}

  // IsManaged 
  if (InsertJsonBoolObj (CsJson, "IsManaged", CSPtr->IsManaged) != RedfishCS_status_success) {goto Error;}

  // Links
  if (CS_To_JSON_Links(CsJson, "Links", CSPtr->Links) != RedfishCS_status_success) {goto Error;}

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

  // Ports 
  if (InsertJsonLinkObj (CsJson, "Ports", &CSPtr->Ports) != RedfishCS_status_success) {goto Error;}

  // PowerState 
  if (InsertJsonStringObj (CsJson, "PowerState", CSPtr->PowerState) != RedfishCS_status_success) {goto Error;}

  // Redundancy 
  if (InsertJsonLinkArrayObj (CsJson, "Redundancy", &CSPtr->Redundancy) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Redundancy@odata.count", CSPtr->Redundancyodata_count) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Redundancy@odata.navigationLink", CSPtr->Redundancyodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // SKU 
  if (InsertJsonStringObj (CsJson, "SKU", CSPtr->SKU) != RedfishCS_status_success) {goto Error;}

  // SerialNumber 
  if (InsertJsonStringObj (CsJson, "SerialNumber", CSPtr->SerialNumber) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // SwitchType 
  if (InsertJsonStringObj (CsJson, "SwitchType", CSPtr->SwitchType) != RedfishCS_status_success) {goto Error;}

  // TotalSwitchWidth 
  if (InsertJsonInt64Obj (CsJson, "TotalSwitchWidth", CSPtr->TotalSwitchWidth) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for Switch.V1_0_0.Switch
//
RedfishCS_status DestroySwitch_V1_0_0_CS(RedfishSwitch_V1_0_0_Switch_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for Switch.V1_0_0.Switch
//
RedfishCS_status DestroySwitch_V1_0_0_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for Switch.V1_0_0.Switch
//
RedfishCS_status
Json_Switch_V1_0_0_To_CS(RedfishCS_char *JsonRawText, RedfishSwitch_V1_0_0_Switch_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishSwitch_V1_0_0_Switch_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "Switch", "v1_0_0", "Switch", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishSwitch_V1_0_0_Switch_CS));
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

  // Description
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Description", &Cs->Description);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // DomainID
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "DomainID", &Cs->DomainID);
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

  // IsManaged
  Status = GetRedfishPropertyBoolean (Cs, JsonObj, "IsManaged", &Cs->IsManaged);
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

  // Ports
  InitializeLinkHead (&Cs->Ports);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "Ports", Cs->Header.ThisUri, &Cs->Ports);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PowerState
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PowerState", &Cs->PowerState);
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

  // SwitchType
  Status = GetRedfishPropertyStr (Cs, JsonObj, "SwitchType", &Cs->SwitchType);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // TotalSwitchWidth
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "TotalSwitchWidth", &Cs->TotalSwitchWidth);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroySwitch_V1_0_0_CS (Cs);
  return Status;
}
