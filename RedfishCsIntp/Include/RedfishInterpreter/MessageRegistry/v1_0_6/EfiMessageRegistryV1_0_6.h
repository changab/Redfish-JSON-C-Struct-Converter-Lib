/** @file
  This file defines the EFI Redfish C Structure Interpreter for MessageRegistry v1_0_6

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#ifndef __EFI_REDFISH_INTERP_MESSAGEREGISTRY_V1_0_6_H__
#define __EFI_REDFISH_INTERP_MESSAGEREGISTRY_V1_0_6_H__

#include <Uefi.h>
#include <Protocol/RestResourceInterpreter.h>
#include "Library/RfishCS/edk2/MessageRegistry/v1_0_6/Redfish_MessageRegistry_v1_0_6_CS.h"
//
// EFI structure of Redfish MessageRegistry v1_0_6
//
typedef struct _EFI_REDFISH_MESSAGEREGISTRY_V1_0_6 {
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER Header;
  EFI_REDFISH_MESSAGEREGISTRY_V1_0_6_CS *MessageRegistry;
} EFI_REDFISH_MESSAGEREGISTRY_V1_0_6;

#endif
