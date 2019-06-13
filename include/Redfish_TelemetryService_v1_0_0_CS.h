//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishTelemetryservice_V1_0_0_CSTRUCT_H_
#define _RedfishTelemetryservice_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishTelemetryService_V1_0_0_Actions_CS RedfishTelemetryService_V1_0_0_Actions_CS;
typedef struct _RedfishTelemetryService_V1_0_0_OemActions_CS RedfishTelemetryService_V1_0_0_OemActions_CS;
typedef struct _RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS;
typedef struct _RedfishTelemetryService_V1_0_0_TelemetryService_CS RedfishTelemetryService_V1_0_0_TelemetryService_CS;
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
// The available actions for this resource.
//
typedef struct _RedfishTelemetryService_V1_0_0_Actions_CS {
    RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS    *TelemetryService_SubmitTestMetricReport;
    RedfishTelemetryService_V1_0_0_OemActions_CS                *Oem;                                       // This property contains the
                                                                                                            // available OEM specific actions
                                                                                                            // for this resource.
} RedfishTelemetryService_V1_0_0_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishTelemetryService_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishTelemetryService_V1_0_0_OemActions_CS;

//
// This action is used to generate a metric report.
//
typedef struct _RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishTelemetryService_V1_0_0_SubmitTestMetricReport_CS;

//
// This is the schema definition for the Metrics Service.  It represents the
// properties for the service itself and has links to collections of metric
// definitions and metric report definitions.
//
typedef struct _RedfishTelemetryService_V1_0_0_TelemetryService_CS {
    RedfishCS_Header                             Header;
    RedfishCS_char                               *odata_context;              
    RedfishCS_char                               *odata_etag;                 
    RedfishCS_char                               *odata_id;                   
    RedfishCS_char                               *odata_type;                 
    RedfishTelemetryService_V1_0_0_Actions_CS    *Actions;                        // The available actions for this
                                                                                  // resource.
    RedfishCS_char                               *Description;                
    RedfishCS_char                               *Id;                         
    RedfishCS_Link                               LogService;                      // This is a reference to a Log
                                                                                  // Service used by the Telemetry
                                                                                  // Service.
    RedfishCS_int64                              *MaxReports;                     // The maximum number of metric
                                                                                  // reports supported by this
                                                                                  // service.
    RedfishCS_Link                               MetricDefinitions;               // A link to the collection of
                                                                                  // Metric Definitions.
    RedfishCS_Link                               MetricReportDefinitions;         // A link to the collection of
                                                                                  // Metric Report Definitions.
    RedfishCS_Link                               MetricReports;                   // A link to the collection of
                                                                                  // Metric Reports.
    RedfishCS_char                               *MinCollectionInterval;          // The minimum time interval
                                                                                  // between collections supported
                                                                                  // by this service.
    RedfishCS_char                               *Name;                       
    RedfishResource_Oem_CS                       *Oem;                            // This is the
                                                                                  // manufacturer/provider specific
                                                                                  // extension moniker used to
                                                                                  // divide the Oem object into
                                                                                  // sections.
    RedfishResource_Status_CS                    *Status;                         // This property describes the
                                                                                  // status and health of the
                                                                                  // resource and its children.
    RedfishCS_char_Array                         *SupportedCollectionFunctions;    // The functions that can be
                                                                                  // performed over each metric.
    RedfishCS_Link                               Triggers;                        // A link to the collection of
                                                                                  // Triggers, which apply to
                                                                                  // metrics.
} RedfishTelemetryService_V1_0_0_TelemetryService_CS;

RedfishCS_status
Json_TelemetryService_V1_0_0_To_CS (char *JsonRawText, RedfishTelemetryService_V1_0_0_TelemetryService_CS **ReturnedCS);

RedfishCS_status
CS_To_TelemetryService_V1_0_0_JSON (RedfishTelemetryService_V1_0_0_TelemetryService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyTelemetryService_V1_0_0_CS (RedfishTelemetryService_V1_0_0_TelemetryService_CS *CSPtr);

RedfishCS_status
DestroyTelemetryService_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
