includes RPC.h;

module StubM {
  uses interface RPCC;
  provides interface servicoX;
}

implementation{

  //colocar uma função que permita o rebind

  uint8_t module_id = 0;//auto-gerado
  uint16_t sensor_id = 0;//auto-gerado
  
  uint8_t args[BUFEER_SIZE]
  servicoX.metodo(uint8_t arg0, uint8_t arg1){
/*     args[0] = arg0; */
/*     args[1] = arg1; */
/*     RPCC.requisicao(sensor_id, modulo_id,args); */
  }
  event result_t RPCC.resposta(uint8_t resp_sensor_id, uint8_t resp_modulo_id, uint8_t *resp_args){
    /* signal servicoX.resposta(resp_args[0]); */
  }

}