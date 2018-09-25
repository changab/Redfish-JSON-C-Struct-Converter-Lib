//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEventdestination_V1_2_2_CSTRUCT_H_
#define _RedfishEventdestination_V1_2_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS Redfishodata_V4_0_1_idRef_Array_CS;
#endif
typedef struct _RedfishEventDestination_V1_2_2_HttpHeaderProperty_Array_CS RedfishEventDestination_V1_2_2_HttpHeaderProperty_Array_CS;
typedef struct _RedfishEventDestination_V1_2_2_Actions_CS RedfishEventDestination_V1_2_2_Actions_CS;
typedef struct _RedfishEventDestination_V1_2_2_EventDestination_CS RedfishEventDestination_V1_2_2_EventDestination_CS;
typedef struct _RedfishEventDestination_V1_2_2_HttpHeaderProperty_CS RedfishEventDestination_V1_2_2_HttpHeaderProperty_CS;
typedef struct _RedfishEventDestination_V1_2_2_OemActions_CS RedfishEventDestination_V1_2_2_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS Redfishodata_V4_0_1_idRef_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishEventDestination_V1_2_2_Actions_CS {
    RedfishEventDestination_V1_2_2_OemActions_CS    *Oem;
} RedfishEventDestination_V1_2_2_Actions_CS;

//
// The value of the HTTP header is the property value.  The header name is the
// property name.
//
typedef struct _RedfishEventDestination_V1_2_2_HttpHeaderProperty_CS {
    RedfishCS_Link    Prop;
} RedfishEventDestination_V1_2_2_HttpHeaderProperty_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishEventDestination_V1_2_2_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishEventDestination_V1_2_2_OemActions_CS;

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
#ifndef __Redfishodata_V4_0_1_idRef_CS__
#define __Redfishodata_V4_0_1_idRef_CS__
typedef struct _Redfishodata_V4_0_1_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_1_idRef_CS;
#endif

//
// An Event Destination desribes the target of an event subscription, including
// the types of events subscribed and context to provide to the target in the
// Event payload.
//
typedef struct _RedfishEventDestination_V1_2_2_EventDestination_CS {
    RedfishCS_Header                                              Header;
    RedfishCS_char                                                *odata_context;            
    RedfishCS_char                                                *odata_id;                 
    RedfishCS_char                                                *odata_type;               
    RedfishEventDestination_V1_2_2_Actions_CS                     *Actions;                      // The available actions for this
                                                                                                 // resource.
    RedfishCS_char                                                *Context;                      // A client-supplied string that
                                                                                                 // is stored with the event
                                                                                                 // destination subscription.
    RedfishCS_char                                                *Description;              
    RedfishCS_char                                                *Destination;                  // The URI of the destination
                                                                                                 // Event Service.
    RedfishCS_char_Array                                          *EventTypes;                   // This property shall contain
                                                                                                 // the types of events that shall
                                                                                                 // be sent to the desination.
    RedfishEventDestination_V1_2_2_HttpHeaderProperty_Array_CS    *HttpHeaders;                  // This is for setting HTTP
                                                                                                 // headers, such as authorization
                                                                                                 // information.  This object will
                                                                                                 // be null on a GET.
    RedfishCS_char                                                *Id;                       
    RedfishCS_char_Array                                          *MessageIds;                   // A list of MessageIds that the
                                                                                                 // service will only send.  If
                                                                                                 // this property is absent or the
                                                                                                 // array is empty, then Events
                                                                                                 // with any MessageId will be
                                                                                                 // sent to the subscriber.
    RedfishCS_char                                                *Name;                     
    RedfishResource_Oem_CS                                        *Oem;                          // This is the
                                                                                                 // manufacturer/provider specific
                                                                                                 // extension moniker used to
                                                                                                 // divide the Oem object into
                                                                                                 // sections.
    Redfishodata_V4_0_1_idRef_Array_CS                            *OriginResources;              // A list of resources for which
                                                                                                 // the service will only send
                                                                                                 // related events.  If this
                                                                                                 // property is absent or the
                                                                                                 // array is empty, then Events
                                                                                                 // originating from any resource
                                                                                                 // will be sent to the
                                                                                                 // subscriber.
    RedfishCS_int64                                               *OriginResourcesodata_count;
    RedfishCS_char                                                *Protocol;                     // The protocol type of the event
                                                                                                 // connection.
} RedfishEventDestination_V1_2_2_EventDestination_CS;

#ifndef __Redfishodata_V4_0_1_idRef_Array_CS__
#define __Redfishodata_V4_0_1_idRef_Array_CS__
typedef struct _Redfishodata_V4_0_1_idRef_Array_CS  {
    Redfishodata_V4_0_1_idRef_Array_CS    *Next;
    Redfishodata_V4_0_1_idRef_CS    *ArrayValue;
} Redfishodata_V4_0_1_idRef_Array_CS;
#endif

typedef struct _RedfishEventDestination_V1_2_2_HttpHeaderProperty_Array_CS  {
    RedfishEventDestination_V1_2_2_HttpHeaderProperty_Array_CS    *Next;
    RedfishEventDestination_V1_2_2_HttpHeaderProperty_CS    *ArrayValue;
} RedfishEventDestination_V1_2_2_HttpHeaderProperty_Array_CS;

RedfishCS_status
Json_EventDestination_V1_2_2_To_CS (char *JsonRawText, RedfishEventDestination_V1_2_2_EventDestination_CS **ReturnedCS);

RedfishCS_status
CS_To_EventDestination_V1_2_2_JSON (RedfishEventDestination_V1_2_2_EventDestination_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEventDestination_V1_2_2_CS (RedfishEventDestination_V1_2_2_EventDestination_CS *CSPtr);

RedfishCS_status
DestroyEventDestination_V1_2_2_Json (RedfishCS_char *JsonText);

#endif
