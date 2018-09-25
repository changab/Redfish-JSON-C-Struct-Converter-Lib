# Definition of Volume.V1_0_3 and functions<br><br>

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


## Identifier
    typedef struct _RedfishResource_V1_1_0_Identifier_CS {
        RedfishCS_char *DurableName;
        RedfishCS_char *DurableNameFormat;
    } RedfishResource_V1_1_0_Identifier_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**DurableName**|RedfishCS_char| String pointer to **DurableName** property.| No| Yes
|**DurableNameFormat**|RedfishCS_char| String pointer to **DurableNameFormat** property.| No| Yes


## Initialize
    typedef struct _RedfishVolume_V1_0_3_Initialize_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishVolume_V1_0_3_Initialize_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## Operations
    typedef struct _RedfishVolume_V1_0_3_Operations_CS {
        RedfishCS_Link AssociatedTask;
        RedfishCS_char *OperationName;
        RedfishCS_int64 *PercentageComplete;
    } RedfishVolume_V1_0_3_Operations_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**AssociatedTask**|RedfishCS_Link| Structure link list to **AssociatedTask** property.| No| Yes
|**OperationName**|RedfishCS_char| String pointer to **OperationName** property.| No| Yes
|**PercentageComplete**|RedfishCS_int64| 64-bit long long interger pointer to **PercentageComplete** property.| No| Yes


## Volume_Actions
    typedef struct _RedfishVolume_V1_0_3_Volume_Actions_CS {
        RedfishVolume_V1_0_3_Initialize_CS *Volume_Initialize;
        RedfishVolume_V1_0_3_Volume_Actions_Oem_CS *Oem;
    } RedfishVolume_V1_0_3_Volume_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Volume_Initialize**|RedfishVolume_V1_0_3_Initialize_CS| Structure points to **#Volume.Initialize** property.| No| No
|**Oem**|RedfishVolume_V1_0_3_Volume_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## Volume_Actions_Oem
    typedef struct _RedfishVolume_V1_0_3_Volume_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishVolume_V1_0_3_Volume_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Volume_Links
    typedef struct _RedfishVolume_V1_0_3_Volume_Links_CS {
        RedfishCS_Link Drives;
        RedfishCS_int64 *Drivesodata_count;
        RedfishCS_char *Drivesodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
    } RedfishVolume_V1_0_3_Volume_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Drives**|RedfishCS_Link| Structure link list to **Drives** property.| No| Yes
|**Drivesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Drives@odata.count** property.| No| No
|**Drivesodata_navigationLink**|RedfishCS_char| String pointer to **Drives@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## Volume
    typedef struct _RedfishVolume_V1_0_3_Volume_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishVolume_V1_0_3_Volume_Actions_CS *Actions;
        RedfishCS_int64 *BlockSizeBytes;
        RedfishCS_int64 *CapacityBytes;
        RedfishCS_char *Description;
        RedfishCS_bool *Encrypted;
        RedfishCS_char *EncryptionTypes;
        RedfishCS_char *Id;
        RedfishResource_V1_1_0_Identifier_CS *Identifiers;
        RedfishVolume_V1_0_3_Volume_Links_CS *Links;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishVolume_V1_0_3_Operations_CS *Operations;
        RedfishCS_int64 *OptimumIOSizeBytes;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *VolumeType;
    } RedfishVolume_V1_0_3_Volume_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishVolume_V1_0_3_Volume_Actions_CS| Structure points to **Actions** property.| No| No
|**BlockSizeBytes**|RedfishCS_int64| 64-bit long long interger pointer to **BlockSizeBytes** property.| No| Yes
|**CapacityBytes**|RedfishCS_int64| 64-bit long long interger pointer to **CapacityBytes** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Encrypted**|RedfishCS_bool| Boolean pointer to **Encrypted** property.| No| No
|**EncryptionTypes**|RedfishCS_char| String pointer to **EncryptionTypes** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Identifiers**|RedfishResource_V1_1_0_Identifier_CS| Structure points to **Identifiers** property.| No| No
|**Links**|RedfishVolume_V1_0_3_Volume_Links_CS| Structure points to **Links** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Operations**|RedfishVolume_V1_0_3_Operations_CS| Structure points to **Operations** property.| No| No
|**OptimumIOSizeBytes**|RedfishCS_int64| 64-bit long long interger pointer to **OptimumIOSizeBytes** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**VolumeType**|RedfishCS_char| String pointer to **VolumeType** property.| No| Yes
## Redfish Volume V1_0_3 to C Structure Function
    RedfishCS_status
    Json_Volume_V1_0_3_To_CS (RedfishCS_char *JsonRawText, RedfishVolume_V1_0_3_Volume_CS **ReturnedCS);

## C Structure to Redfish Volume V1_0_3 JSON Function
    RedfishCS_status
    CS_To_Volume_V1_0_3_JSON (RedfishVolume_V1_0_3_Volume_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Volume V1_0_3 C Structure Function
    RedfishCS_status
    DestroyVolume_V1_0_3_CS (RedfishVolume_V1_0_3_Volume_CS *CSPtr);

