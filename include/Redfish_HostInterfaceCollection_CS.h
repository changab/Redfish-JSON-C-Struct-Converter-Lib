//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishHostinterfacecollection_Noversioned_CSTRUCT_H_
#define _RedfishHostinterfacecollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishHostInterfaceCollection_HostInterfaceCollection_CS RedfishHostInterfaceCollection_HostInterfaceCollection_CS;
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
// A Collection of HostInterface resource instances.
//
typedef struct _RedfishHostInterfaceCollection_HostInterfaceCollection_CS {
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
} RedfishHostInterfaceCollection_HostInterfaceCollection_CS;

RedfishCS_status
Json_HostInterfaceCollection_To_CS (char *JsonRawText, RedfishHostInterfaceCollection_HostInterfaceCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_HostInterfaceCollection_JSON (RedfishHostInterfaceCollection_HostInterfaceCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyHostInterfaceCollection_CS (RedfishHostInterfaceCollection_HostInterfaceCollection_CS *CSPtr);

RedfishCS_status
DestroyHostInterfaceCollection_Json (RedfishCS_char *JsonText);

#endif
