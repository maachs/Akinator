#include "TreeInit.h"

int TreeDtor(Node_t* node)
{
    if(!node)
    {
        return 0;
    }

    TreeDtor(node->left);
    TreeDtor(node->right);

    free(node);

    node = NULL;

    return 0;

}

Node_t* MakeNode(Node_t* parent, char* value)
{
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));

    if(node == NULL)
    {
        printf("calloc error");

        return NULL;
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    node->parent = parent;

    return node;
}
