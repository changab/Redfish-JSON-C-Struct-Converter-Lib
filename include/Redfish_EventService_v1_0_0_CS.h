//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEventservice_V1_0_0_CSTRUCT_H_
#define _RedfishEventservice_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishEventService_V1_0_0_EventService_CS RedfishEventService_V1_0_0_EventService_CS;
typedef struct _RedfishEventService_V1_0_0_EventService_Actions_CS RedfishEventService_V1_0_0_EventService_Actions_CS;
typedef struct _RedfishEventService_V1_0_0_EventService_Actions_Oem_CS RedfishEventService_V1_0_0_EventService_Actions_Oem_CS;
typedef struct _RedfishEventService_V1_0_0_SubmitTestEvent_CS RedfishEventService_V1_0_0_SubmitTestEvent_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishEventService_V1_0_0_EventService_Actions_CS {
    RedfishEventService_V1_0_0_SubmitTestEvent_CS             *EventService_SubmitTestEvent;
    RedfishEventService_V1_0_0_EventService_Actions_Oem_CS    *Oem;                        
} RedfishEventService_V1_0_0_EventService_Actions_CS;

typedef struct _RedfishEventService_V1_0_0_EventService_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishEventService_V1_0_0_EventService_Actions_Oem_CS;

//
// This action is used to generate a test event.
//
typedef struct _RedfishEventService_V1_0_0_SubmitTestEvent_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishEventService_V1_0_0_SubmitTestEvent_CS;

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
// The Event Service resource contains properties for managing event subcriptions
// and generates the events sent to subscribers.  The resource has links to the
// actual collection of subscriptions (called Event Destinations).
//
typedef struct _RedfishEventService_V1_0_0_EventService_CS {
    RedfishCS_Header                                      Header;
    RedfishCS_char                                        *odata_context;              
    RedfishCS_char                                        *odata_id;                   
    RedfishCS_char                                        *odata_type;                 
    RedfishEventService_V1_0_0_EventService_Actions_CS    *Actions;                        // The available actions for this
                                                                                           // resource.
    RedfishCS_int64                                       *DeliveryRetryAttempts;          // This is the number of attempts
                                                                                           // an event posting is retried
                                                                                           // before the subscription is
                                                                                           // terminated.
    RedfishCS_int64                                       *DeliveryRetryIntervalSeconds;    // This represents the number of
                                                                                           // seconds between retry attempts
                                                                                           // for sending any given Event
    RedfishCS_char                                        *Description;                
    RedfishCS_char_Array                                  *EventTypesForSubscription;      // This is the types of Events
                                                                                           // that can be subscribed to.
    RedfishCS_char                                        *Id;                         
    RedfishCS_char                                        *Name;                       
    RedfishResource_Oem_CS                                *Oem;                            // This is the
                                                                                           // manufacturer/provider specific
                                                                                           // extension moniker used to
                                                                                           // divide the Oem object into
                                                                                           // sections.
    RedfishCS_bool                                        *ServiceEnabled;                 // This indicates whether this
                                                                                           // service is enabled.
    RedfishResource_Status_CS                             *Status;                     
    RedfishCS_Link                                        Subscriptions;                   // This is a reference to a
                                                                                           // collection of Event
                                                                                           // Destination resources.
} RedfishEventService_V1_0_0_EventService_CS;

RedfishCS_status
Json_EventService_V1_0_0_To_CS (char *JsonRawText, RedfishEventService_V1_0_0_EventService_CS **ReturnedCS);

RedfishCS_status
CS_To_EventService_V1_0_0_JSON (RedfishEventService_V1_0_0_EventService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEventService_V1_0_0_CS (RedfishEventService_V1_0_0_EventService_CS *CSPtr);

RedfishCS_status
DestroyEventService_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
