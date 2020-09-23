//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHENDPOINTCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHENDPOINTCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_EndpointCollection_CS.h"

typedef RedfishEndpointCollection_EndpointCollection_CS EFI_REDFISH_ENDPOINTCOLLECTION_CS;

RedfishCS_status
Json_EndpointCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_ENDPOINTCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_EndpointCollection_JSON (EFI_REDFISH_ENDPOINTCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyEndpointCollection_CS (EFI_REDFISH_ENDPOINTCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyEndpointCollection_Json (RedfishCS_char *JsonText);

#endif
