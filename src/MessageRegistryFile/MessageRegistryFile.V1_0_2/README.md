# Definition of MessageRegistryFile.V1_0_2 and functions<br><br>

## Location
    typedef struct _RedfishMessageRegistryFile_V1_0_2_Location_CS {
        RedfishCS_char *ArchiveFile;
        RedfishCS_char *ArchiveUri;
        RedfishCS_char *Language;
        RedfishCS_char *PublicationUri;
        RedfishCS_char *Uri;
    } RedfishMessageRegistryFile_V1_0_2_Location_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ArchiveFile**|RedfishCS_char| String pointer to **ArchiveFile** property.| No| Yes
|**ArchiveUri**|RedfishCS_char| String pointer to **ArchiveUri** property.| No| Yes
|**Language**|RedfishCS_char| String pointer to **Language** property.| No| Yes
|**PublicationUri**|RedfishCS_char| String pointer to **PublicationUri** property.| No| Yes
|**Uri**|RedfishCS_char| String pointer to **Uri** property.| No| Yes


## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## MessageRegistryFile
    typedef struct _RedfishMessageRegistryFile_V1_0_2_MessageRegistryFile_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *Languages;
        RedfishMessageRegistryFile_V1_0_2_Location_CS *Location;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *Registry;
    } RedfishMessageRegistryFile_V1_0_2_MessageRegistryFile_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| No
|**Languages**|RedfishCS_char| String pointer to **Languages** property.| Yes| Yes
|**Location**|RedfishMessageRegistryFile_V1_0_2_Location_CS| Structure points to **Location** property.| Yes| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Registry**|RedfishCS_char| String pointer to **Registry** property.| Yes| Yes
## Redfish MessageRegistryFile V1_0_2 to C Structure Function
    RedfishCS_status
    Json_MessageRegistryFile_V1_0_2_To_CS (RedfishCS_char *JsonRawText, RedfishMessageRegistryFile_V1_0_2_MessageRegistryFile_CS **ReturnedCS);

## C Structure to Redfish MessageRegistryFile V1_0_2 JSON Function
    RedfishCS_status
    CS_To_MessageRegistryFile_V1_0_2_JSON (RedfishMessageRegistryFile_V1_0_2_MessageRegistryFile_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish MessageRegistryFile V1_0_2 C Structure Function
    RedfishCS_status
    DestroyMessageRegistryFile_V1_0_2_CS (RedfishMessageRegistryFile_V1_0_2_MessageRegistryFile_CS *CSPtr);

