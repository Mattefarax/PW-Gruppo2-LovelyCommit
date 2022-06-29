#ifndef PROTO_h
#define PROTO_h
#include <xc.h>

char addr = 0x00;
char addrRequested = 0x00;
char displayText[20];

#define payloadValidationTimeout 2 //After this time(ms) of no receive data the queue is checked for payload 
#define payloadAddrRetryMs 2 //Time(ms) between handshakes retry
#define payloadSendMs 10 //Scheduling time(ms) for send payload

//Each of used bit definition for 10th byte of the payload  
#define EMERGENCY_BIT 0X08 
#define BACKDOOR_BIT 0X04 //High when open
#define FRONTDOOR_BIT 0X02 //High when open
#define TOILETTE_BIT 0X01 //High when occupied

char protoStatusByte = 0x00; //X - X - X - X - EMERGENCY_BIT - BACKDOOR_BIT - FRONTDOOR_BIT - TOILETTE_BIT
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
