//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHVLANNETWORKINTERFACECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHVLANNETWORKINTERFACECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_VLanNetworkInterfaceCollection_CS.h"

typedef RedfishVLanNetworkInterfaceCollection_VLanNetworkInterfaceCollection_CS EFI_REDFISH_VLANNETWORKINTERFACECOLLECTION_CS;

RedfishCS_status
Json_VLanNetworkInterfaceCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_VLANNETWORKINTERFACECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_VLanNetworkInterfaceCollection_JSON (EFI_REDFISH_VLANNETWORKINTERFACECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyVLanNetworkInterfaceCollection_CS (EFI_REDFISH_VLANNETWORKINTERFACECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyVLanNetworkInterfaceCollection_Json (RedfishCS_char *JsonText);

#endif
