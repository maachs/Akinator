#include "Dump.h"

void PrintInorder(Node_t* node)
{
    if(!node) return;

    printf("(");

    if(node->left)
    {
        PrintInorder(node->left);
    }

    printf("%s", node->data);

    if(node->right)
    {
        PrintInorder(node->right);
    }

    printf(")");
}

int GraphicDump(Node_t* node, char** argv)
{
    assert(node);
    assert(argv);

    FILE* dump = fopen(argv[2], "w");

    fprintf(dump, "digraph G\n{\n rankdir = UD\n");

    DrawLabels(node, dump);

    fprintf(dump, "}\n");

    fclose(dump);

    system("dot Dump.dot -Tpng -o Dump.png");

    return 0;
}

int DrawLabels(Node_t* node, FILE* dump)
{
    assert(node);
    assert(dump);

    fprintf(dump, "\"%s\" [shape = Mrecord, style = \"filled\", fillcolor = \"forestgreen\", label = \"{%s | addr = %p | left = %p | right = %p | parent = %p}\"];\n",
             node->data,                                                                         node->data,       node, node->left, node->right, node->parent);

    if(node->left != NULL)
    {
        DrawLabels(node->left,  dump);
        fprintf(dump, " edge[color = \"green\", label = \"yes\"];\n");
        fprintf(dump, "\"%s\" -> \"%s\";", node->data, node->left->data);
    }

    if(node->right != NULL)
    {
        DrawLabels(node->right, dump);
        fprintf(dump, " edge[color = \"red\", label = \"no\"];\n");
        fprintf(dump, "\"%s\" -> \"%s\";\n", node->data, node->right->data);
    }

    return 0;
}
