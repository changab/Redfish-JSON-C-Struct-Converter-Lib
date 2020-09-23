//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHRESOURCEBLOCK_V1_1_1_CSTRUCT_H_
#define _EFI_REDFISHRESOURCEBLOCK_V1_1_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ResourceBlock_v1_1_1_CS.h"

typedef RedfishResourceBlock_V1_1_1_ResourceBlock_CS EFI_REDFISH_RESOURCEBLOCK_V1_1_1_CS;

RedfishCS_status
Json_ResourceBlock_V1_1_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_RESOURCEBLOCK_V1_1_1_CS **ReturnedCs);

RedfishCS_status
CS_To_ResourceBlock_V1_1_1_JSON (EFI_REDFISH_RESOURCEBLOCK_V1_1_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyResourceBlock_V1_1_1_CS (EFI_REDFISH_RESOURCEBLOCK_V1_1_1_CS *CSPtr);

RedfishCS_status
DestroyResourceBlock_V1_1_1_Json (RedfishCS_char *JsonText);

#endif