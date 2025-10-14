// AI GENERATED

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the head using pointer-to-pointer
void insertAtHead(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head; // new node points to current head
    *head = newNode;
}

// Print linked list
void printList(const struct Node *head)
{
    const struct Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// Free linked list safely
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

    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);

    printList(head);

    freeList(head);

    return 0;
}