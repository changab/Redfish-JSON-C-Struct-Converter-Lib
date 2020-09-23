/** @file
  This file defines the EFI Redfish C Structure Interpreter for Chassis v1_2_2

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#ifndef __EFI_REDFISH_INTERP_CHASSIS_V1_2_2_H__
#define __EFI_REDFISH_INTERP_CHASSIS_V1_2_2_H__

#include <Uefi.h>
#include <Protocol/RestResourceInterpreter.h>
#include "Library/RfishCS/edk2/Chassis/v1_2_2/Redfish_Chassis_v1_2_2_CS.h"
//
// EFI structure of Redfish Chassis v1_2_2
//
typedef struct _EFI_REDFISH_CHASSIS_V1_2_2 {
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER Header;
  EFI_REDFISH_CHASSIS_V1_2_2_CS *Chassis;
} EFI_REDFISH_CHASSIS_V1_2_2;

#endif
