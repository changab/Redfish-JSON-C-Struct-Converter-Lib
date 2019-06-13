# Definition of HostInterface.V1_1_3 and functions<br><br>

## Actions
    typedef struct _RedfishHostInterface_V1_1_3_Actions_CS {
        RedfishHostInterface_V1_1_3_OemActions_CS *Oem;
    } RedfishHostInterface_V1_1_3_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishHostInterface_V1_1_3_OemActions_CS| Structure points to **Oem** property.| No| No


## Links
    typedef struct _RedfishHostInterface_V1_1_3_Links_CS {
        RedfishCS_Link ComputerSystems;
        RedfishCS_int64 *ComputerSystemsodata_count;
        RedfishCS_Link FirmwareAuthRole;
        RedfishCS_Link KernelAuthRole;
        RedfishResource_Oem_CS *Oem;
    } RedfishHostInterface_V1_1_3_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ComputerSystems**|RedfishCS_Link| Structure link list to **ComputerSystems** property.| No| Yes
|**ComputerSystemsodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ComputerSystems@odata.count** property.| No| No
|**FirmwareAuthRole**|RedfishCS_Link| Structure link list to **FirmwareAuthRole** property.| No| Yes
|**KernelAuthRole**|RedfishCS_Link| Structure link list to **KernelAuthRole** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishHostInterface_V1_1_3_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishHostInterface_V1_1_3_OemActions_CS;

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


## HostInterface
    typedef struct _RedfishHostInterface_V1_1_3_HostInterface_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishHostInterface_V1_1_3_Actions_CS *Actions;
        RedfishCS_char *AuthenticationModes;
        RedfishCS_char *Description;
        RedfishCS_bool *ExternallyAccessible;
        RedfishCS_bool *FirmwareAuthEnabled;
        RedfishCS_char *FirmwareAuthRoleId;
        RedfishCS_Link HostEthernetInterfaces;
        RedfishCS_char *HostInterfaceType;
        RedfishCS_char *Id;
        RedfishCS_bool *InterfaceEnabled;
        RedfishCS_bool *KernelAuthEnabled;
        RedfishCS_char *KernelAuthRoleId;
        RedfishHostInterface_V1_1_3_Links_CS *Links;
        RedfishCS_Link ManagerEthernetInterface;
        RedfishCS_char *Name;
        RedfishCS_Link NetworkProtocol;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
    } RedfishHostInterface_V1_1_3_HostInterface_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishHostInterface_V1_1_3_Actions_CS| Structure points to **Actions** property.| No| No
|**AuthenticationModes**|RedfishCS_char| String pointer to **AuthenticationModes** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**ExternallyAccessible**|RedfishCS_bool| Boolean pointer to **ExternallyAccessible** property.| No| Yes
|**FirmwareAuthEnabled**|RedfishCS_bool| Boolean pointer to **FirmwareAuthEnabled** property.| No| No
|**FirmwareAuthRoleId**|RedfishCS_char| String pointer to **FirmwareAuthRoleId** property.| No| No
|**HostEthernetInterfaces**|RedfishCS_Link| Structure link list to **HostEthernetInterfaces** property.| No| Yes
|**HostInterfaceType**|RedfishCS_char| String pointer to **HostInterfaceType** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**InterfaceEnabled**|RedfishCS_bool| Boolean pointer to **InterfaceEnabled** property.| No| No
|**KernelAuthEnabled**|RedfishCS_bool| Boolean pointer to **KernelAuthEnabled** property.| No| No
|**KernelAuthRoleId**|RedfishCS_char| String pointer to **KernelAuthRoleId** property.| No| No
|**Links**|RedfishHostInterface_V1_1_3_Links_CS| Structure points to **Links** property.| No| No
|**ManagerEthernetInterface**|RedfishCS_Link| Structure link list to **ManagerEthernetInterface** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetworkProtocol**|RedfishCS_Link| Structure link list to **NetworkProtocol** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish HostInterface V1_1_3 to C Structure Function
    RedfishCS_status
    Json_HostInterface_V1_1_3_To_CS (RedfishCS_char *JsonRawText, RedfishHostInterface_V1_1_3_HostInterface_CS **ReturnedCS);

## C Structure to Redfish HostInterface V1_1_3 JSON Function
    RedfishCS_status
    CS_To_HostInterface_V1_1_3_JSON (RedfishHostInterface_V1_1_3_HostInterface_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish HostInterface V1_1_3 C Structure Function
    RedfishCS_status
    DestroyHostInterface_V1_1_3_CS (RedfishHostInterface_V1_1_3_HostInterface_CS *CSPtr);
