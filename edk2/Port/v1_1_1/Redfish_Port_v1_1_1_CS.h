//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPORT_V1_1_1_CSTRUCT_H_
#define _EFI_REDFISHPORT_V1_1_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_Port_v1_1_1_CS.h"

typedef RedfishPort_V1_1_1_Port_CS EFI_REDFISH_PORT_V1_1_1_CS;

RedfishCS_status
Json_Port_V1_1_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_PORT_V1_1_1_CS **ReturnedCs);

RedfishCS_status
CS_To_Port_V1_1_1_JSON (EFI_REDFISH_PORT_V1_1_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPort_V1_1_1_CS (EFI_REDFISH_PORT_V1_1_1_CS *CSPtr);

RedfishCS_status
DestroyPort_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
