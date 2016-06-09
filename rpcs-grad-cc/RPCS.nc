includes ProtocolMsg;
includes SkeletonList;

configuration RPCS{
}

implementation{
  components Main, SkeletonList, SkeletonLeds, LedsC, RPCSM, GenericComm as Comm;
  /* Configurca��o Default */
  Main.StdControl -> RPCSM;
  RPCSM.Skeleton -> SkeletonList.Skeleton; 
  RPCSM.CommControl -> Comm;
  RPCSM.Requisicao -> Comm.ReceiveMsg[AM_RPC];
  RPCSM.Resposta -> Comm.SendMsg[AM_RPC];

  /* Configura��o do Servi�o */
  SkeletonLeds.Leds -> LedsC;
  RPCSM.Skeleton[LEDS] -> SkeletonLeds.Skeleton; 
}
