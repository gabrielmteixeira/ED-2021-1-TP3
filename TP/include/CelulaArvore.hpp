#ifndef CELULA_ARVORE
#define CELULA_ARVORE
#include <string>
#include "ListaEncadeada.hpp"
#include "ArvoreBinaria.hpp"

// Classe que representa as células, ou nós, da árvore binária de pesquisa
// mencionada acima. Armazena uma chave (o nome de uma pessoa), uma lista
// encadeada com os dados referentes à chave e os ponteiros para as células raiz
// das subárvores da esquerda e direita.
class CelulaArvore {

  public:
    // Construtor padrão da classe “CelulaArvore”. Atribui “nullptr” aos
    // ponteiros que referenciam as raízes de suas subárvores da esquerda e
    // direita.
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