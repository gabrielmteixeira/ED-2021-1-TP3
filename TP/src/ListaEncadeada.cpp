#include "../include/ListaEncadeada.hpp"

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
  tamanhoDado = 8;
  int soma = 0;
  CelulaLista* celula = this->primeiro;

  while(aux != nullptr) {
    for(int i = 0; i < tamanhoDado; i++) {
      soma = soma + (std::pow(7-i, 2) * std::stoi(celula->item[i]));
    }
    celula = celula->prox;
  }
  
  return soma;
}

