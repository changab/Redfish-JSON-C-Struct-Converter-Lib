//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSIMPLESTORAGECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHSIMPLESTORAGECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_SimpleStorageCollection_CS.h"

typedef RedfishSimpleStorageCollection_SimpleStorageCollection_CS EFI_REDFISH_SIMPLESTORAGECOLLECTION_CS;

RedfishCS_status
Json_SimpleStorageCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_SIMPLESTORAGECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_SimpleStorageCollection_JSON (EFI_REDFISH_SIMPLESTORAGECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroySimpleStorageCollection_CS (EFI_REDFISH_SIMPLESTORAGECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroySimpleStorageCollection_Json (RedfishCS_char *JsonText);

#endif
