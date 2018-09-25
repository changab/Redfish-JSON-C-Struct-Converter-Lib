//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishLogservice_V1_1_0_CSTRUCT_H_
#define _RedfishLogservice_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishLogService_V1_1_0_Actions_CS RedfishLogService_V1_1_0_Actions_CS;
typedef struct _RedfishLogService_V1_1_0_ClearLog_CS RedfishLogService_V1_1_0_ClearLog_CS;
typedef struct _RedfishLogService_V1_1_0_LogService_CS RedfishLogService_V1_1_0_LogService_CS;
typedef struct _RedfishLogService_V1_1_0_OemActions_CS RedfishLogService_V1_1_0_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishLogService_V1_1_0_Actions_CS {
    RedfishLogService_V1_1_0_ClearLog_CS      *LogService_ClearLog;
    RedfishLogService_V1_1_0_OemActions_CS    *Oem;               
} RedfishLogService_V1_1_0_Actions_CS;

//
// This action is used to clear the log for this Log Service.
//
typedef struct _RedfishLogService_V1_1_0_ClearLog_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishLogService_V1_1_0_ClearLog_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishLogService_V1_1_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishLogService_V1_1_0_OemActions_CS;

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
// This resource represents the log service for the resource or service to which
// it is associated.
//
typedef struct _RedfishLogService_V1_1_0_LogService_CS {
    RedfishCS_Header                       Header;
    RedfishCS_char                         *odata_context;     
    RedfishCS_char                         *odata_id;          
    RedfishCS_char                         *odata_type;        
    RedfishLogService_V1_1_0_Actions_CS    *Actions;               // The available actions for this
                                                                   // resource.
    RedfishCS_char                         *DateTime;              // The current DateTime (with
                                                                   // offset) for the log service,
                                                                   // used to set or read time.
    RedfishCS_char                         *DateTimeLocalOffset;    // The time offset from UTC that
                                                                   // the DateTime property is set
                                                                   // to in format: +06:00 .
    RedfishCS_char                         *Description;       
    RedfishCS_Link                         Entries;                // References to the log entry
                                                                   // collection.
    RedfishCS_char                         *Id;                
    RedfishCS_char                         *LogEntryType;          // The format of the Entries of
                                                                   // this log.
    RedfishCS_int64                        *MaxNumberOfRecords;    // The maximum number of log
                                                                   // entries this service can have.
    RedfishCS_char                         *Name;              
    RedfishResource_Oem_CS                 *Oem;                   // This is the
                                                                   // manufacturer/provider specific
                                                                   // extension moniker used to
                                                                   // divide the Oem object into
                                                                   // sections.
    RedfishCS_char                         *OverWritePolicy;       // The overwrite policy for this
                                                                   // service that takes place when
                                                                   // the log is full.
    RedfishCS_bool                         *ServiceEnabled;        // This indicates whether this
                                                                   // service is enabled.
    RedfishResource_Status_CS              *Status;            
} RedfishLogService_V1_1_0_LogService_CS;

RedfishCS_status
Json_LogService_V1_1_0_To_CS (char *JsonRawText, RedfishLogService_V1_1_0_LogService_CS **ReturnedCS);

RedfishCS_status
CS_To_LogService_V1_1_0_JSON (RedfishLogService_V1_1_0_LogService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyLogService_V1_1_0_CS (RedfishLogService_V1_1_0_LogService_CS *CSPtr);

RedfishCS_status
DestroyLogService_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
