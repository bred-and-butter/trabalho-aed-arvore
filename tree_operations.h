#include "tree_def.h"

#ifndef tree_operations
#define tree_operations

tree *tree_init();

tree *tree_insert(tree *root, tree new_node);

tree *tree_search(tree *root, char key[KEY_SIZE]);

void tree_print(tree *root);

void tree_print_in_order(tree *root);

void tree_print_structure(tree *root);

tree *tree_remove(tree *root, char key[KEY_SIZE]);

int tree_node_amount(tree *root);

int tree_height(tree *root)

#endif