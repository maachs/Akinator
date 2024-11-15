#include "ReadCode.h"

Node_t* ReadTree(Node_t* parent, FILE* file_scan)
{
    assert(file_scan);

    int brackets = 0;
    brackets = fgetc(file_scan);

    char read_data[MAX_DATA_LEN] = {};

    if(brackets == '{')
    {
        fscanf(file_scan, "\"%[^\"]\"", read_data);

        Node_t* new_node = MakeNode(parent, read_data);

        brackets = 0;
        while(brackets != '{' && brackets != '}' && brackets != EOF)
        {
            brackets = fgetc(file_scan);
        }

        if(brackets == '}')
        {
            while(brackets != '{' && brackets != EOF)
            {
                brackets = fgetc(file_scan);
            }
            fseek(file_scan, -1, SEEK_CUR);

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
