module SkeletonLeds{
  provides interface Skeleton;
  uses interface Leds;
}

implementation{

  uint8_t *buffer = NULL;
  result_t result;
  uint8_t value;
  bool ocupado = FALSE;
  
  void marshalling(void *args, uint8_t size, uint8_t *buff){
    memcpy(args, buff, size);
  }

  task void processa(){
	ocupado = TRUE;
	dbg (DBG_USR1, "Chamando comando %d - Serviço LEDS.\n",buffer[0]);
    switch (buffer[0]) {
    case 0:
      result = call Leds.init();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 1:
      result = call Leds.redOn();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); signal Skeleton.resposta(buffer); break;
    case 2:
      result = call Leds.redOff();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); signal Skeleton.resposta(buffer); break;
    case 3:
      result = call Leds.redToggle();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 4:
      result = call Leds.greenOn();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 5:
      result = call Leds.greenOff();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 6:
      result = call Leds.greenToggle();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 7:
      result = call Leds.yellowOn();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 8:
      result = call Leds.yellowOff();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 9:
      result = call Leds.yellowToggle();
      marshalling(&result, sizeof(result_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 10:
      value = call Leds.get();
      marshalling(&value, sizeof(uint8_t), buffer);
      signal Skeleton.resposta(buffer); break;
    case 11:
      if(buffer != NULL)
	result = call Leds.set(buffer[1]);
	marshalling(&result, sizeof(result_t), buffer);
      /* else{ } TODO: Utilizar algum codigo de erro */
      signal Skeleton.resposta(buffer);
      break;
    default:
      /* TODO: Utilizar algum codigo de erro */
      signal Skeleton.resposta(buffer); break; 
    }
  }


  command result_t Skeleton.requisicao(uint8_t *args){
	dbg (DBG_USR1, "Requisição - Serviço LEDS.\n");
    if(args == NULL)
      return FAIL;
    buffer = args;
    post processa();
	ocupado = FALSE;
    return SUCCESS;
  }
  
    command bool Skeleton.ocupado(){
		dbg (DBG_USR1, "Ocupado %d - Serviço LEDS.\n",ocupado);
		return ocupado;
	}

}
