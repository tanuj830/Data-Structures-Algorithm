#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int wt;
    struct node *next;
};

struct adjlist{
    struct node *head;
};

struct graph{
    int v;
    struct adjlist *adjArray;
};

struct graph *createGraph()
{
    struct graph* graph = malloc(sizeof(struct graph));
    graph->v = 5;
    graph->adjArray = malloc(sizeof(struct node) * graph->v);

    return graph;
}

struct node* createNode(int data, int wt)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->wt = wt;
    return newNode;
}

void insert(struct graph *graph, int s, int d, int wt)
{
    struct node *newNode = createNode(d, wt);
    if(graph->adjArray[s].head == NULL)
    {
    printf("tanuj");
        newNode->next = NULL;
       graph->adjArray[s].head = newNode;       
    }

    else{
        struct node *temp = graph->adjArray[s].head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    }


    // d to s
    newNode = createNode(s, wt);

     if(graph->adjArray[d].head == NULL)
    {
        newNode->next = NULL;
       graph->adjArray[d].head = newNode;
    }
else{
    
    struct node *temp = graph->adjArray[d].head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
}

int main()
{
    struct graph *graph = NULL;

graph = createGraph(graph);

 for(int i=1;i<5;i++){
        graph->adjArray[i].head == NULL;
    }

    insert(graph, 1, 2, 5);
    insert(graph, 2, 3, 6);
    insert(graph, 3, 4, 2);
    insert(graph, 1, 3, 15);

    for(int i=1;i<5;i++)
    {
        struct node *temp = graph->adjArray[i].head;

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }    
}