//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishResourceblockcollection_Noversioned_CSTRUCT_H_
#define _RedfishResourceblockcollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishResourceBlockCollection_ResourceBlockCollection_CS RedfishResourceBlockCollection_ResourceBlockCollection_CS;
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
// A Collection of ResourceBlock resource instances.
//
typedef struct _RedfishResourceBlockCollection_ResourceBlockCollection_CS {
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
} RedfishResourceBlockCollection_ResourceBlockCollection_CS;

RedfishCS_status
Json_ResourceBlockCollection_To_CS (char *JsonRawText, RedfishResourceBlockCollection_ResourceBlockCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_ResourceBlockCollection_JSON (RedfishResourceBlockCollection_ResourceBlockCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyResourceBlockCollection_CS (RedfishResourceBlockCollection_ResourceBlockCollection_CS *CSPtr);

RedfishCS_status
DestroyResourceBlockCollection_Json (RedfishCS_char *JsonText);

#endif
