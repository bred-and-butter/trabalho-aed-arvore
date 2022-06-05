#include <stdio.h>
#include <stdlib.h>
#include "tree_def.h"

int menu()
{
    int escolha;

    do
    {
        printf("Escolha:\n");
        printf("1) Inserir elemento na arvore\n");
        printf("2) Buscar e imprimir todos os elementos\n");
        printf("3) Excluir elemento da arvore\n");
        printf("4) Imprimir todos os elementos em ordem\n");
        printf("5) Imprimir quantidade de elementos\n");
        printf("6) Imprimir altura da arvore\n");
        printf("7) Imprimir estrutura da arvore\n");
        printf("8) Sair\n");

        scanf("%d", &escolha);
    }
    while(escolha <= 1 && escolha >= 8);

    return escolha;
}