//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHNETWORKPORTCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHNETWORKPORTCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_NetworkPortCollection_CS.h"

typedef RedfishNetworkPortCollection_NetworkPortCollection_CS EFI_REDFISH_NETWORKPORTCOLLECTION_CS;

RedfishCS_status
Json_NetworkPortCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_NETWORKPORTCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_NetworkPortCollection_JSON (EFI_REDFISH_NETWORKPORTCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyNetworkPortCollection_CS (EFI_REDFISH_NETWORKPORTCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyNetworkPortCollection_Json (RedfishCS_char *JsonText);

#endif
