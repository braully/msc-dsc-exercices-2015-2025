/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.braully.buffer;

import java.io.Serializable;
import java.rmi.Remote;

/**
 *
 * @author braullyrocha
 */
public interface IBufferRemote extends Remote, Serializable {

    public static final double TEMPO_ESPERA_ENTRE_PRODUCOES = 1000 * 7;
    public static final double TEMPO_ESPERA_PRODUCAO = 1000 * 10;

    public String situacaoBuffer();

    public void inserirDado(char dado, String identificadorProdutor);

    public Character removerDado(String identificadorConsumidor);

    public boolean isCheio();

    public boolean isVazio();

}
