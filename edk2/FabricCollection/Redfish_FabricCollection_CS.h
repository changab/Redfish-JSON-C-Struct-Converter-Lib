//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHFABRICCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHFABRICCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_FabricCollection_CS.h"

typedef RedfishFabricCollection_FabricCollection_CS EFI_REDFISH_FABRICCOLLECTION_CS;

RedfishCS_status
Json_FabricCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_FABRICCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_FabricCollection_JSON (EFI_REDFISH_FABRICCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyFabricCollection_CS (EFI_REDFISH_FABRICCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyFabricCollection_Json (RedfishCS_char *JsonText);

#endif
