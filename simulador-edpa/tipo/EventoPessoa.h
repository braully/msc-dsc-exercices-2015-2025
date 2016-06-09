/* 
 * File:   EventoPessoa.h
 * Author: braully
 *
 * Created on 16 de Dezembro de 2014, 15:19
 */

#ifndef EVENTOPESSOA_H
#define	EVENTOPESSOA_H

#include <string>

class EventoPessoa {
public:
    EventoPessoa();
    EventoPessoa(const EventoPessoa& orig);
    virtual ~EventoPessoa();

    EventoPessoa(std::string evento, int momento) :
    evento(evento), momento(momento) {
    }

    std::string GetEvento() const {
        return evento;
    }

    int GetMomento() const {
        return momento;
    }

private:
    int momento;
    std::string evento;
};

#endif	/* EVENTOPESSOA_H */

