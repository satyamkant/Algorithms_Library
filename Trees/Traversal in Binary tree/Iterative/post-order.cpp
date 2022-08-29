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

vector<int> PostOrder(Node *node)
{
    vector<int> ans;
    if (node == NULL)
        return ans;

    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(node);

    while (!st1.empty())
    {
        node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left)
            st1.push(node->left);

        if (node->right)
            st1.push(node->right);
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
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

    vector<int> ans = PostOrder(root);

    for (auto it : ans)
        cout << it << " ";
}

/*///////////////////////////////////////
Post-order ---> left right root
Example tree used for this traveral...
               1
             /  \
            /    \
           2      3
          / \    / \
         4   5  7   8
            /      / \
           6      9  10

Post-order output: 4 6 5 2 7 9 10 8 3 1
//////////////////////////////////////*/
