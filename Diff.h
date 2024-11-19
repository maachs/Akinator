#ifndef DIFFERENCE_
#define DIFFERENCE_

#include "Akinator.h"

int DifferenceInDefinition(Node_t* node);

int PrintSimilarity(Node_t** definition_1, Node_t** definition_2, int* count_1, int* count_2, char* def_word_1, char* def_word_2);

int PrintDifference(Node_t** definition_1, Node_t** definition_2, int* count_1, int* count_2, char* def_word_1, char* def_word_2);

#endif
