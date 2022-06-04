#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_def.h"

tree *tree_init()
{
    tree *root = NULL;

    return root;
}

bool tree_is_empty(tree *root)
{
    if (root == NULL)
        return true;

    return false;
}

tree *tree_insert(tree *root, tree new_node)
{
    if (tree_is_empty(root))
    {
        root = (tree*)malloc(sizeof(tree));

        root->cpf = new_node.cpf;
        strcpy(root->name, new_node.name);
        root->left_node = new_node.left_node;
        root->right_node = new_node.right_node;

        return root;
    }
    else if (2==3)
    {
        /* code */
    }
}
