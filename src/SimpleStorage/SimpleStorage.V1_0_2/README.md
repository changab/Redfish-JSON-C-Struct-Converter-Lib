# Definition of SimpleStorage.V1_0_2 and functions<br><br>

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
    typedef struct _RedfishSimpleStorage_V1_0_2_Device_CS {
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishSimpleStorage_V1_0_2_Device_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No


## SimpleStorage
    typedef struct _RedfishSimpleStorage_V1_0_2_SimpleStorage_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishSimpleStorage_V1_0_2_Device_CS *Devices;
        RedfishCS_char *Id;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *UefiDevicePath;
    } RedfishSimpleStorage_V1_0_2_SimpleStorage_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| No
|**Devices**|RedfishSimpleStorage_V1_0_2_Device_CS| Structure points to **Devices** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UefiDevicePath**|RedfishCS_char| String pointer to **UefiDevicePath** property.| No| Yes
## Redfish SimpleStorage V1_0_2 to C Structure Function
    RedfishCS_status
    Json_SimpleStorage_V1_0_2_To_CS (RedfishCS_char *JsonRawText, RedfishSimpleStorage_V1_0_2_SimpleStorage_CS **ReturnedCS);

## C Structure to Redfish SimpleStorage V1_0_2 JSON Function
    RedfishCS_status
    CS_To_SimpleStorage_V1_0_2_JSON (RedfishSimpleStorage_V1_0_2_SimpleStorage_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish SimpleStorage V1_0_2 C Structure Function
    RedfishCS_status
    DestroySimpleStorage_V1_0_2_CS (RedfishSimpleStorage_V1_0_2_SimpleStorage_CS *CSPtr);

