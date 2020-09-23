//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHBOOTOPTIONCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHBOOTOPTIONCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_BootOptionCollection_CS.h"

typedef RedfishBootOptionCollection_BootOptionCollection_CS EFI_REDFISH_BOOTOPTIONCOLLECTION_CS;

RedfishCS_status
Json_BootOptionCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_BOOTOPTIONCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_BootOptionCollection_JSON (EFI_REDFISH_BOOTOPTIONCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyBootOptionCollection_CS (EFI_REDFISH_BOOTOPTIONCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyBootOptionCollection_Json (RedfishCS_char *JsonText);

#endif
