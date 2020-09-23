//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMEMORYCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMEMORYCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MemoryCollection_CS.h"

typedef RedfishMemoryCollection_MemoryCollection_CS EFI_REDFISH_MEMORYCOLLECTION_CS;

RedfishCS_status
Json_MemoryCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MEMORYCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MemoryCollection_JSON (EFI_REDFISH_MEMORYCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMemoryCollection_CS (EFI_REDFISH_MEMORYCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMemoryCollection_Json (RedfishCS_char *JsonText);

#endif
