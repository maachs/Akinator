#include "Definition.h"

int Definition(Node_t* node)
{
    char def_word[MAX_DATA_LEN] = {};

    printf("enter the word whose definition you want to know\n");

    if(scanf("%s", def_word) == 0)
    {
        printf("cannot read word for definition\n");
        return -1;
    }

    Node_t** definition_addr = (Node_t**) calloc(TREE_DEPTH, sizeof(Node_t*));

    if(definition_addr == NULL)
    {
        printf("calloc error\n");
        return -1;
    }

    for(int i = 0; i < TREE_DEPTH; i++)
    {
        definition_addr[i] = NULL;
    }

    int count_node = 0;

    GetWord(node, def_word, definition_addr, &count_node);

    if(definition_addr[0] == NULL)
    {
        printf("cannot find %s in tree\n", def_word);
        return 0;
    }

    int count_print = 0;
    while(definition_addr[count_print] != NULL)
    {
        count_print++;
    }
    count_print -= 2;

    printf("%s is ", def_word);

    PrintDefinition(node, definition_addr, &count_print);

    printf("\n");

    return 0;
}

int GetWord(Node_t* node, char def_word[MAX_DATA_LEN], Node_t** definition_addr, int* count_node)
{
    if(stricmp(node->data, def_word) == 0 && node->left == NULL && node->right == NULL)
    {
        definition_addr[(*count_node)++] = node;
        return 0;
    }
    else if(stricmp(node->data, def_word) != 0 && node->left == NULL && node->right == NULL)
    {
        return 1;
    }

    if(GetWord(node->left, def_word, definition_addr, count_node) == 0)
    {
        definition_addr[(*count_node)++] = node;

        return 0;
    }

    if(GetWord(node->right, def_word, definition_addr, count_node) == 0)
    {
        definition_addr[(*count_node)++] = node;

        return 0;
    }

    return 1;
}

int PrintDefinition(Node_t* node, Node_t** definition_addr, int* count_node)
{
    if(definition_addr[(*count_node)] == node->left)
    {
        if(node->left == NULL || node->right == NULL)
        {
            return 0;
        }

        printf("%s ", node->data);

        (*count_node)--;
    }
    else if(definition_addr[(*count_node)] == node->right)
    {
        if(node->left == NULL || node->right == NULL)
        {
            return 0;
        }

        printf("not %s ", node->data);

        (*count_node)--;
    }
    else
    {
        return 0;
    }

    PrintDefinition(node->left, definition_addr, count_node);
    PrintDefinition(node->right, definition_addr, count_node);

    return 0;
}

