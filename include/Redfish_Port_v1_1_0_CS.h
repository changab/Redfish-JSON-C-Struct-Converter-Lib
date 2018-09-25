//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishPort_V1_1_0_CSTRUCT_H_
#define _RedfishPort_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishPort_V1_1_0_Actions_CS RedfishPort_V1_1_0_Actions_CS;
typedef struct _RedfishPort_V1_1_0_Links_CS RedfishPort_V1_1_0_Links_CS;
typedef struct _RedfishPort_V1_1_0_OemActions_CS RedfishPort_V1_1_0_OemActions_CS;
typedef struct _RedfishPort_V1_1_0_Port_CS RedfishPort_V1_1_0_Port_CS;
typedef struct _RedfishPort_V1_1_0_Reset_CS RedfishPort_V1_1_0_Reset_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishPort_V1_1_0_Actions_CS {
    RedfishPort_V1_1_0_Reset_CS         *Port_Reset;
    RedfishPort_V1_1_0_OemActions_CS    *Oem;      
} RedfishPort_V1_1_0_Actions_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishPort_V1_1_0_Links_CS {
    RedfishCS_Link            AssociatedEndpoints;                // An array of references to the
                                                                  // endpoints that connect to the
                                                                  // switch through this port.
    RedfishCS_int64           *AssociatedEndpointsodata_count;
    RedfishCS_Link            ConnectedSwitchPorts;               // An array of references to the
                                                                  // ports that connect to the
                                                                  // switch through this port.
    RedfishCS_int64           *ConnectedSwitchPortsodata_count;
    RedfishCS_Link            ConnectedSwitches;                  // An array of references to the
                                                                  // switches that connect to the
                                                                  // switch through this port.
    RedfishCS_int64           *ConnectedSwitchesodata_count;  
    RedfishResource_Oem_CS    *Oem;                               // Oem extension object.
} RedfishPort_V1_1_0_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishPort_V1_1_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishPort_V1_1_0_OemActions_CS;

//
// This action is used to reset this port.
//
typedef struct _RedfishPort_V1_1_0_Reset_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishPort_V1_1_0_Reset_CS;

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
// Port contains properties describing a port of a switch.
//
typedef struct _RedfishPort_V1_1_0_Port_CS {
    RedfishCS_Header                 Header;
    RedfishCS_char                   *odata_context;  
    RedfishCS_char                   *odata_id;       
    RedfishCS_char                   *odata_type;     
    RedfishPort_V1_1_0_Actions_CS    *Actions;            // The available actions for this
                                                          // resource.
    RedfishCS_int64                  *CurrentSpeedGbps;    // The current speed of this
                                                          // port.
    RedfishCS_char                   *Description;    
    RedfishCS_char                   *Id;             
    RedfishPort_V1_1_0_Links_CS      *Links;              // Contains references to other
                                                          // resources that are related to
                                                          // this resource.
    RedfishCS_Link                   Location;        
    RedfishCS_int64                  *MaxSpeedGbps;       // The maximum speed of this port
                                                          // as currently configured.
    RedfishCS_char                   *Name;           
    RedfishResource_Oem_CS           *Oem;                // This is the
                                                          // manufacturer/provider specific
                                                          // extension moniker used to
                                                          // divide the Oem object into
                                                          // sections.
    RedfishCS_char                   *PortId;             // This is the label of this port
                                                          // on the physical switch
                                                          // package.
    RedfishCS_char                   *PortProtocol;       // The protocol being sent over
                                                          // this port.
    RedfishCS_char                   *PortType;           // This is the type of this port.
    RedfishResource_Status_CS        *Status;         
    RedfishCS_int64                  *Width;              // The number of lanes, phys, or
                                                          // other physical transport links
                                                          // that this port contains.
} RedfishPort_V1_1_0_Port_CS;

RedfishCS_status
Json_Port_V1_1_0_To_CS (char *JsonRawText, RedfishPort_V1_1_0_Port_CS **ReturnedCS);

RedfishCS_status
CS_To_Port_V1_1_0_JSON (RedfishPort_V1_1_0_Port_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyPort_V1_1_0_CS (RedfishPort_V1_1_0_Port_CS *CSPtr);

RedfishCS_status
DestroyPort_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
