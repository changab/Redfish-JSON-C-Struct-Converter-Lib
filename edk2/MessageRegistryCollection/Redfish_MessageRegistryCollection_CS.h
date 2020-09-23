//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMESSAGEREGISTRYCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMESSAGEREGISTRYCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MessageRegistryCollection_CS.h"

typedef RedfishMessageRegistryCollection_MessageRegistryCollection_CS EFI_REDFISH_MESSAGEREGISTRYCOLLECTION_CS;

RedfishCS_status
Json_MessageRegistryCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MESSAGEREGISTRYCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MessageRegistryCollection_JSON (EFI_REDFISH_MESSAGEREGISTRYCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMessageRegistryCollection_CS (EFI_REDFISH_MESSAGEREGISTRYCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMessageRegistryCollection_Json (RedfishCS_char *JsonText);

#endif
