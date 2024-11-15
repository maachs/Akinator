#ifndef DUMP_TREE_
#define DUMP_TREE_

#include "Akinator.h"

void PrintInorder(Node_t* node);

int GraphicDump(Node_t* node, char** argv);

int DrawLabels(Node_t* node, FILE* dump);

#endif
