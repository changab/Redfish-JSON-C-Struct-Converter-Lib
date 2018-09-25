# Definition of Switch.V1_0_3 and functions<br><br>

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


## Actions
    typedef struct _RedfishSwitch_V1_0_3_Actions_CS {
        RedfishSwitch_V1_0_3_Reset_CS *Switch_Reset;
        RedfishSwitch_V1_0_3_OemActions_CS *Oem;
    } RedfishSwitch_V1_0_3_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Switch_Reset**|RedfishSwitch_V1_0_3_Reset_CS| Structure points to **#Switch.Reset** property.| No| No
|**Oem**|RedfishSwitch_V1_0_3_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishSwitch_V1_0_3_Links_CS {
        RedfishCS_Link Chassis;
        RedfishCS_Link ManagedBy;
        RedfishCS_int64 *ManagedByodata_count;
        RedfishResource_Oem_CS *Oem;
    } RedfishSwitch_V1_0_3_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**ManagedBy**|RedfishCS_Link| Structure link list to **ManagedBy** property.| No| Yes
|**ManagedByodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ManagedBy@odata.count** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishSwitch_V1_0_3_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishSwitch_V1_0_3_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Reset
    typedef struct _RedfishSwitch_V1_0_3_Reset_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishSwitch_V1_0_3_Reset_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## Switch
    typedef struct _RedfishSwitch_V1_0_3_Switch_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishSwitch_V1_0_3_Actions_CS *Actions;
        RedfishCS_char *AssetTag;
        RedfishCS_char *Description;
        RedfishCS_int64 *DomainID;
        RedfishCS_char *Id;
        RedfishCS_char *IndicatorLED;
        RedfishCS_bool *IsManaged;
        RedfishSwitch_V1_0_3_Links_CS *Links;
        RedfishCS_Link LogServices;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishCS_Link Ports;
        RedfishCS_char *PowerState;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        RedfishCS_char *SKU;
        RedfishCS_char *SerialNumber;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *SwitchType;
        RedfishCS_int64 *TotalSwitchWidth;
    } RedfishSwitch_V1_0_3_Switch_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishSwitch_V1_0_3_Actions_CS| Structure points to **Actions** property.| No| No
|**AssetTag**|RedfishCS_char| String pointer to **AssetTag** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**DomainID**|RedfishCS_int64| 64-bit long long interger pointer to **DomainID** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**IndicatorLED**|RedfishCS_char| String pointer to **IndicatorLED** property.| No| No
|**IsManaged**|RedfishCS_bool| Boolean pointer to **IsManaged** property.| No| No
|**Links**|RedfishSwitch_V1_0_3_Links_CS| Structure points to **Links** property.| No| No
|**LogServices**|RedfishCS_Link| Structure link list to **LogServices** property.| No| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**Ports**|RedfishCS_Link| Structure link list to **Ports** property.| No| Yes
|**PowerState**|RedfishCS_char| String pointer to **PowerState** property.| No| Yes
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**SwitchType**|RedfishCS_char| String pointer to **SwitchType** property.| No| Yes
|**TotalSwitchWidth**|RedfishCS_int64| 64-bit long long interger pointer to **TotalSwitchWidth** property.| No| Yes
## Redfish Switch V1_0_3 to C Structure Function
    RedfishCS_status
    Json_Switch_V1_0_3_To_CS (RedfishCS_char *JsonRawText, RedfishSwitch_V1_0_3_Switch_CS **ReturnedCS);

## C Structure to Redfish Switch V1_0_3 JSON Function
    RedfishCS_status
    CS_To_Switch_V1_0_3_JSON (RedfishSwitch_V1_0_3_Switch_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Switch V1_0_3 C Structure Function
    RedfishCS_status
    DestroySwitch_V1_0_3_CS (RedfishSwitch_V1_0_3_Switch_CS *CSPtr);

