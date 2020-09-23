/** @file
  This file defines the EFI Redfish C Structure Interpreter for Power v1_4_2

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#ifndef __EFI_REDFISH_INTERP_POWER_V1_4_2_H__
#define __EFI_REDFISH_INTERP_POWER_V1_4_2_H__

#include <Uefi.h>
#include <Protocol/RestResourceInterpreter.h>
#include "Library/RfishCS/edk2/Power/v1_4_2/Redfish_Power_v1_4_2_CS.h"
//
// EFI structure of Redfish Power v1_4_2
//
typedef struct _EFI_REDFISH_POWER_V1_4_2 {
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER Header;
  EFI_REDFISH_POWER_V1_4_2_CS *Power;
} EFI_REDFISH_POWER_V1_4_2;

#endif
