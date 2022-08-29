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

vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node *, pair<int, int>>> qu;
    qu.push({root, {0, 0}});

    while (!qu.empty())
    {
        auto temp = qu.front();
        qu.pop();

        Node *node = temp.first;
        int x = temp.second.first, y = temp.second.second;
        mp[x][y].insert(node->data);
        if (node->left)
            qu.push({node->left, {x - 1, y + 1}});
        if (node->right)
            qu.push({node->right, {x + 1, y + 1}});
    }

    for (auto it : mp)
    {
        vector<int> temp;
        for (auto itt : it.second)
            temp.insert(temp.end(), itt.second.begin(), itt.second.end());

        ans.push_back(temp);
    }

    return ans;
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

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto it : ans)
    {
        for (auto itt : it)
            cout << itt << " ";
        cout << endl;
    }
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
