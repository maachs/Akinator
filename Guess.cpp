#include "Guess.h"

int Guess(Node_t* node)
{
    char answer[MAX_DATA_LEN] = {};

    printf("%s\n", node->data);

    scanf("%s", answer);

    if(stricmp(answer, "yes") == 0)
    {
        if(node->left == NULL)
        {
            printf("you've made a wish %s\n", node->data);

            return 0;
        }
        if(Guess(node->left) == 0)
        {
            return 0;
        }
    }
    else if(stricmp(answer, "no") == 0)
    {
        if(node->right == NULL)
        {
            printf("you've made a wish %s\n", node->data);

            return 0;
        }
        if(Guess(node->right) == 0)
        {
            return 0;
        }
    }
    else
    {
        while(stricmp(answer, "yes") != 0 && stricmp(answer, "no") != 0)
        {
            printf("answer gonna be yes or no\n");
            scanf("%s", answer);
        }
        if(node->right == NULL)
        {
            printf("you've made a wish %s\n", node->data);

            return 0;
        }
        if(Guess(node->right) == 0)
        {
            return 0;
        }
    }

    return 0;
}
