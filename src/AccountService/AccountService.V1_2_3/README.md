# Definition of AccountService.V1_2_3 and functions<br><br>

## Actions
    typedef struct _RedfishAccountService_V1_2_3_Actions_CS {
        RedfishAccountService_V1_2_3_OemActions_CS *Oem;
    } RedfishAccountService_V1_2_3_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishAccountService_V1_2_3_OemActions_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishAccountService_V1_2_3_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishAccountService_V1_2_3_OemActions_CS;

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


## AccountService
    typedef struct _RedfishAccountService_V1_2_3_AccountService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishCS_int64 *AccountLockoutCounterResetAfter;
        RedfishCS_int64 *AccountLockoutDuration;
        RedfishCS_int64 *AccountLockoutThreshold;
        RedfishCS_Link Accounts;
        RedfishAccountService_V1_2_3_Actions_CS *Actions;
        RedfishCS_int64 *AuthFailureLoggingThreshold;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_int64 *MaxPasswordLength;
        RedfishCS_int64 *MinPasswordLength;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_Link PrivilegeMap;
        RedfishCS_Link Roles;
        RedfishCS_bool *ServiceEnabled;
        RedfishResource_Status_CS *Status;
    } RedfishAccountService_V1_2_3_AccountService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**AccountLockoutCounterResetAfter**|RedfishCS_int64| 64-bit long long interger pointer to **AccountLockoutCounterResetAfter** property.| No| No
|**AccountLockoutDuration**|RedfishCS_int64| 64-bit long long interger pointer to **AccountLockoutDuration** property.| No| No
|**AccountLockoutThreshold**|RedfishCS_int64| 64-bit long long interger pointer to **AccountLockoutThreshold** property.| No| No
|**Accounts**|RedfishCS_Link| Structure link list to **Accounts** property.| No| Yes
|**Actions**|RedfishAccountService_V1_2_3_Actions_CS| Structure points to **Actions** property.| No| No
|**AuthFailureLoggingThreshold**|RedfishCS_int64| 64-bit long long interger pointer to **AuthFailureLoggingThreshold** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**MaxPasswordLength**|RedfishCS_int64| 64-bit long long interger pointer to **MaxPasswordLength** property.| No| Yes
|**MinPasswordLength**|RedfishCS_int64| 64-bit long long interger pointer to **MinPasswordLength** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**PrivilegeMap**|RedfishCS_Link| Structure link list to **PrivilegeMap** property.| No| Yes
|**Roles**|RedfishCS_Link| Structure link list to **Roles** property.| No| Yes
|**ServiceEnabled**|RedfishCS_bool| Boolean pointer to **ServiceEnabled** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
## Redfish AccountService V1_2_3 to C Structure Function
    RedfishCS_status
    Json_AccountService_V1_2_3_To_CS (RedfishCS_char *JsonRawText, RedfishAccountService_V1_2_3_AccountService_CS **ReturnedCS);

## C Structure to Redfish AccountService V1_2_3 JSON Function
    RedfishCS_status
    CS_To_AccountService_V1_2_3_JSON (RedfishAccountService_V1_2_3_AccountService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish AccountService V1_2_3 C Structure Function
    RedfishCS_status
    DestroyAccountService_V1_2_3_CS (RedfishAccountService_V1_2_3_AccountService_CS *CSPtr);

