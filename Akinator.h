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

enum Mode
{
    GUESS      = 1,
    DEFINITION = 2,
    DIFFERENCE = 3
};

#endif
