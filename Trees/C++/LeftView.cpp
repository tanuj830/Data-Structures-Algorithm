// Left view of the tree


// Time complexity: O(n)
// Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *createNode = (struct node *)malloc(sizeof(struct node));
    createNode->data = data;
    createNode->left = NULL;
    createNode->right = NULL;

    return createNode;
}

void LeftView(struct node *root)
{
    queue<node*>queue;
    queue.push(root);
    vector<int>nums;

    while(!queue.empty())
    {
        int n = queue.size();
        int tempN = n;

        while(n--)
        {
        auto frontNode = queue.front();
        
             if(n == tempN-1)
             {
                int res = frontNode->data;
                nums.push_back(res);
             }
        queue.pop();

        if(frontNode->left != NULL)
        queue.push(frontNode->left);

        if(frontNode->right != NULL)
        queue.push(frontNode->right);
        }
    }

    for(int i=0;i<nums.size();i++)
    cout << nums[i] << " ";
}

int main()
{
   struct node *root;

    root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

   LeftView(root);
}

// BOTH ARE CORRECT


// // ---------------------------Recursive approch---------------------------------------
// // Time complexity: O(n)
// // Space complexity: O(h)
// // Approch: Do level order traversal and take record of level , if you find level == sizeOf your data structre(in my case vector) than push only

// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node* createNode(int data)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;

//     return newNode;
// }

// void LeftView(struct node *root)
// {
//     queue<node*>queue;
//     vector<int>nums;
//     queue.push(root);
//     int level = 0;

//     while(!queue.empty())
//     {
//         int n = queue.size();
//         int tempN = n;

//         while(n--)
//         {
//             auto frontNode = queue.front();
            
//             if(nums.size() == level)
//             {
//                 nums.push_back((frontNode->data));
//             }

//             queue.pop();

//             if(frontNode->left)
//                 queue.push(frontNode->left);

//             if(frontNode->right)
//                 queue.push(frontNode->right);
//         }
//     level++;
//     }

//     for(auto data : nums)
//     cout << data << " ";
// }

// int main()
// {
//    struct node *root = NULL;

//     root = createNode(4);
//     root->left = createNode(2);
//     root->right = createNode(7);
//     root->left->left = createNode(1);
//     root->left->right = createNode(3);
//     root->right->left = createNode(6);
//     root->left->right->left = createNode(9);

//    LeftView(root);
// }