//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishStorage_V1_1_1_CSTRUCT_H_
#define _RedfishStorage_V1_1_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
#ifndef __RedfishResource_V1_1_0_Identifier_Array_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_Array_CS RedfishResource_V1_1_0_Identifier_Array_CS;
#endif
typedef struct _RedfishStorage_V1_1_1_StorageController_Array_CS RedfishStorage_V1_1_1_StorageController_Array_CS;
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

#ifndef __RedfishResource_V1_1_0_Identifier_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_CS RedfishResource_V1_1_0_Identifier_CS;
#endif

typedef struct _RedfishStorage_V1_1_1_SetEncryptionKey_CS RedfishStorage_V1_1_1_SetEncryptionKey_CS;
typedef struct _RedfishStorage_V1_1_1_Storage_CS RedfishStorage_V1_1_1_Storage_CS;
typedef struct _RedfishStorage_V1_1_1_StorageController_CS RedfishStorage_V1_1_1_StorageController_CS;
typedef struct _RedfishStorage_V1_1_1_StorageController_Links_CS RedfishStorage_V1_1_1_StorageController_Links_CS;
typedef struct _RedfishStorage_V1_1_1_Storage_Actions_CS RedfishStorage_V1_1_1_Storage_Actions_CS;
typedef struct _RedfishStorage_V1_1_1_Storage_Actions_Oem_CS RedfishStorage_V1_1_1_Storage_Actions_Oem_CS;
typedef struct _RedfishStorage_V1_1_1_Storage_Links_CS RedfishStorage_V1_1_1_Storage_Links_CS;
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

#ifndef __RedfishResource_V1_1_0_Identifier_CS__
#define __RedfishResource_V1_1_0_Identifier_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_CS {
    RedfishCS_char    *DurableName;         // This indicates the world wide,
                                            // persistent name of the
                                            // resource.
    RedfishCS_char    *DurableNameFormat;    // This represents the format of
                                            // the DurableName property.
} RedfishResource_V1_1_0_Identifier_CS;
#endif

//
// This action is used to set the encryption key for the storage subsystem.
//
typedef struct _RedfishStorage_V1_1_1_SetEncryptionKey_CS {
    RedfishCS_char    *target;    // Link to invoke action
    RedfishCS_char    *title;    // Friendly action name
} RedfishStorage_V1_1_1_SetEncryptionKey_CS;

//
// This schema defines a storage controller and its respective properties.  A
// storage controller represents a storage device (physical or virtual) that
// produces Volumes.
//
typedef struct _RedfishStorage_V1_1_1_StorageController_CS {
    RedfishCS_char                                      *AssetTag;                       // The user assigned asset tag
                                                                                         // for this storage controller.
    RedfishCS_char                                      *FirmwareVersion;                // The firmware version of this
                                                                                         // storage Controller.
    RedfishResource_V1_1_0_Identifier_Array_CS          *Identifiers;                    // The Durable names for the
                                                                                         // storage controller.
    RedfishStorage_V1_1_1_StorageController_Links_CS    *Links;                          // Contains references to other
                                                                                         // resources that are related to
                                                                                         // this resource.
    RedfishCS_char                                      *Manufacturer;                   // This is the manufacturer of
                                                                                         // this storage controller.
    RedfishCS_char                                      *MemberId;                       // This is the identifier for the
                                                                                         // member within the collection.
    RedfishCS_char                                      *Model;                          // This is the model number for
                                                                                         // the storage controller.
    RedfishResource_Oem_CS                              *Oem;                            // This is the
                                                                                         // manufacturer/provider specific
                                                                                         // extension moniker used to
                                                                                         // divide the Oem object into
                                                                                         // sections.
    RedfishCS_char                                      *PartNumber;                     // The part number for this
                                                                                         // storage controller.
    RedfishCS_char                                      *SKU;                            // This is the SKU for this
                                                                                         // storage controller.
    RedfishCS_char                                      *SerialNumber;                   // The serial number for this
                                                                                         // storage controller.
    RedfishCS_int64                                     *SpeedGbps;                      // The speed of the storage
                                                                                         // controller interface.
    RedfishResource_Status_CS                           *Status;                     
    RedfishCS_char_Array                                *SupportedControllerProtocols;    // This represents the protocols
                                                                                         // by which this storage
                                                                                         // controller can be communicated
                                                                                         // to.
    RedfishCS_char_Array                                *SupportedDeviceProtocols;       // This represents the protocols
                                                                                         // which the storage controller
                                                                                         // can use to communicate with
                                                                                         // attached devices.
} RedfishStorage_V1_1_1_StorageController_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishStorage_V1_1_1_StorageController_Links_CS {
    RedfishCS_Link            Endpoints;                        // An array of references to the
                                                                // endpoints that connect to this
                                                                // controller.
    RedfishCS_int64           *Endpointsodata_count;        
    RedfishCS_char            *Endpointsodata_navigationLink;
    RedfishResource_Oem_CS    *Oem;                             // Oem extension object.
} RedfishStorage_V1_1_1_StorageController_Links_CS;

//
// The available actions for this resource.
//
typedef struct _RedfishStorage_V1_1_1_Storage_Actions_CS {
    RedfishStorage_V1_1_1_SetEncryptionKey_CS       *Storage_SetEncryptionKey;
    RedfishStorage_V1_1_1_Storage_Actions_Oem_CS    *Oem;                    
} RedfishStorage_V1_1_1_Storage_Actions_CS;

typedef struct _RedfishStorage_V1_1_1_Storage_Actions_Oem_CS {
    RedfishCS_Link    Prop;
} RedfishStorage_V1_1_1_Storage_Actions_Oem_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishStorage_V1_1_1_Storage_Links_CS {
    RedfishCS_Link            Enclosures;                        // An array of references to the
                                                                 // chassis to which this storage
                                                                 // subsystem is attached.
    RedfishCS_int64           *Enclosuresodata_count;        
    RedfishCS_char            *Enclosuresodata_navigationLink;
    RedfishResource_Oem_CS    *Oem;                              // Oem extension object.
} RedfishStorage_V1_1_1_Storage_Links_CS;

//
// This schema defines a storage subsystem and its respective properties.  A
// storage subsystem represents a set of storage controllers (physical or virtual)
// and the resources such as volumes that can be accessed from that subsystem.
//
typedef struct _RedfishStorage_V1_1_1_Storage_CS {
    RedfishCS_Header                                    Header;
    RedfishCS_char                                      *odata_context;                        
    RedfishCS_char                                      *odata_id;                             
    RedfishCS_char                                      *odata_type;                           
    RedfishStorage_V1_1_1_Storage_Actions_CS            *Actions;                                  // The available actions for this
                                                                                                   // resource.
    RedfishCS_char                                      *Description;                          
    RedfishCS_Link                                      Drives;                                    // The set of drives attached to
                                                                                                   // the storage controllers
                                                                                                   // represented by this resource.
    RedfishCS_int64                                     *Drivesodata_count;                    
    RedfishCS_char                                      *Drivesodata_navigationLink;           
    RedfishCS_char                                      *Id;                                   
    RedfishStorage_V1_1_1_Storage_Links_CS              *Links;                                    // Contains references to other
                                                                                                   // resources that are related to
                                                                                                   // this resource.
    RedfishCS_char                                      *Name;                                 
    RedfishResource_Oem_CS                              *Oem;                                      // This is the
                                                                                                   // manufacturer/provider specific
                                                                                                   // extension moniker used to
                                                                                                   // divide the Oem object into
                                                                                                   // sections.
    RedfishCS_Link                                      Redundancy;                                // Redundancy information for the
                                                                                                   // storage subsystem.
    RedfishCS_int64                                     *Redundancyodata_count;                
    RedfishCS_char                                      *Redundancyodata_navigationLink;       
    RedfishResource_Status_CS                           *Status;                               
    RedfishStorage_V1_1_1_StorageController_Array_CS    *StorageControllers;                       // The set of storage controllers
                                                                                                   // represented by this resource.
    RedfishCS_int64                                     *StorageControllersodata_count;        
    RedfishCS_char                                      *StorageControllersodata_navigationLink;
    RedfishCS_Link                                      Volumes;                                   // The set of volumes produced by
                                                                                                   // the storage controllers
                                                                                                   // represented by this resource.
} RedfishStorage_V1_1_1_Storage_CS;

#ifndef __RedfishResource_V1_1_0_Identifier_Array_CS__
#define __RedfishResource_V1_1_0_Identifier_Array_CS__
typedef struct _RedfishResource_V1_1_0_Identifier_Array_CS  {
    RedfishResource_V1_1_0_Identifier_Array_CS    *Next;
    RedfishResource_V1_1_0_Identifier_CS    *ArrayValue;
} RedfishResource_V1_1_0_Identifier_Array_CS;
#endif

typedef struct _RedfishStorage_V1_1_1_StorageController_Array_CS  {
    RedfishStorage_V1_1_1_StorageController_Array_CS    *Next;
    RedfishStorage_V1_1_1_StorageController_CS    *ArrayValue;
} RedfishStorage_V1_1_1_StorageController_Array_CS;

RedfishCS_status
Json_Storage_V1_1_1_To_CS (char *JsonRawText, RedfishStorage_V1_1_1_Storage_CS **ReturnedCS);

RedfishCS_status
CS_To_Storage_V1_1_1_JSON (RedfishStorage_V1_1_1_Storage_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyStorage_V1_1_1_CS (RedfishStorage_V1_1_1_Storage_CS *CSPtr);

RedfishCS_status
DestroyStorage_V1_1_1_Json (RedfishCS_char *JsonText);

#endif
