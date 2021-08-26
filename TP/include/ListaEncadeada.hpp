#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <cmath>
#include "CelulaLista.hpp"

//Cada célula da lista representa um servidor com seu próprio buffer
class ListaEncadeada {
  public:
    ListaEncadeada();
    ~ListaEncadeada();

    int getTamanho();
    void insereFinal(std::string item);
    int somaItensInteiros();
    void limpa();
  
  private:
    CelulaLista* primeiro;
    CelulaLista* ultimo;
};

#endif