# Definition of MemoryChunks.V1_2_2 and functions<br><br>

## Actions
    typedef struct _RedfishMemoryChunks_V1_2_2_Actions_CS {
        RedfishMemoryChunks_V1_2_2_OemActions_CS *Oem;
    } RedfishMemoryChunks_V1_2_2_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishMemoryChunks_V1_2_2_OemActions_CS| Structure points to **Oem** property.| No| No


## InterleaveSet
    typedef struct _RedfishMemoryChunks_V1_2_2_InterleaveSet_CS {
        Redfishodata_V4_0_3_idRef_CS *Memory;
        RedfishCS_int64 *MemoryLevel;
        RedfishCS_int64 *OffsetMiB;
        RedfishCS_char *RegionId;
        RedfishCS_int64 *SizeMiB;
    } RedfishMemoryChunks_V1_2_2_InterleaveSet_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Memory**|Redfishodata_V4_0_3_idRef_CS| Structure points to **Memory** property.| No| Yes
|**MemoryLevel**|RedfishCS_int64| 64-bit long long interger pointer to **MemoryLevel** property.| No| Yes
|**OffsetMiB**|RedfishCS_int64| 64-bit long long interger pointer to **OffsetMiB** property.| No| Yes
|**RegionId**|RedfishCS_char| String pointer to **RegionId** property.| No| Yes
|**SizeMiB**|RedfishCS_int64| 64-bit long long interger pointer to **SizeMiB** property.| No| Yes


## OemActions
    typedef struct _RedfishMemoryChunks_V1_2_2_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishMemoryChunks_V1_2_2_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Status
    typedef struct _RedfishResource_Status_CS {
        RedfishCS_char *Health;
        RedfishCS_char *HealthRollup;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *State;
    } RedfishResource_Status_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Health**|RedfishCS_char| String pointer to **Health** property.| No| Yes
|**HealthRollup**|RedfishCS_char| String pointer to **HealthRollup** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**State**|RedfishCS_char| String pointer to **State** property.| No| Yes


## idRef
    typedef struct _Redfishodata_V4_0_3_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_3_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No


## MemoryChunks
    typedef struct _RedfishMemoryChunks_V1_2_2_MemoryChunks_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishMemoryChunks_V1_2_2_Actions_CS *Actions;
        RedfishCS_char *AddressRangeType;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishMemoryChunks_V1_2_2_InterleaveSet_CS *InterleaveSets;
        RedfishCS_bool *IsMirrorEnabled;
        RedfishCS_bool *IsSpare;
        RedfishCS_int64 *MemoryChunkSizeMiB;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishMemoryChunks_V1_2_2_MemoryChunks_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishMemoryChunks_V1_2_2_Actions_CS| Structure points to **Actions** property.| No| No
|**AddressRangeType**|RedfishCS_char| String pointer to **AddressRangeType** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**InterleaveSets**|RedfishMemoryChunks_V1_2_2_InterleaveSet_CS| Structure points to **InterleaveSets** property.| No| No
|**IsMirrorEnabled**|RedfishCS_bool| Boolean pointer to **IsMirrorEnabled** property.| No| Yes
|**IsSpare**|RedfishCS_bool| Boolean pointer to **IsSpare** property.| No| Yes
|**MemoryChunkSizeMiB**|RedfishCS_int64| 64-bit long long interger pointer to **MemoryChunkSizeMiB** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish MemoryChunks V1_2_2 to C Structure Function
    RedfishCS_status
    Json_MemoryChunks_V1_2_2_To_CS (RedfishCS_char *JsonRawText, RedfishMemoryChunks_V1_2_2_MemoryChunks_CS **ReturnedCS);

## C Structure to Redfish MemoryChunks V1_2_2 JSON Function
    RedfishCS_status
    CS_To_MemoryChunks_V1_2_2_JSON (RedfishMemoryChunks_V1_2_2_MemoryChunks_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish MemoryChunks V1_2_2 C Structure Function
    RedfishCS_status
    DestroyMemoryChunks_V1_2_2_CS (RedfishMemoryChunks_V1_2_2_MemoryChunks_CS *CSPtr);

