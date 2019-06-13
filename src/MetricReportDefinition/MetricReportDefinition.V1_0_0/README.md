# Definition of MetricReportDefinition.V1_0_0 and functions<br><br>

## Actions
    typedef struct _RedfishMetricReportDefinition_V1_0_0_Actions_CS {
        RedfishMetricReportDefinition_V1_0_0_OemActions_CS *Oem;
    } RedfishMetricReportDefinition_V1_0_0_Actions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Oem**|RedfishMetricReportDefinition_V1_0_0_OemActions_CS| Structure points to **Oem** property.| No| No


## Metric
    typedef struct _RedfishMetricReportDefinition_V1_0_0_Metric_CS {
        RedfishCS_char *CollectionDuration;
        RedfishCS_char *CollectionFunction;
        RedfishCS_char *CollectionTimeScope;
        RedfishCS_char *MetricId;
        RedfishCS_char_Array *MetricProperties;
    } RedfishMetricReportDefinition_V1_0_0_Metric_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**CollectionDuration**|RedfishCS_char| String pointer to **CollectionDuration** property.| No| No
|**CollectionFunction**|RedfishCS_char| String pointer to **CollectionFunction** property.| No| No
|**CollectionTimeScope**|RedfishCS_char| String pointer to **CollectionTimeScope** property.| No| No
|**MetricId**|RedfishCS_char| String pointer to **MetricId** property.| No| Yes
|**MetricProperties**|RedfishCS_char_Array| Structure array points to one or more than one **RedfishCS_char *** for property **MetricProperties**.| No| No


## OemActions
    typedef struct _RedfishMetricReportDefinition_V1_0_0_OemActions_CS {
        RedfishCS_Link Prop;
    } RedfishMetricReportDefinition_V1_0_0_OemActions_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Prop**|RedfishCS_Link| Structure link list to OEM defined property| ---| ---


## Wildcard
    typedef struct _RedfishMetricReportDefinition_V1_0_0_Wildcard_CS {
        RedfishCS_char_Array *Keys;
        RedfishCS_char *Name;
    } RedfishMetricReportDefinition_V1_0_0_Wildcard_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Keys**|RedfishCS_char_Array| Structure array points to one or more than one **RedfishCS_char *** for property **Keys**.| No| Yes
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes


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



## MetricReportDefinition
    typedef struct _RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS {
        RedfishCS_Header     Header;
        RedfishCS_char *odata_context;
        RedfishCS_char *odata_etag;
        RedfishCS_char *odata_id;
        RedfishCS_char *odata_type;
        RedfishMetricReportDefinition_V1_0_0_Actions_CS *Actions;
        RedfishCS_int64 *AppendLimit;
        RedfishCS_char *Description;
        RedfishCS_char *Id;
        RedfishCS_char *MetricProperties;
        RedfishCS_Link MetricReport;
        RedfishCS_char *MetricReportDefinitionType;
        RedfishMetricReportDefinition_V1_0_0_Metric_CS *Metrics;
        RedfishCS_char *Name;
        RedfishResource_Oem_CS *Oem;
        RedfishCS_char *ReportActions;
        RedfishCS_char *ReportUpdates;
        RedfishCS_Link Schedule;
        RedfishResource_Status_CS *Status;
        RedfishMetricReportDefinition_V1_0_0_Wildcard_CS *Wildcards;
    } RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS;

|Field |C Structure Data Type|Description |Required Property|Read only Property
| ---  | --- | --- | --- | ---
|**Header**|RedfishCS_Header|Redfish C structure header|---|---
|**odata_context**|RedfishCS_char| String pointer to **@odata.context** property.| No| No
|**odata_etag**|RedfishCS_char| String pointer to **@odata.etag** property.| No| No
|**odata_id**|RedfishCS_char| String pointer to **@odata.id** property.| Yes| No
|**odata_type**|RedfishCS_char| String pointer to **@odata.type** property.| Yes| No
|**Actions**|RedfishMetricReportDefinition_V1_0_0_Actions_CS| Structure points to **Actions** property.| No| No
|**AppendLimit**|RedfishCS_int64| 64-bit long long interger pointer to **AppendLimit** property.| No| Yes
|**Description**|RedfishCS_char| String pointer to **Description** property.| No| Yes
|**Id**|RedfishCS_char| String pointer to **Id** property.| Yes| Yes
|**MetricProperties**|RedfishCS_char| String pointer to **MetricProperties** property.| No| No
|**MetricReport**|RedfishCS_Link| Structure link list to **MetricReport** property.| No| Yes
|**MetricReportDefinitionType**|RedfishCS_char| String pointer to **MetricReportDefinitionType** property.| No| No
|**Metrics**|RedfishMetricReportDefinition_V1_0_0_Metric_CS| Structure points to **Metrics** property.| No| No
|**Name**|RedfishCS_char| String pointer to **Name** property.| Yes| Yes
|**Oem**|RedfishResource_Oem_CS| Structure points to **Oem** property.| No| No
|**ReportActions**|RedfishCS_char| String pointer to **ReportActions** property.| No| Yes
|**ReportUpdates**|RedfishCS_char| String pointer to **ReportUpdates** property.| No| Yes
|**Schedule**|RedfishCS_Link| Structure link list to **Schedule** property.| No| No
|**Status**|RedfishResource_Status_CS| Structure points to **Status** property.| No| No
|**Wildcards**|RedfishMetricReportDefinition_V1_0_0_Wildcard_CS| Structure points to **Wildcards** property.| No| No
## Redfish MetricReportDefinition V1_0_0 to C Structure Function
    RedfishCS_status
    Json_MetricReportDefinition_V1_0_0_To_CS (RedfishCS_char *JsonRawText, RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS **ReturnedCS);

## C Structure to Redfish MetricReportDefinition V1_0_0 JSON Function
    RedfishCS_status
    CS_To_MetricReportDefinition_V1_0_0_JSON (RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS *CSPtr, RedfishCS_char **JsonText);

## Destory Redfish MetricReportDefinition V1_0_0 C Structure Function
    RedfishCS_status
    DestroyMetricReportDefinition_V1_0_0_CS (RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS *CSPtr);

