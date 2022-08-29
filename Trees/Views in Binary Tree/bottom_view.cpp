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

void Bottomview(Node *root)
{
    vector<int> ans;
    if (!root)
        return;

    map<int, int> mp;
    queue<pair<Node *, int>> qu;
    qu.push({root, 0});

    while (!qu.empty())
    {
        auto it = qu.front();
        qu.pop();

        Node *node = it.first;
        int line = it.second;
        /////////////....change is only here from top view..../////////
        mp[line] = node->data;

        if (node->left)
            qu.push({node->left, line - 1});
        if (node->right)
            qu.push({node->right, line + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    for (auto it : ans)
        cout << it << " ";
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
    Bottomview(root);
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
