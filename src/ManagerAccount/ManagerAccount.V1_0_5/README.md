# Definition of ManagerAccount.V1_0_5 and functions<br><br>

## ManagerAccount_Links
    typedef struct _RedfishManagerAccount_V1_0_5_ManagerAccount_Links_CS {
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link Role;
    } RedfishManagerAccount_V1_0_5_ManagerAccount_Links_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Role**|RedfishCS_Link| Structure link list to **Role** property.| No| Yes


## Oem
    typedef struct _RedfishResource_Oem_CS {
        RedfishCS_Link Prop;
    } RedfishResource_Oem_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## ManagerAccount
    typedef struct _RedfishManagerAccount_V1_0_5_ManagerAccount_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_char *Description;
        RedfishCS_bool *Enabled;
        RedfishCS_char *Id;
        RedfishManagerAccount_V1_0_5_ManagerAccount_Links_CS *Links;
        RedfishCS_bool *Locked;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *Password;
        RedfishCS_char *RoleId;
        RedfishCS_char *UserName;
    } RedfishManagerAccount_V1_0_5_ManagerAccount_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| No| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Enabled**|RedfishCS_bool| Boolean pointer to **Enabled** property.| No| No
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**Links**|RedfishManagerAccount_V1_0_5_ManagerAccount_Links_CS| Structure points to **Links** property.| No| No
|**Locked**|RedfishCS_bool| Boolean pointer to **Locked** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Password**|RedfishCS_char| String pointer to **Password** property.| No| No
|**RoleId**|RedfishCS_char| String pointer to **RoleId** property.| No| No
|**UserName**|RedfishCS_char| String pointer to **UserName** property.| No| No
## Redfish ManagerAccount V1_0_5 to C Structure Function
    RedfishCS_status
    Json_ManagerAccount_V1_0_5_To_CS (RedfishCS_char *JsonRawText, RedfishManagerAccount_V1_0_5_ManagerAccount_CS **ReturnedCS);

## C Structure to Redfish ManagerAccount V1_0_5 JSON Function
    RedfishCS_status
    CS_To_ManagerAccount_V1_0_5_JSON (RedfishManagerAccount_V1_0_5_ManagerAccount_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish ManagerAccount V1_0_5 C Structure Function
    RedfishCS_status
    DestroyManagerAccount_V1_0_5_CS (RedfishManagerAccount_V1_0_5_ManagerAccount_CS *CSPtr);

