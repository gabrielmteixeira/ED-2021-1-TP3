#include <iostream>
#include <string>
#include <fstream>
#include "../include/ArvoreBinaria.hpp"


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