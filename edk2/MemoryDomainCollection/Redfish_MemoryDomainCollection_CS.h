//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMEMORYDOMAINCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMEMORYDOMAINCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MemoryDomainCollection_CS.h"

typedef RedfishMemoryDomainCollection_MemoryDomainCollection_CS EFI_REDFISH_MEMORYDOMAINCOLLECTION_CS;

RedfishCS_status
Json_MemoryDomainCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MEMORYDOMAINCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MemoryDomainCollection_JSON (EFI_REDFISH_MEMORYDOMAINCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMemoryDomainCollection_CS (EFI_REDFISH_MEMORYDOMAINCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMemoryDomainCollection_Json (RedfishCS_char *JsonText);

#endif
