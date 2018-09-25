/** @file
   
  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/
#ifndef _REDFISH_CS_DATA_TYPE_H_
#define _REDFISH_CS_DATA_TYPE_H_

#include <jansson.h>

typedef char               RedfishCS_char;
typedef int                RedfishCS_bool;
typedef signed char        RedfishCS_int8;
typedef unsigned char      RedfishCS_uint8;
typedef int                RedfishCS_int16;
typedef int                RedfishCS_int;
typedef unsigned int       RedfishCS_uint16;
typedef long int           RedfishCS_int32;
typedef unsigned long int  RedfishCS_uint32;
typedef long long          RedfishCS_int64;
typedef unsigned long long RedfishCS_uint64;
typedef void               RedfishCS_void;

#define RedfishCS_boolean_false 0
#define RedfishCS_boolean_true  1

typedef RedfishCS_int64 RedfishCS_status;
#define RedfishCS_status_success               0
#define RedfishCS_status_unsupported          -1
#define RedfishCS_status_invalid_parameter    -2
#define RedfishCS_status_insufficient_memory  -3
#define RedfishCS_status_not_found            -4
#define RedfishCS_status_unknown_error        -5

typedef struct _RedfishCS_Link RedfishCS_Link;
struct _RedfishCS_Link {
  RedfishCS_Link *BackLink;
  RedfishCS_Link *ForwardLink;
};

#endif


