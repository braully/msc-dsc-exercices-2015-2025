module SkeletonList{
  provides{
    interface Skeleton[uint8_t id];
  }
}

implementation{
  command result_t Skeleton.requisicao[uint8_t id](uint8_t *args){
    dbg(DBG_USR1,"Comando de requisição() Default: %d",id);
    return SUCCESS;
  }
  
  command bool Skeleton.ocupado[uint8_t id](){
    dbg(DBG_USR1,"Comando ocupado() Default: %d",id);
    return FALSE;
  }
  
  default event result_t Skeleton.resposta[uint8_t id](uint8_t *args){
    dbg(DBG_USR1,"Caiu no evento Default funcao: %d",id);
    return SUCCESS;
  }
}
