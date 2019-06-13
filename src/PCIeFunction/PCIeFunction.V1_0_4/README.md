# Definition of PCIeFunction.V1_0_4 and functions<br><br>

## Links
    typedef struct _RedfishPCIeFunction_V1_0_4_Links_CS {
        RedfishCS_Link Drives;
        RedfishCS_int64 *Drivesodata_count;
        RedfishCS_Link EthernetInterfaces;
        RedfishCS_int64 *EthernetInterfacesodata_count;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PCIeDevice;
        RedfishCS_Link StorageControllers;
        RedfishCS_int64 *StorageControllersodata_count;
    } RedfishPCIeFunction_V1_0_4_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Drives**|RedfishCS_Link| Structure link list to **Drives** property.| No| Yes
|**Drivesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Drives@odata.count** property.| No| No
|**EthernetInterfaces**|RedfishCS_Link| Structure link list to **EthernetInterfaces** property.| No| Yes
|**EthernetInterfacesodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **EthernetInterfaces@odata.count** property.| No| No
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PCIeDevice**|RedfishCS_Link| Structure link list to **PCIeDevice** property.| No| Yes
|**StorageControllers**|RedfishCS_Link| Structure link list to **StorageControllers** property.| No| Yes
|**StorageControllersodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **StorageControllers@odata.count** property.| No| No


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


## PCIeFunction
    typedef struct _RedfishPCIeFunction_V1_0_4_PCIeFunction_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *ClassCode;
        RedfishCS_char *Description;
        RedfishCS_char *DeviceClass;
        RedfishCS_char *DeviceId;
        RedfishCS_int64 *FunctionId;
        RedfishCS_char *FunctionType;
        RedfishCS_char *Id;
        RedfishPCIeFunction_V1_0_4_Links_CS *Links;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *RevisionId;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *SubsystemId;
        RedfishCS_char *SubsystemVendorId;
        RedfishCS_char *VendorId;
    } RedfishPCIeFunction_V1_0_4_PCIeFunction_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**ClassCode**|RedfishCS_char| String pointer to **ClassCode** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**DeviceClass**|RedfishCS_char| String pointer to **DeviceClass** property.| No| Yes
|**DeviceId**|RedfishCS_char| String pointer to **DeviceId** property.| No| Yes
|**FunctionId**|RedfishCS_int64| 64-bit long long interger pointer to **FunctionId** property.| No| Yes
|**FunctionType**|RedfishCS_char| String pointer to **FunctionType** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishPCIeFunction_V1_0_4_Links_CS| Structure points to **Links** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**RevisionId**|RedfishCS_char| String pointer to **RevisionId** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**SubsystemId**|RedfishCS_char| String pointer to **SubsystemId** property.| No| Yes
|**SubsystemVendorId**|RedfishCS_char| String pointer to **SubsystemVendorId** property.| No| Yes
|**VendorId**|RedfishCS_char| String pointer to **VendorId** property.| No| Yes
## Redfish PCIeFunction V1_0_4 to C Structure Function
    RedfishCS_status
    Json_PCIeFunction_V1_0_4_To_CS (RedfishCS_char *JsonRawText, RedfishPCIeFunction_V1_0_4_PCIeFunction_CS **ReturnedCS);

## C Structure to Redfish PCIeFunction V1_0_4 JSON Function
    RedfishCS_status
    CS_To_PCIeFunction_V1_0_4_JSON (RedfishPCIeFunction_V1_0_4_PCIeFunction_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish PCIeFunction V1_0_4 C Structure Function
    RedfishCS_status
    DestroyPCIeFunction_V1_0_4_CS (RedfishPCIeFunction_V1_0_4_PCIeFunction_CS *CSPtr);

