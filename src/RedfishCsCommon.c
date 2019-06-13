/** @file
   
  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#include "RedfishCsCommon.h"
#include "RedfishCsMemoryInternal.h"
#include <jansson.h>
#include <stdlib.h>
#include <string.h>

RedfishCS_status GetRedfishPropertyVague(void *Cs, json_t *JsonObj, char *Key, RedfishCS_Vague **DstBuffer);

RedfishCS_Link *InitializeLinkHead (RedfishCS_Link *ListHead)
{
  ListHead->ForwardLink = ListHead;
  ListHead->BackLink = ListHead;
  return ListHead;
}

RedfishCS_Link *InsertHeadLink (RedfishCS_Link *ListHead, RedfishCS_Link *Entry)
{
  Entry->ForwardLink = ListHead->ForwardLink;
  Entry->BackLink = ListHead;
  Entry->ForwardLink->BackLink = Entry;
  ListHead->ForwardLink = Entry;
  return ListHead;
}

RedfishCS_Link * InsertTailLink (RedfishCS_Link *ListHead, RedfishCS_Link *Entry)
{
  Entry->ForwardLink = ListHead;
  Entry->BackLink = ListHead->BackLink;
  Entry->BackLink->ForwardLink = Entry;
  ListHead->BackLink = Entry;
  return ListHead;
}

RedfishCS_Link *GetFirstLink (const RedfishCS_Link *List)
{
  return List->ForwardLink;
}

RedfishCS_Link *GetLastLink (const RedfishCS_Link *List)
{
  return List->BackLink;
}

RedfishCS_Link *GetNextLink (const RedfishCS_Link *List, const RedfishCS_Link *Node)
{
  return Node->ForwardLink;
}

RedfishCS_Link *GetPreviousLink (const RedfishCS_Link *List, const RedfishCS_Link *Node)
{
  return Node->BackLink;
}
RedfishCS_Link *RemoveLink ( const RedfishCS_Link *Link)
{ 
  Link->ForwardLink->BackLink = Link->BackLink;
  Link->BackLink->ForwardLink = Link->ForwardLink;
  return Link->ForwardLink;
}

RedfishCS_bool IsLinkEmpty (const RedfishCS_Link *LinkHead)
{
 return (RedfishCS_bool)(LinkHead->ForwardLink == LinkHead);
}

RedfishCS_bool IsLinkAtEnd (const RedfishCS_Link *LinkHead, const RedfishCS_Link *ThisLink)
{
  return (RedfishCS_bool)(ThisLink->ForwardLink == LinkHead);
}

RedfishCS_status allocateDuplicateStr (void *Cs, char *Str, void **DstBuffer)
{
  RedfishCS_status Status;

  if (Str == NULL || strlen(Str) == 0) {
    *DstBuffer = NULL;
    return RedfishCS_status_success;
  }
  Status = allocateRecordCsMemory(Cs, (RedfishCS_int)strlen(Str) + 1, (void **)DstBuffer);
  if (Status != RedfishCS_status_success) {
    return Status;
  }
  memcpy (*DstBuffer, Str, strlen(Str) + 1);
  return RedfishCS_status_success;
}

RedfishCS_status CreateCsUriByOdataId (json_t *JsonOj, RedfishCS_char *ParentUri, RedfishCS_Type_Uri_Data **CsTypeUriData)
{
  json_t *TempJsonObj;
  RedfishCS_Type_Uri_Data *CsTypeUri;

  CsTypeUri = NULL;
  TempJsonObj = json_object_get(JsonOj, "@odata.id");
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  CsTypeUri = malloc (sizeof (RedfishCS_Type_Uri_Data));
  if (CsTypeUri == NULL) {
    return RedfishCS_status_insufficient_memory;
  }
  InitializeLinkHead (&CsTypeUri->Header.LinkEntry);
  CsTypeUri->Header.ResourceType = RedfishCS_Type_Uri;
  CsTypeUri->Header.ThisUri = ParentUri;
  CsTypeUri->Header.KeyName = (RedfishCS_char *)strdup ("@odata.id");
  CsTypeUri->Uri = (RedfishCS_char *)strdup (json_string_value (TempJsonObj));
  *CsTypeUriData = CsTypeUri;
  return RedfishCS_status_success;
}

RedfishCS_status CreateCsUriByNode (void *Cs, json_t *JsonOj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Type_Uri_Data **CsTypeUriData)
{
  json_t *TempJsonObj;
  json_t *TempJsonObj2;
  RedfishCS_Type_Uri_Data *CsTypeUri;
  RedfishCS_status Status;

  CsTypeUri = NULL;

  if (NodeName != NULL) {
    TempJsonObj = json_object_get(JsonOj, NodeName);
    if (TempJsonObj == NULL) {
      return RedfishCS_status_not_found;
    }
  } else {
    if (JsonOj == NULL) {
      return RedfishCS_status_not_found;
    }
    TempJsonObj = JsonOj;
  }

  TempJsonObj2 = json_object_get(TempJsonObj, "@odata.id");
  if (TempJsonObj2 != NULL) {
    Status = allocateRecordCsMemory (Cs, sizeof (RedfishCS_Type_Uri_Data), (void **)&CsTypeUri);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    InitializeLinkHead (&CsTypeUri->Header.LinkEntry);
    CsTypeUri->Header.ResourceType = RedfishCS_Type_Uri;
    CsTypeUri->Header.ThisUri = ParentUri;
    Status = allocateDuplicateStr (Cs, NodeName, (void **)&CsTypeUri->Header.KeyName);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    *CsTypeUriData = CsTypeUri;
    Status = allocateDuplicateStr (Cs, (char *)json_string_value (TempJsonObj2), (void **)&CsTypeUri->Uri);
    return Status;
  }
  return RedfishCS_status_invalid_parameter;
}

RedfishCS_status CreateCsJsonByNode (void *Cs, json_t *JsonObj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Type_JSON_Data **CsTypeJsonData)
{
  json_t *TempJsonObj;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  RedfishCS_char *TempChar;
  RedfishCS_char *DumpStr;
  RedfishCS_status Status;

  CsTypeJson = NULL;
  if (NodeName != NULL) {
    TempJsonObj = json_object_get(JsonObj, NodeName);
    if (TempJsonObj == NULL) {
      return RedfishCS_status_not_found;
    }
  } else {
    // Dump JSON from JsonObj.
    TempJsonObj = JsonObj;
  }
  TempChar = json_dumps ((const json_t *)TempJsonObj, JSON_INDENT (2));
  if (TempChar != NULL) {
    Status = allocateRecordCsMemory (Cs, sizeof (RedfishCS_Type_JSON_Data), (void **)&CsTypeJson);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    Status = allocateRecordCsMemory (Cs, (RedfishCS_int)strlen (TempChar) + 1, (void **)&DumpStr);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    strncpy (DumpStr, TempChar, strlen (TempChar) + 1);
    InitializeLinkHead(&CsTypeJson->Header.LinkEntry);
    CsTypeJson->Header.ResourceType = RedfishCS_Type_JSON;
    CsTypeJson->Header.ThisUri = ParentUri;
    Status = allocateDuplicateStr (Cs, NodeName, (void **)&CsTypeJson->Header.KeyName);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    CsTypeJson->JsonText = DumpStr;
    *CsTypeJsonData = CsTypeJson;
    return RedfishCS_status_success;     
  }
  return RedfishCS_status_invalid_parameter;
}

RedfishCS_status CreateEmptyPropCsJson(RedfishCS_void *Cs, json_t *JsonObj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Type_EmptyProp_CS_Data **CsTypeEmptyPropCSData, RedfishCS_uint32 NunmOfProperties) {
  json_t *TempJsonObj;
  RedfishCS_status Status;
  RedfishCS_Type_EmptyProp_CS_Data *CsTypeEmptyPropCS;
  RedfishCS_char *KeyName;
  json_t *KeyValueObj;
  RedfishCS_void *n;
  RedfishCS_EmptyProp_KeyValue **KeyValuePtr;
  RedfishCS_EmptyProp_KeyValue *KeyValue;

  CsTypeEmptyPropCS = NULL;
  if (NodeName != NULL) {
    TempJsonObj = json_object_get(JsonObj, NodeName);
    if (TempJsonObj == NULL) {
      return RedfishCS_status_not_found;
    }
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishCS_Type_EmptyProp_CS_Data), (void **)&CsTypeEmptyPropCS);
  if (Status != RedfishCS_status_success) {
    return Status;
  }
  InitializeLinkHead(&CsTypeEmptyPropCS->Header.LinkEntry);
  CsTypeEmptyPropCS->Header.ResourceType = RedfishCS_Type_CS_EmptyProp;
  CsTypeEmptyPropCS->Header.ThisUri = ParentUri;
  Status = allocateDuplicateStr(Cs, NodeName, (void **)&CsTypeEmptyPropCS->Header.KeyName);
  if (Status != RedfishCS_status_success) {
    return Status;
  }
  CsTypeEmptyPropCS->NunmOfProperties = NunmOfProperties;
  //
  // Create instance for each key-value.
  //
  KeyValuePtr = &CsTypeEmptyPropCS->KeyValuePtr;
  json_object_foreach_safe(TempJsonObj, n, KeyName, KeyValueObj) {
    Status = allocateRecordCsMemory(Cs, sizeof(RedfishCS_EmptyProp_KeyValue), (void **)&KeyValue);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    Status = allocateDuplicateStr(Cs, KeyName, (void **)&KeyValue->KeyNamePtr);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    Status = GetRedfishPropertyVague(Cs, TempJsonObj, KeyName, &KeyValue->Value);
    if (Status != RedfishCS_status_success) {
      return Status;
    }

    *KeyValuePtr = KeyValue;
    KeyValuePtr = &KeyValue->NextKeyValuePtr;
  }

  *CsTypeEmptyPropCSData = CsTypeEmptyPropCS;
  return RedfishCS_status_success;
}

RedfishCS_bool CheckSupportedPropTypeInEmptyProperty(json_t *JsonObj) {
  //
  // Only support below property types for the property is declared as 
  // empty property in schema.
  //  e.g. "properties": {}
  //
  if (json_is_string(JsonObj) ||
    json_is_integer(JsonObj) ||
    //json_is_real(JsonObj) ||
    json_is_number(JsonObj) ||
    json_is_boolean(JsonObj)) {
    return RedfishCS_boolean_true;
  }
  return RedfishCS_boolean_false;
}

RedfishCS_bool CheckEmptyPropJsonObject(json_t *JsonObj, RedfishCS_uint32 *NumOfProperty)
{
  RedfishCS_char *NewKey;
  json_t *Value;
  RedfishCS_void *n;
  RedfishCS_uint32 Num;

  Num = 0;
  json_object_foreach_safe(JsonObj, n, NewKey, Value) {
    if (!CheckSupportedPropTypeInEmptyProperty(Value)) {
      return RedfishCS_boolean_false;
    }
    Num ++;
  }
  if (NumOfProperty != NULL) {
    *NumOfProperty = Num;
  }
  return RedfishCS_boolean_true;
}

RedfishCS_bool SupportedRedfishResource (RedfishCS_char *Odata_Type, RedfishCS_char *NameSpace, RedfishCS_char *Version, RedfishCS_char *DataType)
{
  RedfishCS_char *TargetDataType;

  if (Odata_Type == NULL || NameSpace == NULL || DataType == NULL) {
    return RedfishCS_boolean_false;
  }
  if (Version != NULL) {
    TargetDataType = malloc(strlen(NameSpace) + strlen(Version) + strlen(DataType) + 16); // Plus 16 bytes to make more room.
                                                                                          // Actually we just need 1 byte for "#"
                                                                                          // Two bytes for "." and one byte for NULL terminator.
  } else {
    TargetDataType = malloc(strlen(NameSpace) + strlen(DataType) + 16); // Plus 16 bytes to make more room.
                                                                        // Actually we just need 1 byte for "#"
                                                                        // Two bytes for "." and one byte for NULL terminator.
  }
  if (TargetDataType == NULL) {
    return RedfishCS_boolean_false;
  }
  TargetDataType [0] = 0; // Insert NULL terminator.
  strcat (TargetDataType, "#");
  strcat (TargetDataType, NameSpace);
  strcat (TargetDataType, ".");
  if (Version != NULL && (strcmp (Version, "noversioned") != 0)) {
    strcat(TargetDataType, Version);
    strcat (TargetDataType, ".");
  }
  strcat (TargetDataType, DataType);
  if (strcmp (Odata_Type, TargetDataType) == 0) {
    return RedfishCS_boolean_true;
  }
  free (TargetDataType);
  return RedfishCS_boolean_false;
}

RedfishCS_status
CreateCsUriOrJsonByNode (void *Cs, json_t *JsonObj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Link *LinkHead)
{
  json_t *JsonObjTemp;
  RedfishCS_Type_Uri_Data *CsTypeUri;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  RedfishCS_status Status;

  Status = RedfishCS_status_invalid_parameter;
  JsonObjTemp = json_object_get (JsonObj, NodeName);
  if (JsonObjTemp == NULL) {
    return RedfishCS_status_not_found;
  }
  if (json_object_size(JsonObjTemp) == 1) {
    Status = CreateCsUriByNode (Cs, JsonObj, NodeName, ParentUri, &CsTypeUri);
    if (Status == RedfishCS_status_success) {
      InsertTailLink (LinkHead, &CsTypeUri->Header.LinkEntry);
      return RedfishCS_status_success;
    }
  } else {
    Status = CreateCsJsonByNode (Cs, JsonObj, NodeName, ParentUri, &CsTypeJson);
    if (Status == RedfishCS_status_success) {
      InsertTailLink (LinkHead, &CsTypeJson->Header.LinkEntry);
      return RedfishCS_status_success;
    }
  }
  return Status;
}

RedfishCS_status
CreateCsUriOrJsonByNodeArray (void *Cs, json_t *JsonObj, RedfishCS_char *NodeName, RedfishCS_char *ParentUri, RedfishCS_Link *LinkHead)
{
  json_t *JsonObjTemp;
  json_t *JsonObjArray;
  RedfishCS_Type_Uri_Data *CsTypeUri;
  RedfishCS_Type_JSON_Data *CsTypeJson;
  RedfishCS_status Status;
  RedfishCS_uint16 ArrayIndex;

  Status = RedfishCS_status_invalid_parameter;
  JsonObjTemp = json_object_get (JsonObj, NodeName);
  if (JsonObjTemp == NULL) {
    return RedfishCS_status_not_found;
  }
  if (json_array_size (JsonObjTemp) == 0) {
    return RedfishCS_status_not_found;
  }
  for (ArrayIndex = 0; ArrayIndex < (RedfishCS_uint16)json_array_size (JsonObjTemp); ArrayIndex ++) {
    JsonObjArray = json_array_get (JsonObjTemp, (size_t)ArrayIndex);
    if (JsonObjArray == NULL) {
      continue;
    }
    if (json_object_size(JsonObjArray) == 1) {
      Status = CreateCsUriByNode (Cs, JsonObjArray, NULL, ParentUri, &CsTypeUri);
      if (Status == RedfishCS_status_success) {
        InsertTailLink (LinkHead, &CsTypeUri->Header.LinkEntry);
      }
    } else {
      Status = CreateCsJsonByNode (Cs, JsonObjArray, NULL, ParentUri, &CsTypeJson);
      if (Status == RedfishCS_status_success) {
        InsertTailLink (LinkHead, &CsTypeJson->Header.LinkEntry);
      }
    }
  }
  return RedfishCS_status_success;
}

RedfishCS_status
CreateJsonPayloadAndCs (char *JsonRawText, char *ResourceType, char *ResourceVersion, char *TypeName, json_t **JsonObjReturned, void **Cs, int size)
{
  json_t *TempJsonObj;
  RedfishCS_char *TempChar;
  RedfishCS_Header *Header;
  void *TempCS;

  if (JsonRawText == NULL ||
      ResourceType == NULL ||
      TypeName == NULL ||
      Cs == NULL ||
      size == 0
      ) {
    return RedfishCS_status_invalid_parameter;
  }
  *JsonObjReturned = json_loads(JsonRawText, 0, NULL);
  if (*JsonObjReturned == NULL) {
    return RedfishCS_status_unknown_error;
  }
  TempJsonObj = json_object_get(*JsonObjReturned, "@odata.type");
  if (TempJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  TempChar = (RedfishCS_char *)json_string_value(TempJsonObj);
  if (TempChar == NULL || ! SupportedRedfishResource (TempChar, ResourceType, ResourceVersion, TypeName)) {
    return RedfishCS_status_unsupported;
  }
  TempCS = malloc (size);
  if (TempCS == NULL) {
    return RedfishCS_status_insufficient_memory;
  }
  memset (TempCS, 0, size);
  Header = (RedfishCS_Header *)TempCS;
  Header->ResourceType = RedfishCS_Type_CS;
  Header->KeyName = NULL;
  InitializeLinkHead (&Header->LinkEntry);
  *Cs = TempCS;
  return recordCsRootMemory (TempCS);
}

RedfishCS_status GetRedfishPropertyStr (void *Cs, json_t *JsonObj, char *Key, RedfishCS_char **DstBuffer)
{
  json_t *TempJsonObj;
  RedfishCS_status Status;

  if (DstBuffer == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  *DstBuffer = NULL;

  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL){
    return RedfishCS_status_not_found;
  }
  Status = allocateDuplicateStr (Cs, (char *)json_string_value(TempJsonObj), (void **)DstBuffer);
  return Status;
}

RedfishCS_status GetRedfishPropertyBoolean (void *Cs, json_t *JsonObj, char *Key, RedfishCS_bool **DstBuffer)
{
  json_t *TempJsonObj;
  RedfishCS_status Status;

  if (DstBuffer == NULL) {
    return RedfishCS_status_not_found;
  }
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL){
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishCS_bool), (void **)DstBuffer);
  if (Status != RedfishCS_status_success){
    return Status;
  }
  if (TempJsonObj->type == JSON_TRUE) {
    **DstBuffer = RedfishCS_boolean_true;
  } else {
    **DstBuffer = RedfishCS_boolean_false;
  }
  return RedfishCS_status_success;
}

RedfishCS_status GetRedfishPropertyInt64 (void *Cs, json_t *JsonObj, char *Key, RedfishCS_int64 **Dst)
{
  RedfishCS_status Status;
  const json_t *TempJsonObj;

  if (Dst == NULL) {
    return RedfishCS_status_invalid_parameter;
  }

  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL) {
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishCS_int64), (void **)Dst);
  if (Status != RedfishCS_status_success){
    return Status;
  }
  **Dst = (RedfishCS_int64)json_integer_value(TempJsonObj);
  return RedfishCS_status_success;
}

RedfishCS_status GetRedfishPropertyVague (void *Cs, json_t *JsonObj, char *Key, RedfishCS_Vague **DstBuffer)
{
  json_t *TempJsonObj;
  RedfishCS_status Status;
  RedfishCS_Vague *VagueData;

  if (DstBuffer == NULL) {
    return RedfishCS_status_not_found;
  }
  TempJsonObj = json_object_get(JsonObj, Key);
  if (TempJsonObj == NULL){
    return RedfishCS_status_not_found;
  }
  Status = allocateRecordCsMemory(Cs, sizeof(RedfishCS_Vague), (void **)&VagueData);
  if (Status != RedfishCS_status_success){
    return Status;
  }

  if (json_is_string(TempJsonObj)) {
    VagueData->DataType = RedfishCS_Vague_DataType_String;
    Status = GetRedfishPropertyStr (Cs, JsonObj, Key, &VagueData->DataValue.CharPtr);
  } else if (json_is_integer(TempJsonObj)) {
    VagueData->DataType = RedfishCS_Vague_DataType_Int64;
    Status = GetRedfishPropertyInt64 (Cs, JsonObj, Key, &VagueData->DataValue.Int64Ptr);
  } else if (json_is_boolean(TempJsonObj)) {
    VagueData->DataType = RedfishCS_Vague_DataType_Bool;
    Status = GetRedfishPropertyBoolean (Cs, JsonObj, Key, &VagueData->DataValue.BoolPtr);
  } else if (json_is_null(TempJsonObj)) {
    *DstBuffer = NULL; // No value for this key
    free (VagueData);
    return RedfishCS_status_success;
  } else {
    return RedfishCS_status_unsupported;
  }
  if (Status == RedfishCS_status_success) {
    *DstBuffer = VagueData;
  }
  return Status;
}

RedfishCS_status InsertJsonStringObj (json_t *ParentJsonObj, char *Key, RedfishCS_char *StringValue)
{
  json_t  *JsonValue;
  RedfishCS_char NullStr[] = "";
  RedfishCS_char *InsertStr;

  InsertStr = StringValue;
  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (InsertStr == (char *)NULL) {
    InsertStr = NullStr;
  }
  JsonValue = json_string(InsertStr);
  if (JsonValue == NULL) {
    return RedfishCS_status_unsupported;
  }
  if (json_object_set_new (ParentJsonObj, Key, JsonValue) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonBoolObj (json_t *ParentJsonObj, char *Key, RedfishCS_bool *BoolValue)
{
  json_t  *JsonValue;

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (BoolValue == (RedfishCS_bool *)NULL) {
    return RedfishCS_status_success; // No value for this key.
  }
  JsonValue = json_boolean(*BoolValue);
  if (JsonValue == NULL) {
    return RedfishCS_status_unsupported;
  }
  if (json_object_set_new (ParentJsonObj, Key, JsonValue) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonInt64Obj (json_t *ParentJsonObj, char *Key, RedfishCS_int64 *Int64Value)
{
  json_t  *JsonValue;

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (Int64Value == (RedfishCS_int64 *)NULL) {
    return RedfishCS_status_success; // No value for this key.
  }
  JsonValue = json_integer((json_int_t)*Int64Value);
  if (JsonValue == NULL) {
    return RedfishCS_status_unsupported;
  }
  if (json_object_set_new (ParentJsonObj, Key, JsonValue) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonVagueObj (json_t *ParentJsonObj, char *Key, RedfishCS_Vague *VagueValue)
{
  json_t *JsonValue;
  RedfishCS_char NullStr[] = "";

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (VagueValue == (RedfishCS_Vague *)NULL) {
    JsonValue = json_null(); // No value for this key.
  } else if (VagueValue->DataType == RedfishCS_Vague_DataType_String) {
    if (VagueValue->DataValue.CharPtr == NULL) {
      JsonValue = json_string(NullStr);
    } else {
      JsonValue = json_string(VagueValue->DataValue.CharPtr);
    }
  } else if (VagueValue->DataType == RedfishCS_Vague_DataType_Int64) {
    JsonValue = json_integer((json_int_t)*VagueValue->DataValue.Int64Ptr);
  } else if (VagueValue->DataType == RedfishCS_Vague_DataType_Bool) {
    JsonValue = json_boolean(*VagueValue->DataValue.BoolPtr);
  } else {
    return RedfishCS_status_invalid_parameter;
  }
  if (json_object_set_new (ParentJsonObj, Key, JsonValue) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonLinkObj (json_t *JsonObj, char *Key, RedfishCS_Link *Link)
{
  json_t  *JsonTextObj;
  RedfishCS_Type_JSON_Data *CsJsonHeader;

  if (Link == NULL || JsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (IsLinkEmpty (Link)) {
    return RedfishCS_status_success;
  }

  CsJsonHeader = (RedfishCS_Type_JSON_Data *)GetFirstLink (Link);
  if (CsJsonHeader->Header.ResourceType != RedfishCS_Type_JSON) {
    // Only support JASON property for CStructure to JSON
    return RedfishCS_status_unsupported;
  }
  if (CsJsonHeader->JsonText == NULL) {
    return RedfishCS_status_invalid_parameter;
  }

  JsonTextObj = json_loads(CsJsonHeader->JsonText, 0, NULL);
  if (json_object_set_new (JsonObj, Key, JsonTextObj) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonStringArrayObj (json_t *ParentJsonObj, char *Key, RedfishCS_char_Array *StringValueArray)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishCS_char_Array *NextArray;
  RedfishCS_char NullStr[] = "";

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (StringValueArray == (RedfishCS_char_Array *)NULL) {
    return RedfishCS_status_success; // No value for this key.
  }
  ArrayJson = json_array();
  if (ArrayJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  NextArray = StringValueArray;
  do {
    if (NextArray->ArrayValue == NULL) {
      ArrayMember = json_string(NullStr);
    } else {
      ArrayMember = json_string(NextArray->ArrayValue);
    }
    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {
      return RedfishCS_status_unsupported;
    }
    NextArray = NextArray->Next;
  } while (NextArray != NULL);

  if (json_object_set_new (ParentJsonObj, Key, ArrayJson) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonBoolArrayObj (json_t *ParentJsonObj, char *Key, RedfishCS_bool_Array *BoolValueArray)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishCS_bool_Array *NextArray;

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (BoolValueArray == (RedfishCS_bool_Array *)NULL) {
    return RedfishCS_status_success; // No value for this key.
  }
  ArrayJson = json_array();
  if (ArrayJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  NextArray = BoolValueArray;
  do {
    ArrayMember = json_boolean(*NextArray->ArrayValue);
    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {
      return RedfishCS_status_unsupported;
    }
    NextArray = NextArray->Next;
  } while (NextArray != NULL);

  if (json_object_set_new (ParentJsonObj, Key, ArrayJson) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonInt64ArrayObj (json_t *ParentJsonObj, char *Key, RedfishCS_int64_Array *Int64ValueArray)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishCS_int64_Array *NextArray;

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }
  if (Int64ValueArray == (RedfishCS_int64_Array *)NULL) {
    return RedfishCS_status_success; // No value for this key.
  }
  ArrayJson = json_array();
  if (ArrayJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  NextArray = Int64ValueArray;
  do {
    ArrayMember = json_integer(*NextArray->ArrayValue);
    if (json_array_append_new (ArrayJson, ArrayMember) != 0) {
      return RedfishCS_status_unsupported;
    }
    NextArray = NextArray->Next;
  } while (NextArray != NULL);

  if (json_object_set_new (ParentJsonObj, Key, ArrayJson) == -1) {
    return RedfishCS_status_unsupported;
  }
  return RedfishCS_status_success;
}

RedfishCS_status InsertJsonLinkArrayObj (json_t *ParentJsonObj, char *Key, RedfishCS_Link *LinkArray)
{
  json_t *ArrayJson;
  json_t *ArrayMember;
  RedfishCS_Type_Uri_Data *ThisLink;

  if (ParentJsonObj == NULL) {
    return RedfishCS_status_invalid_parameter;
  }

  if (IsLinkEmpty (LinkArray)) {
    return RedfishCS_status_success;
  }

  ArrayJson = json_array();
  if (ArrayJson == NULL) {
    return RedfishCS_status_unsupported;
  }
  ThisLink = (RedfishCS_Type_Uri_Data *)GetFirstLink (LinkArray);
  while (RedfishCS_boolean_true){
    if (ThisLink->Header.ResourceType != RedfishCS_Type_Uri) {
      return RedfishCS_status_invalid_parameter;
    }
    if (ThisLink->Uri != (RedfishCS_char *)NULL) {
      ArrayMember = json_string(ThisLink->Uri);
      if (json_array_append_new (ArrayJson, ArrayMember) != 0) {
        return RedfishCS_status_unsupported;
      }
    }
    if (IsLinkAtEnd (LinkArray, &ThisLink->Header.LinkEntry)) {
      if (json_object_set_new (ParentJsonObj, Key, ArrayJson) == -1) {
        return RedfishCS_status_unsupported;
      }
      return RedfishCS_status_success;
    }
    ThisLink = (RedfishCS_Type_Uri_Data *)GetNextLink(LinkArray, &ThisLink->Header.LinkEntry);
  };
  return RedfishCS_status_success;
}

RedfishCS_status CsEmptyPropLinkToJson(json_t *ParentJsonObj, char *Key, RedfishCS_Link *Link) {
  RedfishCS_uint32 Index;
  RedfishCS_Type_EmptyProp_CS_Data *EmptyProp_CS_Ptr;
  RedfishCS_EmptyProp_KeyValue *KeyValuePtr;
  json_t *JsonObj;
  RedfishCS_status Status;

  EmptyProp_CS_Ptr = (RedfishCS_Type_EmptyProp_CS_Data *)GetFirstLink(Link);
  if (EmptyProp_CS_Ptr->Header.ResourceType != RedfishCS_Type_CS_EmptyProp) {
    return RedfishCS_status_unsupported;
   }

  JsonObj = json_object();
  KeyValuePtr = EmptyProp_CS_Ptr->KeyValuePtr;
  for (Index = 0; Index < EmptyProp_CS_Ptr->NunmOfProperties; Index++) {
    Status = InsertJsonVagueObj(JsonObj, KeyValuePtr->KeyNamePtr, KeyValuePtr->Value);
    if (Status != RedfishCS_status_success) {
      return Status;
    }
    KeyValuePtr = KeyValuePtr->NextKeyValuePtr;
  }
  if (json_object_set_new(ParentJsonObj, Key, JsonObj) != 0) {
    return RedfishCS_status_unknown_error;
  }
  return RedfishCS_status_success;
}

