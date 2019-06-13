//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSwitchcollection_Noversioned_CSTRUCT_H_
#define _RedfishSwitchcollection_Noversioned_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishSwitchCollection_SwitchCollection_CS RedfishSwitchCollection_SwitchCollection_CS;
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
// A Collection of Switch resource instances.
//
typedef struct _RedfishSwitchCollection_SwitchCollection_CS {
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
} RedfishSwitchCollection_SwitchCollection_CS;

RedfishCS_status
Json_SwitchCollection_To_CS (char *JsonRawText, RedfishSwitchCollection_SwitchCollection_CS **ReturnedCS);

RedfishCS_status
CS_To_SwitchCollection_JSON (RedfishSwitchCollection_SwitchCollection_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySwitchCollection_CS (RedfishSwitchCollection_SwitchCollection_CS *CSPtr);

RedfishCS_status
DestroySwitchCollection_Json (RedfishCS_char *JsonText);

#endif
