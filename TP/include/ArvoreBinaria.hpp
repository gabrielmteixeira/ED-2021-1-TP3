#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

#include <iostream>
#include "CelulaArvore.hpp"

//Cada célula da lista representa um servidor com seu próprio buffer
class ArvoreBinaria {
  public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void insere(std::string chave, std::string item);
    void imprime();
    CelulaArvore* pesquisa(std::string chave);
    int remove(std::string chave)
    void limpa();
  
  private:
    void insereRecursivo(CelulaArvore* &celula, std::string chave,
                          std::string item);
    void apagaRecursivo(CelulaArvore* celula);
    CelulaArvore* pesquisaRecursivo(CelulaArvore* celula, std::string chave);
    int removeRecursivo(CelulaArvore* &celula, std::string item);
    void antecessor(CelulaArvore* celula, CelulaArvore* &aux);
    void caminhaInOrdem(CelulaArvore* celula);

    Celula* raiz;
};

#endif