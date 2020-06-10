/* 
 * File:   Historico.h
 * Author: marioandre
 *
 * Created on 24 de Abril de 2016, 15:04
 */

#ifndef HISTORICO_H
#define	HISTORICO_H

#include "Pilha.h"
#include "Fila.h"

#include <string>
using std::string;

class Historico {
public:
    Historico(int n);
    Historico(const Historico& outra,int n);
    void addComando(string co);
    string mostraHistorico();
    string mostraHistorico_n(int n);
    int Id_historico();
    bool historicoVazio(); 
    
private:
    Pilha<string> historico;
    
};    

#endif	/* HISTORICO_H */

