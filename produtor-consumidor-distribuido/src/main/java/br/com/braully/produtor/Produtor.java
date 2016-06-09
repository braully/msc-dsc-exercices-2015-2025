/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.braully.produtor;

import br.com.braully.buffer.IBufferRemote;
import br.com.braully.excecoes.BufferCheioException;
import org.apache.commons.lang.RandomStringUtils;

/**
 *
 * @author braullyrocha
 */
public class Produtor implements IProdutorRemoto {

    private static int contadoInstancias = 0;
    private String identificadorProdutor;

    private IBufferRemote referenciaBuffer;

    boolean fim;

    public Produtor(IBufferRemote referenciaRemotaBuffer) {
        this.referenciaBuffer = referenciaRemotaBuffer;
        this.fim = false;
        this.identificadorProdutor = "produtor/" + contadoInstancias++;

    }

    public void alertaBufferContemDados() {

    }

    public void inserirDado(char dado) {

    }

    public void iniciar() {
        new Thread() {
            public void run() {
                while (!fim) {
                    Character dado = null;
                    try {
                        dado = RandomStringUtils.randomAlphabetic(1).charAt(0);
                        if (!referenciaBuffer.isCheio()) {
                            referenciaBuffer.inserirDado(dado, identificadorProdutor);
                            sleep(Math.round(Math.random() * IBufferRemote.TEMPO_ESPERA_ENTRE_PRODUCOES));
                        } else {
                            System.out.println("=" + identificadorProdutor + " buffer cheio, esperando consumo");
                            sleep(Math.round(Math.random() * IBufferRemote.TEMPO_ESPERA_PRODUCAO));
                        }
                    } catch (BufferCheioException e) {
                        System.err.println("Tentando produzir em buffer cheio");
                    } catch (Exception e) {
                        System.err.println("Falha no produtor: " + e.getLocalizedMessage());
                        e.printStackTrace();
                    }
                }
            }
        }.start();
    }

    public String getIdentificadorProdutor() {
        return identificadorProdutor;
    }

}
