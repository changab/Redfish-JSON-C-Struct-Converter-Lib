//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHASSEMBLY_V1_1_1_CSTRUCT_H_
#define _EFI_REDFISHASSEMBLY_V1_1_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Assembly_v1_1_1_CS.h"

typedef RedfishAssembly_V1_1_1_Assembly_CS EFI_REDFISH_ASSEMBLY_V1_1_1_CS;

RedfishCS_status
Json_Assembly_V1_1_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ASSEMBLY_V1_1_1_CS **ReturnedCs);

RedfishCS_status
CS_To_Assembly_V1_1_1_JSON (EFI_REDFISH_ASSEMBLY_V1_1_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyAssembly_V1_1_1_CS (EFI_REDFISH_ASSEMBLY_V1_1_1_CS *CSPtr);

RedfishCS_status
DestroyAssembly_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
