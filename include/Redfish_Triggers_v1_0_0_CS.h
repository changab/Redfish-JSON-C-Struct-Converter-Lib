//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishTriggers_V1_0_0_CSTRUCT_H_
#define _RedfishTriggers_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishTriggers_V1_0_0_DiscreteTrigger_Array_CS RedfishTriggers_V1_0_0_DiscreteTrigger_Array_CS;
typedef struct _RedfishTriggers_V1_0_0_Wildcard_Array_CS RedfishTriggers_V1_0_0_Wildcard_Array_CS;
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishTriggers_V1_0_0_Actions_CS RedfishTriggers_V1_0_0_Actions_CS;
typedef struct _RedfishTriggers_V1_0_0_DiscreteTrigger_CS RedfishTriggers_V1_0_0_DiscreteTrigger_CS;
typedef struct _RedfishTriggers_V1_0_0_OemActions_CS RedfishTriggers_V1_0_0_OemActions_CS;
typedef struct _RedfishTriggers_V1_0_0_Threshold_CS RedfishTriggers_V1_0_0_Threshold_CS;
typedef struct _RedfishTriggers_V1_0_0_Thresholds_CS RedfishTriggers_V1_0_0_Thresholds_CS;
typedef struct _RedfishTriggers_V1_0_0_Triggers_CS RedfishTriggers_V1_0_0_Triggers_CS;
typedef struct _RedfishTriggers_V1_0_0_Wildcard_CS RedfishTriggers_V1_0_0_Wildcard_CS;
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
typedef struct _RedfishTriggers_V1_0_0_Actions_CS {
    RedfishTriggers_V1_0_0_OemActions_CS    *Oem;    // This property contains the
                                                    // available OEM specific actions
                                                    // for this resource.
} RedfishTriggers_V1_0_0_Actions_CS;

//
// The characteristics of the discrete trigger.
//
typedef struct _RedfishTriggers_V1_0_0_DiscreteTrigger_CS {
    RedfishCS_char    *DwellTime;    // This time the trigger
                                    // occurance persists before a
                                    // trigger event has occurred.
    RedfishCS_char    *Name;        // The name of trigger.
    RedfishCS_char    *Severity;    // This property contains the
                                    // value of the Severity property
                                    // in the Event message.
    RedfishCS_char    *Value;       // The value of the discrete
                                    // metric that constitutes a
                                    // trigger occurance.
} RedfishTriggers_V1_0_0_DiscreteTrigger_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishTriggers_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishTriggers_V1_0_0_OemActions_CS;

//
// A threshold definition for a sensor.
//
typedef struct _RedfishTriggers_V1_0_0_Threshold_CS {
    RedfishCS_char     *Activation;    // The direction of crossing that
                                      // activates this threshold.
    RedfishCS_char     *DwellTime;    // The time interval over which
                                      // the sensor reading must have
                                      // passed through this Threshold
                                      // value before the threshold is
                                      // considered to be violated.
    RedfishCS_int64    *Reading;      // The threshold value.
} RedfishTriggers_V1_0_0_Threshold_CS;

//
// The set of thresholds defined for a sensor.
//
typedef struct _RedfishTriggers_V1_0_0_Thresholds_CS {
    RedfishTriggers_V1_0_0_Threshold_CS    *LowerCritical;    // Below normal range and
                                                             // requires attention.
    RedfishTriggers_V1_0_0_Threshold_CS    *LowerWarning;    // Below normal range.
    RedfishTriggers_V1_0_0_Threshold_CS    *UpperCritical;    // Above normal range and
                                                             // requires attention.
    RedfishTriggers_V1_0_0_Threshold_CS    *UpperWarning;    // Above normal range.
} RedfishTriggers_V1_0_0_Thresholds_CS;

//
// Contains a list of wildcards and their substitution values.
//
typedef struct _RedfishTriggers_V1_0_0_Wildcard_CS {
    RedfishCS_char          *Name;     // The name of Wildcard.
    RedfishCS_char_Array    *Values;    // An array of values to
                                       // substitute for the wildcard.
} RedfishTriggers_V1_0_0_Wildcard_CS;

//
// Triggers which apply to a list of metrics.
//
typedef struct _RedfishTriggers_V1_0_0_Triggers_CS {
    RedfishCS_Header                                   Header;
    RedfishCS_char                                     *odata_context;          
    RedfishCS_char                                     *odata_etag;             
    RedfishCS_char                                     *odata_id;               
    RedfishCS_char                                     *odata_type;             
    RedfishTriggers_V1_0_0_Actions_CS                  *Actions;                    // The available actions for this
                                                                                    // resource.
    RedfishCS_char                                     *Description;            
    RedfishCS_char                                     *DiscreteTriggerCondition;    // Specifies the conditions when
                                                                                    // a discrete metric triggers.
    RedfishTriggers_V1_0_0_DiscreteTrigger_Array_CS    *DiscreteTriggers;           // List of discrete triggers.
    RedfishCS_char                                     *Id;                     
    RedfishCS_char_Array                               *MetricProperties;           // A collection of URI for the
                                                                                    // properties on which this
                                                                                    // metric definition is defined.
    RedfishCS_char                                     *MetricType;                 // The type of trigger.
    RedfishCS_char                                     *Name;                   
    RedfishTriggers_V1_0_0_Thresholds_CS               *NumericThresholds;          // Specifies the thresholds when
                                                                                    // a numeric metric triggers.
    RedfishResource_Oem_CS                             *Oem;                        // This is the
                                                                                    // manufacturer/provider specific
                                                                                    // extension moniker used to
                                                                                    // divide the Oem object into
                                                                                    // sections.
    RedfishResource_Status_CS                          *Status;                     // This property describes the
                                                                                    // status and health of the
                                                                                    // resource and its children.
    RedfishCS_char_Array                               *TriggerActions;             // This property specifies the
                                                                                    // actions to perform when the
                                                                                    // trigger occurs.
    RedfishTriggers_V1_0_0_Wildcard_Array_CS           *Wildcards;                  // Wildcards used to replace
                                                                                    // values in MetricProperties
                                                                                    // array property.
} RedfishTriggers_V1_0_0_Triggers_CS;

typedef struct _RedfishTriggers_V1_0_0_DiscreteTrigger_Array_CS  {
    RedfishTriggers_V1_0_0_DiscreteTrigger_Array_CS    *Next;
    RedfishTriggers_V1_0_0_DiscreteTrigger_CS    *ArrayValue;
} RedfishTriggers_V1_0_0_DiscreteTrigger_Array_CS;

typedef struct _RedfishTriggers_V1_0_0_Wildcard_Array_CS  {
    RedfishTriggers_V1_0_0_Wildcard_Array_CS    *Next;
    RedfishTriggers_V1_0_0_Wildcard_CS    *ArrayValue;
} RedfishTriggers_V1_0_0_Wildcard_Array_CS;

RedfishCS_status
Json_Triggers_V1_0_0_To_CS (char *JsonRawText, RedfishTriggers_V1_0_0_Triggers_CS **ReturnedCS);

RedfishCS_status
CS_To_Triggers_V1_0_0_JSON (RedfishTriggers_V1_0_0_Triggers_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyTriggers_V1_0_0_CS (RedfishTriggers_V1_0_0_Triggers_CS *CSPtr);

RedfishCS_status
DestroyTriggers_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
