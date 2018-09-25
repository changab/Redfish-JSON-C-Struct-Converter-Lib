//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_Endpoint_v1_0_0_CS.h"
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

static RedfishCS_status GenIdentifier_ArrayCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_V1_1_0_Identifier_Array_CS **Dst);
static RedfishCS_status GenOemCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
static RedfishCS_status GenPciIdCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishEndpoint_V1_0_0_PciId_CS **Dst);
//
//Generate C structure for Actions
//
static RedfishCS_status GenActionsCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishEndpoint_V1_0_0_Endpoint_Actions_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishEndpoint_V1_0_0_Endpoint_Actions_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Oem
  InitializeLinkHead (&(*Dst)->Oem);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "Oem", Cs->Header.ThisUri, &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for EntityPciId
//
static RedfishCS_status GenPciIdCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishEndpoint_V1_0_0_PciId_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishEndpoint_V1_0_0_PciId_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // DeviceId
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "DeviceId", &(*Dst)->DeviceId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SubsystemId
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "SubsystemId", &(*Dst)->SubsystemId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SubsystemVendorId
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "SubsystemVendorId", &(*Dst)->SubsystemVendorId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // VendorId
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "VendorId", &(*Dst)->VendorId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
static RedfishCS_status GenIdentifier_Array_ElementCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  RedfishResource_V1_1_0_Identifier_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(RedfishResource_V1_1_0_Identifier_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // DurableName
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "DurableName", &(*Dst)->DurableName);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // DurableNameFormat
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "DurableNameFormat", &(*Dst)->DurableNameFormat);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for RedfishResource_V1_1_0_Identifier_Array_CS
//
static RedfishCS_status GenIdentifier_ArrayCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_V1_1_0_Identifier_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  RedfishResource_V1_1_0_Identifier_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishResource_V1_1_0_Identifier_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenIdentifier_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
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
static RedfishCS_status GenOemCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
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
static RedfishCS_status GenConnectedEntity_Array_ElementCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  RedfishEndpoint_V1_0_0_ConnectedEntity_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(RedfishEndpoint_V1_0_0_ConnectedEntity_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // EntityLink
  InitializeLinkHead (&(*Dst)->EntityLink);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "EntityLink", Cs->Header.ThisUri, &(*Dst)->EntityLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // EntityPciId
  Status = GenPciIdCs (Cs, TempJsonObj, "EntityPciId", &(*Dst)->EntityPciId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // EntityRole
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "EntityRole", &(*Dst)->EntityRole);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // EntityType
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "EntityType", &(*Dst)->EntityType);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Identifiers
  Status = GenIdentifier_ArrayCs (Cs, TempJsonObj, "Identifiers", &(*Dst)->Identifiers);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PciClassCode
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "PciClassCode", &(*Dst)->PciClassCode);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PciFunctionNumber
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "PciFunctionNumber", &(*Dst)->PciFunctionNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for RedfishEndpoint_V1_0_0_ConnectedEntity_Array_CS
//
static RedfishCS_status GenConnectedEntity_ArrayCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishEndpoint_V1_0_0_ConnectedEntity_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  RedfishEndpoint_V1_0_0_ConnectedEntity_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishEndpoint_V1_0_0_ConnectedEntity_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenConnectedEntity_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
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
static RedfishCS_status GenLinksCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishEndpoint_V1_0_0_Endpoint_Links_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishEndpoint_V1_0_0_Endpoint_Links_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // MutuallyExclusiveEndpoints
  InitializeLinkHead (&(*Dst)->MutuallyExclusiveEndpoints);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "MutuallyExclusiveEndpoints", Cs->Header.ThisUri, &(*Dst)->MutuallyExclusiveEndpoints);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MutuallyExclusiveEndpoints@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MutuallyExclusiveEndpoints@odata.count", &(*Dst)->MutuallyExclusiveEndpointsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MutuallyExclusiveEndpoints@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "MutuallyExclusiveEndpoints@odata.navigationLink", &(*Dst)->MutuallyExclusiveEndpointsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Ports
  InitializeLinkHead (&(*Dst)->Ports);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Ports", Cs->Header.ThisUri, &(*Dst)->Ports);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Ports@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Ports@odata.count", &(*Dst)->Portsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Ports@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Ports@odata.navigationLink", &(*Dst)->Portsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishEndpoint_V1_0_0_Endpoint_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
static RedfishCS_status CS_To_JSON_Actions(json_t *CsJson, char *Key, RedfishEndpoint_V1_0_0_Endpoint_Actions_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Oem 
  if (InsertJsonLinkObj (CsJson, "Oem", &CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ConnectedEntitiesEntityPciId(json_t *CsJson, char *Key, RedfishEndpoint_V1_0_0_PciId_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // DeviceId 
  if (InsertJsonStringObj (CsJson, "DeviceId", CSPtr->DeviceId) != RedfishCS_status_success) {goto Error;}

  // SubsystemId 
  if (InsertJsonStringObj (CsJson, "SubsystemId", CSPtr->SubsystemId) != RedfishCS_status_success) {goto Error;}

  // SubsystemVendorId 
  if (InsertJsonStringObj (CsJson, "SubsystemVendorId", CSPtr->SubsystemVendorId) != RedfishCS_status_success) {goto Error;}

  // VendorId 
  if (InsertJsonStringObj (CsJson, "VendorId", CSPtr->VendorId) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ConnectedEntitiesIdentifiers(json_t *CsJson, char *Key, RedfishResource_V1_1_0_Identifier_Array_CS *CSPtr)
{
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_ConnectedEntitiesOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_ConnectedEntities(json_t *CsJson, char *Key, RedfishEndpoint_V1_0_0_ConnectedEntity_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishEndpoint_V1_0_0_ConnectedEntity_Array_CS *NextArray;
  RedfishEndpoint_V1_0_0_ConnectedEntity_CS *NextArrayItem;

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
    // EntityLink 
    if (InsertJsonLinkObj (ArrayMember, "EntityLink", &NextArrayItem->EntityLink) != RedfishCS_status_success) {goto Error;}

    // EntityPciId
    if (CS_To_JSON_ConnectedEntitiesEntityPciId(ArrayMember, "EntityPciId", NextArrayItem->EntityPciId) != RedfishCS_status_success) {goto Error;}

    // EntityRole 
    if (InsertJsonStringObj (ArrayMember, "EntityRole", NextArrayItem->EntityRole) != RedfishCS_status_success) {goto Error;}

    // EntityType 
    if (InsertJsonStringObj (ArrayMember, "EntityType", NextArrayItem->EntityType) != RedfishCS_status_success) {goto Error;}

    // Identifiers
    if (CS_To_JSON_ConnectedEntitiesIdentifiers(ArrayMember, "Identifiers", NextArrayItem->Identifiers) != RedfishCS_status_success) {goto Error;}

    // Oem
    if (CS_To_JSON_ConnectedEntitiesOem(ArrayMember, "Oem", NextArrayItem->Oem) != RedfishCS_status_success) {goto Error;}

    // PciClassCode 
    if (InsertJsonStringObj (ArrayMember, "PciClassCode", NextArrayItem->PciClassCode) != RedfishCS_status_success) {goto Error;}

    // PciFunctionNumber 
    if (InsertJsonInt64Obj (ArrayMember, "PciFunctionNumber", NextArrayItem->PciFunctionNumber) != RedfishCS_status_success) {goto Error;}

    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {goto Error;}
    NextArray = NextArray->Next;
  } while (NextArray != NULL);
  json_object_set_new (CsJson, Key, ArrayJson);

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Identifiers(json_t *CsJson, char *Key, RedfishResource_V1_1_0_Identifier_Array_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_Links(json_t *CsJson, char *Key, RedfishEndpoint_V1_0_0_Endpoint_Links_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // MutuallyExclusiveEndpoints 
  if (InsertJsonLinkArrayObj (CsJson, "MutuallyExclusiveEndpoints", &CSPtr->MutuallyExclusiveEndpoints) != RedfishCS_status_success) {goto Error;}

  // MutuallyExclusiveEndpoints@odata.count 
  if (InsertJsonInt64Obj (CsJson, "MutuallyExclusiveEndpoints@odata.count", CSPtr->MutuallyExclusiveEndpointsodata_count) != RedfishCS_status_success) {goto Error;}

  // MutuallyExclusiveEndpoints@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "MutuallyExclusiveEndpoints@odata.navigationLink", CSPtr->MutuallyExclusiveEndpointsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_LinksOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // Ports 
  if (InsertJsonLinkArrayObj (CsJson, "Ports", &CSPtr->Ports) != RedfishCS_status_success) {goto Error;}

  // Ports@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Ports@odata.count", CSPtr->Portsodata_count) != RedfishCS_status_success) {goto Error;}

  // Ports@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Ports@odata.navigationLink", CSPtr->Portsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

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
static RedfishCS_status CS_To_JSON_PciId(json_t *CsJson, char *Key, RedfishEndpoint_V1_0_0_PciId_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // DeviceId 
  if (InsertJsonStringObj (CsJson, "DeviceId", CSPtr->DeviceId) != RedfishCS_status_success) {goto Error;}

  // SubsystemId 
  if (InsertJsonStringObj (CsJson, "SubsystemId", CSPtr->SubsystemId) != RedfishCS_status_success) {goto Error;}

  // SubsystemVendorId 
  if (InsertJsonStringObj (CsJson, "SubsystemVendorId", CSPtr->SubsystemVendorId) != RedfishCS_status_success) {goto Error;}

  // VendorId 
  if (InsertJsonStringObj (CsJson, "VendorId", CSPtr->VendorId) != RedfishCS_status_success) {goto Error;}

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
// C structure to JSON for Endpoint.V1_0_0.Endpoint
//
RedfishCS_status CS_To_Endpoint_V1_0_0_JSON(RedfishEndpoint_V1_0_0_Endpoint_CS *CSPtr, RedfishCS_char **JsonText)
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

  // ConnectedEntities
  if (CS_To_JSON_ConnectedEntities(CsJson, "ConnectedEntities", CSPtr->ConnectedEntities) != RedfishCS_status_success) {goto Error;}

  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // EndpointProtocol 
  if (InsertJsonStringObj (CsJson, "EndpointProtocol", CSPtr->EndpointProtocol) != RedfishCS_status_success) {goto Error;}

  // HostReservationMemoryBytes 
  if (InsertJsonInt64Obj (CsJson, "HostReservationMemoryBytes", CSPtr->HostReservationMemoryBytes) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // Identifiers
  if (CS_To_JSON_Identifiers(CsJson, "Identifiers", CSPtr->Identifiers) != RedfishCS_status_success) {goto Error;}

  // Links
  if (CS_To_JSON_Links(CsJson, "Links", CSPtr->Links) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PciId
  if (CS_To_JSON_PciId(CsJson, "PciId", CSPtr->PciId) != RedfishCS_status_success) {goto Error;}

  // Redundancy 
  if (InsertJsonLinkArrayObj (CsJson, "Redundancy", &CSPtr->Redundancy) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Redundancy@odata.count", CSPtr->Redundancyodata_count) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Redundancy@odata.navigationLink", CSPtr->Redundancyodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for Endpoint.V1_0_0.Endpoint
//
RedfishCS_status DestroyEndpoint_V1_0_0_CS(RedfishEndpoint_V1_0_0_Endpoint_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for Endpoint.V1_0_0.Endpoint
//
RedfishCS_status DestroyEndpoint_V1_0_0_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for Endpoint.V1_0_0.Endpoint
//
RedfishCS_status
Json_Endpoint_V1_0_0_To_CS(RedfishCS_char *JsonRawText, RedfishEndpoint_V1_0_0_Endpoint_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishEndpoint_V1_0_0_Endpoint_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "Endpoint", "v1_0_0", "Endpoint", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishEndpoint_V1_0_0_Endpoint_CS));
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

  // ConnectedEntities
  Status = GenConnectedEntity_ArrayCs (Cs, JsonObj, "ConnectedEntities", &Cs->ConnectedEntities);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Description
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Description", &Cs->Description);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // EndpointProtocol
  Status = GetRedfishPropertyStr (Cs, JsonObj, "EndpointProtocol", &Cs->EndpointProtocol);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HostReservationMemoryBytes
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "HostReservationMemoryBytes", &Cs->HostReservationMemoryBytes);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Id", &Cs->Id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // Identifiers
  Status = GenIdentifier_ArrayCs (Cs, JsonObj, "Identifiers", &Cs->Identifiers);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Links
  Status = GenLinksCs (Cs, JsonObj, "Links", &Cs->Links);
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

  // PciId
  Status = GenPciIdCs (Cs, JsonObj, "PciId", &Cs->PciId);
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

  // Status
  Status = GenStatusCs (Cs, JsonObj, "Status", &Cs->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyEndpoint_V1_0_0_CS (Cs);
  return Status;
}
