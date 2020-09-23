//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMETRICDEFINITIONCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMETRICDEFINITIONCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MetricDefinitionCollection_CS.h"

typedef RedfishMetricDefinitionCollection_MetricDefinitionCollection_CS EFI_REDFISH_METRICDEFINITIONCOLLECTION_CS;

RedfishCS_status
Json_MetricDefinitionCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_METRICDEFINITIONCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MetricDefinitionCollection_JSON (EFI_REDFISH_METRICDEFINITIONCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMetricDefinitionCollection_CS (EFI_REDFISH_METRICDEFINITIONCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMetricDefinitionCollection_Json (RedfishCS_char *JsonText);

#endif
