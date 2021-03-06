# Definition of PCIeDevice.V1_0_1 and functions<br><br>

## PCIeDevice_Links
    typedef struct _RedfishPCIeDevice_V1_0_1_PCIeDevice_Links_CS {
        RedfishCS_Link Chassis;
        RedfishCS_int64 *Chassisodata_count;
        RedfishCS_char *Chassisodata_navigationLink;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PCIeFunctions;
        RedfishCS_int64 *PCIeFunctionsodata_count;
        RedfishCS_char *PCIeFunctionsodata_navigationLink;
    } RedfishPCIeDevice_V1_0_1_PCIeDevice_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Chassis**|RedfishCS_Link| Structure link list to **Chassis** property.| No| Yes
|**Chassisodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Chassis@odata.count** property.| No| No
|**Chassisodata_navigationLink**|RedfishCS_char| String pointer to **Chassis@odata.navigationLink** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PCIeFunctions**|RedfishCS_Link| Structure link list to **PCIeFunctions** property.| No| Yes
|**PCIeFunctionsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **PCIeFunctions@odata.count** property.| No| No
|**PCIeFunctionsodata_navigationLink**|RedfishCS_char| String pointer to **PCIeFunctions@odata.navigationLink** property.| No| No


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


## PCIeDevice
    typedef struct _RedfishPCIeDevice_V1_0_1_PCIeDevice_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *AssetTag;
        RedfishCS_char *Description;
        RedfishCS_char *DeviceType;
        RedfishCS_char *FirmwareVersion;
        RedfishCS_char *Id;
        RedfishPCIeDevice_V1_0_1_PCIeDevice_Links_CS *Links;
        RedfishCS_char *Manufacturer;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PartNumber;
        RedfishCS_char *SKU;
        RedfishCS_char *SerialNumber;
        RedfishResource_Status_CS *Status;
    } RedfishPCIeDevice_V1_0_1_PCIeDevice_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**AssetTag**|RedfishCS_char| String pointer to **AssetTag** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**DeviceType**|RedfishCS_char| String pointer to **DeviceType** property.| No| Yes
|**FirmwareVersion**|RedfishCS_char| String pointer to **FirmwareVersion** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishPCIeDevice_V1_0_1_PCIeDevice_Links_CS| Structure points to **Links** property.| No| No
|**Manufacturer**|RedfishCS_char| String pointer to **Manufacturer** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PartNumber**|RedfishCS_char| String pointer to **PartNumber** property.| No| Yes
|**SKU**|RedfishCS_char| String pointer to **SKU** property.| No| Yes
|**SerialNumber**|RedfishCS_char| String pointer to **SerialNumber** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish PCIeDevice V1_0_1 to C Structure Function
    RedfishCS_status
    Json_PCIeDevice_V1_0_1_To_CS (RedfishCS_char *JsonRawText, RedfishPCIeDevice_V1_0_1_PCIeDevice_CS **ReturnedCS);

## C Structure to Redfish PCIeDevice V1_0_1 JSON Function
    RedfishCS_status
    CS_To_PCIeDevice_V1_0_1_JSON (RedfishPCIeDevice_V1_0_1_PCIeDevice_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish PCIeDevice V1_0_1 C Structure Function
    RedfishCS_status
    DestroyPCIeDevice_V1_0_1_CS (RedfishPCIeDevice_V1_0_1_PCIeDevice_CS *CSPtr);

