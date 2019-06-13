//
//  (C) Copyright 2018-2019 Hewlett Packard Enterprise Development LP<BR>
//

#ifndef _RedfishSerialinterface_V1_0_2_CSTRUCT_H_
#define _RedfishSerialinterface_V1_0_2_CSTRUCT_H_

#include "RedfishCsCommon.h"

#ifndef __RedfishResource_Oem_CS__
typedef struct _RedfishResource_Oem_CS RedfishResource_Oem_CS;
#endif

typedef struct _RedfishSerialInterface_V1_0_2_SerialInterface_CS RedfishSerialInterface_V1_0_2_SerialInterface_CS;
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
// This schema defines an asynchronous serial interface resource.
//
typedef struct _RedfishSerialInterface_V1_0_2_SerialInterface_CS {
    RedfishCS_Header          Header;
    RedfishCS_char            *odata_context;  
    RedfishCS_char            *odata_id;       
    RedfishCS_char            *odata_type;     
    RedfishCS_char            *BitRate;            // The receive and transmit rate
                                                   // of data flow, typically in
                                                   // bits-per-second (bps), over
                                                   // the serial connection.
    RedfishCS_char            *ConnectorType;      // The type of connector used for
                                                   // this interface.
    RedfishCS_char            *DataBits;           // The number of data bits that
                                                   // will follow the start bit over
                                                   // the serial connection.
    RedfishCS_char            *Description;    
    RedfishCS_char            *FlowControl;        // The type of flow control, if
                                                   // any, that will be imposed on
                                                   // the serial connection.
    RedfishCS_char            *Id;             
    RedfishCS_bool            *InterfaceEnabled;    // This indicates whether this
                                                   // interface is enabled.
    RedfishCS_char            *Name;           
    RedfishResource_Oem_CS    *Oem;                // This is the
                                                   // manufacturer/provider specific
                                                   // extension moniker used to
                                                   // divide the Oem object into
                                                   // sections.
    RedfishCS_char            *Parity;             // The type of parity used by the
                                                   // sender and receiver in order
                                                   // to detect errors over the
                                                   // serial connection.
    RedfishCS_char            *PinOut;             // The physical pin configuration
                                                   // needed for a serial connector.
    RedfishCS_char            *SignalType;         // The type of signal used for
                                                   // the communication connection -
                                                   // RS232 or RS485.
    RedfishCS_char            *StopBits;           // The period of time before the
                                                   // next start bit is transmitted.
} RedfishSerialInterface_V1_0_2_SerialInterface_CS;

RedfishCS_status
Json_SerialInterface_V1_0_2_To_CS (char *JsonRawText, RedfishSerialInterface_V1_0_2_SerialInterface_CS **ReturnedCS);

RedfishCS_status
CS_To_SerialInterface_V1_0_2_JSON (RedfishSerialInterface_V1_0_2_SerialInterface_CS *CSPtr, char **JsonText);

RedfishCS_status
DestroySerialInterface_V1_0_2_CS (RedfishSerialInterface_V1_0_2_SerialInterface_CS *CSPtr);

RedfishCS_status
DestroySerialInterface_V1_0_2_Json (RedfishCS_char *JsonText);

#endif
