/* 
 * File:   Pilha.h
 * Author: marioandre
 *
 * Created on 18 de Abril de 2016, 22:32
 */

#ifndef PILHA_H
#define PILHA_H

 
template <typename T> class Pilha {
 public:
  // construtor: deve-se informar a capacidade da pilha
  Pilha(int umaCapacidade);
 
  // construtor de cópia: cria uma pilha que é cópia de outra
  Pilha(const Pilha& outra);
 
  // destrutor da pilha
  ~Pilha();
 
  // operador de atribuição: torna esta pilha uma cópia de outra pilha
  Pilha<T> & operator=(const Pilha<T> & outra);
 
  // operações da pilha
 
  void push(const T & dado); // empilha um dado
 
  T pop(); // desempilha um dado
  
  T pop_n(Pilha<T> & pilha, int n); //desempilha um dado na posição especificada
 
  T& top() const; // retorna o dado do topo da pilha, sem retirá-lo
  
 
  bool vazia() const { return topo == 0;}
  bool cheia() const {return topo == capacidade;}
  void esvazia();
  
  int idTopo() { //retorna o indice do topo da pilha
      return topo;
  }
  
 protected:
  // atributos da pilha
  T * buffer; // a área de memória para armazenamento da pilha
  int topo, capacidade;
  // outros atributos ???
 
};
 
template <typename T> Pilha<T>::Pilha(int umaCapacidade) {
    capacidade = umaCapacidade;
    topo = 0;
    buffer = new T[capacidade];
}
 
template <typename T> Pilha<T>::Pilha(const Pilha& outra) {
    capacidade = outra.capacidade;
    topo = outra.topo;
    
    buffer = new T[capacidade];
    
    for (int n=0; n< capacidade; n++) {
        buffer[n] = outra.buffer[n];
    }
}

template <typename T> Pilha<T> & Pilha<T>::operator=(const Pilha<T> & outra){
    capacidade = outra.capacidade;
    topo = outra.topo;
    
    delete[] buffer;
    
    buffer = new T[capacidade];
    
    for (int n=0; n< capacidade; n++) {
        buffer[n] = outra.buffer[n];
    }
}
 
template <typename T> Pilha<T>::~Pilha() {
}
 
template <typename T> void Pilha<T>::esvazia() {
    T nulo;
    while (! vazia()) {
        topo--;
        buffer[topo] = nulo;
    }
}
 
template <typename T> void Pilha<T>::push(const T & dado) {
    if (cheia() == false) {
        buffer[topo] = dado;
        topo++;
    }
}
 
template <typename T> T Pilha<T>::pop() {
    T nulo;
    T valor;
    topo--;
    valor = buffer[topo];
    buffer[topo] = nulo;
    return valor;
}

template <typename T> T Pilha<T>::pop_n(Pilha<T> & pilha, int n) {
    T nulo;
    T valor;
    int id1;
    id1 = topo - n;
    valor = pilha.buffer[id1];
    pilha.buffer[id1] = nulo;
    return valor;
}
 
template <typename T> T& Pilha<T>::top() const{
    int indiceTopo;
    indiceTopo = topo;
    indiceTopo--;
    return buffer[indiceTopo];
    
}
 
#endif

