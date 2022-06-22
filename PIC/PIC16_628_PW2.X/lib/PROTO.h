#ifndef PROTO_h
#define PROTO_h
#include <xc.h>

//Declarations

char addr = 0x00;
char addrRequested = 0x00;

#define messageOffsetTimeout 10 // Must be MilliSec/0.2 Ex => {2ms / 0.2 = 10}
#define payloadAddrRetry 2
#define payloadSendSecond 10

void PROTO_HandshakeReq();
void PROTO_SendPayload();
void PROTO_QueueChecker();

#endif
