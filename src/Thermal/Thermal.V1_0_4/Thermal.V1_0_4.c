//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#include"Redfish_Thermal_v1_0_4_CS.h"
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

static RedfishCS_status GenOemCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst);
static RedfishCS_status GenStatusCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst);
static RedfishCS_status GenidRef_ArrayCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, Redfishodata_V4_0_0_idRef_Array_CS **Dst);
//
//Generate C structure for Oem
//
static RedfishCS_status GenOemCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Oem_CS **Dst)
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
static RedfishCS_status GenidRef_Array_ElementCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  Redfishodata_V4_0_0_idRef_CS **Dst)
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
static RedfishCS_status GenidRef_ArrayCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, Redfishodata_V4_0_0_idRef_Array_CS **Dst)
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
//Generate C structure for Status
//
static RedfishCS_status GenStatusCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, RedfishResource_Status_CS **Dst)
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
static RedfishCS_status GenFan_Array_ElementCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  RedfishThermal_V1_0_4_Fan_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(RedfishThermal_V1_0_4_Fan_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // FanName
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "FanName", &(*Dst)->FanName);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LowerThresholdCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "LowerThresholdCritical", &(*Dst)->LowerThresholdCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LowerThresholdFatal
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "LowerThresholdFatal", &(*Dst)->LowerThresholdFatal);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LowerThresholdNonCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "LowerThresholdNonCritical", &(*Dst)->LowerThresholdNonCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MaxReadingRange
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxReadingRange", &(*Dst)->MaxReadingRange);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MemberId
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "MemberId", &(*Dst)->MemberId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MinReadingRange
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MinReadingRange", &(*Dst)->MinReadingRange);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PhysicalContext
  InitializeLinkHead (&(*Dst)->PhysicalContext);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "PhysicalContext", Cs->Header.ThisUri, &(*Dst)->PhysicalContext);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Reading
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Reading", &(*Dst)->Reading);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ReadingUnits
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "ReadingUnits", &(*Dst)->ReadingUnits);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Redundancy
  InitializeLinkHead (&(*Dst)->Redundancy);
  Status = CreateCsUriOrJsonByNodeArray (Cs, TempJsonObj, "Redundancy", Cs->Header.ThisUri, &(*Dst)->Redundancy);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Redundancy@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "Redundancy@odata.count", &(*Dst)->Redundancyodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Redundancy@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Redundancy@odata.navigationLink", &(*Dst)->Redundancyodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // RelatedItem
  Status = GenidRef_ArrayCs (Cs, TempJsonObj, "RelatedItem", &(*Dst)->RelatedItem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // RelatedItem@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "RelatedItem@odata.count", &(*Dst)->RelatedItemodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // RelatedItem@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "RelatedItem@odata.navigationLink", &(*Dst)->RelatedItemodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, TempJsonObj, "Status", &(*Dst)->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UpperThresholdCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "UpperThresholdCritical", &(*Dst)->UpperThresholdCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UpperThresholdFatal
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "UpperThresholdFatal", &(*Dst)->UpperThresholdFatal);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UpperThresholdNonCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "UpperThresholdNonCritical", &(*Dst)->UpperThresholdNonCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for RedfishThermal_V1_0_4_Fan_Array_CS
//
static RedfishCS_status GenFan_ArrayCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, RedfishThermal_V1_0_4_Fan_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  RedfishThermal_V1_0_4_Fan_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishThermal_V1_0_4_Fan_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenFan_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
    if (Status != RedfishCS_status_success){
      goto Error;
    }
    ThisElement = ThisElement->Next;
  }
Error:;
  return Status;
}
static RedfishCS_status GenTemperature_Array_ElementCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, RedfishCS_uint64 Index,  RedfishThermal_V1_0_4_Temperature_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;

  Status = RedfishCS_status_success;
  TempJsonObj = json_array_get (JsonObj, (RedfishCS_int)Index);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsZeroMemory(Cs, sizeof(RedfishThermal_V1_0_4_Temperature_CS), (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  // LowerThresholdCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "LowerThresholdCritical", &(*Dst)->LowerThresholdCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LowerThresholdFatal
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "LowerThresholdFatal", &(*Dst)->LowerThresholdFatal);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // LowerThresholdNonCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "LowerThresholdNonCritical", &(*Dst)->LowerThresholdNonCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MaxReadingRangeTemp
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MaxReadingRangeTemp", &(*Dst)->MaxReadingRangeTemp);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MemberId
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "MemberId", &(*Dst)->MemberId);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // MinReadingRangeTemp
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "MinReadingRangeTemp", &(*Dst)->MinReadingRangeTemp);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Name
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "Name", &(*Dst)->Name);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Oem
  Status = GenOemCs (Cs, TempJsonObj, "Oem", &(*Dst)->Oem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // PhysicalContext
  InitializeLinkHead (&(*Dst)->PhysicalContext);
  Status = CreateCsUriOrJsonByNode (Cs, TempJsonObj, "PhysicalContext", Cs->Header.ThisUri, &(*Dst)->PhysicalContext);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // ReadingCelsius
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "ReadingCelsius", &(*Dst)->ReadingCelsius);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // RelatedItem
  Status = GenidRef_ArrayCs (Cs, TempJsonObj, "RelatedItem", &(*Dst)->RelatedItem);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // RelatedItem@odata.count
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "RelatedItem@odata.count", &(*Dst)->RelatedItemodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // RelatedItem@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, TempJsonObj, "RelatedItem@odata.navigationLink", &(*Dst)->RelatedItemodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // SensorNumber
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "SensorNumber", &(*Dst)->SensorNumber);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Status
  Status = GenStatusCs (Cs, TempJsonObj, "Status", &(*Dst)->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UpperThresholdCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "UpperThresholdCritical", &(*Dst)->UpperThresholdCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UpperThresholdFatal
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "UpperThresholdFatal", &(*Dst)->UpperThresholdFatal);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // UpperThresholdNonCritical
  Status = GetRedfishPropertyInt64 (Cs, TempJsonObj, "UpperThresholdNonCritical", &(*Dst)->UpperThresholdNonCritical);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  return RedfishCS_status_success;
Error:;
  return Status;
}
//
//Generate C structure for RedfishThermal_V1_0_4_Temperature_Array_CS
//
static RedfishCS_status GenTemperature_ArrayCs(RedfishThermal_V1_0_4_Thermal_CS *Cs, json_t *JsonObj, char *Key, RedfishThermal_V1_0_4_Temperature_Array_CS **Dst)
{
  RedfishCS_status Status;
  json_t *TempJsonObj;
  RedfishCS_uint64 ArraySize;
  RedfishCS_uint64 Index;
  RedfishThermal_V1_0_4_Temperature_Array_CS *ThisElement;

  Status = RedfishCS_status_success;
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }

  if (json_is_array(TempJsonObj) != RedfishCS_boolean_true) {
    return RedfishCS_status_invalid_parameter;
  }

  ArraySize = json_array_size (TempJsonObj);
  Status = allocateArrayRecordCsMemory(Cs, sizeof (RedfishThermal_V1_0_4_Temperature_Array_CS), ArraySize, (RedfishCS_void **)Dst);
  if (Status != RedfishCS_status_success){
    goto Error;
  }
  if (*Dst == NULL) {
    // Empty array
    return RedfishCS_status_success;
  }
  ThisElement = *Dst;
  for (Index = 0; Index < ArraySize; Index ++) {
    Status = GenTemperature_Array_ElementCs(Cs, TempJsonObj, Index, &ThisElement->ArrayValue);
    if (Status != RedfishCS_status_success){
      goto Error;
    }
    ThisElement = ThisElement->Next;
  }
Error:;
  return Status;
}
static RedfishCS_status CS_To_JSON_FansOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_FansRelatedItem(json_t *CsJson, char *Key, Redfishodata_V4_0_0_idRef_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  Redfishodata_V4_0_0_idRef_Array_CS *NextArray;
  Redfishodata_V4_0_0_idRef_CS *NextArrayItem;

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
    // @odata.id 
    if (InsertJsonStringObj (ArrayMember, "@odata.id", NextArrayItem->odata_id) != RedfishCS_status_success) {goto Error;}

    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {goto Error;}
    NextArray = NextArray->Next;
  } while (NextArray != NULL);
  json_object_set_new (CsJson, Key, ArrayJson);

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_FansStatusOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_FansStatus(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Health 
  if (InsertJsonStringObj (CsJson, "Health", CSPtr->Health) != RedfishCS_status_success) {goto Error;}

  // HealthRollup 
  if (InsertJsonStringObj (CsJson, "HealthRollup", CSPtr->HealthRollup) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_FansStatusOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // State 
  if (InsertJsonStringObj (CsJson, "State", CSPtr->State) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Fans(json_t *CsJson, char *Key, RedfishThermal_V1_0_4_Fan_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishThermal_V1_0_4_Fan_Array_CS *NextArray;
  RedfishThermal_V1_0_4_Fan_CS *NextArrayItem;

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
    // FanName 
    if (InsertJsonStringObj (ArrayMember, "FanName", NextArrayItem->FanName) != RedfishCS_status_success) {goto Error;}

    // LowerThresholdCritical 
    if (InsertJsonInt64Obj (ArrayMember, "LowerThresholdCritical", NextArrayItem->LowerThresholdCritical) != RedfishCS_status_success) {goto Error;}

    // LowerThresholdFatal 
    if (InsertJsonInt64Obj (ArrayMember, "LowerThresholdFatal", NextArrayItem->LowerThresholdFatal) != RedfishCS_status_success) {goto Error;}

    // LowerThresholdNonCritical 
    if (InsertJsonInt64Obj (ArrayMember, "LowerThresholdNonCritical", NextArrayItem->LowerThresholdNonCritical) != RedfishCS_status_success) {goto Error;}

    // MaxReadingRange 
    if (InsertJsonInt64Obj (ArrayMember, "MaxReadingRange", NextArrayItem->MaxReadingRange) != RedfishCS_status_success) {goto Error;}

    // MemberId 
    if (InsertJsonStringObj (ArrayMember, "MemberId", NextArrayItem->MemberId) != RedfishCS_status_success) {goto Error;}

    // MinReadingRange 
    if (InsertJsonInt64Obj (ArrayMember, "MinReadingRange", NextArrayItem->MinReadingRange) != RedfishCS_status_success) {goto Error;}

    // Oem
    if (CS_To_JSON_FansOem(ArrayMember, "Oem", NextArrayItem->Oem) != RedfishCS_status_success) {goto Error;}

    // PhysicalContext 
    if (InsertJsonLinkObj (ArrayMember, "PhysicalContext", &NextArrayItem->PhysicalContext) != RedfishCS_status_success) {goto Error;}

    // Reading 
    if (InsertJsonInt64Obj (ArrayMember, "Reading", NextArrayItem->Reading) != RedfishCS_status_success) {goto Error;}

    // ReadingUnits 
    if (InsertJsonStringObj (ArrayMember, "ReadingUnits", NextArrayItem->ReadingUnits) != RedfishCS_status_success) {goto Error;}

    // Redundancy 
    if (InsertJsonLinkArrayObj (ArrayMember, "Redundancy", &NextArrayItem->Redundancy) != RedfishCS_status_success) {goto Error;}

    // Redundancy@odata.count 
    if (InsertJsonInt64Obj (ArrayMember, "Redundancy@odata.count", NextArrayItem->Redundancyodata_count) != RedfishCS_status_success) {goto Error;}

    // Redundancy@odata.navigationLink 
    if (InsertJsonStringObj (ArrayMember, "Redundancy@odata.navigationLink", NextArrayItem->Redundancyodata_navigationLink) != RedfishCS_status_success) {goto Error;}

    // RelatedItem
    if (CS_To_JSON_FansRelatedItem(ArrayMember, "RelatedItem", NextArrayItem->RelatedItem) != RedfishCS_status_success) {goto Error;}

    // RelatedItem@odata.count 
    if (InsertJsonInt64Obj (ArrayMember, "RelatedItem@odata.count", NextArrayItem->RelatedItemodata_count) != RedfishCS_status_success) {goto Error;}

    // RelatedItem@odata.navigationLink 
    if (InsertJsonStringObj (ArrayMember, "RelatedItem@odata.navigationLink", NextArrayItem->RelatedItemodata_navigationLink) != RedfishCS_status_success) {goto Error;}

    // Status
    if (CS_To_JSON_FansStatus(ArrayMember, "Status", NextArrayItem->Status) != RedfishCS_status_success) {goto Error;}

    // UpperThresholdCritical 
    if (InsertJsonInt64Obj (ArrayMember, "UpperThresholdCritical", NextArrayItem->UpperThresholdCritical) != RedfishCS_status_success) {goto Error;}

    // UpperThresholdFatal 
    if (InsertJsonInt64Obj (ArrayMember, "UpperThresholdFatal", NextArrayItem->UpperThresholdFatal) != RedfishCS_status_success) {goto Error;}

    // UpperThresholdNonCritical 
    if (InsertJsonInt64Obj (ArrayMember, "UpperThresholdNonCritical", NextArrayItem->UpperThresholdNonCritical) != RedfishCS_status_success) {goto Error;}

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
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
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
static RedfishCS_status CS_To_JSON_TemperaturesOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_TemperaturesRelatedItem(json_t *CsJson, char *Key, Redfishodata_V4_0_0_idRef_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  Redfishodata_V4_0_0_idRef_Array_CS *NextArray;
  Redfishodata_V4_0_0_idRef_CS *NextArrayItem;

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
    // @odata.id 
    if (InsertJsonStringObj (ArrayMember, "@odata.id", NextArrayItem->odata_id) != RedfishCS_status_success) {goto Error;}

    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {goto Error;}
    NextArray = NextArray->Next;
  } while (NextArray != NULL);
  json_object_set_new (CsJson, Key, ArrayJson);

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_TemperaturesStatusOem(json_t *CsJson, char *Key, RedfishResource_Oem_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Check if this is RedfishCS_Type_CS_EmptyProp.
  CsEmptyPropLinkToJson(CsJson, Key, &CSPtr->Prop);
  // No JSON property for this structure.
  return RedfishCS_status_success;
}
static RedfishCS_status CS_To_JSON_TemperaturesStatus(json_t *CsJson, char *Key, RedfishResource_Status_CS *CSPtr)
{
  if (CSPtr == NULL) {
    return RedfishCS_status_success;
  }
  // Health 
  if (InsertJsonStringObj (CsJson, "Health", CSPtr->Health) != RedfishCS_status_success) {goto Error;}

  // HealthRollup 
  if (InsertJsonStringObj (CsJson, "HealthRollup", CSPtr->HealthRollup) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_TemperaturesStatusOem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // State 
  if (InsertJsonStringObj (CsJson, "State", CSPtr->State) != RedfishCS_status_success) {goto Error;}

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}
static RedfishCS_status CS_To_JSON_Temperatures(json_t *CsJson, char *Key, RedfishThermal_V1_0_4_Temperature_Array_CS *CSPtr)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishThermal_V1_0_4_Temperature_Array_CS *NextArray;
  RedfishThermal_V1_0_4_Temperature_CS *NextArrayItem;

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
    // LowerThresholdCritical 
    if (InsertJsonInt64Obj (ArrayMember, "LowerThresholdCritical", NextArrayItem->LowerThresholdCritical) != RedfishCS_status_success) {goto Error;}

    // LowerThresholdFatal 
    if (InsertJsonInt64Obj (ArrayMember, "LowerThresholdFatal", NextArrayItem->LowerThresholdFatal) != RedfishCS_status_success) {goto Error;}

    // LowerThresholdNonCritical 
    if (InsertJsonInt64Obj (ArrayMember, "LowerThresholdNonCritical", NextArrayItem->LowerThresholdNonCritical) != RedfishCS_status_success) {goto Error;}

    // MaxReadingRangeTemp 
    if (InsertJsonInt64Obj (ArrayMember, "MaxReadingRangeTemp", NextArrayItem->MaxReadingRangeTemp) != RedfishCS_status_success) {goto Error;}

    // MemberId 
    if (InsertJsonStringObj (ArrayMember, "MemberId", NextArrayItem->MemberId) != RedfishCS_status_success) {goto Error;}

    // MinReadingRangeTemp 
    if (InsertJsonInt64Obj (ArrayMember, "MinReadingRangeTemp", NextArrayItem->MinReadingRangeTemp) != RedfishCS_status_success) {goto Error;}

    // Name 
    if (InsertJsonStringObj (ArrayMember, "Name", NextArrayItem->Name) != RedfishCS_status_success) {goto Error;}

    // Oem
    if (CS_To_JSON_TemperaturesOem(ArrayMember, "Oem", NextArrayItem->Oem) != RedfishCS_status_success) {goto Error;}

    // PhysicalContext 
    if (InsertJsonLinkObj (ArrayMember, "PhysicalContext", &NextArrayItem->PhysicalContext) != RedfishCS_status_success) {goto Error;}

    // ReadingCelsius 
    if (InsertJsonInt64Obj (ArrayMember, "ReadingCelsius", NextArrayItem->ReadingCelsius) != RedfishCS_status_success) {goto Error;}

    // RelatedItem
    if (CS_To_JSON_TemperaturesRelatedItem(ArrayMember, "RelatedItem", NextArrayItem->RelatedItem) != RedfishCS_status_success) {goto Error;}

    // RelatedItem@odata.count 
    if (InsertJsonInt64Obj (ArrayMember, "RelatedItem@odata.count", NextArrayItem->RelatedItemodata_count) != RedfishCS_status_success) {goto Error;}

    // RelatedItem@odata.navigationLink 
    if (InsertJsonStringObj (ArrayMember, "RelatedItem@odata.navigationLink", NextArrayItem->RelatedItemodata_navigationLink) != RedfishCS_status_success) {goto Error;}

    // SensorNumber 
    if (InsertJsonInt64Obj (ArrayMember, "SensorNumber", NextArrayItem->SensorNumber) != RedfishCS_status_success) {goto Error;}

    // Status
    if (CS_To_JSON_TemperaturesStatus(ArrayMember, "Status", NextArrayItem->Status) != RedfishCS_status_success) {goto Error;}

    // UpperThresholdCritical 
    if (InsertJsonInt64Obj (ArrayMember, "UpperThresholdCritical", NextArrayItem->UpperThresholdCritical) != RedfishCS_status_success) {goto Error;}

    // UpperThresholdFatal 
    if (InsertJsonInt64Obj (ArrayMember, "UpperThresholdFatal", NextArrayItem->UpperThresholdFatal) != RedfishCS_status_success) {goto Error;}

    // UpperThresholdNonCritical 
    if (InsertJsonInt64Obj (ArrayMember, "UpperThresholdNonCritical", NextArrayItem->UpperThresholdNonCritical) != RedfishCS_status_success) {goto Error;}

    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {goto Error;}
    NextArray = NextArray->Next;
  } while (NextArray != NULL);
  json_object_set_new (CsJson, Key, ArrayJson);

  return RedfishCS_status_success;
Error:;
  return RedfishCS_status_unsupported;
}

//
// C structure to JSON for Thermal.V1_0_4.Thermal
//
RedfishCS_status CS_To_Thermal_V1_0_4_JSON(RedfishThermal_V1_0_4_Thermal_CS *CSPtr, RedfishCS_char **JsonText)
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

  // Fans
  if (CS_To_JSON_Fans(CsJson, "Fans", CSPtr->Fans) != RedfishCS_status_success) {goto Error;}

  // Fans@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Fans@odata.count", CSPtr->Fansodata_count) != RedfishCS_status_success) {goto Error;}

  // Fans@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Fans@odata.navigationLink", CSPtr->Fansodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Id 
  if (InsertJsonStringObj (CsJson, "Id", CSPtr->Id) != RedfishCS_status_success) {goto Error;}

  // Name 
  if (InsertJsonStringObj (CsJson, "Name", CSPtr->Name) != RedfishCS_status_success) {goto Error;}

  // Oem
  if (CS_To_JSON_Oem(CsJson, "Oem", CSPtr->Oem) != RedfishCS_status_success) {goto Error;}

  // Redundancy 
  if (InsertJsonLinkArrayObj (CsJson, "Redundancy", &CSPtr->Redundancy) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Redundancy@odata.count", CSPtr->Redundancyodata_count) != RedfishCS_status_success) {goto Error;}

  // Redundancy@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Redundancy@odata.navigationLink", CSPtr->Redundancyodata_navigationLink) != RedfishCS_status_success) {goto Error;}

  // Status
  if (CS_To_JSON_Status(CsJson, "Status", CSPtr->Status) != RedfishCS_status_success) {goto Error;}

  // Temperatures
  if (CS_To_JSON_Temperatures(CsJson, "Temperatures", CSPtr->Temperatures) != RedfishCS_status_success) {goto Error;}

  // Temperatures@odata.count 
  if (InsertJsonInt64Obj (CsJson, "Temperatures@odata.count", CSPtr->Temperaturesodata_count) != RedfishCS_status_success) {goto Error;}

  // Temperatures@odata.navigationLink 
  if (InsertJsonStringObj (CsJson, "Temperatures@odata.navigationLink", CSPtr->Temperaturesodata_navigationLink) != RedfishCS_status_success) {goto Error;}

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
// Destory C Structure for Thermal.V1_0_4.Thermal
//
RedfishCS_status DestroyThermal_V1_0_4_CS(RedfishThermal_V1_0_4_Thermal_CS *CSPtr)
{
  RedfishCS_status Status;

  Status = DestoryCsMemory ((RedfishCS_void *)CSPtr);
  return Status;
}

//
// Destory JSON text for Thermal.V1_0_4.Thermal
//
RedfishCS_status DestroyThermal_V1_0_4_Json(RedfishCS_char *JsonText)
{
  free ((RedfishCS_void *)JsonText);
  return RedfishCS_status_success;
}

//
//Generate C structure for Thermal.V1_0_4.Thermal
//
RedfishCS_status
Json_Thermal_V1_0_4_To_CS(RedfishCS_char *JsonRawText, RedfishThermal_V1_0_4_Thermal_CS **ReturnedCs)
{
  RedfishCS_status  Status;
  json_t *JsonObj;
  RedfishThermal_V1_0_4_Thermal_CS *Cs;

  Status = CreateJsonPayloadAndCs (JsonRawText, "Thermal", "v1_0_4", "Thermal", &JsonObj, (RedfishCS_void **)&Cs, sizeof (RedfishThermal_V1_0_4_Thermal_CS));
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

  // Fans
  Status = GenFan_ArrayCs (Cs, JsonObj, "Fans", &Cs->Fans);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Fans@odata.count
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "Fans@odata.count", &Cs->Fansodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Fans@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Fans@odata.navigationLink", &Cs->Fansodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Id
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Id", &Cs->Id);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

  // Name
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Name", &Cs->Name);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){goto Error;}}

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

  // Status
  Status = GenStatusCs (Cs, JsonObj, "Status", &Cs->Status);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Temperatures
  Status = GenTemperature_ArrayCs (Cs, JsonObj, "Temperatures", &Cs->Temperatures);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Temperatures@odata.count
  Status = GetRedfishPropertyInt64 (Cs, JsonObj, "Temperatures@odata.count", &Cs->Temperaturesodata_count);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  // Temperatures@odata.navigationLink
  Status = GetRedfishPropertyStr (Cs, JsonObj, "Temperatures@odata.navigationLink", &Cs->Temperaturesodata_navigationLink);
  if (Status != RedfishCS_status_success && Status != RedfishCS_status_not_found) {goto Error;}
  else {if (Status == RedfishCS_status_not_found){/*This is not the required property.*/}}

  json_decref(JsonObj);
  *ReturnedCs = Cs;
  return RedfishCS_status_success;
Error:;
  json_decref(JsonObj);
  DestroyThermal_V1_0_4_CS (Cs);
  return Status;
}
