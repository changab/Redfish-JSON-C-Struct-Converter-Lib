//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishActioninfo_V1_0_1_CSTRUCT_H_
#define _RedfishActioninfo_V1_0_1_CSTRUCT_H_

#include "RedfishCsCommon.h"

typedef struct _RedfishActionInfo_V1_0_1_Parameters_Array_CS RedfishActionInfo_V1_0_1_Parameters_Array_CS;
typedef struct _RedfishActionInfo_V1_0_1_ActionInfo_CS RedfishActionInfo_V1_0_1_ActionInfo_CS;
typedef struct _RedfishActionInfo_V1_0_1_Parameters_CS RedfishActionInfo_V1_0_1_Parameters_CS;
#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishActionInfo_V1_0_1_Parameters_CS {
    RedfishCS_char_Array    *AllowableValues;    // A list of values for this
                                                // parameter supported by this
                                                // Action target.
    RedfishCS_char          *DataType;          // The JSON property type used
                                                // for this parameter.
    RedfishCS_char          *Name;              // The name of the parameter for
                                                // this Action.
    RedfishCS_char          *ObjectDataType;    // The OData Type of an object-
                                                // based parameter.
    RedfishCS_bool          *Required;          // Indicates whether the
                                                // parameter is required to
                                                // perform this Action.
} RedfishActionInfo_V1_0_1_Parameters_CS;

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
// ActionInfo describes the parameters and other information necessary to perform
// a Redfish Action to a particular Action target.  As parameter support may
// differ between implementations and even among instances of a resource, this
// data can be used to ensure Action requests from applications contain supported
// parameters.
//
typedef struct _RedfishActionInfo_V1_0_1_ActionInfo_CS {
    RedfishCS_Header                                Header;
    RedfishCS_char                                  *odata_context;
    RedfishCS_char                                  *odata_id;    
    RedfishCS_char                                  *odata_type;  
    RedfishCS_char                                  *Description; 
    RedfishCS_char                                  *Id;          
    RedfishCS_char                                  *Name;        
    RedfishResource_Oem_CS                          *Oem;             // This is the
                                                                      // manufacturer/provider specific
                                                                      // extension moniker used to
                                                                      // divide the Oem object into
                                                                      // sections.
    RedfishActionInfo_V1_0_1_Parameters_Array_CS    *Parameters;      // The parameters associated with
                                                                      // the specified Redfish Action.
} RedfishActionInfo_V1_0_1_ActionInfo_CS;

typedef struct _RedfishActionInfo_V1_0_1_Parameters_Array_CS  {
    RedfishActionInfo_V1_0_1_Parameters_Array_CS    *Next;
    RedfishActionInfo_V1_0_1_Parameters_CS    *ArrayValue;
} RedfishActionInfo_V1_0_1_Parameters_Array_CS;

RedfishCS_status
Json_ActionInfo_V1_0_1_To_CS (char *JsonRawText, RedfishActionInfo_V1_0_1_ActionInfo_CS **ReturnedCS);

RedfishCS_status
CS_To_ActionInfo_V1_0_1_JSON (RedfishActionInfo_V1_0_1_ActionInfo_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroyActionInfo_V1_0_1_CS (RedfishActionInfo_V1_0_1_ActionInfo_CS *CSPtr);

RedfishCS_status
DestroyActionInfo_V1_0_1_Json (RedfishCS_char *JsonText);

#endif
