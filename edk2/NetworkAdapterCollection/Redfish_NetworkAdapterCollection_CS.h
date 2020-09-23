//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHNETWORKADAPTERCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHNETWORKADAPTERCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_NetworkAdapterCollection_CS.h"

typedef RedfishNetworkAdapterCollection_NetworkAdapterCollection_CS EFI_REDFISH_NETWORKADAPTERCOLLECTION_CS;

RedfishCS_status
Json_NetworkAdapterCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_NETWORKADAPTERCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_NetworkAdapterCollection_JSON (EFI_REDFISH_NETWORKADAPTERCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyNetworkAdapterCollection_CS (EFI_REDFISH_NETWORKADAPTERCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyNetworkAdapterCollection_Json (RedfishCS_char *JsonText);

#endif
