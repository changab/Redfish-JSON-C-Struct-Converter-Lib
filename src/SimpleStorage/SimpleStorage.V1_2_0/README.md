# Definition of SimpleStorage.V1_2_0 and functions<br><br>

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


## Device
    typedef struct _RedfishSimpleStorage_V1_2_0_Device_CS {
        RedfishCS_int64 *CapacityBytes;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishSimpleStorage_V1_2_0_Device_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**CapacityBytes**|RedfishCS_int64| 64-bit long long interger pointer to **CapacityBytes** property.| No| Yes
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No


## SimpleStorage_Actions
    typedef struct _RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_CS {
        RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_Oem_CS *Oem;
    } RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## SimpleStorage_Actions_Oem
    typedef struct _RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## SimpleStorage_Links
    typedef struct _RedfishSimpleStorage_V1_2_0_SimpleStorage_Links_CS {
        RedfishCS_Link Chassis;
        RedfishResource_Oem_CS *Oem;
    } RedfishSimpleStorage_V1_2_0_SimpleStorage_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## SimpleStorage
    typedef struct _RedfishSimpleStorage_V1_2_0_SimpleStorage_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishSimpleStorage_V1_2_0_Device_CS *Devices;
        RedfishCS_char *Id;
        RedfishSimpleStorage_V1_2_0_SimpleStorage_Links_CS *Links;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *UefiDevicePath;
    } RedfishSimpleStorage_V1_2_0_SimpleStorage_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishSimpleStorage_V1_2_0_SimpleStorage_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Devices**|RedfishSimpleStorage_V1_2_0_Device_CS| Structure points to **Devices** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishSimpleStorage_V1_2_0_SimpleStorage_Links_CS| Structure points to **Links** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UefiDevicePath**|RedfishCS_char| String pointer to **UefiDevicePath** property.| No| Yes
## Redfish SimpleStorage V1_2_0 to C Structure Function
    RedfishCS_status
    Json_SimpleStorage_V1_2_0_To_CS (RedfishCS_char *JsonRawText, RedfishSimpleStorage_V1_2_0_SimpleStorage_CS **ReturnedCS);

## C Structure to Redfish SimpleStorage V1_2_0 JSON Function
    RedfishCS_status
    CS_To_SimpleStorage_V1_2_0_JSON (RedfishSimpleStorage_V1_2_0_SimpleStorage_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish SimpleStorage V1_2_0 C Structure Function
    RedfishCS_status
    DestroySimpleStorage_V1_2_0_CS (RedfishSimpleStorage_V1_2_0_SimpleStorage_CS *CSPtr);

