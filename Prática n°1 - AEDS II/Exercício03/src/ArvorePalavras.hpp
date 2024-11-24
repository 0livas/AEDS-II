#ifndef ARVOREPALAVRAS_HPP
#define ARVOREPALAVRAS_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct No{
    string Palavra;
    No* esq;
    No* dir;

    No(string palavra) : Palavra(palavra), esq(nullptr), dir(nullptr) {}
};

class ArvorePalavras{
private:
    No* raiz;
    void encontrarSugestões(No* arvore, string palavra, vector<string>& sugestoes);
    bool SubstringExiste(string palavra1, string palavra2);
    No* inserir(No* arvore, string palavra);
public:
    ArvorePalavras() : raiz(nullptr) {}
    void Exibirin_Ordem(No* arvore);
    void inserir(string palavra);
    vector<string> recomendacao(string& palavra);
    void ExecutarPrograma(ArvorePalavras arvore);
    void Lerdados(ArvorePalavras& Arvore);
};

#endif