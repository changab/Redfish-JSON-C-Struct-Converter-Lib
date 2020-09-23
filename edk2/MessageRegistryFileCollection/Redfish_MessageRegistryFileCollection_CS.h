//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMESSAGEREGISTRYFILECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMESSAGEREGISTRYFILECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MessageRegistryFileCollection_CS.h"

typedef RedfishMessageRegistryFileCollection_MessageRegistryFileCollection_CS EFI_REDFISH_MESSAGEREGISTRYFILECOLLECTION_CS;

RedfishCS_status
Json_MessageRegistryFileCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_MESSAGEREGISTRYFILECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MessageRegistryFileCollection_JSON (EFI_REDFISH_MESSAGEREGISTRYFILECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMessageRegistryFileCollection_CS (EFI_REDFISH_MESSAGEREGISTRYFILECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMessageRegistryFileCollection_Json (RedfishCS_char *JsonText);

#endif
