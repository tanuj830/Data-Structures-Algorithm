
// Right view of the tree using BFS
// ONly difference is that: push right node first than push left node.
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void RightView(struct node *root)
{
    queue<node*>queue;
    queue.push(root);
    vector<int>nums;

    while(!queue.empty())
    {
        auto frontNode = queue.front();
        int n = queue.size();
        int tempN = n;

        while(n--)
        {
             if(n == tempN-1)
             {
                int res = frontNode->data;
                nums.push_back(res);
             }
        queue.pop();

        if(frontNode->right != NULL)
        queue.push(frontNode->right);

        if(frontNode->left != NULL)
        queue.push(frontNode->left);

        }
    }

    for(int i=0;i<nums.size();i++)
    cout << nums[i] << " ";
}

int main()
{
   struct node *root;

    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

   RightView(root);
}