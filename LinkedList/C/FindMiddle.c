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

struct node *FindMiddle(struct node *head)
{
    struct node *first = head;
    struct node *second = head;
    while(second->next != NULL && second != NULL)
    {
        first = first->next;
        second = second->next->next;
    }
    return first;
}

int main()
{
    struct node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    // insert(&head, 6);

    struct node *temp = FindMiddle(head);

    printf("Middle Element: %d \n",temp->data);
}