//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHNETWORKDEVICEFUNCTION_V1_3_1_CSTRUCT_H_
#define _EFI_REDFISHNETWORKDEVICEFUNCTION_V1_3_1_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_NetworkDeviceFunction_v1_3_1_CS.h"

typedef RedfishNetworkDeviceFunction_V1_3_1_NetworkDeviceFunction_CS EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_3_1_CS;

RedfishCS_status
Json_NetworkDeviceFunction_V1_3_1_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_3_1_CS **ReturnedCs);

RedfishCS_status
CS_To_NetworkDeviceFunction_V1_3_1_JSON (EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_3_1_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyNetworkDeviceFunction_V1_3_1_CS (EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_3_1_CS *CSPtr);

RedfishCS_status
DestroyNetworkDeviceFunction_V1_3_1_Json (RedfishCS_char *JsonText);

#endif
