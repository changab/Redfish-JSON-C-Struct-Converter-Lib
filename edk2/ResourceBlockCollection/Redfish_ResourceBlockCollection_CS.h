//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHRESOURCEBLOCKCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHRESOURCEBLOCKCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ResourceBlockCollection_CS.h"

typedef RedfishResourceBlockCollection_ResourceBlockCollection_CS EFI_REDFISH_RESOURCEBLOCKCOLLECTION_CS;

RedfishCS_status
Json_ResourceBlockCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_RESOURCEBLOCKCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ResourceBlockCollection_JSON (EFI_REDFISH_RESOURCEBLOCKCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyResourceBlockCollection_CS (EFI_REDFISH_RESOURCEBLOCKCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyResourceBlockCollection_Json (RedfishCS_char *JsonText);

#endif
