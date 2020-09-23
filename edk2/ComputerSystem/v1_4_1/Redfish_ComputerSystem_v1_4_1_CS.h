//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCOMPUTERSYSTEM_V1_4_1_CSTRUCT_H_
#define _EFI_REDFISHCOMPUTERSYSTEM_V1_4_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ComputerSystem_v1_4_1_CS.h"

typedef RedfishComputerSystem_V1_4_1_ComputerSystem_CS EFI_REDFISH_COMPUTERSYSTEM_V1_4_1_CS;

RedfishCS_status
Json_ComputerSystem_V1_4_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_COMPUTERSYSTEM_V1_4_1_CS **ReturnedCs);

RedfishCS_status
CS_To_ComputerSystem_V1_4_1_JSON (EFI_REDFISH_COMPUTERSYSTEM_V1_4_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyComputerSystem_V1_4_1_CS (EFI_REDFISH_COMPUTERSYSTEM_V1_4_1_CS *CSPtr);

RedfishCS_status
DestroyComputerSystem_V1_4_1_Json (RedfishCS_char *JsonText);

#endif
