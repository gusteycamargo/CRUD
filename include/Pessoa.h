#ifndef PESSOA_H
#define PESSOA_H

#include<string>
using namespace std;

class Pessoa
{
    public:
        void setNome(string nome);
        string getNome();
        void setIdade(int idade);
        int getIdade();
        void setCpf(string cpf);
        string getCpf();
        void setEmail(string email);
        string getEmail();
    private:
        string nome;
        int idade;
        string cpf;
        string email;
};

#endif // PESSOA_H
