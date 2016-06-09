#ifndef TOSH_DATA_LENGTH
#define TOSH_DATA_LENGTH 10
#endif

#define TAM_CABECALHO 5
#define TAM_ARGS TOSH_DATA_LENGTH-TAM_CABECALHO

/**
 * Definição do corpo da mensagem.
 */
typedef struct RPC_Msg {
    uint16_t origem_id;
    uint8_t modulo_id;
    uint8_t request_id;
    uint8_t args[TAM_ARGS];
} RPC_Msg;

typedef RPC_Msg *RPC_MsgPtr;

typedef struct No{
	RPC_MsgPtr msg;
	struct No *prox;
} No;

typedef No *NoPtr;

enum {
  AM_RPC = 10
};

