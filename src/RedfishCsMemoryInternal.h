/** @file
   
  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
  This software contains information confidential and proprietary to
  Hewlett Packard Enterprise. It shall not be reproduced in whole or in part,
  or transferred to other documents, or disclosed to third parties, or used
  for any purpose other than that for which it was obtained without the prior
  written consent of Hewlett Packard Enterprise.

**/
#ifndef _REDFISH_CS_MEMORY_INTERNAL_H_
#define _REDFISH_CS_MEMORY_INTERNAL_H_

#include "RedfishDataTypeDef.h"

RedfishCS_Link * InitializeLinkHead (RedfishCS_Link *LinkHead);
RedfishCS_Link * InsertHeadLink (RedfishCS_Link *ListHead, RedfishCS_Link *Entry);
RedfishCS_Link * InsertTailLink (RedfishCS_Link *ListHead, RedfishCS_Link *Entry);
RedfishCS_Link * GetFirstLink (const RedfishCS_Link *List);
RedfishCS_Link * GetLastLink (const RedfishCS_Link *List);
RedfishCS_Link * GetNextLink (const RedfishCS_Link *List, const RedfishCS_Link *Node);
RedfishCS_Link * GetPreviousLink ( const RedfishCS_Link *List, const RedfishCS_Link *Node);
RedfishCS_Link *RemoveLink ( const RedfishCS_Link *Link);
RedfishCS_bool IsLinkEmpty (const RedfishCS_Link *LinkHead);
RedfishCS_bool IsLinkAtEnd (const RedfishCS_Link *LinkHead, const RedfishCS_Link *ThisLink);

typedef struct _RedfishCS_Internal_memory_link {
  RedfishCS_Link nextLink;
  void           *memoryPtr;
} RedfishCS_Internal_memory_link;

typedef struct _RedfishCS_Internal_memory_root {
  RedfishCS_Link  nextRoot;
  RedfishCS_Link  memBlocks;
  void            *CsPtr;
} RedfishCS_Internal_memory_root;

#endif


