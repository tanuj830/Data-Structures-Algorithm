
// Left view of the tree
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int value;
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

void TopView(struct node *root)
{
    map<int, int>map;
    queue<node*>queue;
    queue.push(root);
    int val = 0;
    root->value = val;

    while(!queue.empty())
    {
        auto frontNode = queue.front();
        val = frontNode->value;

        // if element with key val is present than method return true otherwise false
        if(map.count(val) == 0)
        map[val] = frontNode->data;

        if(frontNode->left != NULL)
        {
            // decrement key by one on going left to the tree
           frontNode->left->value = val -1;
           queue.push(frontNode->left); 
        }

        if(frontNode->right != NULL)
        {
            // increment key on going right to the tree
           frontNode->right->value = val + 1;
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
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    TopView(root);
}

//           1
//     2         
//       4      
//         5 
//           5

// queue: 1 2
// vector: 0