# Definition of Manager.V1_2_3 and functions<br><br>

## CommandShell
    typedef struct _RedfishManager_V1_2_3_CommandShell_CS {
        RedfishCS_char_Array *ConnectTypesSupported;
        RedfishCS_int64 *MaxConcurrentSessions;
        RedfishCS_bool *ServiceEnabled;
    } RedfishManager_V1_2_3_CommandShell_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ConnectTypesSupported**|RedfishCS_char_Array| Structure array points to one or more than one **RedfishCS_char *** for property **ConnectTypesSupported**.| No| Yes
|**MaxConcurrentSessions**|RedfishCS_int64| 64-bit long long interger pointer to **MaxConcurrentSessions** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No


## ForceFailover
    typedef struct _RedfishManager_V1_2_3_ForceFailover_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishManager_V1_2_3_ForceFailover_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## GraphicalConsole
    typedef struct _RedfishManager_V1_2_3_GraphicalConsole_CS {
        RedfishCS_char_Array *ConnectTypesSupported;
        RedfishCS_int64 *MaxConcurrentSessions;
        RedfishCS_bool *ServiceEnabled;
    } RedfishManager_V1_2_3_GraphicalConsole_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ConnectTypesSupported**|RedfishCS_char_Array| Structure array points to one or more than one **RedfishCS_char *** for property **ConnectTypesSupported**.| No| Yes
|**MaxConcurrentSessions**|RedfishCS_int64| 64-bit long long interger pointer to **MaxConcurrentSessions** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No


## Manager_Actions
    typedef struct _RedfishManager_V1_2_3_Manager_Actions_CS {
        RedfishManager_V1_2_3_ForceFailover_CS *Manager_ForceFailover;
        RedfishManager_V1_2_3_ModifyRedundancySet_CS *Manager_ModifyRedundancySet;
        RedfishManager_V1_2_3_Reset_CS *Manager_Reset;
        RedfishManager_V1_2_3_Manager_Actions_Oem_CS *Oem;
    } RedfishManager_V1_2_3_Manager_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Manager_ForceFailover**|RedfishManager_V1_2_3_ForceFailover_CS| Structure points to **#Manager.ForceFailover** property.| No| No
|**Manager_ModifyRedundancySet**|RedfishManager_V1_2_3_ModifyRedundancySet_CS| Structure points to **#Manager.ModifyRedundancySet** property.| No| No
|**Manager_Reset**|RedfishManager_V1_2_3_Reset_CS| Structure points to **#Manager.Reset** property.| No| No
|**Oem**|RedfishManager_V1_2_3_Manager_Actions_Oem_CS| Structure points to **Oem** property.| No| No


## Manager_Actions_Oem
    typedef struct _RedfishManager_V1_2_3_Manager_Actions_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishManager_V1_2_3_Manager_Actions_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Manager_Links
    typedef struct _RedfishManager_V1_2_3_Manager_Links_CS {
        RedfishCS_Link ManagerForChassis;
        RedfishCS_int64 *ManagerForChassisodata_count;
        RedfishCS_char *ManagerForChassisodata_navigationLink;
        RedfishCS_Link ManagerForServers;
        RedfishCS_int64 *ManagerForServersodata_count;
        RedfishCS_char *ManagerForServersodata_navigationLink;
        RedfishCS_Link ManagerInChassis;
        RedfishResource_Oem_CS *Oem;
    } RedfishManager_V1_2_3_Manager_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ManagerForChassis**|RedfishCS_Link| Structure link list to **ManagerForChassis** property.| No| Yes
|**ManagerForChassisodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ManagerForChassis@odata.count** property.| No| No
|**ManagerForChassisodata_navigationLink**|RedfishCS_char| String pointer to **ManagerForChassis@odata.navigationLink** property.| No| No
|**ManagerForServers**|RedfishCS_Link| Structure link list to **ManagerForServers** property.| No| Yes
|**ManagerForServersodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **ManagerForServers@odata.count** property.| No| No
|**ManagerForServersodata_navigationLink**|RedfishCS_char| String pointer to **ManagerForServers@odata.navigationLink** property.| No| No
|**ManagerInChassis**|RedfishCS_Link| Structure link list to **ManagerInChassis** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No


## ModifyRedundancySet
    typedef struct _RedfishManager_V1_2_3_ModifyRedundancySet_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishManager_V1_2_3_ModifyRedundancySet_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## Reset
    typedef struct _RedfishManager_V1_2_3_Reset_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishManager_V1_2_3_Reset_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## SerialConsole
    typedef struct _RedfishManager_V1_2_3_SerialConsole_CS {
        RedfishCS_char_Array *ConnectTypesSupported;
        RedfishCS_int64 *MaxConcurrentSessions;
        RedfishCS_bool *ServiceEnabled;
    } RedfishManager_V1_2_3_SerialConsole_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**ConnectTypesSupported**|RedfishCS_char_Array| Structure array points to one or more than one **RedfishCS_char *** for property **ConnectTypesSupported**.| No| Yes
|**MaxConcurrentSessions**|RedfishCS_int64| 64-bit long long interger pointer to **MaxConcurrentSessions** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No


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


## RedfishCS_char_Array
    typedef struct _RedfishCS_char_Array  {
        RedfishCS_Link *Next;
        RedfishCS_char *ArrayValue;
    } RedfishCS_char_Array;



## Manager
    typedef struct _RedfishManager_V1_2_3_Manager_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishManager_V1_2_3_Manager_Actions_CS *Actions;
        RedfishManager_V1_2_3_CommandShell_CS *CommandShell;
        RedfishCS_char *DateTime;
        RedfishCS_char *DateTimeLocalOffset;
        RedfishCS_char *Description;
        RedfishCS_Link EthernetInterfaces;
        RedfishCS_char *FirmwareVersion;
        RedfishManager_V1_2_3_GraphicalConsole_CS *GraphicalConsole;
        RedfishCS_char *Id;
        RedfishManager_V1_2_3_Manager_Links_CS *Links;
        RedfishCS_Link LogServices;
        RedfishCS_char *ManagerType;
        RedfishCS_char *Model;
        RedfishCS_char *Name;
        RedfishCS_Link NetworkProtocol;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *PowerState;
        RedfishCS_Link Redundancy;
        RedfishCS_int64 *Redundancyodata_count;
        RedfishCS_char *Redundancyodata_navigationLink;
        RedfishManager_V1_2_3_SerialConsole_CS *SerialConsole;
        RedfishCS_Link SerialInterfaces;
        RedfishCS_char *ServiceEntryPointUUID;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *UUID;
        RedfishCS_Link VirtualMedia;
    } RedfishManager_V1_2_3_Manager_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Actions**|RedfishManager_V1_2_3_Manager_Actions_CS| Structure points to **Actions** property.| No| No
|**CommandShell**|RedfishManager_V1_2_3_CommandShell_CS| Structure points to **CommandShell** property.| No| No
|**DateTime**|RedfishCS_char| String pointer to **DateTime** property.| No| No
|**DateTimeLocalOffset**|RedfishCS_char| String pointer to **DateTimeLocalOffset** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**EthernetInterfaces**|RedfishCS_Link| Structure link list to **EthernetInterfaces** property.| No| Yes
|**FirmwareVersion**|RedfishCS_char| String pointer to **FirmwareVersion** property.| No| Yes
|**GraphicalConsole**|RedfishManager_V1_2_3_GraphicalConsole_CS| Structure points to **GraphicalConsole** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishManager_V1_2_3_Manager_Links_CS| Structure points to **Links** property.| No| No
|**LogServices**|RedfishCS_Link| Structure link list to **LogServices** property.| No| Yes
|**ManagerType**|RedfishCS_char| String pointer to **ManagerType** property.| No| Yes
|**Model**|RedfishCS_char| String pointer to **Model** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**NetworkProtocol**|RedfishCS_Link| Structure link list to **NetworkProtocol** property.| No| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PowerState**|RedfishCS_char| String pointer to **PowerState** property.| No| Yes
|**Redundancy**|RedfishCS_Link| Structure link list to **Redundancy** property.| No| No
|**Redundancyodata_count**|RedfishCS_int64| 64-bit long long interger pointer to **Redundancy@odata.count** property.| No| No
|**Redundancyodata_navigationLink**|RedfishCS_char| String pointer to **Redundancy@odata.navigationLink** property.| No| No
|**SerialConsole**|RedfishManager_V1_2_3_SerialConsole_CS| Structure points to **SerialConsole** property.| No| No
|**SerialInterfaces**|RedfishCS_Link| Structure link list to **SerialInterfaces** property.| No| Yes
|**ServiceEntryPointUUID**|RedfishCS_char| String pointer to **ServiceEntryPointUUID** property.| No| Yes
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**UUID**|RedfishCS_char| String pointer to **UUID** property.| No| Yes
|**VirtualMedia**|RedfishCS_Link| Structure link list to **VirtualMedia** property.| No| Yes
## Redfish Manager V1_2_3 to C Structure Function
    RedfishCS_status
    Json_Manager_V1_2_3_To_CS (RedfishCS_char *JsonRawText, RedfishManager_V1_2_3_Manager_CS **ReturnedCS);

## C Structure to Redfish Manager V1_2_3 JSON Function
    RedfishCS_status
    CS_To_Manager_V1_2_3_JSON (RedfishManager_V1_2_3_Manager_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish Manager V1_2_3 C Structure Function
    RedfishCS_status
    DestroyManager_V1_2_3_CS (RedfishManager_V1_2_3_Manager_CS *CSPtr);

