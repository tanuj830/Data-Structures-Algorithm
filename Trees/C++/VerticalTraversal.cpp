// sum of nodes vertically
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int level;
};

struct node *newNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    // newNode->value = 0;
    return newNode;
}

void sumVerticalNodes(struct node *root)
{
   map<int, int>map;
   queue<node*>queue;

    
   queue.push(root);

   while(!queue.empty())
   {
     auto frontNode = queue.front();
    int level = frontNode->level;
   
    if(map.count(level) == 0)
    map[level] = frontNode->data;

    else {
        int res = map[level] + (frontNode->data);
        map[level] = res;
    }

    if(frontNode->left != NULL)
    {
        frontNode->left->level = level-1;
        queue.push(frontNode->left);
    }

    if(frontNode->right != NULL)
    {
        frontNode->right->level = level+1;
        queue.push(frontNode->right);
    }
    

    queue.pop();
   }

     for (auto i = map.begin(); i != map.end(); i++) {
        cout << i->second << " ";
    }
}

int main()
{
   struct node *root;

  root = newNode(1);
    root->left = newNode(5);
    root->right = newNode(8);
    root->right->left = newNode(17);
    root->right->right = newNode(24);
    root->right->left->right = newNode(9);
    root->right->left->right->left = newNode(2);

    sumVerticalNodes(root);
}
