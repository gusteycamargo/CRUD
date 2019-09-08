#ifndef MANTERPESSOA_H
#define MANTERPESSOA_H

#include "Pessoa.h"
#include<string>
using namespace std;

class ManterPessoa
{
    public:
        void gravaEmArquivo(Pessoa p);
        void visualizaArquivo();
        bool excluirPessoa(string nome);
        bool editarPessoa(Pessoa p, string nome);
    protected:

    private:
};

#endif // MANTERPESSOA_H
