#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_def.h"

#define CALL_LIMIT 50

unsigned int FUNCTION_CALL_AMOUNT = 0;

int highest(int a, int b)
{
    return (a > b) ? a : b;
}

tree *tree_init()
{
    tree *root = NULL;

    return root;
}

bool node_is_empty(tree *node)
{
    if (node == NULL)
        return true;

    return false;
}

int node_height(tree *node)
{
    if (node_is_empty(node))
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

tree *tree_insert(tree *node, tree new_node)
{
    FUNCTION_CALL_AMOUNT++;

    if (FUNCTION_CALL_AMOUNT > CALL_LIMIT)
    {
        printf("Chamadas aninhadas de funcao excederam limite de %d", CALL_LIMIT);
        exit(1);
    }
    else if (node_is_empty(node))
    {
        node = (tree *)malloc(sizeof(tree));

        node->cpf = new_node.cpf;
        strcpy(node->name, new_node.name);
        node->left_node = new_node.left_node;
        node->right_node = new_node.right_node;
    }
    else if (new_node.cpf < node->cpf)
    {
        node->left_node = tree_insert(node->left_node, new_node);
    }
    else if (new_node.cpf > node->cpf)
    {
        node->right_node = tree_insert(node->right_node, new_node);
    }
    else if (new_node.cpf == node->cpf)
    {
        printf("Erro! Chave ja existe!");
    }

    node->height = highest(node_height(node->left_node), node_height(node->right_node));

    // node = rebalance(node);

    return node;
}

void tree_print_left_to_right(tree *node, int level)
{
    if (!node_is_empty(node))
    {
        tree_print_left_to_right(node->left_node, level + 1);

        printf("[%d] %s (%d)", node->cpf, node->name, level);

        tree_print_left_to_right(node->right_node, level + 1);
    }

    return;
}

tree *tree_remove(tree *node, int key)
{
    if (node == NULL)
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else
    { // procura o nó a remover
        if (node->cpf == key)
        {
            // remove nós folhas (nós sem filhos)
            if (node->left_node == NULL && node->right_node == NULL)
            {
                printf("Elemento folha removido: [%d] %s !\n", node->cpf, node->name);
                free(node);
                return NULL;
            }
            else
            {
                // remover nós que possuem 2 filhos
                if (node->left_node != NULL && node->right_node != NULL)
                {
                    tree *aux = node->left_node;
                    while (aux->right_node != NULL) // nao sei exatamente oq isso faz
                        aux = aux->right_node;
                    node->cpf = aux->cpf;
                    aux->cpf = key;
                    printf("Elemento trocado: %d !\n", key);
                    node->left_node = tree_remove(node->left_node, key);
                    return node;
                }
                else
                {
                    // remover nós que possuem apenas 1 filho
                    tree *aux;
                    if (node->left_node != NULL)
                        aux = node->left_node;
                    else
                        aux = node->right_node;
                    free(node);
                    printf("Elemento com 1 filho removido: %d !\n", key);
                    return aux;
                }
            }
        }
        else
        {
            if (key < node->cpf)
                node->left_node = tree_remove(node->left_node, key);
            else
                node->right_node = tree_remove(node->right_node, key);
        }
        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        node->height = highest(node_height(node->left_node), node_height(node->right_node)) + 1;

        /*
                // verifica a necessidade de rebalancear a árvore
                raiz = balancear(raiz);
        */
        return node;
    }
}
