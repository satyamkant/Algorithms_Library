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

vector<int> PreOrder(Node *node)
{
    vector<int> ans;
    if (node == NULL)
        return ans;

    stack<Node *> st;
    st.push(node);

    while (!st.empty())
    {
        node = st.top();
        st.pop();
        ans.push_back(node->data);

        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
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

    vector<int> ans = PreOrder(root);

    for (auto it : ans)
        cout << it << " ";
}

/*///////////////////////////////////////
Pre-order ---> root left right
Example tree used for this traveral...
               1
             /  \
            /    \
           2      3
          / \    / \
         4   5  7   8
            /      / \
           6      9  10

Pre-order output: 1 2 4 5 6 3 7 8 9 10
//////////////////////////////////////*/
