module SkeletonMStub{
  provides interface Skeleton;
  //uses interface servicoX;
}
implementation{
  uint8_t count = 0;
  uint8_t arg0; //Numero de parametros de acordo com o comando no servixo x

  task void process(){
    //call servicoX.metodoX(arg0);
    //Fazer marshalling da resposta
    signal Skeleton.reposta(&arg0);
  }

  command result_t Skeleton.requisicao(uint8_t *args){
    arg0 = args[count++]; //Umarshalling meia boca
    post process();
  }
}