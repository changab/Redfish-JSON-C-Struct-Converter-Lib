# Definition of SoftwareInventory.V1_1_0 and functions<br><br>

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


## SoftwareInventory_Actions
    typedef struct _RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_CS {
        RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_Oem_CS *Oem;
    } RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## SoftwareInventory_Actions_Oem
    typedef struct _RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## idRef
    typedef struct _Redfishodata_V4_0_0_idRef_CS {
        RedfishCS_char *odata_id;
    } Redfishodata_V4_0_0_idRef_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No


## SoftwareInventory
    typedef struct _RedfishSoftwareInventory_V1_1_0_SoftwareInventory_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *LowestSupportedVersion;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        Redfishodata_V4_0_0_idRef_CS *RelatedItem;
        RedfishCS_int64 *RelatedItemodata_count;
        RedfishCS_char *RelatedItemodata_navigationLink;
        RedfishCS_char *SoftwareId;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *UefiDevicePaths;
        RedfishCS_bool *Updateable;
        RedfishCS_char *Version;
    } RedfishSoftwareInventory_V1_1_0_SoftwareInventory_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishSoftwareInventory_V1_1_0_SoftwareInventory_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**LowestSupportedVersion**|RedfishCS_char| String pointer to **LowestSupportedVersion** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**RelatedItem**|Redfishodata_V4_0_0_idRef_CS| Structure points to **RelatedItem** property.| No| Yes
|**RelatedItemodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **RelatedItem@odata.count** property.| No| No
|**RelatedItemodata_navigationLink**|RedfishCS_char| String pointer to **RelatedItem@odata.navigationLink** property.| No| No
|**SoftwareId**|RedfishCS_char| String pointer to **SoftwareId** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UefiDevicePaths**|RedfishCS_char| String pointer to **UefiDevicePaths** property.| No| Yes
|**Updateable**|RedfishCS_bool| Boolean pointer to **Updateable** property.| No| Yes
|**Version**|RedfishCS_char| String pointer to **Version** property.| No| Yes
## Redfish SoftwareInventory V1_1_0 to C Structure Function
    RedfishCS_status
    Json_SoftwareInventory_V1_1_0_To_CS (RedfishCS_char *JsonRawText, RedfishSoftwareInventory_V1_1_0_SoftwareInventory_CS **ReturnedCS);

## C Structure to Redfish SoftwareInventory V1_1_0 JSON Function
    RedfishCS_status
    CS_To_SoftwareInventory_V1_1_0_JSON (RedfishSoftwareInventory_V1_1_0_SoftwareInventory_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish SoftwareInventory V1_1_0 C Structure Function
    RedfishCS_status
    DestroySoftwareInventory_V1_1_0_CS (RedfishSoftwareInventory_V1_1_0_SoftwareInventory_CS *CSPtr);

