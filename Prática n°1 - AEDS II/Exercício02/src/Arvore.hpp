#ifndef ARVORE_HPP
#define ARVORE_HPP
#include <string>
#include <iostream>
using namespace std;

struct No {
    int Dado;
    No* Esq;
    No* Dir;

    No(int Dado) : Dado(Dado), Esq(nullptr), Dir(nullptr) {};
};

class Arvore {
private:
    No* raiz;

public:
    Arvore() : raiz(nullptr) {};
    ~Arvore();
    No* Remover(No* no, int dado);
    No* EncontrarMinimo(No* no);
    void insercao(int dado);
    No* insercao(No* no, int dado);
    void destruirArvore(No* no);
    void ExibirIn_Ordem(No* no);
    int Altura(No* no);
    No* getraiz();

    void Lerdados(Arvore& arvore, string nome);
    void ExecuçãodoPrograma();
};

#endif
