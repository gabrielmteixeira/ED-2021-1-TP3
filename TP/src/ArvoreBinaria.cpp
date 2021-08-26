#include "../include/ArvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria() {
  this->raiz = nullptr;
  this->tamanho = 0;
}

void ArvoreBinaria::insere(std::string chave, std::string item) {
  insereRecursivo(this->raiz, chave, item);
}

void ArvoreBinaria::insereRecursivo(CelulaArvore* &celula, std::string chave,
                                    std::string item) {
  if (celula == nullptr) {
    celula = new CelulaArvore();
    celula->chave = chave;
    celula->dados.insereFinal(item);
    this->tamanho++;
  } else if (celula->chave == chave) {
    celula->dados.insereFinal(item);
  } else {
    if (chave < celula->chave) {
      insereRecursivo(celula->esq, chave, item);
    } else {
      insereRecursivo(celula->dir, chave, item);
    }
  }
}

int ArvoreBinaria::remove(std::string chave) {
  return removeRecursivo(this->raiz, chave);
}

int ArvoreBinaria::removeRecursivo(CelulaArvore* &celula, std::string chave) {
  CelulaArvore* aux;

  if (celula == nullptr) {
    throw("Item não está presente");
  }
  if (chave < celula->chave) {
    return removeRecursivo(celula->esq, chave);
  } else if (chave > celula->chave) {
    return removeRecursivo(celula->dir, chave);
  } else {
    std::cout << celula->chave << " " << celula->dados.somaItensInteiros() << std::endl;
    if (celula->dir == nullptr) {
      aux = celula;
      celula = celula->esq;
      delete aux;
    } else if (celula->esq == nullptr) {
      aux = celula;
      celula = celula ->dir;
      delete aux;
    } else {
      antecessor(celula, celula->esq);
    }
    
    this->tamanho--;
  }
}

void ArvoreBinaria::antecessor(CelulaArvore* celula, CelulaArvore* &aux) {
  if (aux->dir != nullptr) {
    antecessor(celula, aux->dir);
    return;
  }

  celula->chave = aux->chave;
  celula = aux;
  aux = celula->esq;
  delete(celula);
}

void ArvoreBinaria::imprime() {
  int contador = 0;
  caminhaInOrdem(this->raiz, contador);
}

void ArvoreBinaria::caminhaInOrdem(CelulaArvore* celula, int &contador) {
  if(celula != nullptr) {
    caminhaInOrdem(celula->esq, contador);
    contador++;
    if (contador < this->tamanho) std::cout << celula->chave << " ";
    else std::cout << celula->chave << std::endl;
    caminhaInOrdem(celula->dir, contador);
  }
}