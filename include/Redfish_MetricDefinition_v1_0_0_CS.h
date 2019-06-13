//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMetricdefinition_V1_0_0_CSTRUCT_H_
#define _RedfishMetricdefinition_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMetricDefinition_V1_0_0_CalculationParamsType_Array_CS RedfishMetricDefinition_V1_0_0_CalculationParamsType_Array_CS;
typedef struct _RedfishMetricDefinition_V1_0_0_Wildcard_Array_CS RedfishMetricDefinition_V1_0_0_Wildcard_Array_CS;
typedef struct _RedfishMetricDefinition_V1_0_0_Actions_CS RedfishMetricDefinition_V1_0_0_Actions_CS;
typedef struct _RedfishMetricDefinition_V1_0_0_CalculationParamsType_CS RedfishMetricDefinition_V1_0_0_CalculationParamsType_CS;
typedef struct _RedfishMetricDefinition_V1_0_0_MetricDefinition_CS RedfishMetricDefinition_V1_0_0_MetricDefinition_CS;
typedef struct _RedfishMetricDefinition_V1_0_0_OemActions_CS RedfishMetricDefinition_V1_0_0_OemActions_CS;
typedef struct _RedfishMetricDefinition_V1_0_0_Wildcard_CS RedfishMetricDefinition_V1_0_0_Wildcard_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishMetricDefinition_V1_0_0_Actions_CS {
    RedfishMetricDefinition_V1_0_0_OemActions_CS    *Oem;    // This property contains the
                                                            // available OEM specific actions
                                                            // for this resource.
} RedfishMetricDefinition_V1_0_0_Actions_CS;

//
// Specifies the usage of the parameter in the calculation.
//
typedef struct _RedfishMetricDefinition_V1_0_0_CalculationParamsType_CS {
    RedfishCS_char    *ResultMetric;    // The metric property used to
                                       // store the results of the
                                       // calculation.
    RedfishCS_char    *SourceMetric;    // The metric property used as
                                       // the input into the
                                       // calculation.
} RedfishMetricDefinition_V1_0_0_CalculationParamsType_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishMetricDefinition_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishMetricDefinition_V1_0_0_OemActions_CS;

//
// Contains a list of wildcards and their substitution values.
//
typedef struct _RedfishMetricDefinition_V1_0_0_Wildcard_CS {
    RedfishCS_char          *Name;     // The name of Wildcard.
    RedfishCS_char_Array    *Values;    // An array of values to
                                       // substitute for the wildcard.
} RedfishMetricDefinition_V1_0_0_Wildcard_CS;

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
// The metadata information about a metric.
//
typedef struct _RedfishMetricDefinition_V1_0_0_MetricDefinition_CS {
    RedfishCS_Header                                                 Header;
    RedfishCS_char                                                   *odata_context;         
    RedfishCS_char                                                   *odata_etag;            
    RedfishCS_char                                                   *odata_id;              
    RedfishCS_char                                                   *odata_type;            
    RedfishCS_int64                                                  *Accuracy;                  // Estimated percent error of
                                                                                                 // measured vs. actual values.
    RedfishMetricDefinition_V1_0_0_Actions_CS                        *Actions;                   // The available actions for this
                                                                                                 // resource.
    RedfishCS_char                                                   *Calculable;                // Indicates whether the  metric
                                                                                                 // can be used in a calculation.
    RedfishCS_char                                                   *CalculationAlgorithm;      // The calculation which is
                                                                                                 // performed on a source metric
                                                                                                 // to obtain the metric being
                                                                                                 // defined.
    RedfishMetricDefinition_V1_0_0_CalculationParamsType_Array_CS    *CalculationParameters;     // Specifies the metric
                                                                                                 // properties which are part of
                                                                                                 // the synthesis calculation.
                                                                                                 // This property is present when
                                                                                                 // the MetricType property has
                                                                                                 // the value 'Synthesized'.
    RedfishCS_char                                                   *CalculationTimeInterval;    // The time interval over which
                                                                                                 // the metric calculation is
                                                                                                 // performed.
    RedfishCS_int64                                                  *Calibration;               // Specifies the calibration
                                                                                                 // offset added to the metric
                                                                                                 // reading.
    RedfishCS_char                                                   *Description;           
    RedfishCS_char_Array                                             *DiscreteValues;            // This array property specifies
                                                                                                 // possible values of a discrete
                                                                                                 // metric.
    RedfishCS_char                                                   *Id;                    
    RedfishCS_char                                                   *Implementation;            // The implementation of the
                                                                                                 // metric.
    RedfishCS_bool                                                   *IsLinear;                  // Indicates whether the metric
                                                                                                 // values are linear (vs non-
                                                                                                 // linear).
    RedfishCS_int64                                                  *MaxReadingRange;           // Maximum value for metric
                                                                                                 // reading.
    RedfishCS_char                                                   *MetricDataType;            // The data type of the metric.
    RedfishCS_char_Array                                             *MetricProperties;          // A collection of URI for the
                                                                                                 // properties on which this
                                                                                                 // metric definition is defined.
    RedfishCS_char                                                   *MetricType;                // The type of metric.
    RedfishCS_int64                                                  *MinReadingRange;           // Minimum value for metric
                                                                                                 // reading.
    RedfishCS_char                                                   *Name;                  
    RedfishResource_Oem_CS                                           *Oem;                       // This is the
                                                                                                 // manufacturer/provider specific
                                                                                                 // extension moniker used to
                                                                                                 // divide the Oem object into
                                                                                                 // sections.
    RedfishCS_char                                                   *PhysicalContext;           // Specifies the physical context
                                                                                                 // of the metric.
    RedfishCS_int64                                                  *Precision;                 // Number of significant digits
                                                                                                 // in the metric reading.
    RedfishCS_char                                                   *SensingInterval;           // The time interval between when
                                                                                                 // a metric is updated.
    RedfishCS_char                                                   *TimestampAccuracy;         // Accuracy of the timestamp.
    RedfishCS_char                                                   *Units;                     // The units of measure for this
                                                                                                 // metric.
    RedfishMetricDefinition_V1_0_0_Wildcard_Array_CS                 *Wildcards;                 // Wildcards used to replace
                                                                                                 // values in AppliesTo and
                                                                                                 // Calculates metric property
                                                                                                 // arrays.
} RedfishMetricDefinition_V1_0_0_MetricDefinition_CS;

typedef struct _RedfishMetricDefinition_V1_0_0_CalculationParamsType_Array_CS  {
    RedfishMetricDefinition_V1_0_0_CalculationParamsType_Array_CS    *Next;
    RedfishMetricDefinition_V1_0_0_CalculationParamsType_CS    *ArrayValue;
} RedfishMetricDefinition_V1_0_0_CalculationParamsType_Array_CS;

typedef struct _RedfishMetricDefinition_V1_0_0_Wildcard_Array_CS  {
    RedfishMetricDefinition_V1_0_0_Wildcard_Array_CS    *Next;
    RedfishMetricDefinition_V1_0_0_Wildcard_CS    *ArrayValue;
} RedfishMetricDefinition_V1_0_0_Wildcard_Array_CS;

RedfishCS_status
Json_MetricDefinition_V1_0_0_To_CS (char *JsonRawText, RedfishMetricDefinition_V1_0_0_MetricDefinition_CS **ReturnedCS);

RedfishCS_status
CS_To_MetricDefinition_V1_0_0_JSON (RedfishMetricDefinition_V1_0_0_MetricDefinition_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMetricDefinition_V1_0_0_CS (RedfishMetricDefinition_V1_0_0_MetricDefinition_CS *CSPtr);

RedfishCS_status
DestroyMetricDefinition_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
