includes ProtocolMsg;
includes SkeletonList;

configuration RPCS{
}

implementation{
  components Main, SkeletonList, SkeletonLeds, LedsC, RPCSM, GenericComm as Comm;
  /* Configurcação Default */
  Main.StdControl -> RPCSM;
  RPCSM.Skeleton -> SkeletonList.Skeleton; 
  RPCSM.CommControl -> Comm;
  RPCSM.Requisicao -> Comm.ReceiveMsg[AM_RPC];
  RPCSM.Resposta -> Comm.SendMsg[AM_RPC];

  /* Configuração do Serviço */
  SkeletonLeds.Leds -> LedsC;
  RPCSM.Skeleton[LEDS] -> SkeletonLeds.Skeleton; 
}
