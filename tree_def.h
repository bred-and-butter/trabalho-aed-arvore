#define KEY_SIZE 12

#ifndef tree_definition
#define tree_definition

typedef struct tree
{
    char cpf[KEY_SIZE];
    char name[50];
    unsigned int age;
    struct tree *left_node;
    struct tree *right_node;
} tree;

#endif

#ifndef tree_operations
#define tree_operations

tree *tree_insert(tree *root, tree new_node);

tree *tree_search(tree *root, char key[KEY_SIZE]);

void tree_print(tree *root);

void tree_print_in_order(tree *root);

void tree_print_structure(tree *root);

tree *tree_remove(tree *root, char key[KEY_SIZE]);

int tree_node_amount(tree *root);

int tree_height(tree *root)

#endif
