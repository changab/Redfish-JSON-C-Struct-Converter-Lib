//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHNETWORKDEVICEFUNCTIONCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHNETWORKDEVICEFUNCTIONCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_NetworkDeviceFunctionCollection_CS.h"

typedef RedfishNetworkDeviceFunctionCollection_NetworkDeviceFunctionCollection_CS EFI_REDFISH_NETWORKDEVICEFUNCTIONCOLLECTION_CS;

RedfishCS_status
Json_NetworkDeviceFunctionCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_NETWORKDEVICEFUNCTIONCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_NetworkDeviceFunctionCollection_JSON (EFI_REDFISH_NETWORKDEVICEFUNCTIONCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyNetworkDeviceFunctionCollection_CS (EFI_REDFISH_NETWORKDEVICEFUNCTIONCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyNetworkDeviceFunctionCollection_Json (RedfishCS_char *JsonText);

#endif
