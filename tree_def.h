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

void tree_search(tree *node, int key); // ok

void tree_print_inc_order(tree *node); // ok

void tree_print_structure(tree *root, int level);

tree *tree_remove(tree *root, int key); // ok

int tree_node_count(tree *root, int level); // ok

int node_height(tree *root); // ok

void tree_clear(tree *root);

#endif
