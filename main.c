#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_def.h"

tree create_new_node()
{
    int cpf;
    char name[50];
    tree new_node;

    printf("Insira o cpf: ");
    scanf("%d", &cpf);
    printf("Insira o nome(max 50 caracteres): ");
    scanf("%s", name);

    new_node.cpf = cpf;
    strcpy(new_node.name, name);
    new_node.left_node = NULL;
    new_node.right_node = NULL;
    new_node.height = 0;

    return new_node;
}

int main()
{
    tree new_node;

    tree *root = tree_init();
    int escolha, key;

    do
    {
        escolha = menu();

        switch (escolha)
        {
        case 1:
            printf("\nInserindo novo nó\n");

            new_node = create_new_node();
            root = tree_insert(root, new_node);

            break;

        case 2:
            printf("Insira cpf do elemento que deseja buscar: ");
            scanf("%d", &key);

            tree_search(root, key);

            break;

        case 3:
            printf("Insira cpf do elemento que deseja remover: ");
            scanf("%d", &key);

            root = tree_remove(root, key);

            break;

        case 4:
            printf("Imprimindo elementos em ordem crescente\n");

            tree_print_inc_order(root);
            break;

        case 5:
            printf("Imprimindo quantidade de elementos:\n");

            printf("%d\n", tree_node_count(root, 0));
            break;

        case 6:
            printf("Altura da arvore: %d\n", node_height(root));

            break;

        case 7:
            printf("Imprimindo estrutura da arvore\n");

            tree_print_structure(root, 0);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }

    } while (true);

    return 0;
}
