#include "../include/ListaEncadeada.hpp"
#include <iostream>

ListaEncadeada::ListaEncadeada() {
  this->primeiro = new CelulaLista();
  this->ultimo = this->primeiro;
}

ListaEncadeada::~ListaEncadeada() {
  this->limpa();
  delete this->primeiro;
}

void ListaEncadeada::insereFinal(std::string item) {
  CelulaLista* nova = new CelulaLista();
  nova->item = item;
  this->ultimo->prox = nova;
  this->ultimo = nova;
}

void ListaEncadeada::limpa() {
  CelulaLista* celula = this->primeiro->prox;

  while(celula!=nullptr) {
    this->primeiro->prox = celula->prox;
    delete celula;
    celula = this->primeiro->prox;
  }
  this->ultimo = this->primeiro;
}

int ListaEncadeada::somaItensInteiros() {
  int tamanhoDado = 8; // todas os dados são binários de 8 bits
  int soma = 0;
  CelulaLista* celula = this->primeiro->prox;

  while(celula != nullptr) {
    for(int i = 0; i < tamanhoDado; i++) {
      // 48 == valor inteiro do char 0 na tabela ascii
      int binario = celula->item[i] % 48;
      soma = soma + (std::pow(2, 7 - i) * binario);   
    }
    celula = celula->prox;
  }
  
  return soma;
}

