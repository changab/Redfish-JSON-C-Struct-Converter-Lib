//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVirtualmediacollection_Noversioned_CSTRUCT_H_
#define _RedfishVirtualmediacollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVirtualMediaCollection_VirtualMediaCollection_CS RedfishVirtualMediaCollection_VirtualMediaCollection_CS;
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
// A Collection of VirtualMedia resource instances.
//
typedef struct _RedfishVirtualMediaCollection_VirtualMediaCollection_CS {
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
} RedfishVirtualMediaCollection_VirtualMediaCollection_CS;

RedfishCS_status
Json_VirtualMediaCollection_To_CS (char *JsonRawText, RedfishVirtualMediaCollection_VirtualMediaCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_VirtualMediaCollection_JSON (RedfishVirtualMediaCollection_VirtualMediaCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVirtualMediaCollection_CS (RedfishVirtualMediaCollection_VirtualMediaCollection_CS *CSPtr);

RedfishCS_status
DestroyVirtualMediaCollection_Json (RedfishCS_char *JsonText);

#endif
