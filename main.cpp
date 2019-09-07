#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "Pessoa.h"

using namespace std;

void gravaEmArquivo(Pessoa p);
void visualizaArquivo();

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


