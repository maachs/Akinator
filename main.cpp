#include "AkinatorFunc.h"

int main(int argc, char** argv)
{
    struct Node_t* root = NULL;

    if(argc != 3)
    {
        printf("argc error\n");
        return -1;
    }

    FILE* file_scan = fopen(argv[1], "r");

    if(file_scan == NULL)
    {
        printf("cannot open file\n");
        return -1;
    }

    root = ReadTree(root, file_scan);

    fclose(file_scan);

    //Definition(root);

    Guess(root);

    GraphicDump(root, argv);

    TreeDtor(root);

    return 0;
}
