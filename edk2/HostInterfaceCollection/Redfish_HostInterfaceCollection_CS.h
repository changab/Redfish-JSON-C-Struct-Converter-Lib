//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHHOSTINTERFACECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHHOSTINTERFACECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_HostInterfaceCollection_CS.h"

typedef RedfishHostInterfaceCollection_HostInterfaceCollection_CS EFI_REDFISH_HOSTINTERFACECOLLECTION_CS;

RedfishCS_status
Json_HostInterfaceCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_HOSTINTERFACECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_HostInterfaceCollection_JSON (EFI_REDFISH_HOSTINTERFACECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyHostInterfaceCollection_CS (EFI_REDFISH_HOSTINTERFACECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyHostInterfaceCollection_Json (RedfishCS_char *JsonText);

#endif
