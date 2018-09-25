//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishVlannetworkinterface_V1_1_0_CSTRUCT_H_
#define _RedfishVlannetworkinterface_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLAN_CS RedfishVLanNetworkInterface_V1_1_0_VLAN_CS;
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS;
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_CS RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_CS;
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_Oem_CS RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_Oem_CS;
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
// This type describes the attributes of a Virtual LAN.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLAN_CS {
    RedfishCS_bool     *VLANEnable;    // This indicates if this VLAN is
                                      // enabled.
    RedfishCS_int64    *VLANId;       // This indicates the VLAN
                                      // identifier for this VLAN.
} RedfishVLanNetworkInterface_V1_1_0_VLAN_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_CS {
    RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_Oem_CS    *Oem;    // The available OEM specific
                                                                                      // actions for this resource.
} RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_Oem_CS;

//
// This resource describes the attributes of a Virtual LAN.
//
typedef struct _RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS {
    RedfishCS_Header                                                      Header;
    RedfishCS_char                                                        *odata_context;
    RedfishCS_char                                                        *odata_id;    
    RedfishCS_char                                                        *odata_type;  
    RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_Actions_CS    *Actions;         // The available actions for this
                                                                                            // resource.
    RedfishCS_char                                                        *Description; 
    RedfishCS_char                                                        *Id;          
    RedfishCS_char                                                        *Name;        
    RedfishResource_Oem_CS                                                *Oem;             // This is the
                                                                                            // manufacturer/provider specific
                                                                                            // extension moniker used to
                                                                                            // divide the Oem object into
                                                                                            // sections.
    RedfishCS_bool                                                        *VLANEnable;      // This indicates if this VLAN is
                                                                                            // enabled.
    RedfishCS_int64                                                       *VLANId;          // This indicates the VLAN
                                                                                            // identifier for this VLAN.
} RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS;

RedfishCS_status
Json_VLanNetworkInterface_V1_1_0_To_CS (char *JsonRawText, RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_VLanNetworkInterface_V1_1_0_JSON (RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyVLanNetworkInterface_V1_1_0_CS (RedfishVLanNetworkInterface_V1_1_0_VLanNetworkInterface_CS *CSPtr);

RedfishCS_status
DestroyVLanNetworkInterface_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
