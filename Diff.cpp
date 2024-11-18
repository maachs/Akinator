#include "Diff.h"
#include "Definition.h"

int DifferenceInDefinition(Node_t* node)
{
    assert(node);

    char dif_word_1[MAX_DATA_LEN] = {};
    char dif_word_2[MAX_DATA_LEN] = {};

    printf("enter the word whose definition you want to know\n");

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

    int count_print_1 = 0, count_print_2 = 0;

    while(definition_addr_1[count_print_1] != NULL)
    {
        count_print_1++;
    }
    count_print_1 -= 2;

    while(definition_addr_2[count_print_2] != NULL)
    {
        count_print_2++;
    }
    count_print_2 -= 2;

}

int PrintDifference(Node_t* node, Node_t** definition_1, Node_t** definition_2, int* count_1, int* count_2)
{
    if(definition_1[count_1] != definition_2[count_2])
    {
        printf("difference is %s\n", );
    }
}
