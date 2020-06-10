/* 
 * File:   Macro.cpp
 * Author: marioandre
 * 
 * Created on 23 de Abril de 2016, 11:19
 */

#include "Macro.h"
#include "Lista.h"


Macro::Macro():comandos(10){
  
}

Macro::Macro(string m):comandos(10){ //Construtor com parametro
  nome = m;
}

Macro::Macro(const Macro& outra):comandos(10) { //Construtuor de copia
    nome = outra.nome;
    comandos = outra.comandos;
}

/*Macro::Macro(){
    
}

Macro::Macro(string m){
    nome = m;
}*/

Macro::~Macro() {
    
}

string Macro::getNome(){ //retorna o nome da macro
        return nome;
}
    
void Macro::adiciona(string ad){ //Adiciona o conteudo passado no parametro na macro
        comandos.enfileira(ad);
    //comandos.anexa(ad);
}

string Macro::retira(){ //Retira o conteudo da macro
        return comandos.desenfileira(); 
    
    
}

bool Macro::vazio(){ //retorna se a fila da macro esta vazia
    return comandos.vazia(); 
}

/*void Macro::inicia(){ //Retira o conteudo da macro
       
    return comandos.inicia();
    
}

string& Macro::proximo(){ //Retira o conteudo da macro
        
    return comandos.proximo();
    
}

bool Macro::fim(){ //Retira o conteudo da macro
        
    return comandos.fim();
    
}*/


    


