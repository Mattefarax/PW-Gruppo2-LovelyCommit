#ifndef PROTO_h
#define PROTO_h
#include <xc.h>

//Declarations

char addr = 0x00;
char addrRequested = 0x00;
char displayText[20];

#define messageOffsetTimeout 2 // Must be MilliSec
#define payloadAddrRetry 2
#define payloadSendSecond 10

char protoStatusByte = 0x00; //10th byte of the payload

#define EMERGENCY_BIT 0X08 
#define BACKDOOR_BIT 0X04 //High when open
#define FRONTDOOR_BIT 0X02 //High when open
#define TOILETTE_BIT 0X01 //High when occupied


char  temp_1_2;
char  temp_2_2;
char  setTemp_1_2;
char  setTemp_2_2;
char  humidity_1_2; 
char  humidity_2_2;

void PROTO_HandshakeReq();
void PROTO_SendPayload();
void PROTO_QueueChecker();

#endif
