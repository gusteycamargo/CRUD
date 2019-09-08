#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "Pessoa.h"

using namespace std;

void gravaEmArquivo(Pessoa p);
void visualizaArquivo();
bool excluirPessoa(string nome);

int main()
{
    int op = 0;
    Pessoa p;
    string nome, cpf, email;
    int idade = 0;

    do{
        op = 0;
        system("CLS");
        cout << "CRUD de pessoas \n" << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Visualizar" << endl;
        cout << "3 - Excluir" << endl;
        cout << "4 - Sair" << endl;

        cin >> op;

        if(op == 1){
            system("CLS");
            cout << "CRUD de pessoas \n" << endl;
            cout << "Digite o nome: " << endl;
            cin >> nome;

            cout << "Digite o CPF (sem pontuacao): " << endl;
            cin >> cpf;

            cout << "Digite o e-mail: " << endl;
            cin >> email;

            cout << "Digite a idade: " << endl;
            cin >> idade;

            p.setNome(nome);
            p.setCpf(cpf);
            p.setEmail(email);
            p.setIdade(idade);

            gravaEmArquivo(p);

            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
        else if(op == 2){
            system("CLS");
            visualizaArquivo();
            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
        else if(op == 3){
            system("CLS");
            cout << "Digite o nome da pessoa a ser excluida: " << endl;
            cin >> nome;
            if(excluirPessoa(nome) == true){
                cout << "Pessoa excluida com sucesso..." << endl;
            }
            else{
                cout << "Erro ao excluir..." << endl;
            }
            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
        else if(op == 4){
            cout << "Saindo..." << endl;
        }
        else{
            cout << "Opcao invalida!" << endl;
            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
    }while(op != 4);

    return 0;
}

void gravaEmArquivo(Pessoa p){
    ofstream arquivo;

    arquivo.open("pessoas.txt", ios::app);

    arquivo << p.getNome() << "\n";
    arquivo << p.getCpf() << "\n";
    arquivo << p.getEmail() << "\n";
    arquivo << p.getIdade() << "\n";

    arquivo.close();

}

void visualizaArquivo(){
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

bool excluirPessoa(string nome){
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


