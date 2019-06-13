//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishUpdateservice_V1_1_4_CSTRUCT_H_
#define _RedfishUpdateservice_V1_1_4_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishUpdateService_V1_1_4_Actions_CS RedfishUpdateService_V1_1_4_Actions_CS;
typedef struct _RedfishUpdateService_V1_1_4_OemActions_CS RedfishUpdateService_V1_1_4_OemActions_CS;
typedef struct _RedfishUpdateService_V1_1_4_SimpleUpdate_CS RedfishUpdateService_V1_1_4_SimpleUpdate_CS;
typedef struct _RedfishUpdateService_V1_1_4_UpdateService_CS RedfishUpdateService_V1_1_4_UpdateService_CS;
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
// The available actions for this resource.
//
typedef struct _RedfishUpdateService_V1_1_4_Actions_CS {
    RedfishUpdateService_V1_1_4_SimpleUpdate_CS    *UpdateService_SimpleUpdate;
    RedfishUpdateService_V1_1_4_OemActions_CS      *Oem;                          // This property contains the
                                                                                  // available OEM specific actions
                                                                                  // for this resource.
} RedfishUpdateService_V1_1_4_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishUpdateService_V1_1_4_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishUpdateService_V1_1_4_OemActions_CS;

//
// This action is used to update software components.
//
typedef struct _RedfishUpdateService_V1_1_4_SimpleUpdate_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishUpdateService_V1_1_4_SimpleUpdate_CS;

//
// This is the schema definition for the Update Service. It represents the
// properties for the service itself and has links to collections of firmware and
// software inventory.
//
typedef struct _RedfishUpdateService_V1_1_4_UpdateService_CS {
    RedfishCS_Header                          Header;
    RedfishCS_char                            *odata_context;  
    RedfishCS_char                            *odata_etag;     
    RedfishCS_char                            *odata_id;       
    RedfishCS_char                            *odata_type;     
    RedfishUpdateService_V1_1_4_Actions_CS    *Actions;            // The available actions for this
                                                                   // resource.
    RedfishCS_char                            *Description;    
    RedfishCS_Link                            FirmwareInventory;    // An inventory of firmware.
    RedfishCS_char                            *HttpPushUri;        // The URI used to perform an
                                                                   // HTTP or HTTPS push update to
                                                                   // the Update Service.
    RedfishCS_char                            *Id;             
    RedfishCS_char                            *Name;           
    RedfishResource_Oem_CS                    *Oem;                // This is the
                                                                   // manufacturer/provider specific
                                                                   // extension moniker used to
                                                                   // divide the Oem object into
                                                                   // sections.
    RedfishCS_bool                            *ServiceEnabled;     // This indicates whether this
                                                                   // service is enabled.
    RedfishCS_Link                            SoftwareInventory;    // An inventory of software.
    RedfishResource_Status_CS                 *Status;             // This property describes the
                                                                   // status and health of the
                                                                   // resource and its children.
} RedfishUpdateService_V1_1_4_UpdateService_CS;

RedfishCS_status
Json_UpdateService_V1_1_4_To_CS (char *JsonRawText, RedfishUpdateService_V1_1_4_UpdateService_CS **ReturnedCS);

RedfishCS_status
CS_To_UpdateService_V1_1_4_JSON (RedfishUpdateService_V1_1_4_UpdateService_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyUpdateService_V1_1_4_CS (RedfishUpdateService_V1_1_4_UpdateService_CS *CSPtr);

RedfishCS_status
DestroyUpdateService_V1_1_4_Json (RedfishCS_char *JsonText);

#endif
