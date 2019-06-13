//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishCompositionservice_V1_0_0_CSTRUCT_H_
#define _RedfishCompositionservice_V1_0_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishCompositionService_V1_0_0_CompositionService_CS RedfishCompositionService_V1_0_0_CompositionService_CS;
typedef struct _RedfishCompositionService_V1_0_0_CompositionService_Actions_CS RedfishCompositionService_V1_0_0_CompositionService_Actions_CS;
typedef struct _RedfishCompositionService_V1_0_0_CompositionService_Actions_Oem_CS RedfishCompositionService_V1_0_0_CompositionService_Actions_Oem_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishCompositionService_V1_0_0_CompositionService_Actions_CS {
    RedfishCompositionService_V1_0_0_CompositionService_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                                  // actions for this resource.
} RedfishCompositionService_V1_0_0_CompositionService_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishCompositionService_V1_0_0_CompositionService_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishCompositionService_V1_0_0_CompositionService_Actions_Oem_CS;

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
// This is the schema definition for the Composition Service.  It represents the
// properties for the service itself and has links to the actual list of resources
// available for composition.
//
typedef struct _RedfishCompositionService_V1_0_0_CompositionService_CS {
    RedfishCS_Header                                                  Header;
    RedfishCS_char                                                    *odata_context;
    RedfishCS_char                                                    *odata_id;     
    RedfishCS_char                                                    *odata_type;   
    RedfishCompositionService_V1_0_0_CompositionService_Actions_CS    *Actions;          // The available actions for this
                                                                                         // resource.
    RedfishCS_char                                                    *Description;  
    RedfishCS_char                                                    *Id;           
    RedfishCS_char                                                    *Name;         
    RedfishResource_Oem_CS                                            *Oem;              // This is the
                                                                                         // manufacturer/provider specific
                                                                                         // extension moniker used to
                                                                                         // divide the Oem object into
                                                                                         // sections.
    RedfishCS_Link                                                    ResourceBlocks;    // The resource blocks available
                                                                                         // on the service.
    RedfishCS_Link                                                    ResourceZones;     // The resource zones available
                                                                                         // on the service.
    RedfishCS_bool                                                    *ServiceEnabled;    // This indicates whether this
                                                                                         // service is enabled.
    RedfishResource_Status_CS                                         *Status;       
} RedfishCompositionService_V1_0_0_CompositionService_CS;

RedfishCS_status
Json_CompositionService_V1_0_0_To_CS (char *JsonRawText, RedfishCompositionService_V1_0_0_CompositionService_CS **ReturnedCS);

RedfishCS_status
CS_To_CompositionService_V1_0_0_JSON (RedfishCompositionService_V1_0_0_CompositionService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyCompositionService_V1_0_0_CS (RedfishCompositionService_V1_0_0_CompositionService_CS *CSPtr);

RedfishCS_status
DestroyCompositionService_V1_0_0_Json (RedfishCS_char *JsonText);

#endif
