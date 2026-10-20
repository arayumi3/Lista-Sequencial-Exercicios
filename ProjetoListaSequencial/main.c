#include <stdio.h>
#include <stdlib.h>
#include "listaSequencial.h"

// Função para limpar a tela
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para pausar a execução até o usuário pressionar Enter
void pausar() {
    printf("\nPressione Enter para continuar...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

// Exibe o menu de opções para o usuário
void exibirMenu() {
    limparTela();
    printf("\n----------- MENU DE OPERACOES COM LISTA SEQUENCIAL -----------\n");
    printf(" 1. Inserir elemento no inicio\n");
    printf(" 2. Inserir elemento no final\n");
    printf(" 3. Inserir elemento em posicao especifica\n");
    printf(" 4. Remover elemento do inicio\n");
    printf(" 5. Remover elemento do final\n");
    printf(" 6. Remover elemento de posicao especifica\n");
    printf(" 7. Buscar elemento por valor (retorna primeira ocorrencia)\n");
    printf(" 8. Buscar elemento por posicao\n");
    printf(" 9. Verificar se a lista esta vazia\n");
    printf("10. Obter o tamanho da lista\n");
    printf("11. Imprimir todos os elementos da lista\n");
    printf("12. Substituir elemento em posicao especifica\n");
    printf("13. Contar ocorrencias de um valor\n");
    printf("14. Obter a posicao da primeira ocorrencia de um valor\n");
    printf("15. Obter a posicao da ultima ocorrencia de um valor\n");
    printf("16. Inverter a lista\n");
    printf("17. Concatenar com uma segunda lista\n");
    printf("18. Comparar com uma segunda lista\n");
    printf("19. Verificar se a lista e um palindromo\n");
    printf("20. Remover todas as ocorrencias de um valor\n");
    printf("21. Inserir elemento em ordem crescente (lista deve estar ordenada)\n");
    printf("22. Verificar se a lista esta ordenada\n");
    printf("23. Encontrar o maior elemento\n");
    printf("24. Encontrar o menor elemento\n");
    printf("25. Remover os elementos em posicoes pares\n");
    printf("26. Intercalar com uma segunda lista ordenada\n");
    printf("27. Clonar a lista\n");
    printf("28. Rotacionar a lista a esquerda\n");
    printf("29. Rotacionar a lista a direita\n");
    printf("30. Remover os N maiores elementos da lista\n");
    printf(" 0. Sair do programa\n");
    printf("----------------------------------------------------------------\n");
}

// Função para criar uma segunda lista
void criarSegundaLista(Lista* lista2) {
    inicializarLista(lista2);
    int qtd, val;
    printf("Criando a segunda lista para a operacao.\n");
    printf("Quantos elementos deseja inserir na segunda lista? ");
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++) {
        printf("Digite o elemento %d/%d: ", i + 1, qtd);
        scanf("%d", &val);
        inserirFim(lista2, val);
    }
    printf("Segunda lista criada: ");
    imprimirLista(lista2);
}

int main() {
    Lista lista, lista2, lista_resultado;
    inicializarLista(&lista);
    int opcao, valor, pos, n, resultado, sucesso;

    do {
        exibirMenu();
        printf("\nLista Principal Atualmente: ");
        imprimirLista(&lista);
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                if (inserirInicio(&lista, valor)) printf("Sucesso: Valor inserido.\n");
                else printf("Erro: Nao foi possivel inserir. A lista pode estar cheia.\n");
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                if (inserirFim(&lista, valor)) printf("Sucesso: Valor inserido.\n");
                else printf("Erro: Nao foi possivel inserir. A lista pode estar cheia.\n");
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posicao para inserir: ");
                scanf("%d", &pos);
                if (inserirPosicao(&lista, valor, pos)) printf("Sucesso: Valor inserido na posicao %d.\n", pos);
                else printf("Erro: Nao foi possivel inserir. Posicao invalida ou lista cheia.\n");
                break;
            case 4:
                if (removerInicio(&lista)) printf("Sucesso: Elemento do inicio removido.\n");
                else printf("Erro: Nao foi possivel remover. A lista pode estar vazia.\n");
                break;
            case 5:
                if (removerFim(&lista)) printf("Sucesso: Elemento do final removido.\n");
                else printf("Erro: Nao foi possivel remover. A lista pode estar vazia.\n");
                break;
            case 6:
                printf("Digite a posicao a ser removida: ");
                scanf("%d", &pos);
                if (removerPosicao(&lista, pos)) printf("Sucesso: Elemento da posicao %d removido.\n", pos);
                else printf("Erro: Nao foi possivel remover. Posicao invalida ou lista vazia.\n");
                break;
            case 7:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                resultado = buscarPorValor(&lista, valor);
                if (resultado != -1) printf("Valor encontrado na posicao %d.\n", resultado);
                else printf("Valor nao encontrado na lista.\n");
                break;
            case 8:
                printf("Digite a posicao a ser buscada: ");
                scanf("%d", &pos);
                if (buscarPorPosicao(&lista, pos, &valor)) printf("O valor na posicao %d e %d.\n", pos, valor);
                else printf("Posicao invalida ou lista vazia.\n");
                break;
            case 9:
                if (listaVazia(&lista)) printf("A lista esta vazia.\n");
                else printf("A lista NAO esta vazia.\n");
                break;
            case 10:
                printf("O tamanho atual da lista e %d.\n", obterTamanho(&lista));
                break;
            case 11:
                printf("Lista completa: ");
                imprimirLista(&lista);
                break;
            case 12:
                printf("Digite a posicao do elemento a ser substituido: ");
                scanf("%d", &pos);
                printf("Digite o novo valor: ");
                scanf("%d", &valor);
                if (substituirElemento(&lista, pos, valor)) printf("Sucesso: Elemento da posicao %d substituido.\n", pos);
                else printf("Posicao invalida.\n");
                break;
            case 13:
                printf("Digite o valor para contar as ocorrencias: ");
                scanf("%d", &valor);
                resultado = contarOcorrencias(&lista, valor);
                printf("O valor %d aparece %d vez(es) na lista.\n", valor, resultado);
                break;
            case 14:
                printf("Digite o valor para buscar a primeira ocorrencia: ");
                scanf("%d", &valor);
                resultado = primeiraOcorrencia(&lista, valor);
                if (resultado != -1) printf("Primeira ocorrencia do valor %d esta na posicao %d.\n", valor, resultado);
                else printf("Valor nao encontrado.\n");
                break;
            case 15:
                printf("Digite o valor para buscar a ultima ocorrencia: ");
                scanf("%d", &valor);
                resultado = ultimaOcorrencia(&lista, valor);
                if (resultado != -1) printf(" Ultima ocorrencia do valor %d esta na posicao %d.\n", valor, resultado);
                else printf("Valor nao encontrado.\n");
                break;
            case 16:
                inverterLista(&lista);
                printf("A lista foi invertida.\n");
                break;
            case 17:
                criarSegundaLista(&lista2);
                if (concatenarListas(&lista, &lista2)) printf("Sucesso: Listas concatenadas.\n");
                else printf("Nao foi possivel concatenar. Espaco insuficiente na lista principal.\n");
                break;
            case 18:
                criarSegundaLista(&lista2);
                if (compararListas(&lista, &lista2)) printf("As listas sao iguais.\n");
                else printf("As listas sao diferentes.\n");
                break;
            case 19:
                if (ehPalindromo(&lista)) printf(" A lista e um palindromo.\n");
                else printf(" A lista NAO e um palindromo.\n");
                break;
            case 20:
                printf("Digite o valor a ter todas as ocorrencias removidas: ");
                scanf("%d", &valor);
                if(removerOcorrencias(&lista, valor)) printf("Sucesso: Todas as ocorrencias de %d foram removidas.\n", valor);
                else printf("Valor %d nao encontrado para remocao.\n", valor);
                break;
            case 21:
                printf("Digite o valor a ser inserido em ordem (a lista deve estar ordenada): ");
                scanf("%d", &valor);
                if (inserirOrdenado(&lista, valor)) printf("Sucesso: Valor inserido mantendo a ordem.\n");
                else printf("Erro: Nao foi possivel inserir. Lista cheia.\n");
                break;
            case 22:
                if (estaOrdenada(&lista)) printf("A lista esta ordenada em ordem crescente.\n");
                else printf(" A lista NAO esta ordenada.\n");
                break;
            case 23:
                if (maiorElemento(&lista, &valor)) printf(" O maior elemento da lista e %d.\n", valor);
                else printf("Erro: Nao ha elementos na lista.\n");
                break;
            case 24:
                if (menorElemento(&lista, &valor)) printf(" O menor elemento da lista e %d.\n", valor);
                else printf("Erro: Nao ha elementos na lista.\n");
                break;
            case 25:
                removerPosicoesPares(&lista);
                printf("Sucesso: Elementos de posicoes pares foram removidos.\n");
                break;
            case 26:
                printf("A lista principal DEVE estar ordenada.\n");
                criarSegundaLista(&lista2);
                printf("A segunda lista tambem DEVE estar ordenada.\n");
                sucesso = intercalarListas(&lista, &lista2, &lista_resultado);
                if(sucesso) {
                    printf("Sucesso: Listas intercaladas. A lista resultante e: ");
                    imprimirLista(&lista_resultado);
                    printf("(A lista principal nao foi alterada)\n");
                } else {
                    printf("Erro: Nao foi possivel intercalar. Espaco insuficiente.\n");
                }
                break;
            case 27:
                clonarLista(&lista, &lista_resultado);
                printf(">> Sucesso: Lista clonada. O clone e: ");
                imprimirLista(&lista_resultado);
                break;
            case 28:
                rotacionarEsquerda(&lista);
                printf("Sucesso: Lista rotacionada para a esquerda.\n");
                break;
            case 29:
                rotacionarDireita(&lista);
                printf("Sucesso: Lista rotacionada para a direita.\n");
                break;
            case 30:
                printf("Quantos (N) maiores elementos deseja remover? ");
                scanf("%d", &n);
                removerNMaiores(&lista, n);
                printf("Sucesso: Operacao concluida.\n");
                break;
            case 0:
                printf("Encerrando o programa. Ate logo!\n");
                break;
            default:
                printf("Erro: Opcao invalida! Tente novamente.\n");
        }
        if(opcao != 0) pausar();
    } while (opcao != 0);

    return 0;
}