//
//  (C) Copyright 2018 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishPrivilegeregistry_V1_1_1_CSTRUCT_H_
#define _RedfishPrivilegeregistry_V1_1_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Mapping_Array_CS RedfishPrivilegeRegistry_V1_1_1_Mapping_Array_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Actions_CS RedfishPrivilegeRegistry_V1_1_1_Actions_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Mapping_CS RedfishPrivilegeRegistry_V1_1_1_Mapping_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OemActions_CS RedfishPrivilegeRegistry_V1_1_1_OemActions_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OperationMap_CS RedfishPrivilegeRegistry_V1_1_1_OperationMap_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_CS RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS;
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_CS RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Actions_CS {
    RedfishPrivilegeRegistry_V1_1_1_OemActions_CS    *Oem;
} RedfishPrivilegeRegistry_V1_1_1_Actions_CS;

//
// This type describes a mapping between an entity and the relevant privileges
// used to access it.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Mapping_CS {
    RedfishCS_char                                                  *Entity;                 // Indicates entity name. e.g.,
                                                                                             // Manager.
    RedfishPrivilegeRegistry_V1_1_1_OperationMap_CS                 *OperationMap;           // List mapping between HTTP
                                                                                             // method and privilege required
                                                                                             // for entity.
    RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS    *PropertyOverrides;      // Indicates privilege overrides
                                                                                             // of property or element within
                                                                                             // a entity.
    RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS    *ResourceURIOverrides;    // Indicates privilege overrides
                                                                                             // of Resource URI.
    RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS    *SubordinateOverrides;    // Indicates privilege overrides
                                                                                             // of subordinate resource.
} RedfishPrivilegeRegistry_V1_1_1_Mapping_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishPrivilegeRegistry_V1_1_1_OemActions_CS;

//
// Used for describing the specific privileges for a set of HTTP operations.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OperationMap_CS {
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *DELETE;    // Indicates privilege required
                                                                              // for HTTP DELETE operation.
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *GET;      // Indicates privilege required
                                                                              // for HTTP GET operation.
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *HEAD;     // Indicates privilege required
                                                                              // for HTTP HEAD operation.
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *PATCH;    // Indicates privilege required
                                                                              // for HTTP PATCH operation.
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *POST;     // Indicates privilege required
                                                                              // for HTTP POST operation.
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *PUT;      // Indicates privilege required
                                                                              // for HTTP PUT operation.
} RedfishPrivilegeRegistry_V1_1_1_OperationMap_CS;

//
// Used for describing the specific privileges for a given type of HTTP operation.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_CS {
    RedfishCS_char_Array    *Privilege;    // Lists the privileges that are
                                          // allowed to perform the given
                                          // type of HTTP operation on the
                                          // entity type.
} RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_CS;

//
// This type describes a mapping between one or more targets and the HTTP
// operations associated with them.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_CS {
    RedfishPrivilegeRegistry_V1_1_1_OperationMap_CS    *OperationMap;    // List mapping between HTTP
                                                                        // operation and privilege needed
                                                                        // to perform operation.
    RedfishCS_char_Array                               *Targets;        // Indicates the URI or Entity.
} RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_CS;

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
// This is the schema definition for Operation to Privilege mapping.
//
typedef struct _RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS {
    RedfishCS_Header                                    Header;
    RedfishCS_char                                      *odata_context;   
    RedfishCS_char                                      *odata_id;        
    RedfishCS_char                                      *odata_type;      
    RedfishPrivilegeRegistry_V1_1_1_Actions_CS          *Actions;             // The available actions for this
                                                                              // resource.
    RedfishCS_char                                      *Description;     
    RedfishCS_char                                      *Id;              
    RedfishPrivilegeRegistry_V1_1_1_Mapping_Array_CS    *Mappings;        
    RedfishCS_char                                      *Name;            
    RedfishCS_char_Array                                *OEMPrivilegesUsed;    // Lists the set of OEM
                                                                              // Priviliges used in building
                                                                              // this mapping.
    RedfishResource_Oem_CS                              *Oem;                 // This is the
                                                                              // manufacturer/provider specific
                                                                              // extension moniker used to
                                                                              // divide the Oem object into
                                                                              // sections.
    RedfishCS_char_Array                                *PrivilegesUsed;      // Lists the set of Redfish
                                                                              // standard priviliges used in
                                                                              // building this mapping.
} RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS;

typedef struct _RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS  {
    RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS    *Next;
    RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_CS    *ArrayValue;
} RedfishPrivilegeRegistry_V1_1_1_Target_PrivilegeMap_Array_CS;

typedef struct _RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS  {
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS    *Next;
    RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_CS    *ArrayValue;
} RedfishPrivilegeRegistry_V1_1_1_OperationPrivilege_Array_CS;

typedef struct _RedfishPrivilegeRegistry_V1_1_1_Mapping_Array_CS  {
    RedfishPrivilegeRegistry_V1_1_1_Mapping_Array_CS    *Next;
    RedfishPrivilegeRegistry_V1_1_1_Mapping_CS    *ArrayValue;
} RedfishPrivilegeRegistry_V1_1_1_Mapping_Array_CS;

RedfishCS_status
Json_PrivilegeRegistry_V1_1_1_To_CS (char *JsonRawText, RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS **ReturnedCS);

RedfishCS_status
CS_To_PrivilegeRegistry_V1_1_1_JSON (RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyPrivilegeRegistry_V1_1_1_CS (RedfishPrivilegeRegistry_V1_1_1_PrivilegeRegistry_CS *CSPtr);

RedfishCS_status
DestroyPrivilegeRegistry_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
