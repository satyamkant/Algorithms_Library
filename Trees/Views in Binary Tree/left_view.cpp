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

void dfs(Node *root, vector<int> &ans, int curr)
{
    if (!root)
        return;
    if (curr > ans.size())
        ans.push_back(root->data);
    dfs(root->left, ans, curr + 1);
    dfs(root->right, ans, curr + 1);
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
    dfs(root, ans, 1);
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
