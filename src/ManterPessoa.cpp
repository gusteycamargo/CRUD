#include<string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "ManterPessoa.h"
#include "Pessoa.h"

using namespace std;

void ManterPessoa::gravaEmArquivo(Pessoa p){
    ofstream arquivo;

    arquivo.open("pessoas.txt", ios::app);

    arquivo << p.getNome() << "\n";
    arquivo << p.getCpf() << "\n";
    arquivo << p.getEmail() << "\n";
    arquivo << p.getIdade() << "\n";

    arquivo.close();
}

void ManterPessoa::visualizaArquivo(){
    ifstream arquivo;
    string linha;
    int cont = 0;
    arquivo.open("pessoas.txt");
    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            if(cont == 0){
                cout << "Nome: " << linha << endl;
                cont++;
            }
            else if(cont == 1){
                cout << "CPF: " << linha << endl;
                cont++;
            }
            else if(cont == 2){
                cout << "E-mail: " << linha << endl;
                cont++;
            }
            else if(cont == 3){
                cout << "Idade: " << linha << "\n" << endl;
                cont = 0;
            }
        }
    }
    else{
        cout << "Não foi possível abrir o arquivo" << endl;
    }

    arquivo.close();
}

bool ManterPessoa::excluirPessoa(string nome){
    ifstream arquivoE;
    ofstream arquivoI;
    string linha;
    int cont = 0, contLinha = 0;
    bool ver = false;
    arquivoE.open("pessoas.txt");
    arquivoI.open("temp.txt");
    if(arquivoE.is_open()){
        while(getline(arquivoE, linha)){
            if(nome == linha){
                ver = true;
                if(contLinha == 0){
                    contLinha = 4;
                }
            }
            else{
                ver = false;
            }

            if(cont == 0 && contLinha == 0){
                arquivoI << linha << "\n";
                cont++;
            }
            else if(cont == 1 && contLinha == 0){
                arquivoI << linha << "\n";
                cont++;
            }
            else if(cont == 2 && contLinha == 0){
                arquivoI << linha << "\n";
                cont++;
            }
            else if(cont == 3 && contLinha == 0){
                arquivoI << linha << "\n";
                cont = 0;
                contLinha = 0;
            }

            if(contLinha != 0){
                contLinha--;
            }
        }
    }
    else{
        cout << "Não foi possível abrir o arquivo" << endl;
        return false;
    }
    arquivoI.close();
    arquivoE.close();

    remove("pessoas.txt");
    rename("temp.txt", "pessoas.txt");

    return true;
}

bool ManterPessoa::editarPessoa(Pessoa p, string nome){
    ifstream arquivoE;
    ofstream arquivoI;
    string linha;
    int cont = 0, contLinha = 0;
    bool ver = false;
    arquivoE.open("pessoas.txt");
    arquivoI.open("temp.txt");

    if(arquivoE.is_open()){
        while(getline(arquivoE, linha)){
            if(nome == linha){
                ver = true;
                if(contLinha == 0){
                    contLinha = 4;
                }
            }

            if(cont == 0){
                if(ver == true){
                    arquivoI << p.getNome() << "\n";
                }
                else{
                    arquivoI << linha << "\n";
                }

                cont++;
            }
            else if(cont == 1){
                if(ver == true){
                    arquivoI << p.getCpf() << "\n";
                }
                else{
                    arquivoI << linha << "\n";
                }

                cont++;
            }
            else if(cont == 2){
                if(ver == true){
                    arquivoI << p.getEmail() << "\n";
                }
                else{
                    arquivoI << linha << "\n";
                }

                cont++;
            }
            else if(cont == 3){
                if(ver == true){
                    arquivoI << p.getIdade() << "\n";
                }
                else{
                    arquivoI << linha << "\n";
                }

                cont = 0;
                contLinha = 0;
                ver = false;
            }

            if(contLinha != 0){
                contLinha--;
            }
        }
    }
    else{
        cout << "Não foi possível abrir o arquivo" << endl;
        return false;
    }
    arquivoI.close();
    arquivoE.close();

    remove("pessoas.txt");
    rename("temp.txt", "pessoas.txt");

    return true;
}


