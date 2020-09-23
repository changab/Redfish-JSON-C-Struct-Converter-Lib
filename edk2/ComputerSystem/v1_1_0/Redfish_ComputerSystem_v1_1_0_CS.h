//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCOMPUTERSYSTEM_V1_1_0_CSTRUCT_H_
#define _EFI_REDFISHCOMPUTERSYSTEM_V1_1_0_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ComputerSystem_v1_1_0_CS.h"

typedef RedfishComputerSystem_V1_1_0_ComputerSystem_CS EFI_REDFISH_COMPUTERSYSTEM_V1_1_0_CS;

RedfishCS_status
Json_ComputerSystem_V1_1_0_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_COMPUTERSYSTEM_V1_1_0_CS **ReturnedCs);

RedfishCS_status
CS_To_ComputerSystem_V1_1_0_JSON (EFI_REDFISH_COMPUTERSYSTEM_V1_1_0_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyComputerSystem_V1_1_0_CS (EFI_REDFISH_COMPUTERSYSTEM_V1_1_0_CS *CSPtr);

RedfishCS_status
DestroyComputerSystem_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
