// AI generated
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          // data stored in the node
    struct Node *next; // pointer to the next node
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Node *head = NULL;

    struct Node *first = createNode(10);
    struct Node *second = createNode(20);

    first->next = second;

    head = first;

    printf("%d -> %d\n", head->data, head->next->data);

    return 0;
}