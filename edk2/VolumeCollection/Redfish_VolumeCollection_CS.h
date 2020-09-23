//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHVOLUMECOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHVOLUMECOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_VolumeCollection_CS.h"

typedef RedfishVolumeCollection_VolumeCollection_CS EFI_REDFISH_VOLUMECOLLECTION_CS;

RedfishCS_status
Json_VolumeCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_VOLUMECOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_VolumeCollection_JSON (EFI_REDFISH_VOLUMECOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyVolumeCollection_CS (EFI_REDFISH_VOLUMECOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyVolumeCollection_Json (RedfishCS_char *JsonText);

#endif
