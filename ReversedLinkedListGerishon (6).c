#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;

void search(int value);
void insert(int value);
void traverseReverse(struct Node *node);
void deleteNode(int value);

int main(void)
{
    int val;
    printf("Enter a value: ");
    scanf("%d",&val);
    insert (val);

    insert(5);
    insert(25);
    insert(20);
    insert(30);
    search(5);
    deleteNode(5);
    traverseReverse(front);
    return 0;
}

void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    struct Node *current = NULL;
    if(front == NULL)
    {
        front = newNode;
    }
    else
    {
        current = front;
        while(current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = newNode;
    }
}

void traverseReverse(struct Node *node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        traverseReverse(node->next);
        printf("%d ", node->data);
    }
}

void search(int value)
{
    struct Node *current = NULL;
    if(front == NULL)
    {
        printf("Empty linked list \n");
    }
    else
    {
        current = front;
        while(current != NULL)
        {
            if(current -> data == value)
            {
                printf("Value found \n");
                break;
            }
            current = current -> next;
        }
        if(current == NULL)
            printf("Not found \n");
    }
}

void deleteNode(int value)
{
    struct Node *current = NULL;
    struct Node *previous = NULL;
    if(front == NULL)
    {
        printf("Empty list \n");
    }
    else if(front -> data == value)
    {
        current = front;
        front = front -> next;
        free(current);
        printf("Node deleted \n");
    }
    else
    {
        current = front;
        previous = current;
        current = current -> next;
        while(current != NULL)
        {
            if(current -> data == value)
            {
                previous -> next = current -> next;
                free(current);
                printf("Node deleted \n");
                break;
            }
            else
            {
                previous = current;
                current = current -> next;
            }
        }
        if(current == NULL)
        {
            printf("Node not deleted \n");
        }
    }
}

