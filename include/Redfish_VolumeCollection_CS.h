//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVolumecollection_Noversioned_CSTRUCT_H_
#define _RedfishVolumecollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVolumeCollection_VolumeCollection_CS RedfishVolumeCollection_VolumeCollection_CS;
//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVolumeCollection_VolumeCollection_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;             
    RedfishCS_char            *odata_id;                  
    RedfishCS_char            *odata_type;                
    RedfishCS_char            *Description;               
    RedfishCS_Link            Members;                        // Contains the members of this
                                                              // collection.
    RedfishCS_int64           *Membersodata_count;        
    RedfishCS_char            *Membersodata_navigationLink;
    RedfishCS_char            *Name;                      
    RedfishResource_Oem_CS    *Oem;                           // This is the
                                                              // manufacturer/provider specific
                                                              // extension moniker used to
                                                              // divide the Oem object into
                                                              // sections.
} RedfishVolumeCollection_VolumeCollection_CS;

RedfishCS_status
Json_VolumeCollection_To_CS (char *JsonRawText, RedfishVolumeCollection_VolumeCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_VolumeCollection_JSON (RedfishVolumeCollection_VolumeCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVolumeCollection_CS (RedfishVolumeCollection_VolumeCollection_CS *CSPtr);

RedfishCS_status
DestroyVolumeCollection_Json (RedfishCS_char *JsonText);

#endif
