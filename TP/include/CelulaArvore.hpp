#ifndef CELULA_ARVORE
#define CELULA_ARVORE
#include <string>
#include "ListaEncadeada.hpp"
#include "ArvoreBinaria.hpp"

class CelulaArvore {

  public:
    CelulaArvore() {
      this->esq = nullptr;
      this->dir = nullptr;
    };

  private:
    std::string chave;
    ListaEncadeada dados;
    CelulaArvore* esq;
    CelulaArvore* dir;

  friend class ArvoreBinaria;
};

#endif