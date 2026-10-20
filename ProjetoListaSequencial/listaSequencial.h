#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 100 // Tamanho máximo da lista

// Estrutura da lista sequencial
typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

// Função de inicialização
void inicializarLista(Lista *lista);

// Inserir elemento no início
int inserirInicio(Lista *lista, int valor);

// Inserir elemento no final
int inserirFim(Lista *lista, int valor);

//  Inserir elemento em posição específica
int inserirPosicao(Lista *lista, int valor, int pos);

// Remover elemento do início
int removerInicio(Lista *lista);

// Remover elemento do final
int removerFim(Lista *lista);

// Remover elemento de posição específica
int removerPosicao(Lista *lista, int pos);

// Buscar elemento por valor
int buscarPorValor(Lista *lista, int valor);

// Buscar elemento por posição
int buscarPorPosicao(Lista *lista, int pos, int *valor);

// Verificar se a lista está vazia
int listaVazia(Lista *lista);

// Obter o tamanho da lista
int obterTamanho(Lista *lista);

// Imprimir todos os elementos
void imprimirLista(Lista *lista);

// Substituir elemento em posição específica
int substituirElemento(Lista *lista, int pos, int novoValor);

// Contar quantas vezes um valor aparece
int contarOcorrencias(Lista *lista, int valor);

// Obter a posição da primeira ocorrência de um valor
int primeiraOcorrencia(Lista *lista, int valor);

// Obter a posição da última ocorrência de um valor
int ultimaOcorrencia(Lista *lista, int valor);

// Inverter a lista
void inverterLista(Lista *lista);

// Concatenar duas listas
int concatenarListas(Lista *lista1, Lista *lista2);

// Comparar duas listas
int compararListas(Lista *lista1, Lista *lista2);

// Verificar se a lista é palíndromo
int ehPalindromo(Lista *lista);

// Remover todas as ocorrências de um valor
int removerOcorrencias(Lista *lista, int valor);

// Inserir elementos em ordem crescente
int inserirOrdenado(Lista *lista, int valor);

// Verificar se a lista está ordenada
int estaOrdenada(Lista *lista);

// Encontrar o maior elemento
int maiorElemento(Lista *lista, int *maior);

// Encontrar o menor elemento
int menorElemento(Lista *lista, int *menor);

// Remover os elementos em posições pares
void removerPosicoesPares(Lista *lista);

// Intercalar duas listas ordenadas
int intercalarListas(Lista *lista1, Lista *lista2, Lista *lista_intercalada);

// Clonar a lista
void clonarLista(Lista *original, Lista *clone);

// Rotacionar a lista à esquerda
void rotacionarEsquerda(Lista *lista);

// Rotacionar a lista à direita
void rotacionarDireita(Lista *lista);

// Remover os N maiores elementos da lista
void removerNMaiores(Lista *lista, int n);

#endif