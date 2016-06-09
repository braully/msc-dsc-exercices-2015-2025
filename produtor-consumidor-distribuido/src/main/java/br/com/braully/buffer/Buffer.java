/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.com.braully.buffer;

import br.com.braully.excecoes.BufferCheioException;
import br.com.braully.excecoes.BufferVazioException;
import java.rmi.Naming;

/**
 *
 * @author braullyrocha
 */
public class Buffer implements IBufferRemote {

    public static final int TAMANHO_MAXIMO_BUFFER = 100;

    private static int inicio, fim, tamanho;
    private static char[] buffer;
    private static boolean controlarConcorrencia;

    static {
        inicio = fim = tamanho = 0;
        buffer = new char[TAMANHO_MAXIMO_BUFFER];
        controlarConcorrencia = true;
    }

    public int getFim() {
        return fim;
    }

    public int getInicio() {
        return inicio;
    }

    public synchronized void inserirDado(char dado, String identificadorProdutor) {
        while (tamanho >= TAMANHO_MAXIMO_BUFFER - 1) {
            try {
                System.out.println("Buffer cheio: Esperando retiradas");
                this.wait((long) IBufferRemote.TEMPO_ESPERA_ENTRE_PRODUCOES);
            } catch (Exception ex) {
                throw new BufferCheioException();
            }
        }
        buffer[fim] = dado;
        System.out.println(">" + identificadorProdutor + " inserindo " + dado + "\tna posição " + fim + "\t");
        fim++;
        if (fim >= TAMANHO_MAXIMO_BUFFER - 1) {
            fim = TAMANHO_MAXIMO_BUFFER - 1;
        }
        tamanho++;
        informarSitauacaoBuffer();
        /* caso o buffer estivesse vazio, acordar as threads consumidoras */
        if (tamanho == 1) {
            this.notifyAll();
        }
    }

    @Override
    public synchronized Character removerDado(String identificador) {
        Character retirado = null;

        while (tamanho <= 0) {
            try {
                System.out.println("=" + identificador + " buffer vazio, esperando produção");
                this.wait((long) IBufferRemote.TEMPO_ESPERA_ENTRE_PRODUCOES);
            } catch (Exception e) {
                throw new BufferVazioException();
            }
        }
        /* armazendo o item a ser retirado */
        /* atualizando a quantidade de itens */
        tamanho--;
        fim--;
        if (fim < 0) {
            fim = TAMANHO_MAXIMO_BUFFER - 1;
        }
        retirado = buffer[fim];
        System.out.println("<" + identificador + " retirando " + retirado + "\tda posição " + fim + "\t");
        informarSitauacaoBuffer();

        if (tamanho == TAMANHO_MAXIMO_BUFFER - 1) {
            this.notifyAll();
        }
        return retirado;
    }

    public boolean isControlarConcorrencia() {
        return controlarConcorrencia;
    }

    public void setControlarConcorrencia(boolean controlarConcorrencia) {
        this.controlarConcorrencia = controlarConcorrencia;
    }

    public int getTamanho() {
        return tamanho;
    }

    private void informarSitauacaoBuffer() {
        System.out.println(situacaoBuffer());
    }

    public static void main(String... args) throws Exception {
        IBufferRemote buffer = new Buffer();
        Naming.rebind("buffer", buffer);
    }

    @Override
    public boolean isCheio() {
        return tamanho >= TAMANHO_MAXIMO_BUFFER;
    }

    @Override
    public boolean isVazio() {
        return tamanho <= 0;
    }

    @Override
    public String situacaoBuffer() {
        StringBuilder sb = new StringBuilder();
        sb.append("buffer[");
        sb.append(tamanho);
        sb.append("]\t = ");
        for (int i = 0; i < fim; i++) {
            sb.append(buffer[i]);
            sb.append(" ");
        }
        return sb.toString();
    }
}
