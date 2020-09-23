//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPORT_V1_0_3_CSTRUCT_H_
#define _EFI_REDFISHPORT_V1_0_3_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Port_v1_0_3_CS.h"

typedef RedfishPort_V1_0_3_Port_CS EFI_REDFISH_PORT_V1_0_3_CS;

RedfishCS_status
Json_Port_V1_0_3_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_PORT_V1_0_3_CS **ReturnedCs);

RedfishCS_status
CS_To_Port_V1_0_3_JSON (EFI_REDFISH_PORT_V1_0_3_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPort_V1_0_3_CS (EFI_REDFISH_PORT_V1_0_3_CS *CSPtr);

RedfishCS_status
DestroyPort_V1_0_3_Json (RedfishCS_char *JsonText);

#endif
