# Definition of NetworkDeviceFunctionCollection and functions<br><br>

## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## NetworkDeviceFunctionCollection
    typedef struct _RedfishNetworkDeviceFunctionCollection_NetworkDeviceFunctionCollection_CS {
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
    } RedfishNetworkDeviceFunctionCollection_NetworkDeviceFunctionCollection_CS;

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
## Redfish NetworkDeviceFunctionCollection  to C Structure Function
    RedfishCS_status
    Json_NetworkDeviceFunctionCollection_To_CS (RedfishCS_char *JsonRawText, RedfishNetworkDeviceFunctionCollection_NetworkDeviceFunctionCollection_CS **ReturnedCS);

## C Structure to Redfish NetworkDeviceFunctionCollection  JSON Function
    RedfishCS_status
    CS_To_NetworkDeviceFunctionCollection_JSON (RedfishNetworkDeviceFunctionCollection_NetworkDeviceFunctionCollection_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish NetworkDeviceFunctionCollection  C Structure Function
    RedfishCS_status
    DestroyNetworkDeviceFunctionCollection_CS (RedfishNetworkDeviceFunctionCollection_NetworkDeviceFunctionCollection_CS *CSPtr);
