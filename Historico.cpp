#include "Historico.h"

    Historico::Historico(int n):historico(n){
        
    }
    
    Historico::Historico(const Historico& outra,int n):historico(n){
        historico = outra.historico;
            
    }
    
    void Historico::addComando(string co){
        historico.push(co);
    }
    
    string Historico::mostraHistorico(){
        return historico.pop();
        
    }
    
    string Historico::mostraHistorico_n(int n){
        Pilha<string>copiaHistorico = historico;
        return historico.pop_n(copiaHistorico,n);
        
    }
    
    int Historico::Id_historico(){
      return historico.idTopo();
    }
    
    bool Historico::historicoVazio(){
        return historico.vazia();
    }
