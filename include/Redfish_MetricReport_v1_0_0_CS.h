//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMetricreport_V1_0_0_CSTRUCT_H_
#define _RedfishMetricreport_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMetricReport_V1_0_0_MetricValue_Array_CS RedfishMetricReport_V1_0_0_MetricValue_Array_CS;
typedef struct _RedfishMetricReport_V1_0_0_Actions_CS RedfishMetricReport_V1_0_0_Actions_CS;
typedef struct _RedfishMetricReport_V1_0_0_MetricReport_CS RedfishMetricReport_V1_0_0_MetricReport_CS;
typedef struct _RedfishMetricReport_V1_0_0_MetricValue_CS RedfishMetricReport_V1_0_0_MetricValue_CS;
typedef struct _RedfishMetricReport_V1_0_0_OemActions_CS RedfishMetricReport_V1_0_0_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishMetricReport_V1_0_0_Actions_CS {
    RedfishMetricReport_V1_0_0_OemActions_CS    *Oem;    // This property contains the
                                                        // available OEM specific actions
                                                        // for this resource.
} RedfishMetricReport_V1_0_0_Actions_CS;

//
// A metric Value.
//
typedef struct _RedfishMetricReport_V1_0_0_MetricValue_CS {
    RedfishCS_Link    MetricDefinition;    // A link to the Metric
                                          // Definition.
    RedfishCS_char    *MetricId;          // The metric definitions
                                          // identifier for this metric.
    RedfishCS_char    *MetricProperty;    // The URI for the property from
                                          // which this metric is derived.
    RedfishCS_char    *MetricValue;       // The value identifies this
                                          // resource.
    RedfishCS_char    *Timestamp;         // The time when the value of the
                                          // metric is obtained.
} RedfishMetricReport_V1_0_0_MetricValue_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishMetricReport_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishMetricReport_V1_0_0_OemActions_CS;

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
// The metric definitions used to create a metric report.
//
typedef struct _RedfishMetricReport_V1_0_0_MetricReport_CS {
    RedfishCS_Header                                   Header;
    RedfishCS_char                                     *odata_context;       
    RedfishCS_char                                     *odata_etag;          
    RedfishCS_char                                     *odata_id;            
    RedfishCS_char                                     *odata_type;          
    RedfishMetricReport_V1_0_0_Actions_CS              *Actions;                 // The available actions for this
                                                                                 // resource.
    RedfishCS_char                                     *Description;         
    RedfishCS_char                                     *Id;                  
    RedfishCS_Link                                     MetricReportDefinition;    // The metric definitions used to
                                                                                 // create a metric report.
    RedfishMetricReport_V1_0_0_MetricValue_Array_CS    *MetricValues;            // An array of metric values for
                                                                                 // the metered items of this
                                                                                 // Metric.
    RedfishCS_char                                     *Name;                
    RedfishResource_Oem_CS                             *Oem;                     // This is the
                                                                                 // manufacturer/provider specific
                                                                                 // extension moniker used to
                                                                                 // divide the Oem object into
                                                                                 // sections.
    RedfishCS_char                                     *ReportSequence;          // The current sequence
                                                                                 // identifier for this metric
                                                                                 // report.
} RedfishMetricReport_V1_0_0_MetricReport_CS;

typedef struct _RedfishMetricReport_V1_0_0_MetricValue_Array_CS  {
    RedfishMetricReport_V1_0_0_MetricValue_Array_CS    *Next;
    RedfishMetricReport_V1_0_0_MetricValue_CS    *ArrayValue;
} RedfishMetricReport_V1_0_0_MetricValue_Array_CS;

RedfishCS_status
Json_MetricReport_V1_0_0_To_CS (char *JsonRawText, RedfishMetricReport_V1_0_0_MetricReport_CS **ReturnedCS);

RedfishCS_status
CS_To_MetricReport_V1_0_0_JSON (RedfishMetricReport_V1_0_0_MetricReport_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMetricReport_V1_0_0_CS (RedfishMetricReport_V1_0_0_MetricReport_CS *CSPtr);

RedfishCS_status
DestroyMetricReport_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
