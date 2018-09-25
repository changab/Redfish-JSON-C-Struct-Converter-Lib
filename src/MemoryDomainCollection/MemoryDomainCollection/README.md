# Definition of MemoryDomainCollection and functions<br><br>

## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## MemoryDomainCollection
    typedef struct _RedfishMemoryDomainCollection_MemoryDomainCollection_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishCS_Link Members;
        RedfishCS_int64 *Membersodata_count;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
    } RedfishMemoryDomainCollection_MemoryDomainCollection_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Members**|RedfishCS_Link| Structure link list to **Members** property.| No| Yes
|**Membersodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Members@odata.count** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
## Redfish MemoryDomainCollection  to C Structure Function
    RedfishCS_status
    Json_MemoryDomainCollection_To_CS (RedfishCS_char *JsonRawText, RedfishMemoryDomainCollection_MemoryDomainCollection_CS **ReturnedCS);

## C Structure to Redfish MemoryDomainCollection  JSON Function
    RedfishCS_status
    CS_To_MemoryDomainCollection_JSON (RedfishMemoryDomainCollection_MemoryDomainCollection_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish MemoryDomainCollection  C Structure Function
    RedfishCS_status
    DestroyMemoryDomainCollection_CS (RedfishMemoryDomainCollection_MemoryDomainCollection_CS *CSPtr);
