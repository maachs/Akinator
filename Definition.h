#ifndef DEFINITION_
#define DEFINITION_

#include "Akinator.h"

int Definition(Node_t* node);

int GetWord(Node_t* node, char def_word[MAX_DATA_LEN], Node_t** definition_addr, int* count_node);

int PrintDefinition(Node_t* node, Node_t** definition_addr, int* count_node);

#endif
