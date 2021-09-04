#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

#include <iostream>
#include "CelulaArvore.hpp"

// Classe que representa uma árvore binária de pesquisa e armazena, em seus nós,
// os nomes passados na entrada como chave e os respectivos dados como
// componentes de uma lista encadeada. Armazena como atributos privados o nó
// raiz e o seu tamanho (número total de nós).
class ArvoreBinaria {
  public:
    // Construtor da classe “ArvoreBinaria”. Inicializa “raiz” como “nullptr” e
    // “tamanho” como 0.
    ArvoreBinaria();
    // Chama o método “limpa()” no contexto da árvore binária em questão, a fim
    // de liberar a memória alocada para suas células.
    ~ArvoreBinaria();

    // Método público que chama o método “insereRecursivo()”, passando para ele,
    // como parâmetros, a raiz da árvore em questão, o dado a ser inserido e a
    // sua chave. 
    void insere(std::string chave, std::string item);
    // Imprime a chave de todos os nós da árvore, seguindo a política in-ordem,
    // por meio do método auxiliar “caminhaInOrdem()”.
    void imprime();
    // Método público que chama o método “removeRecursivo()”, passando para ele,
    // como parâmetros, a raiz da árvore em questão e a chave do nó a ser
    // removido.
    void remove(std::string chave);
    // Deleta todos os nós da árvore, com o auxílio do método
    // “apagaRecursivo()”, para então atribuir “nullptr” ao nó raiz.
    void limpa();
  
  private:
    // Método privado que recebe como parâmetro duas instâncias de
    // “CelulaArvore”, “celula” e “aux”, respectivamente. Esvazia a lista
    // encadeada de “celula” a partir do método “limpa()”. Insere na lista de
    // “celula” todos os dados armazenados na lista de “aux”, de modo que as
    // duas sejam iguais.
    void trocaDados(CelulaArvore* celula, CelulaArvore* aux);
    // Método privado que procura o local na árvore em que o dado passado como
    // parâmetro deve ser inserido. Tal processo é feito procurando,
    // recursivamente,a posição em que a chave daquele dado (também passada como
    // parâmetro) se encaixa na árvore. A busca começa na raiz da árvore desce
    // pelos nós seguindo o padrão da árvore binária de pesquisa (nós da
    // subárvore da esquerda de um nó raiz são menores que eles e os da direita
    // são maiores). Caso seja achado um nó com a mesma chave do dado a ser
    // inserido, o dado em questão é adicionado no fim da lista encadeada desse
    // nó. Caso esse nó não exista, é criado um novo (seguindo a estrutura
    // padrão de uma árvore binária de pesquisa), com o dado sendo inserido em
    // sua fila encadeada.
    void insereRecursivo(CelulaArvore* &celula, std::string chave,
                          std::string item);
    // Percorre, recursivamente, todos os nós das subárvores da esquerda e
    // direita da raiz da árvore em questão, deletando-os no sentido das folhas
    // para a raiz.
    void apagaRecursivo(CelulaArvore* celula);
    // Método privado que percorre a árvore recursivamente, a partir da raiz, em
    // busca de uma célula com a mesma chave que a passada como parâmetro para o
    // método. Caso a árvore seja percorrida até uma das folhas e, mesmo assim,
    // a célula a ser removida não tenha sido achada, um erro é lançado,
    // avisando que o nó a ser removido não está presente na árvore. Se o nó
    // desejado for encontrado, sua chave é impressa na saída, junto da soma de
    // seus dados no formato decimal (que é calculada com o auxílio do método
    // “somaItensInteiros()” da classe “ListaEncadeada”). Se esse nó só tiver um
    // filho, ele é deletado (por meio do operador “delete”) e esse filho é
    // colocado em seu lugar, mas se tiver dois filhos, o método “antecessor()”
    // é chamado, sendo passado para ele, como parâmetros, o nó a ser removida e
    // seu nó filho da subárvore na esquerda. Por fim, “this->tamanho” é
    // decrementado.
    void removeRecursivo(CelulaArvore* &celula, std::string item);
    // Método privado que troca a chave e os dados (a lista encadeada) do nó
    // passado como primeiro parâmetro, “celula”, para os os de seu antecessor
    // em sua subárvore da esquerda, ou seja, o nó mais à direita dessa
    // subárvore. A troca de dados é feita com o auxílio do método
    // “trocaDados()”. Por fim, o nó antecessor em questão é deletado e seu
    // filho da esquerda é colocado em seu lugar (se existir).
    void antecessor(CelulaArvore* celula, CelulaArvore* &aux);
    // Método privado que percorre a árvore recursivamente, imprimindo a chave
    // de todas as células (nós) da árvore, em ordem crescente (seguindo a
    // lógica do caminhamento in-ordem).
    void caminhaInOrdem(CelulaArvore* celula, int &contador);

    CelulaArvore* raiz;
    int tamanho;
};

#endif