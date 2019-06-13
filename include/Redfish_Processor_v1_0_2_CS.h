//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishProcessor_V1_0_2_CSTRUCT_H_
#define _RedfishProcessor_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishProcessor_V1_0_2_Processor_CS RedfishProcessor_V1_0_2_Processor_CS;
typedef struct _RedfishProcessor_V1_0_2_ProcessorId_CS RedfishProcessor_V1_0_2_ProcessorId_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishProcessor_V1_0_2_ProcessorId_CS {
    RedfishCS_char    *EffectiveFamily;           // The effective Family for this
                                                  // processor
    RedfishCS_char    *EffectiveModel;            // The effective Model for this
                                                  // processor
    RedfishCS_char    *IdentificationRegisters;    // The contents of the
                                                  // Identification Registers
                                                  // (CPUID) for this processor
    RedfishCS_char    *MicrocodeInfo;             // The Microcode Information for
                                                  // this processor
    RedfishCS_char    *Step;                      // The Step value for this
                                                  // processor
    RedfishCS_char    *VendorId;                  // The Vendor Identification for
                                                  // this processor
} RedfishProcessor_V1_0_2_ProcessorId_CS;

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
// This is the schema definition for the Processor resource.  It represents the
// properties of a processor attached to a System.
//
typedef struct _RedfishProcessor_V1_0_2_Processor_CS {
    RedfishCS_Header                          Header;
    RedfishCS_char                            *odata_context;       
    RedfishCS_char                            *odata_id;            
    RedfishCS_char                            *odata_type;          
    RedfishCS_char                            *Description;         
    RedfishCS_char                            *Id;                  
    RedfishCS_char                            *InstructionSet;          // The instruction set of the
                                                                        // processor
    RedfishCS_char                            *Manufacturer;            // The processor manufacturer
    RedfishCS_int64                           *MaxSpeedMHz;             // The maximum clock speed of the
                                                                        // processor
    RedfishCS_char                            *Model;                   // The product model number of
                                                                        // this device
    RedfishCS_char                            *Name;                
    RedfishResource_Oem_CS                    *Oem;                     // This is the
                                                                        // manufacturer/provider specific
                                                                        // extension moniker used to
                                                                        // divide the Oem object into
                                                                        // sections.
    RedfishCS_char                            *ProcessorArchitecture;    // The architecture of the
                                                                        // processor
    RedfishProcessor_V1_0_2_ProcessorId_CS    *ProcessorId;             // Identification information for
                                                                        // this processor.
    RedfishCS_char                            *ProcessorType;           // The type of processor
    RedfishCS_char                            *Socket;                  // The socket or location of the
                                                                        // processor
    RedfishResource_Status_CS                 *Status;              
    RedfishCS_int64                           *TotalCores;              // The total number of cores
                                                                        // contained in this processor
    RedfishCS_int64                           *TotalThreads;            // The total number of execution
                                                                        // threads supported by this
                                                                        // processor
} RedfishProcessor_V1_0_2_Processor_CS;

RedfishCS_status
Json_Processor_V1_0_2_To_CS (char *JsonRawText, RedfishProcessor_V1_0_2_Processor_CS **ReturnedCS);

RedfishCS_status
CS_To_Processor_V1_0_2_JSON (RedfishProcessor_V1_0_2_Processor_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyProcessor_V1_0_2_CS (RedfishProcessor_V1_0_2_Processor_CS *CSPtr);

RedfishCS_status
DestroyProcessor_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
