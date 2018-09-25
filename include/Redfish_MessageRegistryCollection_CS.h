//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMessageregistrycollection_Noversioned_CSTRUCT_H_
#define _RedfishMessageregistrycollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMessageRegistryCollection_MessageRegistryCollection_CS RedfishMessageRegistryCollection_MessageRegistryCollection_CS;
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
// A Collection of MessageRegistry resource instances.
//
typedef struct _RedfishMessageRegistryCollection_MessageRegistryCollection_CS {
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
} RedfishMessageRegistryCollection_MessageRegistryCollection_CS;

RedfishCS_status
Json_MessageRegistryCollection_To_CS (char *JsonRawText, RedfishMessageRegistryCollection_MessageRegistryCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_MessageRegistryCollection_JSON (RedfishMessageRegistryCollection_MessageRegistryCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMessageRegistryCollection_CS (RedfishMessageRegistryCollection_MessageRegistryCollection_CS *CSPtr);

RedfishCS_status
DestroyMessageRegistryCollection_Json (RedfishCS_char *JsonText);

#endif
