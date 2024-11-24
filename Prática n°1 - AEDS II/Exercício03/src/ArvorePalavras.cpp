#include "ArvorePalavras.hpp"
#include <fstream>

No* ArvorePalavras::inserir(No* arvore, string palavra){
    if(arvore == nullptr){
        return new No(palavra);
    }

    if(palavra < arvore->Palavra){
        arvore->esq = inserir(arvore->esq, palavra);
    }
    else if(palavra > arvore->Palavra){
        arvore->dir = inserir(arvore->dir, palavra);
    }

    return arvore;
}

void ArvorePalavras::inserir(string palavra){
    raiz = inserir(raiz, palavra);
}

bool ArvorePalavras::SubstringExiste(string palavra1, string palavra2){
    return palavra1.find(palavra2) != string::npos || palavra2.find(palavra1) != string::npos;
}

void ArvorePalavras::encontrarSugestões(No* arvore, string palavra, vector<string>& sugestoes){
    if(arvore == nullptr){
        return;
    }

    if(SubstringExiste(arvore->Palavra, palavra) || SubstringExiste(palavra, arvore->Palavra)){
        sugestoes.push_back(arvore->Palavra);
    }

    encontrarSugestões(arvore->esq, palavra, sugestoes);
    encontrarSugestões(arvore->dir, palavra, sugestoes);
}

void ArvorePalavras::Exibirin_Ordem(No* arvore){
    if(arvore != nullptr){
        Exibirin_Ordem(arvore->esq);
        cout << arvore->Palavra << " ";
        Exibirin_Ordem(arvore->dir);
    }
}

vector<string> ArvorePalavras::recomendacao(string& palavra){
    vector<string> sugestoes;
    encontrarSugestões(raiz, palavra, sugestoes);
    return sugestoes;
}

void ArvorePalavras::Lerdados(ArvorePalavras& Arvore){
    string aux;
    ifstream arq ("datasets/dados.txt");
    if(!arq.is_open()){
        cout << "Erro na abertura do arquivo!" << endl;
        return;
    }
    while(getline(arq, aux)){
        Arvore.inserir(aux);
    }

    arq.close();
}

void ArvorePalavras::ExecutarPrograma(ArvorePalavras arvore){

    cout << "Programa de Auto-completar e Sugestão!" << endl;
    int opcao = 0;
    arvore.Lerdados(arvore);

    do{
        cout << "\n---------------MENU---------------" << endl;
        cout << "1 - Inserir nova palavra." << endl;
        cout << "2 - Olhar palavras já inseridas." << endl;
        cout << "3 - Finalizar o programa." << endl;
        cout << "----------------------------------" << endl;
        cout << "\n Digite uma das opções: ";
        cin >> opcao;
        cin.ignore();
        
        if(opcao == 1){
            cout << "Digite a palavra que você deseja inserir: ";
            string palavra;
            cin >> palavra;
            cin.ignore();

            vector<string> recomendacao = arvore.recomendacao(palavra);

            cout << "Sugestões e recomendações para '" << palavra << "':" << endl;
            for(string aux : recomendacao){
                cout << "- " << aux << endl;
            }
        }

        if(opcao == 2){
            arvore.Exibirin_Ordem(arvore.raiz);
        }

    } while(opcao != 3);

    cout << "\nFinalizando o programa!" << endl;
    }
