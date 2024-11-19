#ifndef GUESS_
#define GUESS_

#include "Akinator.h"

int Guess(Node_t* node, Node_t* root, char** argv);

Node_t* CreateNode(Node_t* node, Node_t* root, char** argv);

int RewriteFile(Node_t* node, FILE* rewrite);

#endif
