// AI generated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void freeList(struct Node *head)
{
    struct Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    struct Node *head = NULL;

    struct Node *first = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);
    struct Node *fourth = createNode(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    head = first;

    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    struct Node *tmp = head;

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");

    freeList(head);

    return 0;
}