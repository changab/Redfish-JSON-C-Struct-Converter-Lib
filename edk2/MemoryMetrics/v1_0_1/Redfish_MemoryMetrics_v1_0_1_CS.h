//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMEMORYMETRICS_V1_0_1_CSTRUCT_H_
#define _EFI_REDFISHMEMORYMETRICS_V1_0_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_MemoryMetrics_v1_0_1_CS.h"

typedef RedfishMemoryMetrics_V1_0_1_MemoryMetrics_CS EFI_REDFISH_MEMORYMETRICS_V1_0_1_CS;

RedfishCS_status
Json_MemoryMetrics_V1_0_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MEMORYMETRICS_V1_0_1_CS **ReturnedCs);

RedfishCS_status
CS_To_MemoryMetrics_V1_0_1_JSON (EFI_REDFISH_MEMORYMETRICS_V1_0_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMemoryMetrics_V1_0_1_CS (EFI_REDFISH_MEMORYMETRICS_V1_0_1_CS *CSPtr);

RedfishCS_status
DestroyMemoryMetrics_V1_0_1_Json (RedfishCS_char *JsonText);

#endif