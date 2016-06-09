includes SkeletonList;
includes ProtocolMsg;

module RPCSM{
  provides{
    interface StdControl;
  }
  uses{
    interface StdControl as CommControl;
    interface Skeleton[uint8_t id];
    interface SendMsg as Resposta;
    interface ReceiveMsg as Requisicao;
  }
}

implementation{
  TOS_Msg msg;
  
  RPC_MsgPtr temp_resp;
  RPC_MsgPtr temp_req;
  
  /* Status do Radio */
  bool ocupado;
  
  /* Fila de Espera */
  No *head;
  
  void inicializa(){
	head = NULL;
	ocupado = FALSE;
  }
   
	int insere(RPC_MsgPtr msg){
		No *temp = malloc(sizeof(No));
		if(temp == NULL) return -1; //Erro, acabou a memoria
		temp->msg = msg;
		temp->prox = NULL;
		
		if(head == NULL) {
			head = temp;
		} else {
			NoPtr ant = head;
			NoPtr p = ant->prox;
			
			while(p != NULL && p->msg->modulo_id <= temp->msg->modulo_id){
				ant = p;
				p = p->prox;
			}
			ant->prox = temp;
			temp->prox = p;
		}
		dbg (DBG_USR1, "Mensagem Adicionada na Fila.\n");
		return 0; //Sucesso
	}
	
	RPC_MsgPtr remove(uint8_t modulo_id) {
		NoPtr ant = head;
		NoPtr p = head;
		RPC_MsgPtr ret = NULL;
		
		//if(head != NULL)  p = head->prox;
		
		while(p != NULL && p->msg->modulo_id < modulo_id) {
			ant = p;
			p = p->prox;
		}
		
		if(p != NULL){
			ret = p->msg;
			ant->prox = p->prox;
			ret = p->msg;
		} else dbg(DBG_USR1,"A mensagem não está na fila.");
		return ret;
	}
	
	RPC_MsgPtr busca(uint8_t modulo_id) {
		NoPtr p = head;
		RPC_MsgPtr ret = NULL;
		while(p != NULL && p->msg->modulo_id != modulo_id) p = p->prox;
		if(p!= NULL) ret = p->msg;
		return ret;
	}
  
  command result_t StdControl.init(){
    dbg (DBG_USR1, "Componentes Iniciados - Aguardando Requisicoes.\n");
	inicializa();
    return call CommControl.init();
  }
  
  command result_t StdControl.start(){
	dbg (DBG_USR1, "Componentes Startados.\n");
    return call CommControl.start();
  }
  
  command result_t StdControl.stop(){
	dbg (DBG_USR1, "Componentes Parados.\n");
    return call CommControl.stop();
  }

  task void envia_resposta(){
	dbg (DBG_USR1, "Preparando Mensagem de Resposta.\n");
	if(temp_resp != NULL){
		atomic{
			dbg (DBG_USR1, "Dereferenciando ponteiro.\n");
			//temp_resp->request_id++;
			msg.addr = temp_resp->origem_id;
			temp_resp->origem_id = TOS_LOCAL_ADDRESS;

			dbg (DBG_USR1, "Duplicando resposta.\n");
			memcpy(msg.data, temp_resp, sizeof(RPC_Msg));
			dbg (DBG_USR1, "Liberando memoria utilizada.\n");
			free(temp_resp);
		}
		dbg (DBG_USR1, "Enviando Resposta - para:%d",msg.addr);
		call Resposta.send(TOS_UART_ADDR, sizeof(RPC_Msg), &msg);
	} else dbg (DBG_USR1, "Erro Resposta Corrompida.\n");
  }

  task void despacha(){
	RPC_MsgPtr ptr = (RPC_MsgPtr)malloc(sizeof(RPC_Msg));
	dbg (DBG_USR1, "Adicionando Mensagem a Fila.\n");
	
	memcpy(ptr, temp_req, sizeof(RPC_Msg));
	insere(ptr);
	
	dbg (DBG_USR1, "Despachando Requisição - Servico %d\n",ptr->modulo_id);
	if(!call Skeleton.ocupado[ptr->modulo_id]()) {
		(DBG_USR1, "Acionando Modulo do Serviço.\n");
		call Skeleton.requisicao[ptr->modulo_id](ptr->args);
	} else (DBG_USR1, "Modulo Ocupado, Aguardando Liberação.\n");
  }
  
  event result_t Resposta.sendDone(TOS_MsgPtr sent, result_t success) {
	dbg (DBG_USR1, " Mensagem enviada.\n");
	
	/* se existir alguma requisição na fila será despachada */
	atomic{
		RPC_MsgPtr p;
		p = (RPC_MsgPtr)sent->data;
		ocupado = FALSE;
		temp_req = busca(p->modulo_id);
	}
	if(temp_req != NULL) post despacha();
    return SUCCESS;
  }
  
  event result_t Skeleton.resposta[uint8_t id](uint8_t *args){
	dbg (DBG_USR1, "Processamento da requisição terminado: Skeleton %d.\n",id);
	temp_resp = remove(id);
	post envia_resposta();
  }

  event TOS_MsgPtr Requisicao.receive(TOS_MsgPtr m) {
	dbg(DBG_USR1, "RPCSM - Mensagem Recebida.\n");
	temp_req = (struct RPC_Msg *)m->data;
    post despacha();
  }
}
