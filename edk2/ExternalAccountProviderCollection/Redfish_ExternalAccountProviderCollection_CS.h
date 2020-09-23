//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHEXTERNALACCOUNTPROVIDERCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHEXTERNALACCOUNTPROVIDERCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ExternalAccountProviderCollection_CS.h"

typedef RedfishExternalAccountProviderCollection_ExternalAccountProviderCollection_CS EFI_REDFISH_EXTERNALACCOUNTPROVIDERCOLLECTION_CS;

RedfishCS_status
Json_ExternalAccountProviderCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_EXTERNALACCOUNTPROVIDERCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ExternalAccountProviderCollection_JSON (EFI_REDFISH_EXTERNALACCOUNTPROVIDERCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyExternalAccountProviderCollection_CS (EFI_REDFISH_EXTERNALACCOUNTPROVIDERCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyExternalAccountProviderCollection_Json (RedfishCS_char *JsonText);

#endif
