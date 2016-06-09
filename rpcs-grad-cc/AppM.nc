module AppM{
  provides{
    interface Skeleton; 
  }
}
  implementation{
    command result_t Skeleton.requisicao(uint8_t *args){
      dbg (DBG_USR1, "AppM - Requisicao Feita.\n");
      signal Skeleton.resposta(args);
    }
}