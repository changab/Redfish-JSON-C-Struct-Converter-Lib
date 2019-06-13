# Redfish-JSON-C-Struct-Converter

## About
***Redfish-JSON-C-Struct-Converter*** is a C client library which used to convert Redfish resource in JSON text format to C structure and vice versa. The functions in Redfish-JSON-C-Struct-Converter library provides the C language friendly structure which can be easily utilized in C programs.<Br/>  
Each C file is a converter for the specific version of Redfish schema released by SPFM. For example,  **ServiceRoot.v1_2_0.c** under **/ServiceRoot/ServiceRoot.v1_2_0** provides functions to convert **ServiceRoot.v1_2_0.ServiceRoot** property to predefined **RedfishServiceRootV1_2_0_CS** C structure. It also provides functions to convert **RedfishServiceRootV1_2_0_CS** C structure to JSON text file. All C files under **/src** are built into a single library. Other programs which built with ***Redfish-JSON-C-Struct-Converter*** library must links with this library and invokes the conversion functions as it needs.
## Pre-requisists
***Redfish-JSON-C-Struct-Converter*** is based on C and C compiling system. This library requires to build with below libraries.
- jannson library - [http://www.digip.org/jansson/")
- C standard library

### Directories
#### Directories of ***Redfish-JSON-C-Struct-Converter*** follows the directory hierarchy of ***libredfish***. <br/>
    - src
      Source code of a variety of Redfish JSON-CStructure Converter.
    - include
      C header files of Redfish JSON-CStructure Converter. No subdirectories under /include. All header files of Redfish-JSON-C-Struct-Converter must located under /include.

##### Under **/src**, directory must be created for each Redfish JSON schema **ResourceTypeName** . 
    For example,
      /src/ServiceRoot
        |_/Chassis

##### Under **/src/ResourceTypeName**, the directories must be created for each Redfish JSON schema type **NameSpace**. 
    For example,
      /src/ServiceRoot/ServiceRoot.v1_0_0
        |       |_____/ServiceRoot.v1_1_0
        |       |_____/ServiceRoot.v1_2_0
        |       |_____/ServiceRoot.v1_3_0
        |_/Chassis/Chassis.v1_0_0
              |___/Chassis.v2_0_0

##### C source file for the specific Redfish JSON schema must located under the corresponding directory.
    For example,
      /src/ServiceRoot/ServiceRoot.v1_0_0/ServiceRoot.v1_0_0.c
                |_____/ServiceRoot.v1_1_0/ServiceRoot.v1_1_0.c
                |_____/ServiceRoot.v1_1_0/ServiceRoot.v1_2_0.c

##### CMAKE file CMakeLists.txt is located under src/_build. Use cmake to build Redfish JSON-CStructure Converter libraries.
      /src/_build/CMakeLists.txt

      Build Redfish C Structure library using below command under _build,
        mkdir build-dir
        cd build-dir
        cmake -G <generator-name> ..  # for example, cmake -G "Visual Studio 11 2012 Win64" ..
        cmake --build . 

### Naming of C Source Code
#### Use "Namesapce" of Redfish resource Type identifier as the naming of C source code.
    Namespace = "ResourceTypeName.vMajorVersion_MinorVersion_Errata"
    For example,  namespace for ServiceRoot 1.3.0 is ServiceRoot.v1_3_0. The naming of C source code must be ServiceRoot.v1_3_0.c
   
### Naming of C Header File
##### Below is the naming of C header file of Redfish JSON-C structure converter.
    Redfish_<ResourceTypeName>_<SchemaVersion>_CS.h
    <ResourceTypeName> : For example, ServiceRoot
    <SchemaVersion>    : For example, v1_2_0
    CS                 : Means C Structure

    The naming of header file for ServiceRoot.v1_2_0 schema will be Redfish_ServiceRoot_V1_2_0_CS.h.

### C Source File of Redfish JSON-C Structure Converter
Provides three major functions for Redfish JSON-C structure converter. Those are Redfish JSON to C Structure converter, C Structure to Redfish JSON converter and destory JSON C structure.
##### The prototyoe and naming of function is shown as below,
Redfish JSON to C Structure:

       RedfishCS_status Json_<ResourceTypeName>_<SchemaVersion>_To_Cs (RedfishCS_char *JsonRawText,  <RedfishCStructureName> **ReturnCS);
	 For example,
        RedfishCS_status = *Json_ServiceRoot_V1_2_0_To_CS (RedfishCS_char *JsonRawText, RedfishServiceRootV1_2_0_CS **ReturnCS);

C Structure to Redfish JSON:

       RedfishCS_status Cs_<ResourceTypeName>_<SchemaVersion>_Json (<RedfishCStructureName> *CsPtr, RedfishCS_char **JsonText);
	 For example,
       RedfishCS_status Cs_ServiceRoot_V1_2_0_To_Json (RedfishServiceRootV1_2_0_CS *RedfishCs, RedfishCS_char **JsonText);

Redfish JSON C Structure Destory:

       RedfishCS_status Cs_<ResourceTypeName>_<SchemaVersion>_Json (<RedfishCStructureName> *CsPtr);
	 For example,
       RedfishCS_status DestroyServiceRoot_V1_2_0_CS (RedfishServiceRoot_V1_2_0_ServiceRoot_CS *CSPtr);

### C Header File of Redfish JSON-C Structure Converter
In most of implementations, C header file of Redfish JSON-C structure converter only defines C structure of certain Redfish Schema and prototype of conversion functions.
##### For example,
    #ifndef _REDFISH_SERVICEROOT_V1_2_0_CSTRUCT_H_
    #define _REDFISH_SERVICEROOT_V1_2_0_CSTRUCT_H_
    
    #include "RedfishCsCommon.h"
    
    typedef struct _RedfishServiceRoot_V1_2_0_ServiceRoot_CS {
      RedfishCS_Header                                  Header;
      RedfishCS_char                                    *odata_context;   
      RedfishCS_char                                    *odata_id;        
      RedfishCS_char                                    *odata_type;      
      RedfishCS_Link                                    AccountService;     // This is a link to the Account
                                                                            // Service.
      RedfishCS_Link                                    Chassis;            // This is a link to a collection
                                                                            // of Chassis.
      RedfishCS_Link                                    CompositionService; // This is a link to the
                                                                            // CompositionService.
      RedfishCS_char                                    *Description;     
      RedfishCS_Link                                    EventService;       // This is a link to the
                                                                            // EventService.
      RedfishCS_Link                                    Fabrics;            // A link to a collection of all
                                                                            // fabric entities.
      RedfishCS_char                                    *Id;              
      RedfishCS_Link                                    JsonSchemas;        // This is a link to a collection
                                                                            // of Json-Schema files.
      RedfishServiceRoot_V1_2_0_ServiceRoot_Links_CS    *Links;             // Contains references to other
                                                                            // resources that are related to
                                                                            // this resource.
      RedfishCS_Link                                    Managers;           // This is a link to a collection
                                                                            // of Managers.
      RedfishCS_char                                    *Name;            
      RedfishResource_Oem_CS                            *Oem;               // This is the
                                                                            // manufacturer/provider specific
                                                                            // extension moniker used to
                                                                            // divide the Oem object into
                                                                            // sections.
      RedfishCS_char                                    *RedfishVersion;    // The version of the Redfish
                                                                            // service.
      RedfishCS_Link                                    Registries;         // This is a link to a collection
                                                                            // of Registries.
      RedfishCS_Link                                    SessionService;     // This is a link to the Sessions
                                                                            // Service.
      RedfishCS_Link                                    StorageServices;    // A link to a collection of all
                                                                            // storage service entities.
      RedfishCS_Link                                    StorageSystems;     // This is a link to a collection
                                                                            // of storage systems.
      RedfishCS_Link                                    Systems;            // This is a link to a collection
                                                                            // of Systems.
      RedfishCS_Link                                    Tasks;              // This is a link to the Task
                                                                            // Service.
      RedfishCS_char                                    *UUID;              // Unique identifier for a
                                                                            // service instance. When SSDP is
                                                                            // used, this value should be an
                                                                            // exact match of the UUID value
                                                                            // returned in a 200OK from an
                                                                            // SSDP M-SEARCH request during
                                                                            // discovery.
      RedfishCS_Link                                    UpdateService;      // This is a link to the
                                                                            // UpdateService.
    } RedfishServiceRoot_V1_2_0_ServiceRoot_CS;
    
    RedfishServiceRootV1_2_0_CS *
    Json_ServiceRoot_V1_2_0_To_CS (char *JsonRawText);

### C Data Types
In order to flexibly support different bindings on top of ***Redfish-JSON-C-Struct-Converte***, we use alternated data type instead of using native C data types. The alternated ones may replaced by bindings.


| C Data Type | Redfish C Structure Data Type | Description 
| ---  | --- | ---
| **bool** | RedfishCS_bool | Boolean, true or false. <br/> Refer to **Redfish-JSON-C-Struct-Converter Defined C Data Types**
| **char** | RedfishCS_char | 8-bit character.
| **signed char** | RedfishCS_int8 | 8-bit signed value.
| **unsigned char** | RedfishCS_uint8 | 8-bit unsigned value.  
| **int** | RedfishCS_int16| Integer in range  [−32,767, +32,767]
| **unsigned int** | RedfishCS_uint16| Integer in range [0, 65535]
| **long int** | RedfishCS_int32| Integer in range [−2,147,483,647, +2,147,483,647]
| **unsigned long int** | RedfishCS_uint32| Integer in range [0, 4,294,967,295] 
| **long long** | RedfishCS_int64| Integer in range  [−9,223,372,036,854,775,807, +9,223,372,036,854,775,807] 
| **unsigned long long** | RedfishCS_uint64|Integer in range [0, 2^64 - 1]
| **double** | RedfishCS_double| Double-precision floating-point
| **float** | RedfishCS_float| Single-precision floating-point

### Redfish-JSON-C-Struct-Converter Defined C Data Types
|Data Type | Description                                                                                           |
| --- | ---
| **RedfishCS_boolean_false** | Means 0 or false
| **RedfishCS_boolean_true**  | Means 1 or true

### Redfish-JSON-C-Struct-Converter Defined Return Stastus
|Data Type | Value                                                                                           |
| --- | ---
| **RedfishCS_status_successe** | 0
| **RedfishCS_status_unsupported**  | -1
| **RedfishCS_status_invalid_parameter**  | -2
| **RedfishCS_status_insufficient_memory**  | -3
| **RedfishCS_status_not_found**  | -4
| **RedfishCS_status_unknown_error**  | -5

## Redfish-JSON-C-Struct-Converter Defined Structure
|Redfish-JSON-C-Struct Defined Structure | Description  
| --- | ---
| **RedfishCS_linklist** |  Linked list used in Redfish-JSON-C-Struct, this structure is used to link to the next Redfish C structure.<br/><br/>`typedef struct _RedfishCS_linklist {`<br/> ` RedfishCS_linklist BackLinkList;`<br/>`  RedfishCS_linklist NextLinkList;`<br/>`};`<br/><br/>
| **RedfishCS_Header** | Redfish C Structure Header, the header of each Redfish C structure. <br/> <br/>`typedef struct _RedfishCS_Header {`<br/>`RedfishCS_Link     LinkEntry;`<br/>`RedfishCS_Type     ResourceType;`<br/>`RedfishCS_char     *KeyName;`<br/>`RedfishCS_char     *ThisUri;`<br/>`} RedfishCS_Header;`<br/><br/>
| **RedfishCS_Type** | Redfish C Structure Type, the type of information this Redfish C structure provides. <br/> <br/>`typedef enum {`<br/>`RedfishCS_Type_CS = 1,`<br/>`RedfishCS_Type_JSON,`<br/>`RedfishCS_Type_Uri`<br/>`} RedfishCS_Type;`<br/><br/>See below definitions for each type<br/><br/>
| **RedfishCS_Type_Uri_Data** | Redfish C Structure of URI information, this type of Redfish C structure provides the URI to Redfish resource.<br/><br/>`typedef struct _RedfishCS_Type_Uri_Data {`<br/>`RedfishCS_Header  Header;`<br/>`RedfishCS_char    *Uri;`<br/>`} RedfishCS_Type_Uri_Data;`<br/><br/>
| **RedfishCS_Type_CS_Data** | Redfish C Structure of Redfish resource, this type of Redfish C structure provides Redfish resource in C structure format.<br/><br/>`typedef struct _RedfishCS_Type_CS_Data {`<br/>`  RedfishCS_Header  Header;`<br/>`  //`<br/>`// Followed by C structure of resource.`<br/>`// The format of following structure is JSON--Struct-Converter specific`<br/>`//`<br/>`} RedfishCS_Type_CS_Data;`<br/><br/>
| **RedfishCS_Type_EmptyProp_CS_Data** | Redfish C Structure of Redfish resource which property is declared as empty property ("properties": {}), this type of Redfish C structure provides Redfish resource in C structure format.<br/>Only support below types of JSON value, the JSON object nested in the property is not supported,<br/><br/>`  JSON type string`<br/>`  JSON type number`<br/>`  JSON type integer`<br/<br/>`typedef struct _RedfishCS_EmptyProp_KeyValue {`<br/>`  RedfishCS_EmptyProp_KeyValue *NextKeyValuePtr;`<br/>`  RedfishCS_char  *KeyNamePtr;`<br/>`  RedfishCS_Vague *Value;`<br/>`} RedfishCS_EmptyProp_KeyValue;`<br/><br/>`typedef struct _RedfishCS_Type_EmptyProp_CS_Data {`<br/>`  RedfishCS_Header  Header;`<br/>`  RedfishCS_uint32 NunmOfProperties;`<br/>`  RedfishCS_EmptyProp_KeyValue *KeyValuePtr;`<br/>`} RedfishCS_Type_EmptyProp_CS_Data;`<br/><br/>
| **RedfishCS_Type_JSON_Data** |Redfish C Structure of resource in JSON text format, this type prvides the Redfish resource in Json text format.<br/><br/>`typedef struct _RedfishCS_Type_JSON_Data {`<br/>`RedfishCS_Header  Header;`<br/>`RedfishCS_char  *JsonText;`<br/>`} RedfishCS_Type_JSON_Data;`<br/><br/>
| **RedfishCS_Vague** |Redfish C Structure of JSON property which data type could be boolean, int or string.<br/><br/>`typedef enum {`<br/>`RedfishCS_Vague_DataType_String = 1,`<br/>`RedfishCS_Vague_DataType_Int64,`<br/>`RedfishCS_Vague_DataType_Bool`<br/>`} RedfishCS_Vague_DataType;`<br/><br/>`typedef union {`<br/>`RedfishCS_char  *CharPtr;`<br/>`RedfishCS_bool  *BoolPtr;`<br/>`RedfishCS_int64 *Int64Ptr;`<br/>`} RedfishCS_Vague_Ptr;`<br/><br/>`typedef struct _RedfishCS_Vague {`<br/>`RedfishCS_Vague_DataType DataType;`<br/>`RedfishCS_Vague_Ptr 	   DataValue;`<br/>`} RedfishCS_Vague;`<br/><br/>

## README.md for Each Converter
README.md is provided for each ***Redfish-JSON-C-Struct-Converter*** under its source directory.
See src/ServiceRoot/ServiceRoot.v1_1_0/README.md for the example.

