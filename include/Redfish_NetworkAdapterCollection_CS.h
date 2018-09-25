//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishNetworkadaptercollection_Noversioned_CSTRUCT_H_
#define _RedfishNetworkadaptercollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS;
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
// A Collection of NetworkAdapter resource instances.
//
typedef struct _RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS {
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
} RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS;

RedfishCS_status
Json_NetworkAdapterCollection_To_CS (char *JsonRawText, RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_NetworkAdapterCollection_JSON (RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyNetworkAdapterCollection_CS (RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS *CSPtr);

RedfishCS_status
DestroyNetworkAdapterCollection_Json (RedfishCS_char *JsonText);

#endif
