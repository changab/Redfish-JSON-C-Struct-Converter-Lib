//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishEventdestination_V1_0_0_CSTRUCT_H_
#define _RedfishEventdestination_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishEventDestination_V1_0_0_HttpHeaderProperty_Array_CS RedfishEventDestination_V1_0_0_HttpHeaderProperty_Array_CS;
typedef struct _RedfishEventDestination_V1_0_0_EventDestination_CS RedfishEventDestination_V1_0_0_EventDestination_CS;
typedef struct _RedfishEventDestination_V1_0_0_HttpHeaderProperty_CS RedfishEventDestination_V1_0_0_HttpHeaderProperty_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// The value of the HTTP header is the property value.  The header name is the
// property name.
//
typedef struct _RedfishEventDestination_V1_0_0_HttpHeaderProperty_CS {
    RedfishCS_Link    Prop;
} RedfishEventDestination_V1_0_0_HttpHeaderProperty_CS;

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
// An Event Destination desribes the target of an event subscription, including
// the types of events subscribed and context to provide to the target in the
// Event payload.
//
typedef struct _RedfishEventDestination_V1_0_0_EventDestination_CS {
    RedfishCS_Header                                              Header;
    RedfishCS_char                                                *odata_context;
    RedfishCS_char                                                *odata_id;    
    RedfishCS_char                                                *odata_type;  
    RedfishCS_char                                                *Context;         // A client-supplied string that
                                                                                    // is stored with the event
                                                                                    // destination subscription.
    RedfishCS_char                                                *Description; 
    RedfishCS_char                                                *Destination;     // The URI of the destination
                                                                                    // Event Service.
    RedfishCS_char_Array                                          *EventTypes;      // This property shall contain
                                                                                    // the types of events that shall
                                                                                    // be sent to the desination.
    RedfishEventDestination_V1_0_0_HttpHeaderProperty_Array_CS    *HttpHeaders;     // This is for setting HTTP
                                                                                    // headers, such as authorization
                                                                                    // information.  This object will
                                                                                    // be null on a GET.
    RedfishCS_char                                                *Id;          
    RedfishCS_char                                                *Name;        
    RedfishResource_Oem_CS                                        *Oem;             // This is the
                                                                                    // manufacturer/provider specific
                                                                                    // extension moniker used to
                                                                                    // divide the Oem object into
                                                                                    // sections.
    RedfishCS_char                                                *Protocol;        // The protocol type of the event
                                                                                    // connection.
} RedfishEventDestination_V1_0_0_EventDestination_CS;

typedef struct _RedfishEventDestination_V1_0_0_HttpHeaderProperty_Array_CS  {
    RedfishEventDestination_V1_0_0_HttpHeaderProperty_Array_CS    *Next;
    RedfishEventDestination_V1_0_0_HttpHeaderProperty_CS    *ArrayValue;
} RedfishEventDestination_V1_0_0_HttpHeaderProperty_Array_CS;

RedfishCS_status
Json_EventDestination_V1_0_0_To_CS (char *JsonRawText, RedfishEventDestination_V1_0_0_EventDestination_CS **ReturnedCS);

RedfishCS_status
CS_To_EventDestination_V1_0_0_JSON (RedfishEventDestination_V1_0_0_EventDestination_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyEventDestination_V1_0_0_CS (RedfishEventDestination_V1_0_0_EventDestination_CS *CSPtr);

RedfishCS_status
DestroyEventDestination_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
