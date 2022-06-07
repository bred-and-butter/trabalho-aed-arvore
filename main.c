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
            printf("Imprimindo elementos\n");

            tree_print_left_to_right(root, 0);
            break;

        case 3:
            printf("Insira cpf do elemento que deseja remover: ");
            scanf("%d", &key);

            root = tree_remove(root, key);

            break;

        case 4:
            /* code */
            break;

        case 5:
            /* code */
            break;

        case 6:
            printf("Altura da arvore: %d\n", node_height(root));

            break;

        case 7:
            /* code */
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Opcao invalida");
            break;
        }

    } while (true);

    return 0;
}
