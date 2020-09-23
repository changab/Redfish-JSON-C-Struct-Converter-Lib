//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPCIEFUNCTION_V1_1_2_CSTRUCT_H_
#define _EFI_REDFISHPCIEFUNCTION_V1_1_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_PCIeFunction_v1_1_2_CS.h"

typedef RedfishPCIeFunction_V1_1_2_PCIeFunction_CS EFI_REDFISH_PCIEFUNCTION_V1_1_2_CS;

RedfishCS_status
Json_PCIeFunction_V1_1_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_PCIEFUNCTION_V1_1_2_CS **ReturnedCs);

RedfishCS_status
CS_To_PCIeFunction_V1_1_2_JSON (EFI_REDFISH_PCIEFUNCTION_V1_1_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPCIeFunction_V1_1_2_CS (EFI_REDFISH_PCIEFUNCTION_V1_1_2_CS *CSPtr);

RedfishCS_status
DestroyPCIeFunction_V1_1_2_Json (RedfishCS_char *JsonText);

#endif
