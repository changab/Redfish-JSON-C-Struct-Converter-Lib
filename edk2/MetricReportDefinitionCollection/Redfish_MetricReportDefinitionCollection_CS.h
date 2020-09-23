//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMETRICREPORTDEFINITIONCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMETRICREPORTDEFINITIONCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MetricReportDefinitionCollection_CS.h"

typedef RedfishMetricReportDefinitionCollection_MetricReportDefinitionCollection_CS EFI_REDFISH_METRICREPORTDEFINITIONCOLLECTION_CS;

RedfishCS_status
Json_MetricReportDefinitionCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_METRICREPORTDEFINITIONCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MetricReportDefinitionCollection_JSON (EFI_REDFISH_METRICREPORTDEFINITIONCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMetricReportDefinitionCollection_CS (EFI_REDFISH_METRICREPORTDEFINITIONCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMetricReportDefinitionCollection_Json (RedfishCS_char *JsonText);

#endif
