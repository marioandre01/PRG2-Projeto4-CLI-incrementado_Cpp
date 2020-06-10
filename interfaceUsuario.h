/* 
 * File:   interfaceUsuario.h
 * Author: marioandre
 *
 * Created on 5 de Abril de 2016, 10:35
 */

#ifndef INTERFACEUSUARIO_H
#define	INTERFACEUSUARIO_H

#include <iostream>
#include <sstream>
#include <string>
using std::string;
#include "shell.h"
#include "Macro.h"
#include "Historico.h"
#include "Hash.h"
#include "Lista.h"


 
using namespace std;
 
class InterfaceUsuario {
 private:
  Shell cmd; // o executor de comandos
  Historico historicoInterface;
  Fila<Macro> macros;
  string prompt; // o prompt a ser mostrado na linha que espera comando
  string comando;
  TabelaHash<string> tabV;
  TabelaHash<Lista<string> > tabM;
  //TabelaHash<Macro> tabM;
   
 public:
   
  InterfaceUsuario(const string & umPrompt); // construtor
  ~InterfaceUsuario() {} // destrutor
 
  int ExecutaComando(string & c);
  int leUmComando(); // aguarda um comando, executa-o e retorna o status de terminação
  string meuComando();
  string VerificaComando(string & c2);
  void mostraHistorico();
  string executaHistorico(int num);
  void Adicionar_macro(Macro & outro);
  void verificaMacro(string& cm);
  void verificaMacroCriada(string& comM);
  void verificaVariavelCriada(string& comV);
  void macroConfig();
  void varConfig();
  void serve_comandos();// lê e executa comandos indefinidamente ...
};


#endif	/* INTERFACEUSUARIO_H */

