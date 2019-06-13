//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishAssembly_V1_1_0_CSTRUCT_H_
#define _RedfishAssembly_V1_1_0_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishAssembly_V1_1_0_AssemblyData_Array_CS RedfishAssembly_V1_1_0_AssemblyData_Array_CS;
typedef struct _RedfishAssembly_V1_1_0_Actions_CS RedfishAssembly_V1_1_0_Actions_CS;
typedef struct _RedfishAssembly_V1_1_0_Assembly_CS RedfishAssembly_V1_1_0_Assembly_CS;
typedef struct _RedfishAssembly_V1_1_0_AssemblyData_CS RedfishAssembly_V1_1_0_AssemblyData_CS;
typedef struct _RedfishAssembly_V1_1_0_AssemblyDataActions_CS RedfishAssembly_V1_1_0_AssemblyDataActions_CS;
typedef struct _RedfishAssembly_V1_1_0_AssemblyDataOemActions_CS RedfishAssembly_V1_1_0_AssemblyDataOemActions_CS;
typedef struct _RedfishAssembly_V1_1_0_OemActions_CS RedfishAssembly_V1_1_0_OemActions_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

//
// The available actions for this resource.
//
typedef struct _RedfishAssembly_V1_1_0_Actions_CS {
    RedfishAssembly_V1_1_0_OemActions_CS    *Oem;
} RedfishAssembly_V1_1_0_Actions_CS;

typedef struct _RedfishAssembly_V1_1_0_AssemblyData_CS {
    RedfishAssembly_V1_1_0_AssemblyDataActions_CS    *Actions;                  // The available actions for this
                                                                                // resource.
    RedfishCS_char                                   *BinaryDataURI;            // URI that provides the ability
                                                                                // to access an image of the
                                                                                // assembly information.
    RedfishCS_char                                   *Description;              // Description of the Assembly.
    RedfishCS_char                                   *EngineeringChangeLevel;    // Engineering change level of
                                                                                // the Assembly.
    RedfishCS_char                                   *MemberId;                 // This is the identifier for the
                                                                                // member within the collection.
    RedfishCS_char                                   *Model;                    // Model number of the Assembly.
    RedfishCS_char                                   *Name;                     // Name of the Assembly.
    RedfishResource_Oem_CS                           *Oem;                      // This is the
                                                                                // manufacturer/provider specific
                                                                                // extension moniker used to
                                                                                // divide the Oem object into
                                                                                // sections.
    RedfishCS_char                                   *PartNumber;               // Part number of the Assembly.
    RedfishCS_char                                   *Producer;                 // Producer or manufacturer of
                                                                                // the Assembly.
    RedfishCS_char                                   *ProductionDate;           // Production date of the
                                                                                // Assembly.
    RedfishCS_char                                   *SKU;                      // SKU of the Assembly.
    RedfishCS_char                                   *SparePartNumber;          // Spare part number of the
                                                                                // Assembly.
    RedfishResource_Status_CS                        *Status;               
    RedfishCS_char                                   *Vendor;                   // Vendor of the Assembly.
    RedfishCS_char                                   *Version;                  // Version of the Assembly.
} RedfishAssembly_V1_1_0_AssemblyData_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishAssembly_V1_1_0_AssemblyDataActions_CS {
    RedfishAssembly_V1_1_0_AssemblyDataOemActions_CS    *Oem;
} RedfishAssembly_V1_1_0_AssemblyDataActions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishAssembly_V1_1_0_AssemblyDataOemActions_CS {
    RedfishCS_Link    Prop;
} RedfishAssembly_V1_1_0_AssemblyDataOemActions_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishAssembly_V1_1_0_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishAssembly_V1_1_0_OemActions_CS;

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
// This is the schema definition for the Assembly properties.
//
typedef struct _RedfishAssembly_V1_1_0_Assembly_CS {
    RedfishCS_Header                                Header;
    RedfishCS_char                                  *odata_context;       
    RedfishCS_char                                  *odata_etag;          
    RedfishCS_char                                  *odata_id;            
    RedfishCS_char                                  *odata_type;          
    RedfishAssembly_V1_1_0_Actions_CS               *Actions;                 // The available actions for this
                                                                              // resource.
    RedfishAssembly_V1_1_0_AssemblyData_Array_CS    *Assemblies;              // This is the definition for an
                                                                              // assembly information record.
    RedfishCS_int64                                 *Assembliesodata_count;
    RedfishCS_char                                  *Description;         
    RedfishCS_char                                  *Id;                  
    RedfishCS_char                                  *Name;                
    RedfishResource_Oem_CS                          *Oem;                     // This is the
                                                                              // manufacturer/provider specific
                                                                              // extension moniker used to
                                                                              // divide the Oem object into
                                                                              // sections.
} RedfishAssembly_V1_1_0_Assembly_CS;

typedef struct _RedfishAssembly_V1_1_0_AssemblyData_Array_CS  {
    RedfishAssembly_V1_1_0_AssemblyData_Array_CS    *Next;
    RedfishAssembly_V1_1_0_AssemblyData_CS    *ArrayValue;
} RedfishAssembly_V1_1_0_AssemblyData_Array_CS;

RedfishCS_status
Json_Assembly_V1_1_0_To_CS (char *JsonRawText, RedfishAssembly_V1_1_0_Assembly_CS **ReturnedCS);

RedfishCS_status
CS_To_Assembly_V1_1_0_JSON (RedfishAssembly_V1_1_0_Assembly_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyAssembly_V1_1_0_CS (RedfishAssembly_V1_1_0_Assembly_CS *CSPtr);

RedfishCS_status
DestroyAssembly_V1_1_0_Json (RedfishCS_char *JsonText);

#endif
