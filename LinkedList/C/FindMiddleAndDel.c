#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(struct node **head, int data)
{
    if(*head == NULL)
    {
       *head = createNode(data);
       return;
    }
    struct node *temp = *head;

    while(temp->next != NULL)
    temp = temp->next;

    temp->next = createNode(data);
    return;

}

struct node *FindMiddleAndDelete(struct node *head)
{
    struct node *prev = NULL, *first = head, *second = head;

    while(second->next != NULL || second != NULL)
    {
        prev = first;
        first = first->next;
        second = second->next->next;
    }
    prev->next = first->next;
    first->next = NULL;
    free(first);
   
    return head;
}

int main()
{
    struct node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);

    struct node *temp = FindMiddleAndDelete(head);

    while (temp != NULL)
    {
    printf("%d ",temp->data);
    temp = temp->next;
    }
}