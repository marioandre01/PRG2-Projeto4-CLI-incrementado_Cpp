#ifndef FILA_H
#define	FILA_H

#include<iostream>
using namespace std;


template <typename T> class Fila {
public:
    // cria uma fila com capacidade "N"
    Fila(unsigned int N);
    
    // cria uma fila que é cópia de outra fila
    Fila(const Fila<T>& outra);
 
    // destrutor da fila
    virtual ~Fila();
    
    Fila<T>& operator=(const Fila<T> & outra); //Contrutor de atribuição
 
    // enfileira "algo" no fim da fila
    void enfileira(const T & algo);
 
    // desenfileira um dado do início da fila
    T desenfileira();
 
    // retorna uma referência ao dado que está no início 
    // da fila, sem removê-lo da fila
    T & frente() const;
 
    bool vazia() const {
        return itens == 0; 
    }
    
    bool cheia() const { 
        return itens == capacidade;
    }
    
    unsigned int tamanho() const { 
        return itens;
    }
    
private:
    int capacidade;
    int itens, inicio, fim;
 
    // a área de armazenamento da fila
    T* buffer;
};
 
// Abaixo seguem os esqueletos das implementações dos métodos da Fila
 
template <typename T> Fila<T>::Fila(unsigned int N) {
    // inicia os atributos da fila: inicialmente
    // ela está vazia
    capacidade = N;
    inicio = 0;
    fim = 0;
    itens = 0;
 
    // aloca memória para guardar "capacidade" dados do tipo "T"
    buffer = new T[capacidade];
       
}
 
template <typename T> Fila<T>::Fila(const Fila<T>& outra) {
    capacidade = outra.capacidade;
    inicio = outra.inicio;
    fim = outra.fim;
    itens = outra.itens;
  
    buffer = new T[capacidade];
    
    for (int n=0; n< capacidade; n++) {
        buffer[n] = outra.buffer[n];
    }
}

template <typename T> Fila<T>& Fila<T>::operator=(const Fila<T> & outra) {
    itens = outra.itens;
    capacidade = outra.capacidade;
    inicio = outra.inicio;
    fim = outra.fim;
    
    delete[] buffer;
    
    buffer = new T[capacidade];
    
    for (int n=0; n< capacidade; n++) {
        buffer[n] = outra.buffer[n];
    }
    
}
 
template <typename T> Fila<T>::~Fila() {
}
 
template <typename T> void Fila<T>::enfileira(const T& algo) {
    if (cheia() == false){
        buffer[fim] = algo;
        fim ++;
        itens ++;
   
        if (fim == capacidade){
            fim = 0;
        }
    }else{
        
    }
}
 
template <typename T> T Fila<T>::desenfileira() {
    if (vazia() == false){
        T nulo;
        T valor;
        
        valor = buffer[inicio];
        buffer[inicio] = nulo;
        inicio ++;
        itens --;
        if (inicio == capacidade){
            inicio = 0;
        }
        return valor;
    }else{
        
    }
}
 
template <typename T> T& Fila<T>::frente() const {
    if (vazia() == false){
    //cout << "O primeiro item da fila é: " << buffer[inicio] << endl << endl;
        return buffer[inicio];
    }else{
        //cout << "operação invalida, a fila esta vazia" << endl;
    }
}

 
#endif	/* FILA_H */

