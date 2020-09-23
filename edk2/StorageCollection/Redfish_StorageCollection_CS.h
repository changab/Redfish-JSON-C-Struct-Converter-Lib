//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHSTORAGECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHSTORAGECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_StorageCollection_CS.h"

typedef RedfishStorageCollection_StorageCollection_CS EFI_REDFISH_STORAGECOLLECTION_CS;

RedfishCS_status
Json_StorageCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_STORAGECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_StorageCollection_JSON (EFI_REDFISH_STORAGECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyStorageCollection_CS (EFI_REDFISH_STORAGECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyStorageCollection_Json (RedfishCS_char *JsonText);

#endif
