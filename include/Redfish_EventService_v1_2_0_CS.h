//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEventservice_V1_2_0_CSTRUCT_H_
#define _RedfishEventservice_V1_2_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishEventService_V1_2_0_Actions_CS RedfishEventService_V1_2_0_Actions_CS;
typedef struct _RedfishEventService_V1_2_0_EventService_CS RedfishEventService_V1_2_0_EventService_CS;
typedef struct _RedfishEventService_V1_2_0_OemActions_CS RedfishEventService_V1_2_0_OemActions_CS;
typedef struct _RedfishEventService_V1_2_0_SSEFilterPropertiesSupported_CS RedfishEventService_V1_2_0_SSEFilterPropertiesSupported_CS;
typedef struct _RedfishEventService_V1_2_0_SubmitTestEvent_CS RedfishEventService_V1_2_0_SubmitTestEvent_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishEventService_V1_2_0_Actions_CS {
    RedfishEventService_V1_2_0_SubmitTestEvent_CS    *EventService_SubmitTestEvent;
    RedfishEventService_V1_2_0_OemActions_CS         *Oem;                            // This property contains the
                                                                                      // available OEM specific actions
                                                                                      // for this resource.
} RedfishEventService_V1_2_0_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishEventService_V1_2_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishEventService_V1_2_0_OemActions_CS;

//
// Contains a set of properties that indicate which properties are supported in
// the $filter query parameter for the ServerSentEventUri.
//
typedef struct _RedfishEventService_V1_2_0_SSEFilterPropertiesSupported_CS {
    RedfishCS_bool    *EventFormatType;          // This indicates if the
                                                 // EventFormatType property is
                                                 // supported.
    RedfishCS_bool    *EventType;                // This indicates if the
                                                 // EventType property is
                                                 // supported.
    RedfishCS_bool    *MessageId;                // This indicates if the
                                                 // MessageId property is
                                                 // supported.
    RedfishCS_bool    *MetricReportDefinition;    // This indicates if the
                                                 // MetricReportDefinition
                                                 // property is supported.
    RedfishCS_bool    *OriginResource;           // This indicates if the
                                                 // OriginResource property is
                                                 // supported.
    RedfishCS_bool    *RegistryPrefix;           // This indicates if the
                                                 // RegistryPrefix property is
                                                 // supported.
    RedfishCS_bool    *ResourceType;             // This indicates if the
                                                 // ResourceType property is
                                                 // supported.
} RedfishEventService_V1_2_0_SSEFilterPropertiesSupported_CS;

//
// This action is used to generate a test event.
//
typedef struct _RedfishEventService_V1_2_0_SubmitTestEvent_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishEventService_V1_2_0_SubmitTestEvent_CS;

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
typedef struct _RedfishEventService_V1_2_0_EventService_CS {
    RedfishCS_Header                                              Header;
    RedfishCS_char                                                *odata_context;               
    RedfishCS_char                                                *odata_etag;                  
    RedfishCS_char                                                *odata_id;                    
    RedfishCS_char                                                *odata_type;                  
    RedfishEventService_V1_2_0_Actions_CS                         *Actions;                         // The available actions for this
                                                                                                    // resource.
    RedfishCS_int64                                               *DeliveryRetryAttempts;           // This is the number of attempts
                                                                                                    // an event posting is retried
                                                                                                    // before the subscription is
                                                                                                    // terminated.  This retry is at
                                                                                                    // the service level, meaning the
                                                                                                    // HTTP POST to the Event
                                                                                                    // Destination was returned by
                                                                                                    // the HTTP operation as
                                                                                                    // unsuccessful (4xx or 5xx
                                                                                                    // return code) or an HTTP
                                                                                                    // timeout occurred this many
                                                                                                    // times before the Event
                                                                                                    // Destination subscription is
                                                                                                    // terminated.
    RedfishCS_int64                                               *DeliveryRetryIntervalSeconds;    // This represents the number of
                                                                                                    // seconds between retry attempts
                                                                                                    // for sending any given Event.
    RedfishCS_char                                                *Description;                 
    RedfishCS_char_Array                                          *EventFormatTypes;                // Indicates the content types of
                                                                                                    // the message that this service
                                                                                                    // can send to the event
                                                                                                    // destination.
    RedfishCS_char_Array                                          *EventTypesForSubscription;       // This is the types of Events
                                                                                                    // that can be subscribed to.
    RedfishCS_char                                                *Id;                          
    RedfishCS_char                                                *Name;                        
    RedfishResource_Oem_CS                                        *Oem;                             // This is the
                                                                                                    // manufacturer/provider specific
                                                                                                    // extension moniker used to
                                                                                                    // divide the Oem object into
                                                                                                    // sections.
    RedfishCS_char_Array                                          *RegistryPrefixes;                // A list of the Prefixes of the
                                                                                                    // Message Registries that can be
                                                                                                    // used for the RegistryPrefix
                                                                                                    // property on a subscription.
    RedfishCS_char_Array                                          *ResourceTypes;                   // A list of @odata.type values
                                                                                                    // (Schema names) that can be
                                                                                                    // specified in a ResourceType on
                                                                                                    // a subscription.
    RedfishEventService_V1_2_0_SSEFilterPropertiesSupported_CS    *SSEFilterPropertiesSupported;    // Contains a set of properties
                                                                                                    // that indicate which properties
                                                                                                    // are supported in the $filter
                                                                                                    // query parameter for the
                                                                                                    // ServerSentEventUri.
    RedfishCS_char                                                *ServerSentEventUri;              // Link to a URI for receiving
                                                                                                    // Sever Sent Event
                                                                                                    // representations of the events
                                                                                                    // generated by this service.
    RedfishCS_bool                                                *ServiceEnabled;                  // This indicates whether this
                                                                                                    // service is enabled.
    RedfishResource_Status_CS                                     *Status;                          // This property describes the
                                                                                                    // status and health of the
                                                                                                    // resource and its children.
    RedfishCS_bool                                                *SubordinateResourcesSupported;    // This indicates if the service
                                                                                                    // supports the
                                                                                                    // SubordinateResource property
                                                                                                    // on Event Subscriptions.
    RedfishCS_Link                                                Subscriptions;                    // This is a reference to a
                                                                                                    // collection of Event
                                                                                                    // Destination resources.
} RedfishEventService_V1_2_0_EventService_CS;

RedfishCS_status
Json_EventService_V1_2_0_To_CS (char *JsonRawText, RedfishEventService_V1_2_0_EventService_CS **ReturnedCS);

RedfishCS_status
CS_To_EventService_V1_2_0_JSON (RedfishEventService_V1_2_0_EventService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEventService_V1_2_0_CS (RedfishEventService_V1_2_0_EventService_CS *CSPtr);

RedfishCS_status
DestroyEventService_V1_2_0_Json (RedfishCS_char *JsonText);

#endif