#includes "protocol.h"

#ifndef MAX_ELEMENTOS
#define MAX_ELEMENTOS 20
#endif

typedef struct fila {
	uint8_t *id;
	No *prox;
};

void adiciona(RPC_MsgPtr msg){
		if(msg!= NULL){
			No *ant = fila;
			No *p = fila;
			for(; p != NULL && p->id <= msg->modulo_id;ant = p,p = p->prox);
			
			p* = malloc(sizeof(typedef No));
			p->id = msg->metodo_id;
			p->msg = msg;
			
			if(ant == NULL) fila = p;
			else ant->prox = p;
		}
		
	}