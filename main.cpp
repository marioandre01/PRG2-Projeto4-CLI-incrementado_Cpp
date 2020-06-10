/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on 25 de Julho de 2016, 20:31
 */

#include <iostream>
#include "interfaceUsuario.h"
#include <sstream>
#include <string>

using namespace std;

int main() {
  //Criando objeto interface de tipo interfaceUsuario
  InterfaceUsuario interface("comando> ");
  
  string palavra;
  
  //Criando 10 macros com seus nomes
  /*Macro m1("m1");
  Macro m2("m2");
  Macro m3("m3");
  Macro m4("m4");
  Macro m5("m5");
  Macro m6("m6");
  Macro m7("m7");
  Macro m8("m8");
  Macro m9("m9");
  Macro m10("m10");
  
  //Adicionando comandos nas macros, em cada macro pode-se adicionar 10 comandos
  m1.adiciona("ls");
  m1.adiciona("pwd");
  
  m2.adiciona("date");
  m2.adiciona("historico");
  m2.adiciona("m1");
  
  m3.adiciona("w");
  m3.adiciona("free");
  m3.adiciona("ifconfig");
  m3.adiciona("pwd");
  
  m4.adiciona("ls");
  m4.adiciona("date");
  m4.adiciona("eject");
  m4.adiciona("ls -l");
  
  m5.adiciona("cat /etc/hosts");
  m5.adiciona("uname -a");
  m5.adiciona("hostname");
  
  m6.adiciona("df");
  m6.adiciona("free");
  m6.adiciona("ifconfig");
  
  m7.adiciona("ps");
  m7.adiciona("echo ola mundo");
  m7.adiciona("pwd");
  
  m8.adiciona("w");
  m8.adiciona("free");
  m8.adiciona("m7");
  
  m9.adiciona("ls -la");
  m9.adiciona("m3");
  m9.adiciona("m5");
  
  m10.adiciona("ls -l");
  m10.adiciona("pwd");
  m10.adiciona("w");
  
  //Adicionando objetos das macros criadas no vetor do tipo Macro
  interface.Adicionar_macro(m1);
  interface.Adicionar_macro(m2);
  interface.Adicionar_macro(m3);
  interface.Adicionar_macro(m4);
  interface.Adicionar_macro(m5);
  interface.Adicionar_macro(m6);
  interface.Adicionar_macro(m7);
  interface.Adicionar_macro(m8);
  interface.Adicionar_macro(m9);
  interface.Adicionar_macro(m10);
  */
  
  while (palavra != "exit") {
    
    int status = interface.leUmComando(); //Chamando função que pede para digitar um comando  
    cout << "Executou com status: " << status << endl;
    
    palavra = interface.meuComando(); //Guarda na variavel palavra o comando digitado
    
 }
  cout << endl << "### A interface de linha de comando foi fechada ###" << endl;
  
}
