//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishLogentry_V1_1_4_CSTRUCT_H_
#define _RedfishLogentry_V1_1_4_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishLogEntry_V1_1_4_Links_CS RedfishLogEntry_V1_1_4_Links_CS;
typedef struct _RedfishLogEntry_V1_1_4_LogEntry_CS RedfishLogEntry_V1_1_4_LogEntry_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __Redfishodata_V4_0_3_idRef_CS__
typedef struct _Redfishodata_V4_0_3_idRef_CS Redfishodata_V4_0_3_idRef_CS;
#endif

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishLogEntry_V1_1_4_Links_CS {
    RedfishResource_Oem_CS          *Oem;                 // Oem extension object.
    Redfishodata_V4_0_3_idRef_CS    *OriginOfCondition;    // This is the URI of the
                                                          // resource that caused the log
                                                          // entry.
} RedfishLogEntry_V1_1_4_Links_CS;

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
#ifndef __Redfishodata_V4_0_3_idRef_CS__
#define __Redfishodata_V4_0_3_idRef_CS__
typedef struct _Redfishodata_V4_0_3_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_3_idRef_CS;
#endif

//
// This resource defines the record format for a log.  It is designed to be used
// for SEL logs (from IPMI) as well as Event Logs and OEM-specific log formats.
// The EntryType field indicates the type of log and the resource includes several
// additional properties dependent on the EntryType.
//
typedef struct _RedfishLogEntry_V1_1_4_LogEntry_CS {
    RedfishCS_Header                   Header;
    RedfishCS_char                     *odata_context; 
    RedfishCS_char                     *odata_etag;    
    RedfishCS_char                     *odata_id;      
    RedfishCS_char                     *odata_type;    
    RedfishCS_char                     *Created;           // The time the log entry was
                                                           // created.
    RedfishCS_char                     *Description;   
    RedfishCS_char                     *EntryCode;         // If the EntryType is SEL, this
                                                           // will have the entry code for
                                                           // the log entry.
    RedfishCS_char                     *EntryType;         // This is the type of log entry.
    RedfishCS_char                     *EventId;           // This is a unique instance
                                                           // identifier of an event.
    RedfishCS_char                     *EventTimestamp;    // This is time the event
                                                           // occurred.
    RedfishCS_char                     *EventType;         // This indicates the type of an
                                                           // event recorded in this log.
    RedfishCS_char                     *Id;            
    RedfishLogEntry_V1_1_4_Links_CS    *Links;             // Contains references to other
                                                           // resources that are related to
                                                           // this resource.
    RedfishCS_char                     *Message;           // This property decodes from
                                                           // EntryType.  If the EntryType
                                                           // is Event, then it is a message
                                                           // string.  Otherwise, it is SEL
                                                           // or OEM specific.  In most
                                                           // cases, this will be the actual
                                                           // Log Entry.
    RedfishCS_char_Array               *MessageArgs;       // The values of this property
                                                           // shall be any arguments for the
                                                           // message.
    RedfishCS_char                     *MessageId;         // This property decodes from
                                                           // EntryType.  If the EntryType
                                                           // is Event, then it is a message
                                                           // id.  If the EntryType is SEL,
                                                           // then it contains the Event
                                                           // Data.  Otherwise, it is OEM
                                                           // specific.  This value is only
                                                           // used for registries - for more
                                                           // information, see the
                                                           // specification.
    RedfishCS_char                     *Name;          
    RedfishResource_Oem_CS             *Oem;               // This is the
                                                           // manufacturer/provider specific
                                                           // extension moniker used to
                                                           // divide the Oem object into
                                                           // sections.
    RedfishCS_char                     *OemRecordFormat;    // If the EntryType is Oem, this
                                                           // will contain more information
                                                           // about the record format from
                                                           // the Oem.
    RedfishCS_int64                    *SensorNumber;      // This property decodes from
                                                           // EntryType.  If the EntryType
                                                           // is SEL, it is the sensor
                                                           // number.  If the EntryType is
                                                           // Event, then the count of
                                                           // events.  Otherwise, it is OEM
                                                           // specific.
    RedfishCS_char                     *SensorType;        // If the EntryType is SEL, this
                                                           // will have the sensor type that
                                                           // the log entry pertains to.
    RedfishCS_char                     *Severity;          // This is the severity of the
                                                           // log entry.
} RedfishLogEntry_V1_1_4_LogEntry_CS;

RedfishCS_status
Json_LogEntry_V1_1_4_To_CS (char *JsonRawText, RedfishLogEntry_V1_1_4_LogEntry_CS **ReturnedCS);

RedfishCS_status
CS_To_LogEntry_V1_1_4_JSON (RedfishLogEntry_V1_1_4_LogEntry_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyLogEntry_V1_1_4_CS (RedfishLogEntry_V1_1_4_LogEntry_CS *CSPtr);

RedfishCS_status
DestroyLogEntry_V1_1_4_Json (RedfishCS_char *JsonText);

#endif
