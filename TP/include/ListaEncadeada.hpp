#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <cmath>
#include "CelulaLista.hpp"

// Classe que representa a lista encadeada que armazena, em seus nós, os dados
// binários da respectiva chave. Possui ponteiros para seu primeiro e último
// elemento.
class ListaEncadeada {
  public:
    // Construtor padrão da classe “ListaEncadeada”. Atribui à primeira posição
    // da uma instância de “CelulaLista” dinamicamente alocada, para então
    // atribuir, ao ponteiro para a última célula da lista, o valor do ponteiro
    // para a primeira.
    ListaEncadeada();
    // Destrutor da classe. Utiliza do método “limpa()” como método auxiliar
    // para deletar todas as células da lista, exceto a célula cabeça.
    ~ListaEncadeada();

    int getTamanho();
    // Método público que insere uma nova célula com o dado (do formato
    // “string”) passado como parâmetro no final da lista.
    void insereFinal(std::string item);
    // Método público que percorre toda a lista, transforma os dados binários
    // armazenados em formato “string” em inteiros na escala decimal e retorna
    // a soma total de todos eles.
    int somaItensInteiros();
    // Método público que percorre toda a lista, utilizando do operador “delete”
    // para deletar todas as células, exceto a célula cabeça.
    void limpa();
  
  private:
    CelulaLista* primeiro;
    CelulaLista* ultimo;

  friend class ArvoreBinaria;
};

#endif