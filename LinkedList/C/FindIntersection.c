// Return node where two linked list intersect each other.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int flag;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->flag = 0;
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

struct node *FindIntersection(struct node *h1, struct node *h2)
{
    struct node *t1 = h1, *t2 = h2;
    while(t1->next != NULL)
    {
        t1->flag = 1;
        t1 = t1->next;
    }

    while(t2->next != NULL)
    {
        if(t2->flag == 1)
        {
          return t2;
        }

        t2->flag = 1;
        t2 = t2->next;
    }
}

int main()
{
    struct node *h1 = NULL, *h2 = NULL;

    insert(&h1, 1);
    insert(&h1, 2);
    insert(&h1, 3);
    insert(&h1, 4);
    insert(&h1, 5);
    insert(&h1, 6);

    insert(&h2, 7);
    insert(&h2, 8);
    insert(&h2, 9);
    insert(&h2, 10);

    h2->next->next->next->next = h1->next->next->next;

    struct node *temp = FindIntersection(h1, h2);

    printf("Intersecting node: %d \n",temp->data);
}