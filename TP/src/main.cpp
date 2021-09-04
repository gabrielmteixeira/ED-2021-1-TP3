#include <iostream>
#include <string>
#include <fstream>
#include "../include/ArvoreBinaria.hpp"

// É a principal função do programa, recebendo como parâmetro o arquivo de
// entrada. Inicialmente, ela utiliza da função “getline” para ler a primeira
// linha do arquivo, que contém o valor inteiro “n” referente a quantas
// inserções serão feitas na árvore binária. A partir desse ponto, são lidas as
// “n” linhas seguintes da entrada, separando, em cada uma, o nome e o dado
// binário. Os dados binários são inseridos na árvore binária “consciencias” de
// acordo com as respectivas chaves, os nomes, com o auxílio do método
// “consciencias.insere()”. Ao final das inserções, as chaves de todos os nós
// da árvore são impressas em ordem alfabética. Em seguida, são lidas as linhas
// restantes da entrada (cada uma contendo um nome, ou seja, uma chave de um nó
// da árvore) e, para cada uma, o nó referenciado pela chave é removido de
// “consciencias”, tendo a chave em questão e a soma dos dados binários do
// respectivo nó, transformados em escala decimal, impressos na saída. Por fim,
// após essas remoções, são impressas as chaves (nomes) dos nós restantes da
// árvore, em ordem alfabética.
int main(int argc, char* argv[]) {
  std::ifstream entrada(argv[1]);
  
  try {
    std::string texto;
    std::string numeroLinhasComDados;
    int contadorInsercoes = 0;
    getline(entrada, numeroLinhasComDados);

    ArvoreBinaria consciencias;

    while(contadorInsercoes < std::stoi(numeroLinhasComDados)) {
      std::string nome;
      std::string dado;
      getline(entrada, texto);

      std::string delimitador = " ";
      int indiceEspaco = texto.find(delimitador);
      nome = texto.substr(0, indiceEspaco);
      dado = texto.substr(indiceEspaco + 1, texto.size() - (indiceEspaco + 1));
      
      consciencias.insere(nome, dado);
      contadorInsercoes++;
    }
    consciencias.imprime();
    
    while(getline(entrada, texto)) {
      std::string nome = texto;
      consciencias.remove(nome);
    }
    consciencias.imprime();

    entrada.close();
  } catch(const char* error) {
    entrada.close();
    std::cerr << error << std::endl;
  }
}