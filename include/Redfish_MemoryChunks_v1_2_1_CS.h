//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishMemorychunks_V1_2_1_CSTRUCT_H_
#define _RedfishMemorychunks_V1_2_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishMemoryChunks_V1_2_1_InterleaveSet_Array_CS RedfishMemoryChunks_V1_2_1_InterleaveSet_Array_CS;
typedef struct _RedfishMemoryChunks_V1_2_1_Actions_CS RedfishMemoryChunks_V1_2_1_Actions_CS;
typedef struct _RedfishMemoryChunks_V1_2_1_InterleaveSet_CS RedfishMemoryChunks_V1_2_1_InterleaveSet_CS;
typedef struct _RedfishMemoryChunks_V1_2_1_MemoryChunks_CS RedfishMemoryChunks_V1_2_1_MemoryChunks_CS;
typedef struct _RedfishMemoryChunks_V1_2_1_OemActions_CS RedfishMemoryChunks_V1_2_1_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __Redfishodata_V4_0_2_idRef_CS__
typedef struct _Redfishodata_V4_0_2_idRef_CS Redfishodata_V4_0_2_idRef_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishMemoryChunks_V1_2_1_Actions_CS {
    RedfishMemoryChunks_V1_2_1_OemActions_CS    *Oem;
} RedfishMemoryChunks_V1_2_1_Actions_CS;

//
// This an interleave set for a memory chunk.
//
typedef struct _RedfishMemoryChunks_V1_2_1_InterleaveSet_CS {
    Redfishodata_V4_0_2_idRef_CS    *Memory;        // Describes a memory device of
                                                    // the interleave set.
    RedfishCS_int64                 *MemoryLevel;    // Level of the interleave set
                                                    // for multi-level tiered memory.
    RedfishCS_int64                 *OffsetMiB;     // Offset within the DIMM that
                                                    // corresponds to the start of
                                                    // this memory region, measured
                                                    // in mebibytes (MiB).
    RedfishCS_char                  *RegionId;      // DIMM region identifier.
    RedfishCS_int64                 *SizeMiB;       // Size of this memory region
                                                    // measured in mebibytes (MiB).
} RedfishMemoryChunks_V1_2_1_InterleaveSet_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishMemoryChunks_V1_2_1_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishMemoryChunks_V1_2_1_OemActions_CS;

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
// This type describes the status and health of a resource and its children.
//
#ifndef __RedfishResource_Status_CS__
#define __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS {
    RedfishCS_char            *Health;         // This represents the health
                                               // state of this resource in the
                                               // absence of its dependent
                                               // resources.
    RedfishCS_char            *HealthRollup;    // This represents the overall
                                               // health state from the view of
                                               // this resource.
    RedfishResource_Oem_CS    *Oem;            // Oem extension object.
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// A reference to a resource.
//
#ifndef __Redfishodata_V4_0_2_idRef_CS__
#define __Redfishodata_V4_0_2_idRef_CS__
typedef struct _Redfishodata_V4_0_2_idRef_CS {
    RedfishCS_char    *odata_id;
} Redfishodata_V4_0_2_idRef_CS;
#endif

//
// This is the schema definition of a Memory Chunk and its configuration.
//
typedef struct _RedfishMemoryChunks_V1_2_1_MemoryChunks_CS {
    RedfishCS_Header                                     Header;
    RedfishCS_char                                       *odata_context;    
    RedfishCS_char                                       *odata_etag;       
    RedfishCS_char                                       *odata_id;         
    RedfishCS_char                                       *odata_type;       
    RedfishMemoryChunks_V1_2_1_Actions_CS                *Actions;              // The available actions for this
                                                                                // resource.
    RedfishCS_char                                       *AddressRangeType;     // Memory type of this memory
                                                                                // chunk.
    RedfishCS_char                                       *Description;      
    RedfishCS_char                                       *Id;               
    RedfishMemoryChunks_V1_2_1_InterleaveSet_Array_CS    *InterleaveSets;       // This is the interleave sets
                                                                                // for the memory chunk.
    RedfishCS_bool                                       *IsMirrorEnabled;      // Mirror Enabled status.
    RedfishCS_bool                                       *IsSpare;              // Spare enabled status.
    RedfishCS_int64                                      *MemoryChunkSizeMiB;    // Size of the memory chunk
                                                                                // measured in mebibytes (MiB).
    RedfishCS_char                                       *Name;             
    RedfishResource_Oem_CS                               *Oem;                  // This is the
                                                                                // manufacturer/provider specific
                                                                                // extension moniker used to
                                                                                // divide the Oem object into
                                                                                // sections.
    RedfishResource_Status_CS                            *Status;           
} RedfishMemoryChunks_V1_2_1_MemoryChunks_CS;

typedef struct _RedfishMemoryChunks_V1_2_1_InterleaveSet_Array_CS  {
    RedfishMemoryChunks_V1_2_1_InterleaveSet_Array_CS    *Next;
    RedfishMemoryChunks_V1_2_1_InterleaveSet_CS    *ArrayValue;
} RedfishMemoryChunks_V1_2_1_InterleaveSet_Array_CS;

RedfishCS_status
Json_MemoryChunks_V1_2_1_To_CS (char *JsonRawText, RedfishMemoryChunks_V1_2_1_MemoryChunks_CS **ReturnedCS);

RedfishCS_status
CS_To_MemoryChunks_V1_2_1_JSON (RedfishMemoryChunks_V1_2_1_MemoryChunks_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyMemoryChunks_V1_2_1_CS (RedfishMemoryChunks_V1_2_1_MemoryChunks_CS *CSPtr);

RedfishCS_status
DestroyMemoryChunks_V1_2_1_Json (RedfishCS_char *JsonText);

#endif
