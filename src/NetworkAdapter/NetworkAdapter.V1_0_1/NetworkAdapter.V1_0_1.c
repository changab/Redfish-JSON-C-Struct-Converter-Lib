//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_NetworkAdapter_v1_0_1_CS.h"
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

static RedfishCS_status GenOemCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
//
//Generate C structure for #NetworkAdapter.ResetSettingsToDefault
//
static RedfishCS_status GenResetSettingsToDefaultCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActions_OemCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS **Dst)
{
  RedfishCS_status Status;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS), (RedfishCS_void **)Dst);
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
static RedfishCS_status GenActionsCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // #NetworkAdapter.ResetSettingsToDefault
  Status = GenResetSettingsToDefaultCs (Cs, TempJsonObj, "#NetworkAdapter.ResetSettingsToDefault", &(*Dst)->NetworkAdapter_ResetSettingsToDefault);
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
//Generate C structure for DataCenterBridging
//
static RedfishCS_status GenDataCenterBridgingCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // Capable
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "Capable", &(*Dst)->Capable);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for NPIV
//
static RedfishCS_status GenNPIVCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_NPIV_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_NPIV_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // MaxDeviceLogins
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxDeviceLogins", &(*Dst)->MaxDeviceLogins);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MaxPortLogins
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxPortLogins", &(*Dst)->MaxPortLogins);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for SRIOV
//
static RedfishCS_status GenSRIOVCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_SRIOV_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_SRIOV_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // SRIOVVEPACapable
  Status = GetRedfishPropertyBoolean (Cs, TempJsonObj, "SRIOVVEPACapable", &(*Dst)->SRIOVVEPACapable);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for VirtualFunction
//
static RedfishCS_status GenVirtualFunctionCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // DeviceMaxCount
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "DeviceMaxCount", &(*Dst)->DeviceMaxCount);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MinAssignmentGroupSize
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MinAssignmentGroupSize", &(*Dst)->MinAssignmentGroupSize);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkPortMaxCount
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NetworkPortMaxCount", &(*Dst)->NetworkPortMaxCount);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for VirtualizationOffload
//
static RedfishCS_status GenVirtualizationOffloadCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // SRIOV
  Status = GenSRIOVCs (Cs, TempJsonObj, "SRIOV", &(*Dst)->SRIOV);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // VirtualFunction
  Status = GenVirtualFunctionCs (Cs, TempJsonObj, "VirtualFunction", &(*Dst)->VirtualFunction);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for ControllerCapabilities
//
static RedfishCS_status GenControllerCapabilitiesCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // DataCenterBridging
  Status = GenDataCenterBridgingCs (Cs, TempJsonObj, "DataCenterBridging", &(*Dst)->DataCenterBridging);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NPIV
  Status = GenNPIVCs (Cs, TempJsonObj, "NPIV", &(*Dst)->NPIV);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkDeviceFunctionCount
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NetworkDeviceFunctionCount", &(*Dst)->NetworkDeviceFunctionCount);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkPortCount
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NetworkPortCount", &(*Dst)->NetworkPortCount);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // VirtualizationOffload
  Status = GenVirtualizationOffloadCs (Cs, TempJsonObj, "VirtualizationOffload", &(*Dst)->VirtualizationOffload);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
//
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
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
static RedfishCS_status GenControllers_LinksCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // NetworkDeviceFunctions
  InitializeLinkHead (&(*Dst)->NetworkDeviceFunctions);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "NetworkDeviceFunctions", Cs->Header.ThisUri, &(*Dst)->NetworkDeviceFunctions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkDeviceFunctions@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NetworkDeviceFunctions@odata.count", &(*Dst)->NetworkDeviceFunctionsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkDeviceFunctions@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "NetworkDeviceFunctions@odata.navigationLink", &(*Dst)->NetworkDeviceFunctionsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkPorts
  InitializeLinkHead (&(*Dst)->NetworkPorts);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "NetworkPorts", Cs->Header.ThisUri, &(*Dst)->NetworkPorts);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkPorts@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "NetworkPorts@odata.count", &(*Dst)->NetworkPortsodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkPorts@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "NetworkPorts@odata.navigationLink", &(*Dst)->NetworkPortsodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeDevices
  InitializeLinkHead (&(*Dst)->PCIeDevices);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "PCIeDevices", Cs->Header.ThisUri, &(*Dst)->PCIeDevices);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeDevices@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "PCIeDevices@odata.count", &(*Dst)->PCIeDevicesodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PCIeDevices@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "PCIeDevices@odata.navigationLink", &(*Dst)->PCIeDevicesodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

Error:;
  return Status;
}
static RedfishCS_status GenControllers_Array_ElementCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  RedfishNetworkAdapter_V1_0_1_Controllers_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(RedfishNetworkAdapter_V1_0_1_Controllers_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // ControllerCapabilities
  Status = GenControllerCapabilitiesCs (Cs, TempJsonObj, "ControllerCapabilities", &(*Dst)->ControllerCapabilities);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // FirmwarePackageVersion
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "FirmwarePackageVersion", &(*Dst)->FirmwarePackageVersion);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Links
  Status = GenControllers_LinksCs (Cs, TempJsonObj, "Links", &(*Dst)->Links);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for RedfishNetworkAdapter_V1_0_1_Controllers_Array_CS
//
static RedfishCS_status GenControllers_ArrayCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishNetworkAdapter_V1_0_1_Controllers_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  RedfishNetworkAdapter_V1_0_1_Controllers_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishNetworkAdapter_V1_0_1_Controllers_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenControllers_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
    if (Status != RedfishCS_status_success){
      goto Error;
    }
    ThisElement = ThisElement->Next;
  }
Error:;
  return Status;
}
//
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
static RedfishCS_status CS_To_JSON_ActionsNetworkAdapter_ResetSettingsToDefault(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_ResetSettingsToDefault_CS *CSPtr)
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
static RedfishCS_status CS_To_JSON_ActionsOem(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_Actions(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_NetworkAdapter_Actions_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // #NetworkAdapter.ResetSettingsToDefault
  if (CS_To_JSON_ActionsNetworkAdapter_ResetSettingsToDefault(CsJson, "#NetworkAdapter.ResetSettingsToDefault", CSPtr->NetworkAdapter_ResetSettingsToDefault) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_ActionsOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersControllerCapabilitiesDataCenterBridging(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_DataCenterBridging_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Capable 
  if (InsertJsonBoolObj (CsJson, "Capable", CSPtr->Capable) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersControllerCapabilitiesNPIV(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_NPIV_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // MaxDeviceLogins 
  if (InsertJsonInt64Obj (CsJson, "MaxDeviceLogins", CSPtr->MaxDeviceLogins) != RedfishCS_status_success) {goto Error;}

  // MaxPortLogins 
  if (InsertJsonInt64Obj (CsJson, "MaxPortLogins", CSPtr->MaxPortLogins) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersControllerCapabilitiesVirtualizationOffloadSRIOV(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_SRIOV_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // SRIOVVEPACapable 
  if (InsertJsonBoolObj (CsJson, "SRIOVVEPACapable", CSPtr->SRIOVVEPACapable) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersControllerCapabilitiesVirtualizationOffloadVirtualFunction(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_VirtualFunction_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // DeviceMaxCount 
  if (InsertJsonInt64Obj (CsJson, "DeviceMaxCount", CSPtr->DeviceMaxCount) != RedfishCS_status_success) {goto Error;}

  // MinAssignmentGroupSize 
  if (InsertJsonInt64Obj (CsJson, "MinAssignmentGroupSize", CSPtr->MinAssignmentGroupSize) != RedfishCS_status_success) {goto Error;}

  // NetworkPortMaxCount 
  if (InsertJsonInt64Obj (CsJson, "NetworkPortMaxCount", CSPtr->NetworkPortMaxCount) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersControllerCapabilitiesVirtualizationOffload(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_VirtualizationOffload_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // SRIOV
  if (CS_To_JSON_ControllersControllerCapabilitiesVirtualizationOffloadSRIOV(CsJson, "SRIOV", CSPtr->SRIOV) != RedfishCS_status_success) {goto Error;}

  // VirtualFunction
  if (CS_To_JSON_ControllersControllerCapabilitiesVirtualizationOffloadVirtualFunction(CsJson, "VirtualFunction", CSPtr->VirtualFunction) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersControllerCapabilities(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_ControllerCapabilities_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // DataCenterBridging
  if (CS_To_JSON_ControllersControllerCapabilitiesDataCenterBridging(CsJson, "DataCenterBridging", CSPtr->DataCenterBridging) != RedfishCS_status_success) {goto Error;}

  // NPIV
  if (CS_To_JSON_ControllersControllerCapabilitiesNPIV(CsJson, "NPIV", CSPtr->NPIV) != RedfishCS_status_success) {goto Error;}

  // NetworkDeviceFunctionCount 
  if (InsertJsonInt64Obj (CsJson, "NetworkDeviceFunctionCount", CSPtr->NetworkDeviceFunctionCount) != RedfishCS_status_success) {goto Error;}

  // NetworkPortCount 
  if (InsertJsonInt64Obj (CsJson, "NetworkPortCount", CSPtr->NetworkPortCount) != RedfishCS_status_success) {goto Error;}

  // VirtualizationOffload
  if (CS_To_JSON_ControllersControllerCapabilitiesVirtualizationOffload(CsJson, "VirtualizationOffload", CSPtr->VirtualizationOffload) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_ControllersLinksOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_ControllersLinks(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_Controllers_Links_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // NetworkDeviceFunctions 
  if (InsertJsonLinkArrayObj (CsJson, "NetworkDeviceFunctions", &CSPtr->NetworkDeviceFunctions) != RedfishCS_status_success) {goto Error;}

  // NetworkDeviceFunctions@odata.count 
  if (InsertJsonInt64Obj (CsJson, "NetworkDeviceFunctions@odata.count", CSPtr->NetworkDeviceFunctionsodata_count) != RedfishCS_status_success) {goto Error;}

  // NetworkDeviceFunctions@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "NetworkDeviceFunctions@odata.navigationLink", CSPtr->NetworkDeviceFunctionsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // NetworkPorts 
  if (InsertJsonLinkArrayObj (CsJson, "NetworkPorts", &CSPtr->NetworkPorts) != RedfishCS_status_success) {goto Error;}

  // NetworkPorts@odata.count 
  if (InsertJsonInt64Obj (CsJson, "NetworkPorts@odata.count", CSPtr->NetworkPortsodata_count) != RedfishCS_status_success) {goto Error;}

  // NetworkPorts@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "NetworkPorts@odata.navigationLink", CSPtr->NetworkPortsodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_ControllersLinksOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PCIeDevices 
  if (InsertJsonLinkArrayObj (CsJson, "PCIeDevices", &CSPtr->PCIeDevices) != RedfishCS_status_success) {goto Error;}

  // PCIeDevices@odata.count 
  if (InsertJsonInt64Obj (CsJson, "PCIeDevices@odata.count", CSPtr->PCIeDevicesodata_count) != RedfishCS_status_success) {goto Error;}

  // PCIeDevices@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "PCIeDevices@odata.navigationLink", CSPtr->PCIeDevicesodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Controllers(json_t *CsJson, char *Key, RedfishNetworkAdapter_V1_0_1_Controllers_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishNetworkAdapter_V1_0_1_Controllers_Array_CS *NextArray;
  RedfishNetworkAdapter_V1_0_1_Controllers_CS *NextArrayItem;

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
    // ControllerCapabilities
    if (CS_To_JSON_ControllersControllerCapabilities(ArrayMember, "ControllerCapabilities", NextArrayItem->ControllerCapabilities) != RedfishCS_status_success) {goto Error;}

    // FirmwarePackageVersion 
    if (InsertJsonStringObj (ArrayMember, "FirmwarePackageVersion", NextArrayItem->FirmwarePackageVersion) != RedfishCS_status_success) {goto Error;}

    // Links
    if (CS_To_JSON_ControllersLinks(ArrayMember, "Links", NextArrayItem->Links) != RedfishCS_status_success) {goto Error;}

    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {goto Error;}
    NextArray = NextArray->Next;
  } while (NextArray != NULL);
  json_object_set_new (CsJson, Key, ArrayJson);

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
// C structure to JSON for NetworkAdapter.V1_0_1.NetworkAdapter
//
RedfishCS_status CS_To_NetworkAdapter_V1_0_1_JSON(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *CSPtr, RedfishCS_char **JsonText)
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

  // Controllers
  if (CS_To_JSON_Controllers(CsJson, "Controllers", CSPtr->Controllers) != RedfishCS_status_success) {goto Error;}

  // Description 
  if (InsertJsonStringObj (CsJson, "Description", CSPtr->Description) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // Manufacturer 
  if (InsertJsonStringObj (CsJson, "Manufacturer", CSPtr->Manufacturer) != RedfishCS_status_success) {goto Error;}

  // Model 
  if (InsertJsonStringObj (CsJson, "Model", CSPtr->Model) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // NetworkDeviceFunctions 
  if (InsertJsonLinkObj (CsJson, "NetworkDeviceFunctions", &CSPtr->NetworkDeviceFunctions) != RedfishCS_status_success) {goto Error;}

  // NetworkPorts 
  if (InsertJsonLinkObj (CsJson, "NetworkPorts", &CSPtr->NetworkPorts) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // PartNumber 
  if (InsertJsonStringObj (CsJson, "PartNumber", CSPtr->PartNumber) != RedfishCS_status_success) {goto Error;}

  // SKU 
  if (InsertJsonStringObj (CsJson, "SKU", CSPtr->SKU) != RedfishCS_status_success) {goto Error;}

  // SerialNumber 
  if (InsertJsonStringObj (CsJson, "SerialNumber", CSPtr->SerialNumber) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for NetworkAdapter.V1_0_1.NetworkAdapter
//
RedfishCS_status DestroyNetworkAdapter_V1_0_1_CS(RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for NetworkAdapter.V1_0_1.NetworkAdapter
//
RedfishCS_status DestroyNetworkAdapter_V1_0_1_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for NetworkAdapter.V1_0_1.NetworkAdapter
//
RedfishCS_status
Json_NetworkAdapter_V1_0_1_To_CS(RedfishCS_char *JsonRawText, RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "NetworkAdapter", "v1_0_1", "NetworkAdapter", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishNetworkAdapter_V1_0_1_NetworkAdapter_CS));
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

  // Controllers
  Status = GenControllers_ArrayCs (Cs, JsonObj, "Controllers", &Cs->Controllers);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Description
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Description", &Cs->Description);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Id", &Cs->Id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

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

  // NetworkDeviceFunctions
  InitializeLinkHead (&Cs->NetworkDeviceFunctions);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "NetworkDeviceFunctions", Cs->Header.ThisUri, &Cs->NetworkDeviceFunctions);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // NetworkPorts
  InitializeLinkHead (&Cs->NetworkPorts);
  Status = CreateCsUriOrJsonByNode (Cs, JsonObj, "NetworkPorts", Cs->Header.ThisUri, &Cs->NetworkPorts);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, JsonObj, "Oem", &Cs->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PartNumber
  Status = GetRedfishPropertyStr (Cs, JsonObj, "PartNumber", &Cs->PartNumber);
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

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyNetworkAdapter_V1_0_1_CS (Cs);
  return Status;
}
