//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_ManagerNetworkProtocol_v1_0_2_CS.h"
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
RedfishCS_bool CheckEmptyPropJsonObject(json_t *JsonObj, RedfishCS_uint32 *NumOfProperty);
RedfishCS_status CreateEmptyPropCsJson(RedfishCS_void *Cs, json_t *JsonOj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Type_EmptyProp_CS_Data **CsTypeEmptyPropCS, RedfishCS_uint32 NunmOfProperties);
RedfishCS_status CsEmptyPropLinkToJson(json_t *CsJson, char *Key, RedfishCS_Link *Link);

static RedfishCS_status GenProtocolCs(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs, json_t *JsonObj, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS **Dst);
static RedfishCS_status GenOemCs(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
//
//Generate C structure for HTTP
//
static RedfishCS_status GenProtocolCs(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs, json_t *JsonObj, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Port
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Port", &(*Dst)->Port);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ProtocolEnabled
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "ProtocolEnabled", &(*Dst)->ProtocolEnabled);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  RedfishCS_Type_EmptyProp_CS_Data *CsTypeEmptyPropCS;
  RedfishCS_uint32 NunmOfEmptyPropProperties;
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

  //
  // Try to create C structure if the property is
  // declared as empty property in schema. The supported property type
  // is string, integer, real, number and boolean.
  //
  if (CheckEmptyPropJsonObject(TempJsonObj, &NunmOfEmptyPropProperties)) {
    Status = CreateEmptyPropCsJson(Cs, JsonObj, Key, Cs->Header.ThisUri, &CsTypeEmptyPropCS, NunmOfEmptyPropProperties);
    if (Status != RedfishCS_status_success) {
      goto Error;
    }
    InsertTailLink(&(*Dst)->Prop, &CsTypeEmptyPropCS->Header.LinkEntry);
  } else {
    Status = CreateCsJsonByNode (Cs, JsonObj, Key, Cs->Header.ThisUri, &CsTypeJson);
    if (Status != RedfishCS_status_success) {
      goto Error;
    }
    InsertTailLink(&(*Dst)->Prop, &CsTypeJson->Header.LinkEntry);
  }
Error:;
  return Status;
}
//
//Generate C structure for SSDP
//
static RedfishCS_status GenSSDProtocolCs(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs, json_t *JsonObj, char *Key, RedfishManagerNetworkProtocol_V1_0_2_SSDProtocol_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishManagerNetworkProtocol_V1_0_2_SSDProtocol_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // NotifyIPv6Scope
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "NotifyIPv6Scope", &(*Dst)->NotifyIPv6Scope);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NotifyMulticastIntervalSeconds
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NotifyMulticastIntervalSeconds", &(*Dst)->NotifyMulticastIntervalSeconds);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NotifyTTL
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NotifyTTL", &(*Dst)->NotifyTTL);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Port
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Port", &(*Dst)->Port);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ProtocolEnabled
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "ProtocolEnabled", &(*Dst)->ProtocolEnabled);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
static RedfishCS_status CS_To_JSON_HTTP(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_HTTPS(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_IPMI(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_KVMIP(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Oem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_SNMP(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_SSDP(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_SSDProtocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // NotifyIPv6Scope 
  if (InsertJsonStringObj (CsJson, "NotifyIPv6Scope", CSPtr->NotifyIPv6Scope) != RedfishCS_status_success) {goto Error;}

  // NotifyMulticastIntervalSeconds 
  if (InsertJsonInt64Obj (CsJson, "NotifyMulticastIntervalSeconds", CSPtr->NotifyMulticastIntervalSeconds) != RedfishCS_status_success) {goto Error;}

  // NotifyTTL 
  if (InsertJsonInt64Obj (CsJson, "NotifyTTL", CSPtr->NotifyTTL) != RedfishCS_status_success) {goto Error;}

  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_SSH(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_StatusOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Status(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Health 
  if (InsertJsonStringObj (CsJson, "Health", CSPtr->Health) != RedfishCS_status_success) {goto Error;}

  // HealthRollup 
  if (InsertJsonStringObj (CsJson, "HealthRollup", CSPtr->HealthRollup) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_StatusOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // State 
  if (InsertJsonStringObj (CsJson, "State", CSPtr->State) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Telnet(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_VirtualMedia(json_t *CsJson, char *Key, RedfishManagerNetworkProtocol_V1_0_2_Protocol_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Port 
  if (InsertJsonInt64Obj (CsJson, "Port", CSPtr->Port) != RedfishCS_status_success) {goto Error;}

  // ProtocolEnabled 
  if (InsertJsonBoolObj (CsJson, "ProtocolEnabled", CSPtr->ProtocolEnabled) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}

//
// C structure to JSON for ManagerNetworkProtocol.V1_0_2.ManagerNetworkProtocol
//
RedfishCS_status CS_To_ManagerNetworkProtocol_V1_0_2_JSON(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *CSPtr, RedfishCS_char **JsonText)
{
  json_t  *CsJson;

  if (CSPtr == NULL || JsonText == NULL || CSPtr->Header.ResourceType != RedfishCS_Type_CS) {
    return RedfishCS_status_invalid_parameter;
  }
  CsJson = json_object();
  if (CsJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // FQDN 
  if (InsertJsonStringObj (CsJson, "FQDN", CSPtr->FQDN) != RedfishCS_status_success) {goto Error;}

  // HTTP
  if (CS_To_JSON_HTTP(CsJson, "HTTP", CSPtr->HTTP) != RedfishCS_status_success) {goto Error;}

  // HTTPS
  if (CS_To_JSON_HTTPS(CsJson, "HTTPS", CSPtr->HTTPS) != RedfishCS_status_success) {goto Error;}

  // HostName 
  if (InsertJsonStringObj (CsJson, "HostName", CSPtr->HostName) != RedfishCS_status_success) {goto Error;}

  // IPMI
  if (CS_To_JSON_IPMI(CsJson, "IPMI", CSPtr->IPMI) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // KVMIP
  if (CS_To_JSON_KVMIP(CsJson, "KVMIP", CSPtr->KVMIP) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // SNMP
  if (CS_To_JSON_SNMP(CsJson, "SNMP", CSPtr->SNMP) != RedfishCS_status_success) {goto Error;}

  // SSDP
  if (CS_To_JSON_SSDP(CsJson, "SSDP", CSPtr->SSDP) != RedfishCS_status_success) {goto Error;}

  // SSH
  if (CS_To_JSON_SSH(CsJson, "SSH", CSPtr->SSH) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // Telnet
  if (CS_To_JSON_Telnet(CsJson, "Telnet", CSPtr->Telnet) != RedfishCS_status_success) {goto Error;}

  // VirtualMedia
  if (CS_To_JSON_VirtualMedia(CsJson, "VirtualMedia", CSPtr->VirtualMedia) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for ManagerNetworkProtocol.V1_0_2.ManagerNetworkProtocol
//
RedfishCS_status DestroyManagerNetworkProtocol_V1_0_2_CS(RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for ManagerNetworkProtocol.V1_0_2.ManagerNetworkProtocol
//
RedfishCS_status DestroyManagerNetworkProtocol_V1_0_2_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for ManagerNetworkProtocol.V1_0_2.ManagerNetworkProtocol
//
RedfishCS_status
Json_ManagerNetworkProtocol_V1_0_2_To_CS(RedfishCS_char *JsonRawText, RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "ManagerNetworkProtocol", "v1_0_2", "ManagerNetworkProtocol", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishManagerNetworkProtocol_V1_0_2_ManagerNetworkProtocol_CS));
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

  // Description
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Description", &Cs->Description);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // FQDN
  Status = GetRedfishPropertyStr (Cs, JsonObj, "FQDN", &Cs->FQDN);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HTTP
  Status = GenProtocolCs (Cs, JsonObj, "HTTP", &Cs->HTTP);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HTTPS
  Status = GenProtocolCs (Cs, JsonObj, "HTTPS", &Cs->HTTPS);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // HostName
  Status = GetRedfishPropertyStr (Cs, JsonObj, "HostName", &Cs->HostName);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // IPMI
  Status = GenProtocolCs (Cs, JsonObj, "IPMI", &Cs->IPMI);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Id", &Cs->Id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // KVMIP
  Status = GenProtocolCs (Cs, JsonObj, "KVMIP", &Cs->KVMIP);
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

  // SNMP
  Status = GenProtocolCs (Cs, JsonObj, "SNMP", &Cs->SNMP);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SSDP
  Status = GenSSDProtocolCs (Cs, JsonObj, "SSDP", &Cs->SSDP);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SSH
  Status = GenProtocolCs (Cs, JsonObj, "SSH", &Cs->SSH);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, JsonObj, "Status", &Cs->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Telnet
  Status = GenProtocolCs (Cs, JsonObj, "Telnet", &Cs->Telnet);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // VirtualMedia
  Status = GenProtocolCs (Cs, JsonObj, "VirtualMedia", &Cs->VirtualMedia);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyManagerNetworkProtocol_V1_0_2_CS (Cs);
  return Status;
}
