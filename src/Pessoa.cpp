#include "Pessoa.h"
#include<string>
using namespace std;


void Pessoa::setNome(string nome){
    this->nome = nome;
}

string Pessoa::getNome(){
    return this->nome;
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

int Pessoa::getIdade(){
    return this->idade;
}

void Pessoa::setEmail(string email){
    this->email = email;
}

string Pessoa::getEmail(){
    return this->email;
}

void Pessoa::setCpf(string cpf){
    this->cpf = cpf;
}

string Pessoa::getCpf(){
    return this->cpf;
}
