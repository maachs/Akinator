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

    ChooseMode(root, argv);

    return 0;
}

int ChooseMode(Node_t* root, char** argv)
{
    assert(root);

    int mode = 0;

    printf("choose akinator mode\n");

    scanf("%d", &mode);

    switch(mode)
    {
        case GUESS:
        {
            Guess(root, root, argv);

            GraphicDump(root, argv);

            TreeDtor(root);
        }
        case DEFINITION:
        {
            Definition(root);

            GraphicDump(root, argv);

            TreeDtor(root);
        }
        case DIFFERENCE:
        {
            DifferenceInDefinition(root);

            GraphicDump(root, argv);

            TreeDtor(root);
        }
        default:
        printf("cannot defined mode\n");
        return -1;
    }

    return 0;
}
