#ifndef PROTO_h
#define PROTO_h
#include <xc.h>

//Declarations

char addr = 0x00;
char addrRequested = 0x00;

void PROTO_HandshakeReq();
void PROTO_SendPayload();
void PROTO_QueueChecker();

#endif
