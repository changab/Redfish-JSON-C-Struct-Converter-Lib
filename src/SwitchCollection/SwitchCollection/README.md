# Definition of SwitchCollection and functions<br><br>

## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## SwitchCollection
    typedef struct _RedfishSwitchCollection_SwitchCollection_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishCS_Link Members;
        RedfishCS_int64 *Membersodata_count;
        RedfishCS_char *Membersodata_nextLink;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
    } RedfishSwitchCollection_SwitchCollection_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Members**|RedfishCS_Link| Structure link list to **Members** property.| Yes| Yes
|**Membersodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Members@odata.count** property.| No| No
|**Membersodata_nextLink**|RedfishCS_char| String pointer to **Members@odata.nextLink** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
## Redfish SwitchCollection  to C Structure Function
    RedfishCS_status
    Json_SwitchCollection_To_CS (RedfishCS_char *JsonRawText, RedfishSwitchCollection_SwitchCollection_CS **ReturnedCS);

## C Structure to Redfish SwitchCollection  JSON Function
    RedfishCS_status
    CS_To_SwitchCollection_JSON (RedfishSwitchCollection_SwitchCollection_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish SwitchCollection  C Structure Function
    RedfishCS_status
    DestroySwitchCollection_CS (RedfishSwitchCollection_SwitchCollection_CS *CSPtr);

