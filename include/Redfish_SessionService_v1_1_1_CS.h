//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSessionservice_V1_1_1_CSTRUCT_H_
#define _RedfishSessionservice_V1_1_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishSessionService_V1_1_1_SessionService_CS RedfishSessionService_V1_1_1_SessionService_CS;
typedef struct _RedfishSessionService_V1_1_1_SessionService_Actions_CS RedfishSessionService_V1_1_1_SessionService_Actions_CS;
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
// The Actions object contains the available custom actions on this resource.
//
typedef struct _RedfishSessionService_V1_1_1_SessionService_Actions_CS {
    RedfishCS_Link    Oem;
} RedfishSessionService_V1_1_1_SessionService_Actions_CS;

//
// This is the schema definition for the Session Service.  It represents the
// properties for the service itself and has links to the actual list of sessions.
//
typedef struct _RedfishSessionService_V1_1_1_SessionService_CS {
    RedfishCS_Header                                          Header;
    RedfishCS_char                                            *odata_context;
    RedfishCS_char                                            *odata_id;     
    RedfishCS_char                                            *odata_type;   
    RedfishSessionService_V1_1_1_SessionService_Actions_CS    *Actions;          // The Actions object contains
                                                                                 // the available custom actions
                                                                                 // on this resource.
    RedfishCS_char                                            *Description;  
    RedfishCS_char                                            *Id;           
    RedfishCS_char                                            *Name;         
    RedfishResource_Oem_CS                                    *Oem;              // This is the
                                                                                 // manufacturer/provider specific
                                                                                 // extension moniker used to
                                                                                 // divide the Oem object into
                                                                                 // sections.
    RedfishCS_bool                                            *ServiceEnabled;    // This indicates whether this
                                                                                 // service is enabled.
    RedfishCS_int64                                           *SessionTimeout;    // This is the number of seconds
                                                                                 // of inactivity that a session
                                                                                 // may have before the session
                                                                                 // service closes the session due
                                                                                 // to inactivity.
    RedfishCS_Link                                            Sessions;          // Link to a collection of
                                                                                 // Sessions.
    RedfishResource_Status_CS                                 *Status;       
} RedfishSessionService_V1_1_1_SessionService_CS;

RedfishCS_status
Json_SessionService_V1_1_1_To_CS (char *JsonRawText, RedfishSessionService_V1_1_1_SessionService_CS **ReturnedCS);

RedfishCS_status
CS_To_SessionService_V1_1_1_JSON (RedfishSessionService_V1_1_1_SessionService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySessionService_V1_1_1_CS (RedfishSessionService_V1_1_1_SessionService_CS *CSPtr);

RedfishCS_status
DestroySessionService_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
