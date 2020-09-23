//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHCOMPOSITIONSERVICE_V1_0_2_CSTRUCT_H_
#define _EFI_REDFISHCOMPOSITIONSERVICE_V1_0_2_CSTRUCT_H_

#include "../../RedfishDataTypeDef.h"
#include "../../../include/Redfish_CompositionService_v1_0_2_CS.h"

typedef RedfishCompositionService_V1_0_2_CompositionService_CS EFI_REDFISH_COMPOSITIONSERVICE_V1_0_2_CS;

RedfishCS_status
Json_CompositionService_V1_0_2_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_COMPOSITIONSERVICE_V1_0_2_CS **ReturnedCs);

RedfishCS_status
CS_To_CompositionService_V1_0_2_JSON (EFI_REDFISH_COMPOSITIONSERVICE_V1_0_2_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyCompositionService_V1_0_2_CS (EFI_REDFISH_COMPOSITIONSERVICE_V1_0_2_CS *CSPtr);

RedfishCS_status
DestroyCompositionService_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
