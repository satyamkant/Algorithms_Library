#include <bits/stdc++.h>

using namespace std;

#define int long long

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int FindDepth(Node *root)
{
    if (!root)
        return 0;

    return max(1 + FindDepth(root->left), 1 + FindDepth(root->right));
}

int32_t main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << FindDepth(root);
}

/*///////////////////////////////////////

Example tree used.....
               1
             /  \
            /    \
           2      3
          / \    / \
         4   5  7   8
            /      / \
           6      9  10

//////////////////////////////////////*/
