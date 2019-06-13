# Definition of Drive.V1_5_0 and functions<br><br>

## Actions
    typedef struct _RedfishDrive_V1_5_0_Actions_CS {
        RedfishDrive_V1_5_0_SecureErase_CS *Drive_SecureErase;
        RedfishDrive_V1_5_0_OemActions_CS *Oem;
    } RedfishDrive_V1_5_0_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Drive_SecureErase**|RedfishDrive_V1_5_0_SecureErase_CS| Structure points to **#Drive.SecureErase** property.| No| No
|**Oem**|RedfishDrive_V1_5_0_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishDrive_V1_5_0_Links_CS {
        RedfishCS_Link Chassis;
        RedfishCS_Link Endpoints;
        RedfishCS_int64 *Endpointsodata_count;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link Volumes;
        RedfishCS_int64 *Volumesodata_count;
    } RedfishDrive_V1_5_0_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**Endpoints**|RedfishCS_Link| Structure link list to **Endpoints** property.| No| Yes
|**Endpointsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Endpoints@odata.count** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Volumes**|RedfishCS_Link| Structure link list to **Volumes** property.| No| Yes
|**Volumesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Volumes@odata.count** property.| No| No


## OemActions
    typedef struct _RedfishDrive_V1_5_0_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishDrive_V1_5_0_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Operations
    typedef struct _RedfishDrive_V1_5_0_Operations_CS {
        RedfishCS_Link AssociatedTask;
        RedfishCS_char *OperationName;
        RedfishCS_int64 *PercentageComplete;
    } RedfishDrive_V1_5_0_Operations_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**AssociatedTask**|RedfishCS_Link| Structure link list to **AssociatedTask** property.| No| Yes
|**OperationName**|RedfishCS_char| String pointer to **OperationName** property.| No| Yes
|**PercentageComplete**|RedfishCS_int64| 64-bit long long interger pointer to **PercentageComplete** property.| No| Yes


## SecureErase
    typedef struct _RedfishDrive_V1_5_0_SecureErase_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishDrive_V1_5_0_SecureErase_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


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


## Drive
    typedef struct _RedfishDrive_V1_5_0_Drive_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishDrive_V1_5_0_Actions_CS *Actions;
        RedfishCS_Link Assembly;
        RedfishCS_char *AssetTag;
        RedfishCS_int64 *BlockSizeBytes;
        RedfishCS_int64 *CapableSpeedGbs;
        RedfishCS_int64 *CapacityBytes;
        RedfishCS_char *Description;
        RedfishCS_char *EncryptionAbility;
        RedfishCS_char *EncryptionStatus;
        RedfishCS_bool *FailurePredicted;
        RedfishCS_char *HotspareReplacementMode;
        RedfishCS_char *HotspareType;
        RedfishCS_char *Id;
        RedfishCS_Link Identifiers;
        RedfishCS_char *IndicatorLED;
        RedfishDrive_V1_5_0_Links_CS *Links;
        RedfishCS_Link Location;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *MediaType;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishCS_int64 *NegotiatedSpeedGbs;
        RedfishResource_Oem_CS *Oem;
        RedfishDrive_V1_5_0_Operations_CS *Operations;
        RedfishCS_char *PartNumber;
        RedfishCS_Link PhysicalLocation;
        RedfishCS_int64 *PredictedMediaLifeLeftPercent;
        RedfishCS_char *Protocol;
        RedfishCS_char *Revision;
        RedfishCS_int64 *RotationSpeedRPM;
        RedfishCS_char *SKU;
        RedfishCS_char *SerialNumber;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *StatusIndicator;
    } RedfishDrive_V1_5_0_Drive_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishDrive_V1_5_0_Actions_CS| Structure points to **Actions** property.| No| No
|**Assembly**|RedfishCS_Link| Structure link list to **Assembly** property.| No| Yes
|**AssetTag**|RedfishCS_char| String pointer to **AssetTag** property.| No| No
|**BlockSizeBytes**|RedfishCS_int64| 64-bit long long interger pointer to **BlockSizeBytes** property.| No| Yes
|**CapableSpeedGbs**|RedfishCS_int64| 64-bit long long interger pointer to **CapableSpeedGbs** property.| No| Yes
|**CapacityBytes**|RedfishCS_int64| 64-bit long long interger pointer to **CapacityBytes** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**EncryptionAbility**|RedfishCS_char| String pointer to **EncryptionAbility** property.| No| Yes
|**EncryptionStatus**|RedfishCS_char| String pointer to **EncryptionStatus** property.| No| Yes
|**FailurePredicted**|RedfishCS_bool| Boolean pointer to **FailurePredicted** property.| No| Yes
|**HotspareReplacementMode**|RedfishCS_char| String pointer to **HotspareReplacementMode** property.| No| No
|**HotspareType**|RedfishCS_char| String pointer to **HotspareType** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Identifiers**|RedfishCS_Link| Structure link list to **Identifiers** property.| No| No
|**IndicatorLED**|RedfishCS_char| String pointer to **IndicatorLED** property.| No| No
|**Links**|RedfishDrive_V1_5_0_Links_CS| Structure points to **Links** property.| No| No
|**Location**|RedfishCS_Link| Structure link list to **Location** property.| No| No
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**MediaType**|RedfishCS_char| String pointer to **MediaType** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NegotiatedSpeedGbs**|RedfishCS_int64| 64-bit long long interger pointer to **NegotiatedSpeedGbs** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Operations**|RedfishDrive_V1_5_0_Operations_CS| Structure points to **Operations** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**PhysicalLocation**|RedfishCS_Link| Structure link list to **PhysicalLocation** property.| No| No
|**PredictedMediaLifeLeftPercent**|RedfishCS_int64| 64-bit long long interger pointer to **PredictedMediaLifeLeftPercent** property.| No| Yes
|**Protocol**|RedfishCS_char| String pointer to **Protocol** property.| No| Yes
|**Revision**|RedfishCS_char| String pointer to **Revision** property.| No| Yes
|**RotationSpeedRPM**|RedfishCS_int64| 64-bit long long interger pointer to **RotationSpeedRPM** property.| No| Yes
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**StatusIndicator**|RedfishCS_char| String pointer to **StatusIndicator** property.| No| No
## Redfish Drive V1_5_0 to C Structure Function
    RedfishCS_status
    Json_Drive_V1_5_0_To_CS (RedfishCS_char *JsonRawText, RedfishDrive_V1_5_0_Drive_CS **ReturnedCS);

## C Structure to Redfish Drive V1_5_0 JSON Function
    RedfishCS_status
    CS_To_Drive_V1_5_0_JSON (RedfishDrive_V1_5_0_Drive_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Drive V1_5_0 C Structure Function
    RedfishCS_status
    DestroyDrive_V1_5_0_CS (RedfishDrive_V1_5_0_Drive_CS *CSPtr);

