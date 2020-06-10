#include "interfaceUsuario.h"

using namespace std;

//construtor da classe InterfaceUsuario, ao ser criado um objeto cria um objeto do tipo Historico com capacidade 50, e uma fila do tipo Macro com capacidade 10
InterfaceUsuario::InterfaceUsuario(const string & umPrompt):historicoInterface(50),macros(10),tabV(5),tabM(5){ 
    prompt = umPrompt;
}

int InterfaceUsuario::ExecutaComando(string & c){ //função que executa o comando digitado
    string com;
    com = VerificaComando(c);
    int r = cmd.execute(com);
    return r;
}

int InterfaceUsuario::leUmComando(){ //função que pede para digitar um comando
    cout << prompt;
    comando = "";
    getline(cin,comando);
    ExecutaComando(comando);  
}

string InterfaceUsuario::VerificaComando(string & c2){ //função que verifica o comando digitado para fazer detrminada ação
    
    
    if(c2 == "historico"){ //se o comando for "historico" mostra o historico de comandos digitados
        historicoInterface.addComando(c2);
        mostraHistorico();
        return c2;
    
    }else if(c2[0] == '!'){ //se o comando começar com "!" ignora esse caracter e pega o proximos. se for um numero, pega esse numero e passa-o como parametro para executar o comando do historico especificado 
        string numeroComando;
        
        numeroComando = c2.erase(0,1);
        istringstream stream(numeroComando);
        int numero;
        stream >> numero;
       
        numeroComando = "";
        string cr;
        cr = executaHistorico(numero);
        
        if (cr == "historico"){
            VerificaComando(cr);
        }else{
            historicoInterface.addComando(cr);
        }
        return cr;
    }else if(c2[0] == 'd'){ //
        int n1 = 0;
        //coletando comando antes do caracter espaço ' '
        n1 = c2.find(' ', 0); 
        string palavra = c2.substr(0,n1);
        
        if(palavra == "defvar"){ //defvar alvo=/usr/local/documentos
            
            string chaveV;
            string valorV;
            int n2;
            
            //coletando string "chave" antes do caracter '=' igual
            n2 = n1 + 1;
            n1 = c2.find('=', n2);
            if(n1 > 0){
                chaveV = c2.substr(n2,n1-n2); 
                if(chaveV != ""){
                    //coletando string "valor" depois do caracter '=' igual
                    n2 = n1 + 1;
                    n1 = c2.find('\0', n2); 
                    valorV = c2.substr(n2,n1-n2); 
                    if(valorV != ""){
                    //adicionando chave e valor na tabela hash de variaveis
                    tabV.adiciona(chaveV, valorV);
                    cout << "Variavel criada com sucesso!" << endl;
                    }
                }
            }
        }
        
         if(palavra == "defmacro"){ //defmacro mac1=ls; pwd; date
            string chaveM;
            string valorM;
            int n2;
            
            //coletando a string chave ante do caracter '=' igual
            n2 = n1 + 1;
            n1 = c2.find('=', n2);
            if(n1 > 0){
                chaveM = c2.substr(n2,n1-n2); 
                if(chaveM != ""){
                    Lista<string> comandosM;
            
                    //coletando dados depois do caracter '=' igual
                    char c = '-'; //caracter c igual a ifen, para c ter um valor e entrar dentro do while, podia ser qualqer outro caracter
                    while(c != '\0'){
                        int n3 = 1;
                
                        //coletando comandos que tem o delimitador ";"
                        while(n3 >= 1){
                            n2 = n1 + 1;
                            n1 = c2.find(';', n2);
                            n3 = n1;
                            if(n1 > 0){
                                if(c2[n2] == ' ') n2++;
                                valorM = c2.substr(n2,n1-n2); 
                                comandosM.anexa(valorM);
                            }
                        }
                
                        //coletando comando sem o delimitador ";"
                        if(c2[n2] == ' ') n2++;
                        n1 = c2.find('\0', n2);
                        c = c2[n1];
                        valorM = c2.substr(n2,n1-n2);
                        comandosM.anexa(valorM);
                
                    }
                    if(valorM != ""){
                        tabM.adiciona(chaveM, comandosM);
                        cout << "Macro criada com sucesso!" << endl;
                    }
                }
            }
        }
        
        historicoInterface.addComando(c2); //adiciona comando ao historico
        return c2;
        
    }else if(c2 == "macroConfig"){
        historicoInterface.addComando(c2); //adiciona comando ao historico
        macroConfig();
        
        return c2;
    }else if(c2 == "varConfig"){
        historicoInterface.addComando(c2); //adiciona comando ao historico
        varConfig();
        
        return c2;
    }else{
        
       historicoInterface.addComando(c2); //adiciona comando ao historico
       //verificaMacro(c2); //aqui verifica se o comando digitado é igual aos nomes das macros
       verificaMacroCriada(c2);
       verificaVariavelCriada(c2);
       
       return c2;
    }   
}

void InterfaceUsuario::Adicionar_macro(Macro & outro){ //adiciona o objeto do tipo Macro na fila do tipo Macro
    macros.enfileira(outro);
    
}

void InterfaceUsuario::verificaMacro(string& cm){ //verifica se o comando digitado é igual aos nomes das macros
    Macro resultado;
    Fila<Macro> copiaMacros = macros;
    while (copiaMacros.vazia() == false){
        resultado = copiaMacros.desenfileira();
        if (resultado.getNome() == cm){
            while (resultado.vazio() == false){
               int r2; 
               string teste;
               teste = resultado.retira();
               cout << teste << endl;
               r2 = ExecutaComando(teste);
               cout << "Executou com status: " << r2 << endl;
            }
            
        }
    }
}

void InterfaceUsuario::verificaMacroCriada(string& comM){
    bool existe = tabM.existe(comM);
    
    if(existe == true){
        Lista<string>& resultado = tabM.obtem(comM);
        int x = resultado.comprimento();
        for(int i=0; i < x; i++){
            string comandoM = resultado.obtem(i);
            cout << comandoM << endl;
            int r3 = ExecutaComando(comandoM);
            cout << "Executou com status: " << r3 << endl;
        }
    }
        
        
    
}

void InterfaceUsuario::verificaVariavelCriada(string& comV){ //ls $alvo $alvo2
    int m1, m2, m3; 
    string palavra;
    char c = '-'; //
    
    while(c != '\0'){
        m1 = comV.find('$', 0); // encontra em q posição esta o caracter $
        m2 = m1 + 1;
        m3 = comV.find(' ', m2); //encontra em q posição esta o caracter ' ' espaço
        
        c = m3;
        palavra = comV.substr(m2,m3-m2); //pega a string depois do caracter $ e antes de um caracter ' ' espaço
        
        if(tabV.existe(palavra) == true){ //verifica se a variavel existe na tabela de variaveis
            string& dado = tabV.obtem(palavra); //pega o conteudo da variavel
            comV = comV.replace(m1,m3-m2+1,dado); //substitui o $nome_variavle pelo valor da chave
        }else{
            break;
        }
    }
       
}

void InterfaceUsuario::mostraHistorico(){ //função que mostra o historico dos comandos digitados
    
    int l = 1;
    int id,id2;
    
    
    Historico copiaHistorico = historicoInterface;
    id = copiaHistorico.Id_historico();
    id2 = id;
    id2--;
    string vetorHistorico[id];
    
    for (int i=0; i < id;i++){
        vetorHistorico[id2] = copiaHistorico.mostraHistorico();
        id2--;
    }
    
    cout << "### Historico de comandos executados ###" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i=0; i < id;i++){
        cout << l << "º " << vetorHistorico[i] << endl;
        l++;
    }
    cout << "----------------------------------------" << endl;
    
}

string InterfaceUsuario::executaHistorico(int num){ //função que executa o comando do hisorico especificado
    string comandoH;
    
    comandoH = historicoInterface.mostraHistorico_n(num);
    cout << comandoH << endl; 
    return comandoH;
}

string InterfaceUsuario::meuComando(){ //função que retorna o comando digitado
    return comando;
}

void InterfaceUsuario::macroConfig(){ //interface para configurar as macros - Esta ainda em desenvolvimento...
    int op = 0;
    string opc;
    
    while (op != 3){
        cout << endl;
        cout << "############## Configuração de Macros ##############" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "## Digite 1 para ver nome das macros criadas" << endl;
        cout << "## Digite 2 para remover uma macro" << endl;
        cout << "## Digite 3 para sair" << endl;
        cout << "----------------------------------------------------" << endl;
      
        cout << "Operação escolhida: ";
        cin >> opc;
        cout << endl;
        
        istringstream stream(opc);
        stream >> op; //converte string para int
      
        if(op == 1){
            cout << "**** Macros criadas ****" << endl;
            cout << "-----------------------" << endl;
            Lista<string> * lm = tabM.chaves();
            if(lm->comprimento() > 0){
                lm->ordenaSelecao();
                //lm->mostraLista(cout);
                lm->inicia();
                while(not lm->fim()){
                    string& dado = lm->proximo();
                    cout << dado << " = ";
                    Lista<string>& resultado = tabM.obtem(dado);
                    resultado.inicia();
                    while(not resultado.fim()){
                        string& dado2 = resultado.proximo();
                        cout << dado2 << "; ";
                    }
                    cout << endl;
                }
            }
            cout << "-----------------------" << endl;
        }else if(op == 2){
            if (tabM.tamanho() > 0){
                string ma;
                cout << "Digite o nome da macro a ser removida: ";
                cin >> ma;
                cout << endl;
            
                bool e = tabM.existe(ma);
            
                if(e == true){
                    cout << "-----------------------" << endl;
                    Lista<string> resultado = tabM.remove(ma);
                    cout << "Macro " << ma << " removida com sucesso!" << endl;
                    cout << "-----------------------" << endl;
                }else{
                    cout << "Macro digitada não existe!" << endl;
                }
            }else{
               cout << "Operação negada, nenhuma macro salva no momento!" << endl; 
            }
        }else{
        
        }
    }
  
}

void InterfaceUsuario::varConfig(){
    int op = 0;
    string opc;
    
    while (op != 3){
        cout << endl;
        cout << "############ Configuração de Variaveis #############" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "## Digite 1 para ver as variaveis criadas" << endl;
        cout << "## Digite 2 para remover uma variavel" << endl;
        cout << "## Digite 3 para sair" << endl;
        cout << "----------------------------------------------------" << endl;
      
        cout << "Operação escolhida: ";
        cin >> opc;
        cout << endl;
        
        istringstream stream(opc);
        stream >> op; //converte string para int
      
        if(op == 1){
            cout << "**** Variaveis criadas ****" << endl;
            cout << "-----------------------" << endl;
            Lista<string> * lm = tabV.chaves();
            if(lm->comprimento() > 0){
                lm->ordenaSelecao();
                //lm->mostraLista(cout);
                lm->inicia();
                while(not lm->fim()){
                    string& dado = lm->proximo();
                    cout << dado << " = " << tabV.obtem(dado) << endl;
                }
            }
            cout << "-----------------------" << endl;
        }else if(op == 2){
            if (tabV.tamanho() > 0){
                string ma;
                cout << "Digite o nome da variavel a ser removida: ";
                cin >> ma;
                cout << endl;
            
                bool e = tabV.existe(ma);
            
                if(e == true){
                    cout << "-----------------------" << endl;
                    string resultado = tabV.remove(ma);
                    cout << "Variavel " << ma << " removida com sucesso!" << endl;
                    cout << "-----------------------" << endl;
                }else{
                    cout << "Variavel digitada não existe!" << endl;
                }
            }else{
               cout << "Operação negada, nenhuma variavel salva no momento!" << endl; 
            }
                    
        }else{
        
        }
    }
}









