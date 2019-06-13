//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishLogservicecollection_Noversioned_CSTRUCT_H_
#define _RedfishLogservicecollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishLogServiceCollection_LogServiceCollection_CS RedfishLogServiceCollection_LogServiceCollection_CS;
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
// A Collection of LogService resource instances.
//
typedef struct _RedfishLogServiceCollection_LogServiceCollection_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;       
    RedfishCS_char            *odata_etag;          
    RedfishCS_char            *odata_id;            
    RedfishCS_char            *odata_type;          
    RedfishCS_char            *Description;         
    RedfishCS_Link            Members;                  // Contains the members of this
                                                        // collection.
    RedfishCS_int64           *Membersodata_count;  
    RedfishCS_char            *Membersodata_nextLink;
    RedfishCS_char            *Name;                
    RedfishResource_Oem_CS    *Oem;                     // This is the
                                                        // manufacturer/provider specific
                                                        // extension moniker used to
                                                        // divide the Oem object into
                                                        // sections.
} RedfishLogServiceCollection_LogServiceCollection_CS;

RedfishCS_status
Json_LogServiceCollection_To_CS (char *JsonRawText, RedfishLogServiceCollection_LogServiceCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_LogServiceCollection_JSON (RedfishLogServiceCollection_LogServiceCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyLogServiceCollection_CS (RedfishLogServiceCollection_LogServiceCollection_CS *CSPtr);

RedfishCS_status
DestroyLogServiceCollection_Json (RedfishCS_char *JsonText);

#endif
