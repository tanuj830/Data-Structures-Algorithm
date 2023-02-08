#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void inOrderTraversal(struct node *root)
{
    if(root == NULL)return;
    
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    struct node *root = NULL;
    
    //          0
    //      1      2
    //    3           4
    
    root = createNode(0);
    root->left = createNode(1);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->right->right = createNode(4);
    
    inOrderTraversal(root);
}