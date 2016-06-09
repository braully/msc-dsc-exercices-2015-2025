/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.braully.consumidor;

import br.com.braully.buffer.IBufferRemote;
import br.com.braully.excecoes.BufferVazioException;

/**
 *
 * @author braullyrocha
 */
public class Consumidor implements IConsumidorRemoto {

    private static int contadoInstancias = 0;
    private String identificadorConsumidor;

    private IBufferRemote referenciaBuffer;

    boolean fim;

    public Consumidor(IBufferRemote referenciaRemotaBuffer) {
        this.referenciaBuffer = referenciaRemotaBuffer;
        this.fim = false;
        this.identificadorConsumidor = "consumidor/" + contadoInstancias++;

    }

    public void alertaBufferContemDados() {

    }

    public void inserirDado(char dado) {

    }

    public void iniciar() {
        new Thread() {
            @Override
            public void run() {
                while (!fim) {
                    try {
                        if (!referenciaBuffer.isVazio()) {
                            Character removerDado = referenciaBuffer.removerDado(identificadorConsumidor);
                            sleep(Math.round(Math.random() * IBufferRemote.TEMPO_ESPERA_ENTRE_PRODUCOES));
                        } else {
                            System.out.println("=" + identificadorConsumidor + " buffer vazio, esperando produção");
                            sleep(Math.round(Math.random() * IBufferRemote.TEMPO_ESPERA_PRODUCAO));
                        }
                    } catch (BufferVazioException e) {
                        System.err.println("Tentando remover de buffer vazio");
                    } catch (Exception e) {
                        System.err.println("Falha no consumidor: " + e.getLocalizedMessage());
                        e.printStackTrace();
                    }
                }
            }
        }.start();
    }

    @Override
    public String getIdentificadorConsumidor() {
        return identificadorConsumidor;
    }
}
