//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishPcieslots_V1_0_0_CSTRUCT_H_
#define _RedfishPcieslots_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishPCIeSlots_V1_0_0_PCIeSlot_Array_CS RedfishPCIeSlots_V1_0_0_PCIeSlot_Array_CS;
typedef struct _RedfishPCIeSlots_V1_0_0_Actions_CS RedfishPCIeSlots_V1_0_0_Actions_CS;
typedef struct _RedfishPCIeSlots_V1_0_0_OemActions_CS RedfishPCIeSlots_V1_0_0_OemActions_CS;
typedef struct _RedfishPCIeSlots_V1_0_0_PCIeLinks_CS RedfishPCIeSlots_V1_0_0_PCIeLinks_CS;
typedef struct _RedfishPCIeSlots_V1_0_0_PCIeSlot_CS RedfishPCIeSlots_V1_0_0_PCIeSlot_CS;
typedef struct _RedfishPCIeSlots_V1_0_0_PCIeSlots_CS RedfishPCIeSlots_V1_0_0_PCIeSlots_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishPCIeSlots_V1_0_0_Actions_CS {
    RedfishPCIeSlots_V1_0_0_OemActions_CS    *Oem;    // This property contains the
                                                     // available OEM specific actions
                                                     // for this resource.
} RedfishPCIeSlots_V1_0_0_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishPCIeSlots_V1_0_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishPCIeSlots_V1_0_0_OemActions_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishPCIeSlots_V1_0_0_PCIeLinks_CS {
    RedfishResource_Oem_CS    *Oem;                     // Oem extension object.
    RedfishCS_Link            PCIeDevice;               // An array of references to the
                                                        // PCIe Devices contained in this
                                                        // slot.
    RedfishCS_int64           *PCIeDeviceodata_count;
} RedfishPCIeSlots_V1_0_0_PCIeLinks_CS;

//
// This is the definition for a PCI slot information object.
//
typedef struct _RedfishPCIeSlots_V1_0_0_PCIeSlot_CS {
    RedfishCS_int64                         *Lanes;      // This is the number of PCIe
                                                         // lanes supported by this slot.
    RedfishPCIeSlots_V1_0_0_PCIeLinks_CS    *Links;      // Contains references to other
                                                         // resources that are related to
                                                         // this resource.
    RedfishCS_Link                          Location;    // The Location of the PCIe slot.
    RedfishResource_Oem_CS                  *Oem;        // Oem extension object.
    RedfishCS_char                          *PCIeType;    // This is the PCIe specification
                                                         // supported by this slot.
    RedfishCS_char                          *SlotType;    // This is the PCIe slot type for
                                                         // this slot.
    RedfishResource_Status_CS               *Status;     // This property describes the
                                                         // status and health of the
                                                         // resource and its children.
} RedfishPCIeSlots_V1_0_0_PCIeSlot_CS;

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
// This is the schema definition for the PCIe Slot properties.
//
typedef struct _RedfishPCIeSlots_V1_0_0_PCIeSlots_CS {
    RedfishCS_Header                             Header;
    RedfishCS_char                               *odata_context;
    RedfishCS_char                               *odata_etag;  
    RedfishCS_char                               *odata_id;    
    RedfishCS_char                               *odata_type;  
    RedfishPCIeSlots_V1_0_0_Actions_CS           *Actions;         // The available actions for this
                                                                   // resource.
    RedfishCS_char                               *Description; 
    RedfishCS_char                               *Id;          
    RedfishCS_char                               *Name;        
    RedfishResource_Oem_CS                       *Oem;             // This is the
                                                                   // manufacturer/provider specific
                                                                   // extension moniker used to
                                                                   // divide the Oem object into
                                                                   // sections.
    RedfishPCIeSlots_V1_0_0_PCIeSlot_Array_CS    *Slots;           // An array of PCI Slot
                                                                   // information.
} RedfishPCIeSlots_V1_0_0_PCIeSlots_CS;

typedef struct _RedfishPCIeSlots_V1_0_0_PCIeSlot_Array_CS  {
    RedfishPCIeSlots_V1_0_0_PCIeSlot_Array_CS    *Next;
    RedfishPCIeSlots_V1_0_0_PCIeSlot_CS    *ArrayValue;
} RedfishPCIeSlots_V1_0_0_PCIeSlot_Array_CS;

RedfishCS_status
Json_PCIeSlots_V1_0_0_To_CS (char *JsonRawText, RedfishPCIeSlots_V1_0_0_PCIeSlots_CS **ReturnedCS);

RedfishCS_status
CS_To_PCIeSlots_V1_0_0_JSON (RedfishPCIeSlots_V1_0_0_PCIeSlots_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyPCIeSlots_V1_0_0_CS (RedfishPCIeSlots_V1_0_0_PCIeSlots_CS *CSPtr);

RedfishCS_status
DestroyPCIeSlots_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
