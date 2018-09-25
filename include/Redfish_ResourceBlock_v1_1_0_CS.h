//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishResourceblock_V1_1_0_CSTRUCT_H_
#define _RedfishResourceblock_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishResourceBlock_V1_1_0_Actions_CS RedfishResourceBlock_V1_1_0_Actions_CS;
typedef struct _RedfishResourceBlock_V1_1_0_CompositionStatus_CS RedfishResourceBlock_V1_1_0_CompositionStatus_CS;
typedef struct _RedfishResourceBlock_V1_1_0_Links_CS RedfishResourceBlock_V1_1_0_Links_CS;
typedef struct _RedfishResourceBlock_V1_1_0_OemActions_CS RedfishResourceBlock_V1_1_0_OemActions_CS;
typedef struct _RedfishResourceBlock_V1_1_0_ResourceBlock_CS RedfishResourceBlock_V1_1_0_ResourceBlock_CS;
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
    RedfishResource_Oem_CS    *Oem;        
    RedfishCS_char            *State;          // This indicates the known state
                                               // of the resource, such as if it
                                               // is enabled.
} RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishResourceBlock_V1_1_0_Actions_CS {
    RedfishResourceBlock_V1_1_0_OemActions_CS    *Oem;
} RedfishResourceBlock_V1_1_0_Actions_CS;

//
// Composition status of the Resource Block.
//
typedef struct _RedfishResourceBlock_V1_1_0_CompositionStatus_CS {
    RedfishCS_char     *CompositionState;       // This property represents the
                                                // current state of the Resource
                                                // Block from a composition
                                                // perspective.
    RedfishCS_int64    *MaxCompositions;        // The maximum number of
                                                // compositions in which this
                                                // Resource Block is capable of
                                                // participating simultaneously.
    RedfishCS_int64    *NumberOfCompositions;    // The number of compositions in
                                                // which this Resource Block is
                                                // currently participating.
    RedfishCS_bool     *Reserved;               // This represents if the
                                                // Resource Block is reserved by
                                                // any client.
    RedfishCS_bool     *SharingCapable;         // Indicates if this Resource
                                                // Block is capable of
                                                // participating in multiple
                                                // compositions simultaneously.
    RedfishCS_bool     *SharingEnabled;         // Indicates if this Resource
                                                // Block is allowed to
                                                // participate in multiple
                                                // compositions simultaneously.
} RedfishResourceBlock_V1_1_0_CompositionStatus_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishResourceBlock_V1_1_0_Links_CS {
    RedfishCS_Link            Chassis;                       // An array of references to the
                                                             // Chassis in which this Resource
                                                             // Block is contained.
    RedfishCS_int64           *Chassisodata_count;       
    RedfishCS_Link            ComputerSystems;               // An array of references to the
                                                             // Computer Systems that are
                                                             // composed from this Resource
                                                             // Block.
    RedfishCS_int64           *ComputerSystemsodata_count;
    RedfishResource_Oem_CS    *Oem;                          // Oem extension object.
    RedfishCS_Link            Zones;                         // An array of references to the
                                                             // Zones in which this Resource
                                                             // Block is bound.
    RedfishCS_int64           *Zonesodata_count;         
} RedfishResourceBlock_V1_1_0_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishResourceBlock_V1_1_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishResourceBlock_V1_1_0_OemActions_CS;

//
// This schema defines a Resource Block resource.
//
typedef struct _RedfishResourceBlock_V1_1_0_ResourceBlock_CS {
    RedfishCS_Header                                    Header;
    RedfishCS_char                                      *odata_context;               
    RedfishCS_char                                      *odata_etag;                  
    RedfishCS_char                                      *odata_id;                    
    RedfishCS_char                                      *odata_type;                  
    RedfishResourceBlock_V1_1_0_Actions_CS              *Actions;                         // The available actions for this
                                                                                          // resource.
    RedfishResourceBlock_V1_1_0_CompositionStatus_CS    *CompositionStatus;               // This property describes the
                                                                                          // composition status details for
                                                                                          // this Resource Block.
    RedfishCS_Link                                      ComputerSystems;                  // An array of references to the
                                                                                          // Computer Systems available in
                                                                                          // this Resource Block.
    RedfishCS_int64                                     *ComputerSystemsodata_count;  
    RedfishCS_char                                      *Description;                 
    RedfishCS_Link                                      EthernetInterfaces;               // An array of references to the
                                                                                          // Ethernet Interfaces available
                                                                                          // in this Resource Block.
    RedfishCS_int64                                     *EthernetInterfacesodata_count;
    RedfishCS_char                                      *Id;                          
    RedfishResourceBlock_V1_1_0_Links_CS                *Links;                           // Contains references to other
                                                                                          // resources that are related to
                                                                                          // this resource.
    RedfishCS_Link                                      Memory;                           // An array of references to the
                                                                                          // Memory available in this
                                                                                          // Resource Block.
    RedfishCS_int64                                     *Memoryodata_count;           
    RedfishCS_char                                      *Name;                        
    RedfishCS_Link                                      NetworkInterfaces;                // An array of references to the
                                                                                          // Network Interfaces available
                                                                                          // in this Resource Block.
    RedfishCS_int64                                     *NetworkInterfacesodata_count;
    RedfishResource_Oem_CS                              *Oem;                             // This is the
                                                                                          // manufacturer/provider specific
                                                                                          // extension moniker used to
                                                                                          // divide the Oem object into
                                                                                          // sections.
    RedfishCS_Link                                      Processors;                       // An array of references to the
                                                                                          // Processors available in this
                                                                                          // Resource Block.
    RedfishCS_int64                                     *Processorsodata_count;       
    RedfishCS_char_Array                                *ResourceBlockType;               // This property represents the
                                                                                          // types of resources available
                                                                                          // on this Resource Block.
    RedfishCS_Link                                      SimpleStorage;                    // An array of references to the
                                                                                          // Simple Storage available in
                                                                                          // this Resource Block.
    RedfishCS_int64                                     *SimpleStorageodata_count;    
    RedfishResource_Status_CS                           *Status;                      
    RedfishCS_Link                                      Storage;                          // An array of references to the
                                                                                          // Storage available in this
                                                                                          // Resource Block.
    RedfishCS_int64                                     *Storageodata_count;          
} RedfishResourceBlock_V1_1_0_ResourceBlock_CS;

RedfishCS_status
Json_ResourceBlock_V1_1_0_To_CS (char *JsonRawText, RedfishResourceBlock_V1_1_0_ResourceBlock_CS **ReturnedCS);

RedfishCS_status
CS_To_ResourceBlock_V1_1_0_JSON (RedfishResourceBlock_V1_1_0_ResourceBlock_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyResourceBlock_V1_1_0_CS (RedfishResourceBlock_V1_1_0_ResourceBlock_CS *CSPtr);

RedfishCS_status
DestroyResourceBlock_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
