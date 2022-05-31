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
