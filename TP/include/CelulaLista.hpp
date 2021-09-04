#ifndef CELULA_LISTA
#define CELULA_LISTA
#include <string>
#include "ListaEncadeada.hpp"

// Classe que representa as células, ou nós, da lista encadeada mencionada
// acima. Armazena um dado binário, no formato de string, no atributo “item”,
// além de um ponteiro para a próxima célula da lista.
class CelulaLista {

  public:
    // Construtor padrão da classe “CelulaLista”. Atribui “nullptr” ao ponteiro
    // que referencia a célula na posição seguinte da lista encadeada a que
    // pertence.
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