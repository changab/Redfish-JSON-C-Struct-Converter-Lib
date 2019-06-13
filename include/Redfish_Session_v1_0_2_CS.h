//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSession_V1_0_2_CSTRUCT_H_
#define _RedfishSession_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishSession_V1_0_2_Session_CS RedfishSession_V1_0_2_Session_CS;
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
// The Session resource describes a single connection (session) between a client
// and a Redfish service instance.
//
typedef struct _RedfishSession_V1_0_2_Session_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;
    RedfishCS_char            *odata_id;    
    RedfishCS_char            *odata_type;  
    RedfishCS_char            *Description; 
    RedfishCS_char            *Id;          
    RedfishCS_char            *Name;        
    RedfishResource_Oem_CS    *Oem;             // This is the
                                                // manufacturer/provider specific
                                                // extension moniker used to
                                                // divide the Oem object into
                                                // sections.
    RedfishCS_char            *Password;        // This property is used in a
                                                // POST to specify a password
                                                // when creating a new session.
                                                // This property is null on a
                                                // GET.
    RedfishCS_char            *UserName;        // The UserName for the account
                                                // for this session.
} RedfishSession_V1_0_2_Session_CS;

RedfishCS_status
Json_Session_V1_0_2_To_CS (char *JsonRawText, RedfishSession_V1_0_2_Session_CS **ReturnedCS);

RedfishCS_status
CS_To_Session_V1_0_2_JSON (RedfishSession_V1_0_2_Session_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySession_V1_0_2_CS (RedfishSession_V1_0_2_Session_CS *CSPtr);

RedfishCS_status
DestroySession_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
