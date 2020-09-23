//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSOFTWAREINVENTORYCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHSOFTWAREINVENTORYCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_SoftwareInventoryCollection_CS.h"

typedef RedfishSoftwareInventoryCollection_SoftwareInventoryCollection_CS EFI_REDFISH_SOFTWAREINVENTORYCOLLECTION_CS;

RedfishCS_status
Json_SoftwareInventoryCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SOFTWAREINVENTORYCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_SoftwareInventoryCollection_JSON (EFI_REDFISH_SOFTWAREINVENTORYCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySoftwareInventoryCollection_CS (EFI_REDFISH_SOFTWAREINVENTORYCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroySoftwareInventoryCollection_Json (RedfishCS_char *JsonText);

#endif
