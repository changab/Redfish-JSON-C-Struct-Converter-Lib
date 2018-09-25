//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishTaskservice_V1_0_0_CSTRUCT_H_
#define _RedfishTaskservice_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishTaskService_V1_0_0_TaskService_CS RedfishTaskService_V1_0_0_TaskService_CS;
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
    RedfishResource_Oem_CS    *Oem;        
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// This is the schema definition for the Task Service.  It represents the
// properties for the service itself and has links to the actual list of tasks.
//
typedef struct _RedfishTaskService_V1_0_0_TaskService_CS {
    RedfishCS_Header             Header;
    RedfishCS_char               *odata_context;                 
    RedfishCS_char               *odata_id;                      
    RedfishCS_char               *odata_type;                    
    RedfishCS_char               *CompletedTaskOverWritePolicy;      // Overwrite policy of completed
                                                                     // tasks.
    RedfishCS_char               *DateTime;                          // The current DateTime (with
                                                                     // offset) setting that the task
                                                                     // service is using.
    RedfishCS_char               *Description;                   
    RedfishCS_char               *Id;                            
    RedfishCS_bool               *LifeCycleEventOnTaskStateChange;    // Send an Event upon Task State
                                                                     // Change.
    RedfishCS_char               *Name;                          
    RedfishResource_Oem_CS       *Oem;                               // This is the
                                                                     // manufacturer/provider specific
                                                                     // extension moniker used to
                                                                     // divide the Oem object into
                                                                     // sections.
    RedfishCS_bool               *ServiceEnabled;                    // This indicates whether this
                                                                     // service is enabled.
    RedfishResource_Status_CS    *Status;                        
    RedfishCS_Link               Tasks;                              // References to the Tasks
                                                                     // collection.
} RedfishTaskService_V1_0_0_TaskService_CS;

RedfishCS_status
Json_TaskService_V1_0_0_To_CS (char *JsonRawText, RedfishTaskService_V1_0_0_TaskService_CS **ReturnedCS);

RedfishCS_status
CS_To_TaskService_V1_0_0_JSON (RedfishTaskService_V1_0_0_TaskService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyTaskService_V1_0_0_CS (RedfishTaskService_V1_0_0_TaskService_CS *CSPtr);

RedfishCS_status
DestroyTaskService_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
