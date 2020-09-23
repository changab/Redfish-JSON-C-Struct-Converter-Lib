//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHPROCESSORCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHPROCESSORCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_ProcessorCollection_CS.h"

typedef RedfishProcessorCollection_ProcessorCollection_CS EFI_REDFISH_PROCESSORCOLLECTION_CS;

RedfishCS_status
Json_ProcessorCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_PROCESSORCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_ProcessorCollection_JSON (EFI_REDFISH_PROCESSORCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyProcessorCollection_CS (EFI_REDFISH_PROCESSORCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyProcessorCollection_Json (RedfishCS_char *JsonText);

#endif
