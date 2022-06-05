#include <stdbool.h>

#define KEY_SIZE 12

#ifndef tree_definition
#define tree_definition

typedef struct tree
{
    int cpf;
    char name[50];
    struct tree *left_node;
    struct tree *right_node;
    int height;
} tree;

#endif

#ifndef tree_operations
#define tree_operations

int menu(); // ok

tree *tree_init(); // ok

bool node_is_empty(tree *node); // ok

tree *tree_insert(tree *node, tree new_node); // ok

tree *tree_search(tree *root, int key);

void tree_print_left_to_right(tree *node, int level); // ok

void tree_print_in_order(tree *root);

void tree_print_structure(tree *root);

tree *tree_remove(tree *root, int key); // ok

int tree_node_amount(tree *root);

int tree_height(tree *root);

void tree_clear(tree *root);

#endif
