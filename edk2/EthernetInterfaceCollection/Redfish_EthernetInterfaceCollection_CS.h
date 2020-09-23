//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHETHERNETINTERFACECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHETHERNETINTERFACECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_EthernetInterfaceCollection_CS.h"

typedef RedfishEthernetInterfaceCollection_EthernetInterfaceCollection_CS EFI_REDFISH_ETHERNETINTERFACECOLLECTION_CS;

RedfishCS_status
Json_EthernetInterfaceCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ETHERNETINTERFACECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_EthernetInterfaceCollection_JSON (EFI_REDFISH_ETHERNETINTERFACECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyEthernetInterfaceCollection_CS (EFI_REDFISH_ETHERNETINTERFACECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyEthernetInterfaceCollection_Json (RedfishCS_char *JsonText);

#endif
