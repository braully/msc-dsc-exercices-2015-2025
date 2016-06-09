#include "ProtocolMsg.h"

typedef struct No{
	RPC_MsgPtr msg;
	struct No *prox;
} No;

typedef No *NoPtr;