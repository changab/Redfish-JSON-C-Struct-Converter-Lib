//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSoftwareinventory_V1_0_2_CSTRUCT_H_
#define _RedfishSoftwareinventory_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS;
typedef struct _RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_CS RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_CS;
typedef struct _RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_Oem_CS RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_Oem_CS;
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
// The Actions object contains the available custom actions on this resource.
//
typedef struct _RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_CS {
    RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                                // actions for this resource.
} RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_Oem_CS;

//
// This schema defines an inventory of software components.
//
typedef struct _RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS {
    RedfishCS_Header                                                Header;
    RedfishCS_char                                                  *odata_context;
    RedfishCS_char                                                  *odata_id;    
    RedfishCS_char                                                  *odata_type;  
    RedfishSoftwareInventory_V1_0_2_SoftwareInventory_Actions_CS    *Actions;         // The Actions object contains
                                                                                      // the available custom actions
                                                                                      // on this resource.
    RedfishCS_char                                                  *Description; 
    RedfishCS_char                                                  *Id;          
    RedfishCS_char                                                  *Name;        
    RedfishResource_Oem_CS                                          *Oem;             // This is the
                                                                                      // manufacturer/provider specific
                                                                                      // extension moniker used to
                                                                                      // divide the Oem object into
                                                                                      // sections.
    RedfishResource_Status_CS                                       *Status;      
    RedfishCS_bool                                                  *Updateable;      // Indicates whether this
                                                                                      // software can be updated by the
                                                                                      // update service.
    RedfishCS_char                                                  *Version;         // A string representing the
                                                                                      // version of this software.
} RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS;

RedfishCS_status
Json_SoftwareInventory_V1_0_2_To_CS (char *JsonRawText, RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS **ReturnedCS);

RedfishCS_status
CS_To_SoftwareInventory_V1_0_2_JSON (RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySoftwareInventory_V1_0_2_CS (RedfishSoftwareInventory_V1_0_2_SoftwareInventory_CS *CSPtr);

RedfishCS_status
DestroySoftwareInventory_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
