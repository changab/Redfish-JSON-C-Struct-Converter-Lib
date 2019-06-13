# Definition of TelemetryService.V1_0_0 and functions<br><br>

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
    typedef struct _RedfishTelemetryService_V1_0_0_Actions_CS {
        RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS *TelemetryService_SubmitTestMetricReport;
        RedfishTelemetryService_V1_0_0_OemActions_CS *Oem;
    } RedfishTelemetryService_V1_0_0_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**TelemetryService_SubmitTestMetricReport**|RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS| Structure points to **#TelemetryService.SubmitTestMetricReport** property.| No| No
|**Oem**|RedfishTelemetryService_V1_0_0_OemActions_CS| Structure points to **Oem** property.| No| No


## OemActions
    typedef struct _RedfishTelemetryService_V1_0_0_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishTelemetryService_V1_0_0_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## SubmitTestMetricReport
    typedef struct _RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS {
        RedfishCS_char *target;
        RedfishCS_char *title;
    } RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**target**|RedfishCS_char| String pointer to **target** property.| No| No
|**title**|RedfishCS_char| String pointer to **title** property.| No| No


## TelemetryService
    typedef struct _RedfishTelemetryService_V1_0_0_TelemetryService_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishTelemetryService_V1_0_0_Actions_CS *Actions;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_Link LogService;
        RedfishCS_int64 *MaxReports;
        RedfishCS_Link MetricDefinitions;
        RedfishCS_Link MetricReportDefinitions;
        RedfishCS_Link MetricReports;
        RedfishCS_char *MinCollectionInterval;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishResource_Status_CS *Status;
        RedfishCS_char *SupportedCollectionFunctions;
        RedfishCS_Link Triggers;
    } RedfishTelemetryService_V1_0_0_TelemetryService_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishTelemetryService_V1_0_0_Actions_CS| Structure points to **Actions** property.| No| No
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**LogService**|RedfishCS_Link| Structure link list to **LogService** property.| No| Yes
|**MaxReports**|RedfishCS_int64| 64-bit long long interger pointer to **MaxReports** property.| No| Yes
|**MetricDefinitions**|RedfishCS_Link| Structure link list to **MetricDefinitions** property.| No| Yes
|**MetricReportDefinitions**|RedfishCS_Link| Structure link list to **MetricReportDefinitions** property.| No| Yes
|**MetricReports**|RedfishCS_Link| Structure link list to **MetricReports** property.| No| Yes
|**MinCollectionInterval**|RedfishCS_char| String pointer to **MinCollectionInterval** property.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**SupportedCollectionFunctions**|RedfishCS_char| String pointer to **SupportedCollectionFunctions** property.| No| No
|**Triggers**|RedfishCS_Link| Structure link list to **Triggers** property.| No| Yes
## Redfish TelemetryService V1_0_0 to C Structure Function
    RedfishCS_status
    Json_TelemetryService_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishTelemetryService_V1_0_0_TelemetryService_CS **ReturnedCS);

## C Structure to Redfish TelemetryService V1_0_0 JSON Function
    RedfishCS_status
    CS_To_TelemetryService_V1_0_0_JSON (RedfishTelemetryService_V1_0_0_TelemetryService_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish TelemetryService V1_0_0 C Structure Function
    RedfishCS_status
    DestroyTelemetryService_V1_0_0_CS (RedfishTelemetryService_V1_0_0_TelemetryService_CS *CSPtr);

