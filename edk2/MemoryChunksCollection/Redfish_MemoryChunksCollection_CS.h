//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMEMORYCHUNKSCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMEMORYCHUNKSCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MemoryChunksCollection_CS.h"

typedef RedfishMemoryChunksCollection_MemoryChunksCollection_CS EFI_REDFISH_MEMORYCHUNKSCOLLECTION_CS;

RedfishCS_status
Json_MemoryChunksCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MEMORYCHUNKSCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MemoryChunksCollection_JSON (EFI_REDFISH_MEMORYCHUNKSCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMemoryChunksCollection_CS (EFI_REDFISH_MEMORYCHUNKSCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMemoryChunksCollection_Json (RedfishCS_char *JsonText);

#endif
