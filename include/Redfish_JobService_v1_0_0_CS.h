//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishJobservice_V1_0_0_CSTRUCT_H_
#define _RedfishJobservice_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishJobService_V1_0_0_Actions_CS RedfishJobService_V1_0_0_Actions_CS;
typedef struct _RedfishJobService_V1_0_0_JobService_CS RedfishJobService_V1_0_0_JobService_CS;
typedef struct _RedfishJobService_V1_0_0_JobServiceCapabilities_CS RedfishJobService_V1_0_0_JobServiceCapabilities_CS;
typedef struct _RedfishJobService_V1_0_0_OemActions_CS RedfishJobService_V1_0_0_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishJobService_V1_0_0_Actions_CS {
    RedfishJobService_V1_0_0_OemActions_CS    *Oem;    // This property contains the
                                                      // available OEM specific actions
                                                      // for this resource.
} RedfishJobService_V1_0_0_Actions_CS;

//
// This object describes the supported capabilities of this Job Service
// implementation.
//
typedef struct _RedfishJobService_V1_0_0_JobServiceCapabilities_CS {
    RedfishCS_int64    *MaxJobs;      // Maximum number of Jobs
                                      // supported.
    RedfishCS_int64    *MaxSteps;     // Maximum number of Job Steps
                                      // supported.
    RedfishCS_bool     *Scheduling;    // Indicates whether scheduling
                                      // of Jobs is supported.
} RedfishJobService_V1_0_0_JobServiceCapabilities_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishJobService_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishJobService_V1_0_0_OemActions_CS;

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
// This is the schema definition for the Job Service.  It represents the
// properties for the service itself and has links to the actual list of tasks.
//
typedef struct _RedfishJobService_V1_0_0_JobService_CS {
    RedfishCS_Header                                      Header;
    RedfishCS_char                                        *odata_context;     
    RedfishCS_char                                        *odata_etag;        
    RedfishCS_char                                        *odata_id;          
    RedfishCS_char                                        *odata_type;        
    RedfishJobService_V1_0_0_Actions_CS                   *Actions;               // The available actions for this
                                                                                  // resource.
    RedfishCS_char                                        *DateTime;              // The current DateTime (with
                                                                                  // offset) setting that the job
                                                                                  // service is using.
    RedfishCS_char                                        *Description;       
    RedfishCS_char                                        *Id;                
    RedfishCS_Link                                        Jobs;                   // References to the Jobs
                                                                                  // collection.
    RedfishCS_Link                                        Log;                    // This is a reference to a Log
                                                                                  // Service used by the Job
                                                                                  // Service.
    RedfishCS_char                                        *Name;              
    RedfishResource_Oem_CS                                *Oem;                   // This is the
                                                                                  // manufacturer/provider specific
                                                                                  // extension moniker used to
                                                                                  // divide the Oem object into
                                                                                  // sections.
    RedfishJobService_V1_0_0_JobServiceCapabilities_CS    *ServiceCapabilities;    // This object describes the
                                                                                  // supported capabilities of this
                                                                                  // Job Service implementation.
    RedfishCS_bool                                        *ServiceEnabled;        // This indicates whether this
                                                                                  // service is enabled.
    RedfishResource_Status_CS                             *Status;                // This property describes the
                                                                                  // status and health of the
                                                                                  // resource and its children.
} RedfishJobService_V1_0_0_JobService_CS;

RedfishCS_status
Json_JobService_V1_0_0_To_CS (char *JsonRawText, RedfishJobService_V1_0_0_JobService_CS **ReturnedCS);

RedfishCS_status
CS_To_JobService_V1_0_0_JSON (RedfishJobService_V1_0_0_JobService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyJobService_V1_0_0_CS (RedfishJobService_V1_0_0_JobService_CS *CSPtr);

RedfishCS_status
DestroyJobService_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
