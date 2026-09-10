#ifndef KPD_CONFIG
#define KPD_CONFIG

#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/DIO/DIO_Private.h"

#define KPD_ColNo    4
#define KPD_RowNo    4

#define KPD_R0Pin    DIO_pin0
#define KPD_R1Pin    DIO_pin1
#define KPD_R2Pin    DIO_pin2
#define KPD_R3Pin    DIO_pin3
#define KPD_RowPinsConfigured {KPD_R0Pin, KPD_R1Pin, KPD_R2Pin, KPD_R3Pin}

#define KPD_R0Group  DIO_GroupD
#define KPD_R1Group  DIO_GroupD
#define KPD_R2Group  DIO_GroupD
#define KPD_R3Group  DIO_GroupD
#define KPD_RowGroupsConfigured {KPD_R0Group, KPD_R1Group, KPD_R2Group, KPD_R3Group}

#define KPD_C0Pin    DIO_pin4
#define KPD_C1Pin    DIO_pin5
#define KPD_C2Pin    DIO_pin6
#define KPD_C3Pin    DIO_pin7
#define KPD_ColPinsConfigured {KPD_C0Pin, KPD_C1Pin, KPD_C2Pin, KPD_C3Pin}

#define KPD_C0Group  DIO_GroupD
#define KPD_C1Group  DIO_GroupD
#define KPD_C2Group  DIO_GroupD
#define KPD_C3Group  DIO_GroupD
#define KPD_ColGroupsConfigured {KPD_C0Group, KPD_C1Group, KPD_C2Group, KPD_C3Group}

#define KPDValueConfigured {{'1','2','3','+'},\
                            {'4','5','6','-'},\
                            {'7','8','9','*'},\
                            {'C','0','E','/'}}

#endif /* KPD_CONFIG */
