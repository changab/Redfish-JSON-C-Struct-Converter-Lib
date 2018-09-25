//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSoftwareinventorycollection_Noversioned_CSTRUCT_H_
#define _RedfishSoftwareinventorycollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS;
//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

typedef struct _RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS {
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
} RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS;

RedfishCS_status
Json_SoftwareInventoryCollection_To_CS (char *JsonRawText, RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_SoftwareInventoryCollection_JSON (RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySoftwareInventoryCollection_CS (RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS *CSPtr);

RedfishCS_status
DestroySoftwareInventoryCollection_Json (RedfishCS_char *JsonText);

#endif
