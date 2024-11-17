#ifndef GLOBALS_
#define GLOBALS_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const int MAX_DATA_LEN = 40;
const int TREE_DEPTH   = 12;

struct Node_t
{
    char*   data;
    Node_t* left;
    Node_t* right;
    Node_t* parent;
};

#endif
