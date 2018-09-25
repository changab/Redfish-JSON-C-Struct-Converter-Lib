//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEvent_V1_0_3_CSTRUCT_H_
#define _RedfishEvent_V1_0_3_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishEvent_V1_0_3_EventRecord_Array_CS RedfishEvent_V1_0_3_EventRecord_Array_CS;
typedef struct _RedfishEvent_V1_0_3_Event_CS RedfishEvent_V1_0_3_Event_CS;
typedef struct _RedfishEvent_V1_0_3_EventRecord_CS RedfishEvent_V1_0_3_EventRecord_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __Redfishodata_V4_0_0_idRef_CS__
typedef struct _Redfishodata_V4_0_0_idRef_CS Redfishodata_V4_0_0_idRef_CS;
#endif

//
// This is the base type for addressable members of an array.
//
typedef struct _RedfishEvent_V1_0_3_EventRecord_CS {
    RedfishCS_char                  *Context;             // A context can be supplied at
                                                          // subscription time.  This
                                                          // property is the context value
                                                          // supplied by the subscriber.
    RedfishCS_char                  *EventId;             // This is a unique instance
                                                          // identifier of an event.
    RedfishCS_char                  *EventTimestamp;      // This is time the event
                                                          // occurred.
    RedfishCS_char                  *EventType;           // This indicates the type of
                                                          // event sent, according to the
                                                          // definitions in the
                                                          // EventService.
    RedfishCS_char                  *MemberId;            // This is the identifier for the
                                                          // member within the collection.
    RedfishCS_char                  *Message;             // This is the human readable
                                                          // message, if provided.
    RedfishCS_char_Array            *MessageArgs;         // This array of message
                                                          // arguments are substituted for
                                                          // the arguments in the message
                                                          // when looked up in the message
                                                          // registry.
    RedfishCS_char                  *MessageId;           // This is the key for this
                                                          // message which can be used to
                                                          // look up the message in a
                                                          // message registry.
    RedfishResource_Oem_CS          *Oem;                 // This is the
                                                          // manufacturer/provider specific
                                                          // extension moniker used to
                                                          // divide the Oem object into
                                                          // sections.
    Redfishodata_V4_0_0_idRef_CS    *OriginOfCondition;    // This indicates the resource
                                                          // that originated the condition
                                                          // that caused the event to be
                                                          // generated.
    RedfishCS_char                  *Severity;            // This is the severity of the
                                                          // event.
} RedfishEvent_V1_0_3_EventRecord_CS;

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
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_0_idRef_CS__
#define __Redfishodata_V4_0_0_idRef_CS__
typedef struct _Redfishodata_V4_0_0_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_0_idRef_CS;
#endif

//
// The Event schema describes the JSON payload received by an Event Destination
// (which has subscribed to event notification) when events occurs.  This resource
// contains data about event(s), including descriptions, severity and MessageId
// reference to a Message Registry that can be accessed for further information.
//
typedef struct _RedfishEvent_V1_0_3_Event_CS {
    RedfishCS_Header                            Header;
    RedfishCS_char                              *odata_context;            
    RedfishCS_char                              *odata_id;                 
    RedfishCS_char                              *odata_type;               
    RedfishCS_char                              *Description;              
    RedfishEvent_V1_0_3_EventRecord_Array_CS    *Events;                       // Each event in this array has a
                                                                               // set of properties that
                                                                               // describe the event.  Since
                                                                               // this is an array, more than
                                                                               // one event can be sent
                                                                               // simultaneously.
    RedfishCS_int64                             *Eventsodata_count;        
    RedfishCS_char                              *Eventsodata_navigationLink;
    RedfishCS_char                              *Id;                       
    RedfishCS_char                              *Name;                     
    RedfishResource_Oem_CS                      *Oem;                          // This is the
                                                                               // manufacturer/provider specific
                                                                               // extension moniker used to
                                                                               // divide the Oem object into
                                                                               // sections.
} RedfishEvent_V1_0_3_Event_CS;

typedef struct _RedfishEvent_V1_0_3_EventRecord_Array_CS  {
    RedfishEvent_V1_0_3_EventRecord_Array_CS    *Next;
    RedfishEvent_V1_0_3_EventRecord_CS    *ArrayValue;
} RedfishEvent_V1_0_3_EventRecord_Array_CS;

RedfishCS_status
Json_Event_V1_0_3_To_CS (char *JsonRawText, RedfishEvent_V1_0_3_Event_CS **ReturnedCS);

RedfishCS_status
CS_To_Event_V1_0_3_JSON (RedfishEvent_V1_0_3_Event_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEvent_V1_0_3_CS (RedfishEvent_V1_0_3_Event_CS *CSPtr);

RedfishCS_status
DestroyEvent_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
