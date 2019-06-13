//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMetricreportdefinition_V1_0_0_CSTRUCT_H_
#define _RedfishMetricreportdefinition_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMetricReportDefinition_V1_0_0_Metric_Array_CS RedfishMetricReportDefinition_V1_0_0_Metric_Array_CS;
typedef struct _RedfishMetricReportDefinition_V1_0_0_Wildcard_Array_CS RedfishMetricReportDefinition_V1_0_0_Wildcard_Array_CS;
typedef struct _RedfishMetricReportDefinition_V1_0_0_Actions_CS RedfishMetricReportDefinition_V1_0_0_Actions_CS;
typedef struct _RedfishMetricReportDefinition_V1_0_0_Metric_CS RedfishMetricReportDefinition_V1_0_0_Metric_CS;
typedef struct _RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS;
typedef struct _RedfishMetricReportDefinition_V1_0_0_OemActions_CS RedfishMetricReportDefinition_V1_0_0_OemActions_CS;
typedef struct _RedfishMetricReportDefinition_V1_0_0_Wildcard_CS RedfishMetricReportDefinition_V1_0_0_Wildcard_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishMetricReportDefinition_V1_0_0_Actions_CS {
    RedfishMetricReportDefinition_V1_0_0_OemActions_CS    *Oem;    // This property contains the
                                                                  // available OEM specific actions
                                                                  // for this resource.
} RedfishMetricReportDefinition_V1_0_0_Actions_CS;

//
// Specifies a metric to include in the metric report. The metrics are derived by
// applying a calculation on each of the listed metric properties.
//
typedef struct _RedfishMetricReportDefinition_V1_0_0_Metric_CS {
    RedfishCS_char          *CollectionDuration;    // Specifies the duration over
                                                    // which the function is
                                                    // computed.
    RedfishCS_char          *CollectionFunction;    // Specified the function to
                                                    // perform on each of the metric
                                                    // properties listed in the
                                                    // MetricProperties property.
    RedfishCS_char          *CollectionTimeScope;    // Specifies the scope of time
                                                    // scope over which the function
                                                    // is applied.
    RedfishCS_char          *MetricId;              // Specifies the label for the
                                                    // metric definition which is
                                                    // derived by applying the
                                                    // CollectionFunction to the
                                                    // metric property.
    RedfishCS_char_Array    *MetricProperties;      // A collection of URI for the
                                                    // properties on which this
                                                    // metric is collected.
} RedfishMetricReportDefinition_V1_0_0_Metric_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishMetricReportDefinition_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishMetricReportDefinition_V1_0_0_OemActions_CS;

//
// Contains a list of wildcards and their substitution values.
//
typedef struct _RedfishMetricReportDefinition_V1_0_0_Wildcard_CS {
    RedfishCS_char_Array    *Keys;    // An array of Key values to
                                     // substitute for the wildcard.
    RedfishCS_char          *Name;    // The name of Wildcard.
} RedfishMetricReportDefinition_V1_0_0_Wildcard_CS;

//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

//
// This type describes the status and health of a resource and its children.
//
#ifndef __RedfishResource_Status_CS__
#define __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS {
    RedfishCS_char            *Health;         // This represents the health
                                               // state of this resource in the
                                               // absence of its dependent
                                               // resources.
    RedfishCS_char            *HealthRollup;    // This represents the overall
                                               // health state from the view of
                                               // this resource.
    RedfishResource_Oem_CS    *Oem;            // Oem extension object.
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// A set of metrics that are collected into a metric report.
//
typedef struct _RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS {
    RedfishCS_Header                                          Header;
    RedfishCS_char                                            *odata_context;            
    RedfishCS_char                                            *odata_etag;               
    RedfishCS_char                                            *odata_id;                 
    RedfishCS_char                                            *odata_type;               
    RedfishMetricReportDefinition_V1_0_0_Actions_CS           *Actions;                      // The available actions for this
                                                                                             // resource.
    RedfishCS_int64                                           *AppendLimit;                  // Indicates the maximum number
                                                                                             // of entries that can be
                                                                                             // appended to a metric report.
                                                                                             // When the metric report reaches
                                                                                             // its limit, its behavior is
                                                                                             // dictated by the ReportUpdates
                                                                                             // property.
    RedfishCS_char                                            *Description;              
    RedfishCS_char                                            *Id;                       
    RedfishCS_char_Array                                      *MetricProperties;             // Specifies a list of metric
                                                                                             // properties to include in the
                                                                                             // metric report.
    RedfishCS_Link                                            MetricReport;                  // Specifies the location where
                                                                                             // the resultant metric report is
                                                                                             // placed.
    RedfishCS_char                                            *MetricReportDefinitionType;    // Specifies when the metric
                                                                                             // report is generated.
    RedfishMetricReportDefinition_V1_0_0_Metric_Array_CS      *Metrics;                      // Specifies a list of metrics to
                                                                                             // include in the metric report.
                                                                                             // The metrics may include metric
                                                                                             // properties or calculations
                                                                                             // applied to a metric property.
    RedfishCS_char                                            *Name;                     
    RedfishResource_Oem_CS                                    *Oem;                          // This is the
                                                                                             // manufacturer/provider specific
                                                                                             // extension moniker used to
                                                                                             // divide the Oem object into
                                                                                             // sections.
    RedfishCS_char_Array                                      *ReportActions;                // Specifies the actions to
                                                                                             // perform when a metric report
                                                                                             // is generated.
    RedfishCS_char                                            *ReportUpdates;                // When logging metric reports,
                                                                                             // specifies how subsequent
                                                                                             // metric reports are handled in
                                                                                             // relationship to an existing
                                                                                             // metric report created from the
                                                                                             // metric report definition.
                                                                                             // Namely, whether to overwrite,
                                                                                             // append, or create new report
                                                                                             // resource.
    RedfishCS_Link                                            Schedule;                      // Specifies the schedule for
                                                                                             // generating the metric report.
    RedfishResource_Status_CS                                 *Status;                       // This property describes the
                                                                                             // status and health of the
                                                                                             // resource and its children.
    RedfishMetricReportDefinition_V1_0_0_Wildcard_Array_CS    *Wildcards;                    // Specifies the strings used to
                                                                                             // replace wildcards in the paths
                                                                                             // in MetricProperties array
                                                                                             // property.
} RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS;

typedef struct _RedfishMetricReportDefinition_V1_0_0_Metric_Array_CS  {
    RedfishMetricReportDefinition_V1_0_0_Metric_Array_CS    *Next;
    RedfishMetricReportDefinition_V1_0_0_Metric_CS    *ArrayValue;
} RedfishMetricReportDefinition_V1_0_0_Metric_Array_CS;

typedef struct _RedfishMetricReportDefinition_V1_0_0_Wildcard_Array_CS  {
    RedfishMetricReportDefinition_V1_0_0_Wildcard_Array_CS    *Next;
    RedfishMetricReportDefinition_V1_0_0_Wildcard_CS    *ArrayValue;
} RedfishMetricReportDefinition_V1_0_0_Wildcard_Array_CS;

RedfishCS_status
Json_MetricReportDefinition_V1_0_0_To_CS (char *JsonRawText, RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS **ReturnedCS);

RedfishCS_status
CS_To_MetricReportDefinition_V1_0_0_JSON (RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMetricReportDefinition_V1_0_0_CS (RedfishMetricReportDefinition_V1_0_0_MetricReportDefinition_CS *CSPtr);

RedfishCS_status
DestroyMetricReportDefinition_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
