#include "ReadCode.h"

Node_t* ReadTree(Node_t* parent, FILE* file_scan)
{
    assert(parent);
    assert(file_scan);

    int brackets = fgetc(file_scan);

    char read_data[MAX_DATA_LEN] = {};

    if(brackets == '{')
    {
        fscanf(file_scan, "%[^\"]", read_data);

        Node_t* new_node = MakeNode(parent, read_data);

        while(brackets != '{' && brackets != '}')
        {
            brackets = fgetc(file_scan);
        }

        if(brackets == '}')
        {
            return new_node;
        }
        else
        {
            fseek(file_scan, -1, SEEK_CUR);

            new_node->left  = ReadTree(new_node, file_scan);
            new_node->right = ReadTree(new_node, file_scan);
        }

        return new_node;
    }

    return NULL;
}
