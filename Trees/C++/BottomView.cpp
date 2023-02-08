// Bottom view of the tree
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
    newNode->level = 0;
    return newNode;
}

void BottomView(struct node *root)
{
    map<int, int>map;
    queue<node*>queue;
    queue.push(root);


    while(!queue.empty())
    {
        auto frontNode = queue.front();
        int frontLevel = frontNode->level;
        // if element with key val is present than method return true otherwise false
        map[frontLevel] = frontNode->data;

        if(frontNode->left != NULL)
        {
            // decrement key by one on going left to the tree
           frontNode->left->level = frontLevel -1;
           queue.push(frontNode->left); 
        }

        if(frontNode->right != NULL)
        {
            // increment key on going right to the tree
           frontNode->right->level = frontLevel + 1;
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

    BottomView(root);
}
