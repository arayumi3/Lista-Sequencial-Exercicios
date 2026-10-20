#include "listaSequencial.h"
#include <stdio.h>

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
}

int inserirInicio(Lista *lista, int valor) {
    if (lista->tamanho >= MAX) return 0;
    for (int i = lista->tamanho; i > 0; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }
    lista->dados[0] = valor;
    lista->tamanho++;
    return 1;
}

int inserirFim(Lista *lista, int valor) {
    if (lista->tamanho >= MAX) return 0;
    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}

int inserirPosicao(Lista *lista, int valor, int pos) {
    if (lista->tamanho >= MAX || pos < 0 || pos > lista->tamanho) return 0;
    for (int i = lista->tamanho; i > pos; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }
    lista->dados[pos] = valor;
    lista->tamanho++;
    return 1;
}

int removerInicio(Lista *lista) {
    if (listaVazia(lista)) return 0;
    for (int i = 0; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->tamanho--;
    return 1;
}

int removerFim(Lista *lista) {
    if (listaVazia(lista)) return 0;
    lista->tamanho--;
    return 1;
}

int removerPosicao(Lista *lista, int pos) {
    if (listaVazia(lista) || pos < 0 || pos >= lista->tamanho) return 0;
    for (int i = pos; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->tamanho--;
    return 1;
}

int buscarPorValor(Lista *lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) return i;
    }
    return -1;
}

int buscarPorPosicao(Lista *lista, int pos, int *valor) {
    if (pos < 0 || pos >= lista->tamanho) return 0;
    *valor = lista->dados[pos];
    return 1;
}

int listaVazia(Lista *lista) {
    return lista->tamanho == 0;
}

int obterTamanho(Lista *lista) {
    return lista->tamanho;
}

void imprimirLista(Lista *lista) {
    if (listaVazia(lista)) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d%s", lista->dados[i], (i == lista->tamanho - 1) ? "" : ", ");
    }
    printf("]\n");
}

int substituirElemento(Lista *lista, int pos, int novoValor) {
    if (pos < 0 || pos >= lista->tamanho) return 0;
    lista->dados[pos] = novoValor;
    return 1;
}

int contarOcorrencias(Lista *lista, int valor) {
    int cont = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) cont++;
    }
    return cont;
}

int primeiraOcorrencia(Lista *lista, int valor) {
    return buscarPorValor(lista, valor);
}

int ultimaOcorrencia(Lista *lista, int valor) {
    for (int i = lista->tamanho - 1; i >= 0; i--) {
        if (lista->dados[i] == valor) return i;
    }
    return -1;
}

void inverterLista(Lista *lista) {
    int inicio = 0, fim = lista->tamanho - 1;
    while (inicio < fim) {
        int temp = lista->dados[inicio];
        lista->dados[inicio] = lista->dados[fim];
        lista->dados[fim] = temp;
        inicio++;
        fim--;
    }
}

int concatenarListas(Lista *lista1, Lista *lista2) {
    if (lista1->tamanho + lista2->tamanho > MAX) return 0;
    for (int i = 0; i < lista2->tamanho; i++) {
        inserirFim(lista1, lista2->dados[i]);
    }
    return 1;
}

int compararListas(Lista *lista1, Lista *lista2) {
    if (lista1->tamanho != lista2->tamanho) return 0;
    for (int i = 0; i < lista1->tamanho; i++) {
        if (lista1->dados[i] != lista2->dados[i]) return 0;
    }
    return 1;
}

int ehPalindromo(Lista *lista) {
    int inicio = 0, fim = lista->tamanho - 1;
    while (inicio < fim) {
        if (lista->dados[inicio] != lista->dados[fim]) return 0;
        inicio++;
        fim--;
    }
    return 1;
}

int removerOcorrencias(Lista *lista, int valor) {
    int i = 0, j = 0;
    while (i < lista->tamanho) {
        if (lista->dados[i] != valor) {
            lista->dados[j] = lista->dados[i];
            j++;
        }
        i++;
    }
    int removidos = lista->tamanho - j;
    lista->tamanho = j;
    return removidos > 0;
}

int inserirOrdenado(Lista *lista, int valor) {
    if (lista->tamanho >= MAX) return 0;
    int i = 0;
    while (i < lista->tamanho && lista->dados[i] < valor) {
        i++;
    }
    return inserirPosicao(lista, valor, i);
}

int estaOrdenada(Lista *lista) {
    for (int i = 0; i < lista->tamanho - 1; i++) {
        if (lista->dados[i] > lista->dados[i + 1]) return 0;
    }
    return 1;
}

int maiorElemento(Lista *lista, int *maior) {
    if (listaVazia(lista)) return 0;
    *maior = lista->dados[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->dados[i] > *maior) *maior = lista->dados[i];
    }
    return 1;
}

int menorElemento(Lista *lista, int *menor) {
    if (listaVazia(lista)) return 0;
    *menor = lista->dados[0];
    for (int i = 1; i < lista->tamanho; i++) {
        if (lista->dados[i] < *menor) *menor = lista->dados[i];
    }
    return 1;
}

void removerPosicoesPares(Lista *lista) {
    int j = 0;
    for (int i = 1; i < lista->tamanho; i += 2) {
        lista->dados[j] = lista->dados[i];
        j++;
    }
    lista->tamanho = j;
}

int intercalarListas(Lista *lista1, Lista *lista2, Lista *lista_intercalada) {
    if (lista1->tamanho + lista2->tamanho > MAX) return 0;
    inicializarLista(lista_intercalada);
    int i = 0, j = 0;
    while (i < lista1->tamanho && j < lista2->tamanho) {
        if (lista1->dados[i] < lista2->dados[j]) {
            inserirFim(lista_intercalada, lista1->dados[i++]);
        } else {
            inserirFim(lista_intercalada, lista2->dados[j++]);
        }
    }
    while (i < lista1->tamanho) inserirFim(lista_intercalada, lista1->dados[i++]);
    while (j < lista2->tamanho) inserirFim(lista_intercalada, lista2->dados[j++]);
    return 1;
}

void clonarLista(Lista *original, Lista *clone) {
    inicializarLista(clone);
    for (int i = 0; i < original->tamanho; i++) {
        clone->dados[i] = original->dados[i];
    }
    clone->tamanho = original->tamanho;
}

void rotacionarEsquerda(Lista *lista) {
    if (lista->tamanho <= 1) return;
    int primeiro = lista->dados[0];
    for (int i = 0; i < lista->tamanho - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->dados[lista->tamanho - 1] = primeiro;
}

void rotacionarDireita(Lista *lista) {
    if (lista->tamanho <= 1) return;
    int ultimo = lista->dados[lista->tamanho - 1];
    for (int i = lista->tamanho - 1; i > 0; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }
    lista->dados[0] = ultimo;
}

void removerNMaiores(Lista *lista, int n) {
    if (n <= 0) return;
    if (n >= lista->tamanho) {
        inicializarLista(lista);
        return;
    }
    for (int i = 0; i < n; i++) {
        int maior_val, pos_maior = 0;
        if (!maiorElemento(lista, &maior_val)) return;

        for (int j = 0; j < lista->tamanho; j++) {
            if (lista->dados[j] == maior_val) {
                pos_maior = j;
                break;
            }
        }
        removerPosicao(lista, pos_maior);
    }
}