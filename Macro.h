/* 
 * File:   Macro.h
 * Author: marioandre
 *
 * Created on 23 de Abril de 2016, 11:19
 */

#ifndef MACRO_H
#define	MACRO_H

#include "Fila.h"
#include "Lista.h"


class Macro{
public:
   
    Macro();
    Macro(string m);
    Macro(const Macro& outra);
    virtual ~Macro();
    string getNome();
    void adiciona(string ad);
    string retira();
    void inicia();
    string& proximo();
    bool fim();
    bool vazio();
    
    
    
private:
    string nome;
    Fila<string> comandos;
      //Lista<string> comandos;
    
};

#endif	/* MACRO_H */

