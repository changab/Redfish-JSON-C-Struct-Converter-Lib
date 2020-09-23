//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHNETWORKDEVICEFUNCTION_V1_2_2_CSTRUCT_H_
#define _EFI_REDFISHNETWORKDEVICEFUNCTION_V1_2_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_NetworkDeviceFunction_v1_2_2_CS.h"

typedef RedfishNetworkDeviceFunction_V1_2_2_NetworkDeviceFunction_CS EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_2_2_CS;

RedfishCS_status
Json_NetworkDeviceFunction_V1_2_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_2_2_CS **ReturnedCs);

RedfishCS_status
CS_To_NetworkDeviceFunction_V1_2_2_JSON (EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_2_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyNetworkDeviceFunction_V1_2_2_CS (EFI_REDFISH_NETWORKDEVICEFUNCTION_V1_2_2_CS *CSPtr);

RedfishCS_status
DestroyNetworkDeviceFunction_V1_2_2_Json (RedfishCS_char *JsonText);

#endif
