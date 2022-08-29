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

void leftboundary(Node *root, vector<int> &ans)
{
    Node *curr = root->left;

    while (curr)
    {
        if (curr->left != NULL || curr->right != NULL)
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void rightboundary(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (curr->left != NULL || curr->right != NULL)
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
}

void leafboundary(Node *curr, vector<int> &ans)
{
    if (curr->left == NULL && curr->right == NULL)
    {
        ans.push_back(curr->data);
        return;
    }

    if (curr->left)
        leafboundary(curr->left, ans);
    if (curr->right)
        leafboundary(curr->right, ans);
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

    vector<int> ans;
    if (root->left != NULL || root->right != NULL)
        ans.push_back(root->data);
    leftboundary(root, ans);
    leafboundary(root, ans);
    rightboundary(root, ans);

    for (auto it : ans)
        cout << it << " ";
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
