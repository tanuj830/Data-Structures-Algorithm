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

// Finding previous node of middle node
void FindMiddle(struct node *head, struct node **h1, struct node **h2)
{
    struct node *slow = head, *fast = head;

    while(fast != NULL && fast->next->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next->next;
    }

    *h1 = head;
    *h2 = slow->next;
    slow->next = NULL;
}

struct node *merge(struct node *h1, struct node *h2)
{
      struct node *head = NULL;

      if(h1 == NULL)       
      {
          head = h2;
          return head;
      }

      else if(h2 == NULL)
      {
          head = h1;
          return head;
      }
// h1- 1 2 3    | h2- 2 3 4
    // Picking only one linked list for comparison.
      if(h1-> data <= h2->data)
      {
       // h1 picked.
        head = h1;
        head->next = merge(h1->next, h2);
      }
      else
      {
          // h2 picked.
         head = h2;
         head->next = merge(h1, h2->next);
      }
      return head;
}

void mergeSort(struct node **head)
{
    struct node *h1 = NULL, *h2 = NULL, *h;
    
    h = *head;

if(*head == NULL || (*(head))->next == NULL)  return;

    FindMiddle(*head, &h1, &h2);

   
    mergeSort(&h1);
    mergeSort(&h2);
    
    *head = merge(h1, h2);
}

int main()
{
    struct node *head = NULL;

    insert(&head, 11);
    insert(&head, 21);
    insert(&head, 3);
    insert(&head, 14);
    insert(&head, 5);
    insert(&head, 16);

    // struct node *temp = FindMiddle(head);

    mergeSort(&head);

    while(head!= NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    // printf("Middle Element: %d \n",temp->data);
}