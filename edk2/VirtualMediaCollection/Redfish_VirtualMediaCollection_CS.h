//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHVIRTUALMEDIACOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHVIRTUALMEDIACOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_VirtualMediaCollection_CS.h"

typedef RedfishVirtualMediaCollection_VirtualMediaCollection_CS EFI_REDFISH_VIRTUALMEDIACOLLECTION_CS;

RedfishCS_status
Json_VirtualMediaCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_VIRTUALMEDIACOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_VirtualMediaCollection_JSON (EFI_REDFISH_VIRTUALMEDIACOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyVirtualMediaCollection_CS (EFI_REDFISH_VIRTUALMEDIACOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyVirtualMediaCollection_Json (RedfishCS_char *JsonText);

#endif
