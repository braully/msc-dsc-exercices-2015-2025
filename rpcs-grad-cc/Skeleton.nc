interface Skeleton {
  command result_t requisicao(uint8_t *args);
  command bool ocupado();
  event result_t resposta(uint8_t *args);
}
