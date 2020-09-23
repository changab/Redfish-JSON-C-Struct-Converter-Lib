//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCOMPUTERSYSTEM_V1_0_3_CSTRUCT_H_
#define _EFI_REDFISHCOMPUTERSYSTEM_V1_0_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_ComputerSystem_v1_0_3_CS.h"

typedef RedfishComputerSystem_V1_0_3_ComputerSystem_CS EFI_REDFISH_COMPUTERSYSTEM_V1_0_3_CS;

RedfishCS_status
Json_ComputerSystem_V1_0_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_COMPUTERSYSTEM_V1_0_3_CS **ReturnedCs);

RedfishCS_status
CS_To_ComputerSystem_V1_0_3_JSON (EFI_REDFISH_COMPUTERSYSTEM_V1_0_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyComputerSystem_V1_0_3_CS (EFI_REDFISH_COMPUTERSYSTEM_V1_0_3_CS *CSPtr);

RedfishCS_status
DestroyComputerSystem_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
