#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_def.h"

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

short balance_factor(tree *node)
{
    if (node)
        return (node_height(node->left_node) - node_height(node->right_node));
    else
        return 0;
}

tree *rotate_left(tree *node)
{
    tree *son, *grandson;

    son = node->right_node;    // son aponta para a subárvore direita da raiz node
    grandson = son->left_node; // grandson aponta para o filho esquerdo de son

    son->left_node = node;       // o filho esquerdo de son passa a ser a raiz node
    node->right_node = grandson; // o filho direito de node passa a ser grandson

    // recalcula a altura dos nós que foram movimentados
    node->height = highest(node_height(node->left_node), node_height(node->right_node)) + 1;
    son->height = highest(node_height(son->left_node), node_height(son->right_node)) + 1;

    return son;
}

tree *rotate_right(tree *node)
{
    tree *son, *grandson;

    son = node->left_node;
    grandson = son->right_node;

    son->right_node = node;
    node->left_node = grandson;

    node->height = highest(node_height(node->left_node), node_height(node->right_node)) + 1;
    son->height = highest(node_height(son->left_node), node_height(son->right_node)) + 1;

    return son;
}

tree *rotate_left_right(tree *node)
{
    node->left_node = rotate_left(node->left_node);
    return rotate_right(node);
}

tree *rotate_right_left(tree *node)
{
    node->right_node = rotate_right(node->right_node);
    return rotate_left(node);
}

tree *rebalance(tree *node)
{
    short fb = balance_factor(node);

    // Rotação à esquerda
    if (fb < -1 && balance_factor(node->right_node) <= 0)
        node = rotate_left(node);

    // Rotação à direita
    else if (fb > 1 && balance_factor(node->left_node) >= 0)
        node = rotate_right(node);

    // Rotação dupla à esquerda
    else if (fb > 1 && balance_factor(node->left_node) < 0)
        node = rotate_left_right(node);

    // Rotação dupla à direita
    else if (fb < -1 && balance_factor(node->right_node) > 0)
        node = rotate_right_left(node);

    return node;
}

tree *tree_insert(tree *node, tree new_node)
{
    if (node_is_empty(node))
    {
        node = (tree *)malloc(sizeof(tree));

        node->cpf = new_node.cpf;
        strcpy(node->name, new_node.name);
        node->left_node = new_node.left_node;
        node->right_node = new_node.right_node;
        node->height = 0;

        return node;
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

    node->height = highest(node_height(node->left_node), node_height(node->right_node)) + 1;

    node = rebalance(node);

    return node;
}

void tree_print(tree *node)
{
    if (!node_is_empty(node))
    {
        printf("[%d] %s (%d) ", node->cpf, node->name, node->height);

        tree_print(node->left_node);

        tree_print(node->right_node);
    }

    return;
}

void tree_print_inc_order(tree *node)
{
    if (!node_is_empty(node))
    {
        tree_print_inc_order(node->left_node);

        printf("[%d] %s (%d) ", node->cpf, node->name, node->height);

        tree_print_inc_order(node->right_node);
    }

    return;
}

void tree_print_structure(tree *node, int level)
{
    int i;
    if (!node_is_empty(node))
    {
        tree_print_structure(node->right_node, level + 1);
        for (i = 0; i <= level; i++)
            printf("   ");
        printf("[%d] %s (%d)\n", node->cpf, node->name, node->height /*level*/);

        tree_print_structure(node->left_node, level + 1);
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

                    while (aux->right_node != NULL)
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

        // verifica a necessidade de rebalancear a árvore
        node = rebalance(node);

        return node;
    }
}
