//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMemorydomain_V1_0_2_CSTRUCT_H_
#define _RedfishMemorydomain_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMemoryDomain_V1_0_2_MemorySet_Array_CS RedfishMemoryDomain_V1_0_2_MemorySet_Array_CS;
typedef struct _RedfishMemoryDomain_V1_0_2_MemoryDomain_CS RedfishMemoryDomain_V1_0_2_MemoryDomain_CS;
typedef struct _RedfishMemoryDomain_V1_0_2_MemorySet_CS RedfishMemoryDomain_V1_0_2_MemorySet_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// This is the interleave sets for a memory chunk.
//
typedef struct _RedfishMemoryDomain_V1_0_2_MemorySet_CS {
    RedfishCS_Link     MemorySet;                        // This is the collection of
                                                         // memory for a particular
                                                         // interleave set.
    RedfishCS_int64    *MemorySetodata_count;        
    RedfishCS_char     *MemorySetodata_navigationLink;
} RedfishMemoryDomain_V1_0_2_MemorySet_CS;

//
// Oem extension object.
//
#ifndef __RedfishResource_Oem_CS__
#define __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishResource_Oem_CS;
#endif

//
// This is the schema definition of a Memory Domain and its configuration. Memory
// Domains are used to indicate to the client which Memory (DIMMs) can be grouped
// together in Memory Chunks to form interleave sets or otherwise grouped
// together.
//
typedef struct _RedfishMemoryDomain_V1_0_2_MemoryDomain_CS {
    RedfishCS_Header                                 Header;
    RedfishCS_char                                   *odata_context;           
    RedfishCS_char                                   *odata_id;                
    RedfishCS_char                                   *odata_type;              
    RedfishCS_bool                                   *AllowsBlockProvisioning;     // Indicates if this Memory
                                                                                   // Domain supports the
                                                                                   // provisioning of blocks of
                                                                                   // memory.
    RedfishCS_bool                                   *AllowsMemoryChunkCreation;    // Indicates if this Memory
                                                                                   // Domain supports the creation
                                                                                   // of Memory Chunks.
    RedfishCS_char                                   *Description;             
    RedfishCS_char                                   *Id;                      
    RedfishMemoryDomain_V1_0_2_MemorySet_Array_CS    *InterleavableMemorySets;     // This is the interleave sets
                                                                                   // for the memory chunk.
    RedfishCS_Link                                   MemoryChunks;                 // A reference to the collection
                                                                                   // of Memory Chunks associated
                                                                                   // with this Memory Domain.
    RedfishCS_char                                   *Name;                    
    RedfishResource_Oem_CS                           *Oem;                         // This is the
                                                                                   // manufacturer/provider specific
                                                                                   // extension moniker used to
                                                                                   // divide the Oem object into
                                                                                   // sections.
} RedfishMemoryDomain_V1_0_2_MemoryDomain_CS;

typedef struct _RedfishMemoryDomain_V1_0_2_MemorySet_Array_CS  {
    RedfishMemoryDomain_V1_0_2_MemorySet_Array_CS    *Next;
    RedfishMemoryDomain_V1_0_2_MemorySet_CS    *ArrayValue;
} RedfishMemoryDomain_V1_0_2_MemorySet_Array_CS;

RedfishCS_status
Json_MemoryDomain_V1_0_2_To_CS (char *JsonRawText, RedfishMemoryDomain_V1_0_2_MemoryDomain_CS **ReturnedCS);

RedfishCS_status
CS_To_MemoryDomain_V1_0_2_JSON (RedfishMemoryDomain_V1_0_2_MemoryDomain_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMemoryDomain_V1_0_2_CS (RedfishMemoryDomain_V1_0_2_MemoryDomain_CS *CSPtr);

RedfishCS_status
DestroyMemoryDomain_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
