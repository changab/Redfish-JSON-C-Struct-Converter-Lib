//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSimplestorage_V1_2_1_CSTRUCT_H_
#define _RedfishSimplestorage_V1_2_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishSimpleStorage_V1_2_1_Device_Array_CS RedfishSimpleStorage_V1_2_1_Device_Array_CS;
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

#ifndef __RedfishResource_Status_CS__
typedef struct _RedfishResource_Status_CS RedfishResource_Status_CS;
#endif

typedef struct _RedfishSimpleStorage_V1_2_1_Actions_CS RedfishSimpleStorage_V1_2_1_Actions_CS;
typedef struct _RedfishSimpleStorage_V1_2_1_Device_CS RedfishSimpleStorage_V1_2_1_Device_CS;
typedef struct _RedfishSimpleStorage_V1_2_1_Links_CS RedfishSimpleStorage_V1_2_1_Links_CS;
typedef struct _RedfishSimpleStorage_V1_2_1_OemActions_CS RedfishSimpleStorage_V1_2_1_OemActions_CS;
typedef struct _RedfishSimpleStorage_V1_2_1_SimpleStorage_CS RedfishSimpleStorage_V1_2_1_SimpleStorage_CS;
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
typedef struct _RedfishSimpleStorage_V1_2_1_Actions_CS {
    RedfishSimpleStorage_V1_2_1_OemActions_CS    *Oem;    // This property contains the
                                                         // available OEM specific actions
                                                         // for this resource.
} RedfishSimpleStorage_V1_2_1_Actions_CS;

//
// A storage device such as a disk drive or optical media device.
//
typedef struct _RedfishSimpleStorage_V1_2_1_Device_CS {
    RedfishCS_int64              *CapacityBytes;    // The size of the storage
                                                   // device.
    RedfishCS_char               *Manufacturer;    // The name of the manufacturer
                                                   // of this device.
    RedfishCS_char               *Model;           // The product model number of
                                                   // this device.
    RedfishCS_char               *Name;            // The name of the resource or
                                                   // array element.
    RedfishResource_Oem_CS       *Oem;             // Oem extension object.
    RedfishResource_Status_CS    *Status;          // This property describes the
                                                   // status and health of the
                                                   // resource and its children.
} RedfishSimpleStorage_V1_2_1_Device_CS;

//
// Contains references to other resources that are related to this resource.
//
typedef struct _RedfishSimpleStorage_V1_2_1_Links_CS {
    RedfishCS_Link            Chassis;    // A reference to the Chassis
                                         // which contains this Simple
                                         // Storage.
    RedfishResource_Oem_CS    *Oem;      // Oem extension object.
} RedfishSimpleStorage_V1_2_1_Links_CS;

//
// The available OEM specific actions for this resource.
//
typedef struct _RedfishSimpleStorage_V1_2_1_OemActions_CS {
    RedfishCS_Link    Prop;
} RedfishSimpleStorage_V1_2_1_OemActions_CS;

//
// This is the schema definition for the Simple Storage resource.  It represents
// the properties of a storage controller and its directly-attached devices.
//
typedef struct _RedfishSimpleStorage_V1_2_1_SimpleStorage_CS {
    RedfishCS_Header                               Header;
    RedfishCS_char                                 *odata_context;
    RedfishCS_char                                 *odata_etag;   
    RedfishCS_char                                 *odata_id;     
    RedfishCS_char                                 *odata_type;   
    RedfishSimpleStorage_V1_2_1_Actions_CS         *Actions;          // The available actions for this
                                                                      // resource.
    RedfishCS_char                                 *Description;  
    RedfishSimpleStorage_V1_2_1_Device_Array_CS    *Devices;          // The storage devices associated
                                                                      // with this resource.
    RedfishCS_char                                 *Id;           
    RedfishSimpleStorage_V1_2_1_Links_CS           *Links;            // Contains references to other
                                                                      // resources that are related to
                                                                      // this resource.
    RedfishCS_char                                 *Name;         
    RedfishResource_Oem_CS                         *Oem;              // This is the
                                                                      // manufacturer/provider specific
                                                                      // extension moniker used to
                                                                      // divide the Oem object into
                                                                      // sections.
    RedfishResource_Status_CS                      *Status;           // This property describes the
                                                                      // status and health of the
                                                                      // resource and its children.
    RedfishCS_char                                 *UefiDevicePath;    // The UEFI device path used to
                                                                      // access this storage
                                                                      // controller.
} RedfishSimpleStorage_V1_2_1_SimpleStorage_CS;

typedef struct _RedfishSimpleStorage_V1_2_1_Device_Array_CS  {
    RedfishSimpleStorage_V1_2_1_Device_Array_CS    *Next;
    RedfishSimpleStorage_V1_2_1_Device_CS    *ArrayValue;
} RedfishSimpleStorage_V1_2_1_Device_Array_CS;

RedfishCS_status
Json_SimpleStorage_V1_2_1_To_CS (char *JsonRawText, RedfishSimpleStorage_V1_2_1_SimpleStorage_CS **ReturnedCS);

RedfishCS_status
CS_To_SimpleStorage_V1_2_1_JSON (RedfishSimpleStorage_V1_2_1_SimpleStorage_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySimpleStorage_V1_2_1_CS (RedfishSimpleStorage_V1_2_1_SimpleStorage_CS *CSPtr);

RedfishCS_status
DestroySimpleStorage_V1_2_1_Json (RedfishCS_char *JsonText);

#endif
