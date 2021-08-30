#ifndef CELULA_LISTA
#define CELULA_LISTA
#include <string>
#include "ListaEncadeada.hpp"

class CelulaLista {

  public:

    CelulaLista() {
      this->prox = nullptr;
    };

  private:
    std::string item;
    CelulaLista* prox;

  friend class ListaEncadeada;
  friend class ArvoreBinaria;
};

#endif