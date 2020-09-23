//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPORTCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHPORTCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_PortCollection_CS.h"

typedef RedfishPortCollection_PortCollection_CS EFI_REDFISH_PORTCOLLECTION_CS;

RedfishCS_status
Json_PortCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_PORTCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_PortCollection_JSON (EFI_REDFISH_PORTCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyPortCollection_CS (EFI_REDFISH_PORTCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyPortCollection_Json (RedfishCS_char *JsonText);

#endif
