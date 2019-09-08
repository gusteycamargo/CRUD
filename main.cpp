#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "Pessoa.h"
#include "ManterPessoa.h"

using namespace std;

int main()
{
    int op = 0;
    Pessoa p;
    ManterPessoa mp;
    string nome, cpf, email, nomeP;
    int idade = 0;

    do{
        op = 0;
        system("CLS");
        cout << "CRUD de pessoas \n" << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Visualizar" << endl;
        cout << "3 - Excluir" << endl;
        cout << "4 - Editar" << endl;
        cout << "5 - Sair" << endl;

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

            mp.gravaEmArquivo(p);

            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
        else if(op == 2){
            system("CLS");
            mp.visualizaArquivo();
            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
        else if(op == 3){
            system("CLS");
            cout << "Digite o nome da pessoa a ser excluida: " << endl;
            cin >> nome;
            if(mp.excluirPessoa(nome) == true){
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
            system("CLS");
            cout << "Digite o nome da pessoa a ser editada: " << endl;
            cin >> nomeP;
            cout << "Novos valores da pessoas \n" << endl;
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

            if(mp.editarPessoa(p, nomeP) == true){
                cout << "Pessoa editada com sucesso..." << endl;
            }
            else{
                cout << "Erro ao excluir..." << endl;
            }
            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
        else if(op == 5){
            cout << "Saindo..." << endl;
        }
        else{
            cout << "Opcao invalida!" << endl;
            cout << "Pressione qualquer tecla para continuar..." << endl;
            fflush(stdin);
            getchar();
        }
    }while(op != 5);

    return 0;
}
