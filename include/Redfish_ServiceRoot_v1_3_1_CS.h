//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishServiceroot_V1_3_1_CSTRUCT_H_
#define _RedfishServiceroot_V1_3_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishServiceRoot_V1_3_1_Expand_CS RedfishServiceRoot_V1_3_1_Expand_CS;
typedef struct _RedfishServiceRoot_V1_3_1_Links_CS RedfishServiceRoot_V1_3_1_Links_CS;
typedef struct _RedfishServiceRoot_V1_3_1_ProtocolFeaturesSupported_CS RedfishServiceRoot_V1_3_1_ProtocolFeaturesSupported_CS;
typedef struct _RedfishServiceRoot_V1_3_1_ServiceRoot_CS RedfishServiceRoot_V1_3_1_ServiceRoot_CS;
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
// Contains information about the use of $expand in the service.
//
typedef struct _RedfishServiceRoot_V1_3_1_Expand_CS {
    RedfishCS_bool     *ExpandAll;    // This indicates whether the
                                     // expand support of asterisk
                                     // (expand all entries) is
                                     // supported.
    RedfishCS_bool     *Levels;      // This indicates whether the
                                     // expand support of the $levels
                                     // qualifier is supported by the
                                     // service.
    RedfishCS_bool     *Links;       // This indicates whether the
                                     // expand support of tilde
                                     // (expand only entries in the
                                     // Links section) is supported.
    RedfishCS_int64    *MaxLevels;    // This indicates the maximum
                                     // number value of the $levels
                                     // qualifier in expand
                                     // operations.
    RedfishCS_bool     *NoLinks;     // This indicates whether the
                                     // expand support of period
                                     // (expand only entries not in
                                     // the Links section) is
                                     // supported.
} RedfishServiceRoot_V1_3_1_Expand_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishServiceRoot_V1_3_1_Links_CS {
    RedfishResource_Oem_CS    *Oem;       // Oem extension object.
    RedfishCS_Link            Sessions;    // Link to a collection of
                                          // Sessions.
} RedfishServiceRoot_V1_3_1_Links_CS;

//
// Contains information about protocol features supported by the service.
//
typedef struct _RedfishServiceRoot_V1_3_1_ProtocolFeaturesSupported_CS {
    RedfishServiceRoot_V1_3_1_Expand_CS    *ExpandQuery;    // Contains information about the
                                                           // use of $expand in the service.
    RedfishCS_bool                         *FilterQuery;    // This indicates whether the
                                                           // filter query parameter is
                                                           // supported.
    RedfishCS_bool                         *SelectQuery;    // This indicates whether the
                                                           // select query parameter is
                                                           // supported.
} RedfishServiceRoot_V1_3_1_ProtocolFeaturesSupported_CS;

//
// This object represents the root Redfish service.
//
typedef struct _RedfishServiceRoot_V1_3_1_ServiceRoot_CS {
    RedfishCS_Header                                          Header;
    RedfishCS_char                                            *odata_context;           
    RedfishCS_char                                            *odata_etag;              
    RedfishCS_char                                            *odata_id;                
    RedfishCS_char                                            *odata_type;              
    RedfishCS_Link                                            AccountService;               // This is a link to the Account
                                                                                            // Service.
    RedfishCS_Link                                            Chassis;                      // This is a link to a collection
                                                                                            // of Chassis.
    RedfishCS_Link                                            CompositionService;           // This is a link to the
                                                                                            // CompositionService.
    RedfishCS_char                                            *Description;             
    RedfishCS_Link                                            EventService;                 // This is a link to the
                                                                                            // EventService.
    RedfishCS_Link                                            Fabrics;                      // A link to a collection of all
                                                                                            // fabric entities.
    RedfishCS_char                                            *Id;                      
    RedfishCS_Link                                            JsonSchemas;                  // This is a link to a collection
                                                                                            // of Json-Schema files.
    RedfishServiceRoot_V1_3_1_Links_CS                        *Links;                       // Contains references to other
                                                                                            // resources that are related to
                                                                                            // this resource.
    RedfishCS_Link                                            Managers;                     // This is a link to a collection
                                                                                            // of Managers.
    RedfishCS_char                                            *Name;                    
    RedfishResource_Oem_CS                                    *Oem;                         // This is the
                                                                                            // manufacturer/provider specific
                                                                                            // extension moniker used to
                                                                                            // divide the Oem object into
                                                                                            // sections.
    RedfishCS_char                                            *Product;                     // The product associated with
                                                                                            // this Redfish service.
    RedfishServiceRoot_V1_3_1_ProtocolFeaturesSupported_CS    *ProtocolFeaturesSupported;    // Contains information about
                                                                                            // protocol features supported by
                                                                                            // the service.
    RedfishCS_char                                            *RedfishVersion;              // The version of the Redfish
                                                                                            // service.
    RedfishCS_Link                                            Registries;                   // This is a link to a collection
                                                                                            // of Registries.
    RedfishCS_Link                                            SessionService;               // This is a link to the Sessions
                                                                                            // Service.
    RedfishCS_Link                                            StorageServices;              // A link to a collection of all
                                                                                            // storage service entities.
    RedfishCS_Link                                            StorageSystems;               // This is a link to a collection
                                                                                            // of storage systems.
    RedfishCS_Link                                            Systems;                      // This is a link to a collection
                                                                                            // of Systems.
    RedfishCS_Link                                            Tasks;                        // This is a link to the Task
                                                                                            // Service.
    RedfishCS_char                                            *UUID;                        // Unique identifier for a
                                                                                            // service instance. When SSDP is
                                                                                            // used, this value should be an
                                                                                            // exact match of the UUID value
                                                                                            // returned in a 200OK from an
                                                                                            // SSDP M-SEARCH request during
                                                                                            // discovery.
    RedfishCS_Link                                            UpdateService;                // This is a link to the
                                                                                            // UpdateService.
} RedfishServiceRoot_V1_3_1_ServiceRoot_CS;

RedfishCS_status
Json_ServiceRoot_V1_3_1_To_CS (char *JsonRawText, RedfishServiceRoot_V1_3_1_ServiceRoot_CS **ReturnedCS);

RedfishCS_status
CS_To_ServiceRoot_V1_3_1_JSON (RedfishServiceRoot_V1_3_1_ServiceRoot_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyServiceRoot_V1_3_1_CS (RedfishServiceRoot_V1_3_1_ServiceRoot_CS *CSPtr);

RedfishCS_status
DestroyServiceRoot_V1_3_1_Json (RedfishCS_char *JsonText);

#endif
