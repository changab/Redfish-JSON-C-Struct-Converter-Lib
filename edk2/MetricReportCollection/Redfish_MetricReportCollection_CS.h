//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _EFI_REDFISHMETRICREPORTCOLLECTION_CSTRUCT_H_
#define _EFI_REDFISHMETRICREPORTCOLLECTION_CSTRUCT_H_

#include "../RedfishDataTypeDef.h"
#include "../../include/Redfish_MetricReportCollection_CS.h"

typedef RedfishMetricReportCollection_MetricReportCollection_CS EFI_REDFISH_METRICREPORTCOLLECTION_CS;

RedfishCS_status
Json_MetricReportCollection_To_CS (RedfishCS_char *JsonRawText, EFI_REDFISH_METRICREPORTCOLLECTION_CS **ReturnedCs);

RedfishCS_status
CS_To_MetricReportCollection_JSON (EFI_REDFISH_METRICREPORTCOLLECTION_CS *CSPtr, RedfishCS_char **JsonText);

RedfishCS_status
DestroyMetricReportCollection_CS (EFI_REDFISH_METRICREPORTCOLLECTION_CS *CSPtr);

RedfishCS_status
DestroyMetricReportCollection_Json (RedfishCS_char *JsonText);

#endif
