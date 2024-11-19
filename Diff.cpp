#include "Diff.h"
#include "Definition.h"

int DifferenceInDefinition(Node_t* node)
{
    assert(node);

    char dif_word_1[MAX_DATA_LEN] = {};
    char dif_word_2[MAX_DATA_LEN] = {};

    printf("enter the words whose difference in definition you want to know\n");

    if(scanf("%s %s", dif_word_1, dif_word_2) == 0)
    {
        printf("cannot read word for definition\n");
        return -1;
    }

    Node_t** definition_addr_1 = (Node_t**) calloc(TREE_DEPTH, sizeof(Node_t*));
    Node_t** definition_addr_2 = (Node_t**) calloc(TREE_DEPTH, sizeof(Node_t*));

    if(definition_addr_1 == NULL || definition_addr_2 == NULL)
    {
        printf("calloc error\n");
        return -1;
    }

    int count_node_1 = 0, count_node_2 = 0;

    GetWord(node, dif_word_1, definition_addr_1, &count_node_1);
    GetWord(node, dif_word_2, definition_addr_2, &count_node_2);

    count_node_1 -= 1;
    count_node_2 -= 1;

    for(int i = count_node_1; i > 0; i--)
    {
        printf("data 1 = %s\n", definition_addr_1[i]->data);
    }
    printf("\n");

    for(int i = count_node_2; i > 0; i--)
    {
        printf("data 2 = %s\n", definition_addr_2[i]->data);
    }
    printf("\n");


    int count_node_1_ = count_node_1, count_node_2_ = count_node_2;

    printf("difference:\n");

    PrintDifference(definition_addr_1, definition_addr_2, &count_node_1, &count_node_2, dif_word_1, dif_word_2);

    printf("\nsimilarity:\n");

    PrintSimilarity(definition_addr_1, definition_addr_2, &count_node_1_, &count_node_2_, dif_word_1, dif_word_2);

    //printf("%s\n%s\n", definition_addr_1[count_node_1]->data, definition_addr_2[count_node_2]->data);

    return 0;
}

int PrintDifference(Node_t** definition_1, Node_t** definition_2, int* count_1, int* count_2, char* def_word_1, char* def_word_2)
{
    if((*count_1) == 0 || (*count_2) == 0)
    {
        return 0;
    }
    if((strcmp(definition_1[(*count_1) - 1]->data, definition_2[(*count_2) - 1]->data) != 0) &&
       (strcmp(definition_1[(*count_1) - 1]->data, definition_1[(*count_1)]->left->data) == 0) &&
       (strcmp(definition_2[(*count_2) - 1]->data, definition_2[(*count_2)]->right->data) == 0))
    {
        printf("%s is %s but %s is not %s\n", def_word_1, definition_1[*count_1]->data, def_word_2, definition_2[*count_2]->data);

        (*count_1) -= 1;
        (*count_2) -= 1;
    }
    else if((strcmp(definition_1[(*count_1) - 1]->data, definition_2[(*count_2) - 1]->data) != 0) &&
            (strcmp(definition_1[(*count_1) - 1]->data, definition_1[(*count_1)]->right->data) == 0) &&
            (strcmp(definition_2[(*count_2) - 1]->data, definition_2[(*count_2)]->left->data) == 0))
    {
        printf("%s is not %s but %s is %s\n", def_word_1, definition_1[*count_1]->data, def_word_2, definition_2[*count_2]->data);

        (*count_1) -= 1;
        (*count_2) -= 1;
    }
    else
    {
        //printf("IN ELSE\n");
        (*count_1)--;
        (*count_2)--;
    }


    if(PrintDifference(definition_1, definition_2, count_1, count_2, def_word_1, def_word_2) == 0)
    {
        return 0;
    }

    return 0;
}

int PrintSimilarity(Node_t** definition_1, Node_t** definition_2, int* count_1, int* count_2, char* def_word_1, char* def_word_2)
{
    if((*count_1) == 0 || (*count_2) == 0)
    {
        return 0;
    }

    if((definition_1[*count_1] == definition_2[*count_2]) &&
       (strcmp(definition_1[(*count_1) - 1]->data, definition_1[(*count_1)]->left->data) == 0) &&
       (strcmp(definition_2[(*count_2) - 1]->data, definition_2[(*count_2)]->left->data) == 0))
    {
        printf("%s is %s and %s is %s\n", def_word_1, definition_1[*count_1]->data, def_word_2, definition_2[*count_2]->data);

        (*count_1) -= 1;
        (*count_2) -= 1;
    }
    else if((definition_1[*count_1] == definition_2[*count_2]) &&
            (strcmp(definition_1[(*count_1) - 1]->data, definition_1[(*count_1)]->right->data) == 0) &&
            (strcmp(definition_2[(*count_2) - 1]->data, definition_2[(*count_2)]->right->data) == 0))
    {
        printf("%s is not %s and %s is not %s\n", def_word_1, definition_1[*count_1]->data, def_word_2, definition_2[*count_2]->data);

        (*count_1) -= 1;
        (*count_2) -= 1;
    }
    else
    {
        (*count_1)--;
        (*count_2)--;
    }

    if(PrintSimilarity(definition_1, definition_2, count_1, count_2, def_word_1, def_word_2) == 0)
    {
        return 0;
    }

    return 0;
}
