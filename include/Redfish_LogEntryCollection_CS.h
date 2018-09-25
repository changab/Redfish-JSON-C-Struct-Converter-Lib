//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishLogentrycollection_Noversioned_CSTRUCT_H_
#define _RedfishLogentrycollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishLogEntryCollection_LogEntryCollection_CS RedfishLogEntryCollection_LogEntryCollection_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

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
// A Collection of LogEntry resource instances.
//
typedef struct _RedfishLogEntryCollection_LogEntryCollection_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;    
    RedfishCS_char            *odata_etag;       
    RedfishCS_char            *odata_id;         
    RedfishCS_char            *odata_type;       
    RedfishCS_char            *Description;      
    RedfishCS_Link            Members;               // Contains the members of this
                                                     // collection.
    RedfishCS_int64           *Membersodata_count;
    RedfishCS_char            *Name;             
    RedfishResource_Oem_CS    *Oem;                  // This is the
                                                     // manufacturer/provider specific
                                                     // extension moniker used to
                                                     // divide the Oem object into
                                                     // sections.
} RedfishLogEntryCollection_LogEntryCollection_CS;

RedfishCS_status
Json_LogEntryCollection_To_CS (char *JsonRawText, RedfishLogEntryCollection_LogEntryCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_LogEntryCollection_JSON (RedfishLogEntryCollection_LogEntryCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyLogEntryCollection_CS (RedfishLogEntryCollection_LogEntryCollection_CS *CSPtr);

RedfishCS_status
DestroyLogEntryCollection_Json (RedfishCS_char *JsonText);

#endif
