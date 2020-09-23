/** @file
  This file defines the EFI Redfish C Structure Interpreter for ExternalAccountProvider v1_0_1

  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/

#ifndef __EFI_REDFISH_INTERP_EXTERNALACCOUNTPROVIDER_V1_0_1_H__
#define __EFI_REDFISH_INTERP_EXTERNALACCOUNTPROVIDER_V1_0_1_H__

#include <Uefi.h>
#include <Protocol/RestResourceInterpreter.h>
#include "Library/RfishCS/edk2/ExternalAccountProvider/v1_0_1/Redfish_ExternalAccountProvider_v1_0_1_CS.h"
//
// EFI structure of Redfish ExternalAccountProvider v1_0_1
//
typedef struct _EFI_REDFISH_EXTERNALACCOUNTPROVIDER_V1_0_1 {
  EFI_REST_RESOURCE_INTERPED_PROPERTY_HEADER Header;
  EFI_REDFISH_EXTERNALACCOUNTPROVIDER_V1_0_1_CS *ExternalAccountProvider;
} EFI_REDFISH_EXTERNALACCOUNTPROVIDER_V1_0_1;

#endif
