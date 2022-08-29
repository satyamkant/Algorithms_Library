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

vector<vector<int>> LevelOrder(Node *node)
{
    vector<vector<int>> ans;

    if (node == NULL)
        return ans;

    queue<Node *> qu;
    qu.push(node);
    while (!qu.empty())
    {
        vector<int> level;
        int sz = qu.size();
        for (int i = 0; i < sz; i++)
        {
            Node *curr = qu.front();
            qu.pop();
            if (curr->left)
                qu.push(curr->left);
            if (curr->right)
                qu.push(curr->right);

            level.push_back(curr->data);
        }
        ans.push_back(level);
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

    vector<vector<int>> ans = LevelOrder(root);

    for (auto it : ans)
    {
        for (auto itt : it)
            cout << itt << " ";
        cout << endl;
    }
}

/*///////////////////////////////////////
Level-order ---> level-wise printing
Example tree used for this traveral...
               1
             /  \
            /    \
           2      3
          / \    / \
         4   5  7   8
            /      / \
           6      9  10

Level-order output: 1 2 3 4 5 7 8 6 9 10
//////////////////////////////////////*/
