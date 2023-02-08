// TWO APPROCHES:
// First: find middle and reverse the right sub part
//
//
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *createNode(char data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(struct node **head, char data)
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

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; 
}
int compare(struct node *head, struct node *mid)
{
    struct node *temp_head = head, *temp_mid = mid;

    while(temp_mid != NULL)
    {
    if(temp_head->data == temp_mid->data)
      {
          temp_head = temp_head->next;
          temp_mid =temp_mid->next;
      }

    else      return 0;
    
    }
    return 1;
}

void display(struct node *temp)
{
     while (temp != NULL)
    {
    printf("%c ",temp->data);
    temp = temp->next;
    }
}

int isPalindrome(struct node *head)
{
    struct node *temp = head, *first = head, *second = head,*reversed;

    while( second != NULL && second->next != NULL)// r a d a r
    {
        first = first->next;
        second = second->next->next;
    }
   
   reversed = reverse(first);

    int t = compare(head, reversed);

    reverse(reversed);
return t;
}

int main()
{
    struct node *head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'n');
    insert(&head, 'a');

    isPalindrome(head) ? printf("Palindrome...!") : printf("Not Palindrome");
}