#include "Arvore.hpp"
#include <fstream>
using namespace std;

void Arvore::insercao(int dado) {
    raiz = insercao(raiz, dado);
};

No* Arvore::insercao(No* no, int dado) {
    if (no == nullptr) return new No(dado);

    if (dado < no->Dado) no->Esq = insercao(no->Esq, dado);
    else if (dado > no->Dado) no->Dir = insercao(no->Dir, dado);

    return no;
};

void Arvore::destruirArvore(No* no) {
    if (no == nullptr) return;

    destruirArvore(no->Esq);
    destruirArvore(no->Dir);
    delete no;
};

Arvore::~Arvore() {
    destruirArvore(raiz);
};

void Arvore::ExibirIn_Ordem(No* no) {
    if (no == nullptr) return;

    ExibirIn_Ordem(no->Esq);
    cout << no->Dado << " ";
    ExibirIn_Ordem(no->Dir);
};

No* Arvore::getraiz() {
    return raiz;
};

void Arvore::Lerdados(Arvore& arvore, string nome){
    ifstream arq(nome);
    if(!arq.is_open()){
        cout << "Erro na abertura do arquivo!" << endl;
    }

    int aux;
    while(arq >> aux){
        arvore.insercao(aux);
    }

    arq.close();
    
};

No* Arvore::EncontrarMinimo(No* arvore){
    while(arvore && arvore->Esq != nullptr) {
        arvore = arvore->Esq; 
    }

    return arvore;
};

No* Arvore::Remover(No* no, int dado) {
    if (no == nullptr) {
        return no; // Árvore vazia ou dado não encontrado
    }

    // Localiza o nó a ser removido
    if (dado < no->Dado) {
        no->Esq = Remover(no->Esq, dado);
    } else if (dado > no->Dado) {
        no->Dir = Remover(no->Dir, dado);
    } else {
        // Caso 1: Nó sem filhos (é uma folha)
        if (no->Esq == nullptr && no->Dir == nullptr) {
            delete no;
            return nullptr;
        }
        // Caso 2: Nó com um único filho
        else if (no->Esq == nullptr) {
            No* temp = no->Dir;
            delete no;
            return temp;
        } else if (no->Dir == nullptr) {
            No* temp = no->Esq;
            delete no;
            return temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            // Encontrar o sucessor
            No* sucessor = EncontrarMinimo(no->Dir);
            no->Dado = sucessor->Dado; // Substitui o valor do nó pelo sucessor
            no->Dir = Remover(no->Dir, sucessor->Dado); // Remove o sucessor
        }
    }
    return no;
};

int Arvore::Altura(No* no) {
    if (no == nullptr) {
        return -1; //vazia ou folha
    }

    // Altura da subárvore esquerda e direita
    int alturaEsquerda = Altura(no->Esq);
    int alturaDireita = Altura(no->Dir);

    // Altura do nó atual
    return 1 + max(alturaEsquerda, alturaDireita);
}


void Arvore::ExecuçãodoPrograma(){
    Arvore arvore1, arvore2;
    arvore1.Lerdados(arvore1, "datasets/teste1.txt"); //arvore normal
    arvore2.Lerdados(arvore2, "datasets/teste2.txt"); // arvore tendenciada

    int a = 0;
    do{
        cout << endl;
        cout << "-------------MENU-------------" << endl;
        cout << "1 - Inserir elemento." << endl;
        cout << "2 - Remover elemento." << endl;
        cout << "3 - Nível das árvores." << endl;
        cout << "4 - Exibir elementos in-ordem." << endl;
        cout << "5 - Encerrar o Programa." << endl;
        cout << "------------------------------" << endl;
        cout << "Digite a opção desejada: ";
        cin >> a;
        cin.ignore();
        
        if (a == 1){
            int add = 0;
            cout << "\nDigite o elemento a ser adicionado nas árvores: ";
            cin >> add;
            cin.ignore();

            arvore1.insercao(add);
            arvore2.insercao(add);
            cout << "O elemento " << add << " foi adicionado em ambas as árvores!" << endl;
            cout << endl;
        }

        if(a == 2){
            int remove = 0;
            cout << "Digite o elemento a ser removido das árvores: ";
            cin >> remove;
            cin.ignore();
            
            arvore1.Remover(arvore1.getraiz(), remove);
            arvore2.Remover(arvore2.getraiz(), remove);

            cout << "O elemento " << remove << " foi retirado de ambas as árvores" << endl;

            cout << endl;
        }

        if(a == 3){
            cout << "A altura máxima da árvore não tendenciada é: "  << arvore1.Altura(arvore1.getraiz()) << endl;

            cout << "A altura máxima da árvore tendenciada é: " << arvore2.Altura(arvore2.getraiz()) << endl;

            cout << endl;
        }

        if (a == 4){
            cout << "| ARVORE 1 - NÃO TENDENCIADA |" << endl;
            arvore1.ExibirIn_Ordem(arvore1.getraiz());
            cout << "\n" << endl;
            cout << "| ARVORE 2 - TENDENCIADA     |" << endl;
            arvore2.ExibirIn_Ordem(arvore2.getraiz());
            cout << endl;
        }

    } while (a != 5);

    cout << "Finalizando o programa!" << endl;
}
