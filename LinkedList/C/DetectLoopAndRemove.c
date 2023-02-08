// Detect loop and remove loop
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

struct node *DetectLoopAndDelete(struct node *head)
{
    struct node *prev = NULL, *temp = head;

    while(temp != NULL)
    {
        if(temp->flag == 1)
        {
            prev->next = NULL;

            return head;
        }  
        prev = temp;
        temp->flag = 1;
        temp = temp->next;
        
    }
    
    return head;
}

void display(struct node *temp)
{
     while (temp != NULL)
    {
    printf("%d ",temp->data);
    temp = temp->next;
    }
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

    struct node* temp = head;

     while (temp->next != NULL)
    {
    temp = temp->next;
    }
    temp->next = head->next->next;

    // printf("\nBefore detecting loop\n"); // run infinitely
    // display(head);

    temp = DetectLoopAndDelete(head);

    printf("\nAfter detecting loop\n");
    display(head);
   
}