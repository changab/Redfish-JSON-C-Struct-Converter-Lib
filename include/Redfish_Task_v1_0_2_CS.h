//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishTask_V1_0_2_CSTRUCT_H_
#define _RedfishTask_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishTask_V1_0_2_Task_CS RedfishTask_V1_0_2_Task_CS;
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
// This resource contains information about a specific Task scheduled by or being
// executed by a Redfish service's Task Service.
//
typedef struct _RedfishTask_V1_0_2_Task_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;
    RedfishCS_char            *odata_id;    
    RedfishCS_char            *odata_type;  
    RedfishCS_char            *Description; 
    RedfishCS_char            *EndTime;         // The date-time stamp that the
                                                // task was last completed.
    RedfishCS_char            *Id;          
    RedfishCS_Link            Messages;         // This is an array of messages
                                                // associated with the task.
    RedfishCS_char            *Name;        
    RedfishResource_Oem_CS    *Oem;             // This is the
                                                // manufacturer/provider specific
                                                // extension moniker used to
                                                // divide the Oem object into
                                                // sections.
    RedfishCS_char            *StartTime;       // The date-time stamp that the
                                                // task was last started.
    RedfishCS_char            *TaskState;       // The state of the task.
    RedfishCS_char            *TaskStatus;      // This is the completion status
                                                // of the task.
} RedfishTask_V1_0_2_Task_CS;

RedfishCS_status
Json_Task_V1_0_2_To_CS (char *JsonRawText, RedfishTask_V1_0_2_Task_CS **ReturnedCS);

RedfishCS_status
CS_To_Task_V1_0_2_JSON (RedfishTask_V1_0_2_Task_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyTask_V1_0_2_CS (RedfishTask_V1_0_2_Task_CS *CSPtr);

RedfishCS_status
DestroyTask_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
