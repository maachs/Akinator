#include "Guess.h"
#include "TreeInit.h"

int Guess(Node_t* node, Node_t* root, char** argv)
{
    char answer[MAX_DATA_LEN] = {};

    printf("%s\n", node->data);

    scanf("%s", answer);

    if(stricmp(answer, "no") == 0 && node->left == NULL && node->right == NULL)
    {
        node = CreateNode(node, root, argv);

        printf("get answer\n");
    }

    if(stricmp(answer, "yes") == 0)
    {
        if(node->left == NULL)
        {
            printf("you've made a wish %s\n", node->data);

            return 0;
        }
        if(Guess(node->left, root, argv) == 0)
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
        if(Guess(node->right, root, argv) == 0)
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
        if(stricmp(answer, "yes") == 0)
        {
            if(node->left == NULL)
            {
                printf("you've made a wish %s\n", node->data);

                return 0;
            }
            if(Guess(node->left, root, argv) == 0)
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
            if(Guess(node->right, root, argv) == 0)
            {
                return 0;
            }
        }
    }

    return 0;
}

Node_t* CreateNode(Node_t* node, Node_t* root, char** argv)
{
    assert(node);
    assert(root);
    assert(argv);

    char new_question[MAX_DATA_LEN] = {};
    char new_left    [MAX_DATA_LEN] = {};
    char new_right   [MAX_DATA_LEN] = {};

    printf("enter new question\n");
    scanf("%s", new_question);

    printf("enter answer if yes\n");
    scanf("%s", new_left);

    printf("enter answer if no\n");
    scanf("%s", new_right);

    node->data = strdup(new_question);

    node->left = MakeNode(node, new_left);

    node->right = MakeNode(node, new_right);

    FILE* rewrite = fopen(argv[1], "w");

    if(rewrite == NULL)
    {
        printf("cannot open file\n");
        return NULL;
    }

    RewriteFile(root, rewrite);

    fclose(rewrite);

    return node;
}

int RewriteFile(Node_t* node, FILE* rewrite)
{
    if(node == NULL)
    {
        return 0;
    }

    fprintf(rewrite, "{\"%s\"", node->data);

    RewriteFile(node->left, rewrite);
    RewriteFile(node->right, rewrite);


    fprintf(rewrite, "}");

    return 0;
}

