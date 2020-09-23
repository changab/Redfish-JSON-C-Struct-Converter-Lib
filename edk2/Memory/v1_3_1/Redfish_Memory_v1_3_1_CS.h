//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMEMORY_V1_3_1_CSTRUCT_H_
#define _EFI_REDFISHMEMORY_V1_3_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Memory_v1_3_1_CS.h"

typedef RedfishMemory_V1_3_1_Memory_CS EFI_REDFISH_MEMORY_V1_3_1_CS;

RedfishCS_status
Json_Memory_V1_3_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MEMORY_V1_3_1_CS **ReturnedCs);

RedfishCS_status
CS_To_Memory_V1_3_1_JSON (EFI_REDFISH_MEMORY_V1_3_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMemory_V1_3_1_CS (EFI_REDFISH_MEMORY_V1_3_1_CS *CSPtr);

RedfishCS_status
DestroyMemory_V1_3_1_Json (RedfishCS_char *JsonText);

#endif