// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

// link:- https://leetcode.com/problems/maximum-number-of-robots-within-budget/

class segment_tree {
    // tl and tr are used for the tree only 
    // l and r are used for the query range
    // Node is the index of the current node in the tree array
    // 0 based indexing is used here
    int N;
    vector<int> tree; // tree will store the data as node->left (2*i) -> right(2*i+1)

    // function to change the logic
    int operation(int a, int b) {
        return a + b;
    }

    void build(vector<int>& arr, int Node, int tl, int tr) {
        if (tl == tr) {
            tree[Node] = arr[tl];
        }
        else {
            int mid = (tl + tr) >> 1;

            build(arr, 2 * Node + 1, tl, mid); // left child 2*Node
            build(arr, 2 * Node + 2, mid + 1, tr); // right child 2*Node+1

            tree[Node] = operation(tree[2 * Node + 1], tree[2 * Node + 2]); // operating the left child and right child results
        }
    }

    int query(int Node, int tl, int tr, int l, int r) {
        // completely overlapping
        if (tl >= l && tr <= r)
            return tree[Node];
        // out of bounds range
        if (tl > r || tr < l)
            return 0;

        // partial overlapping 
        int mid = (tl + tr) >> 1;

        int left = query(2 * Node + 1, tl, mid, l, r);
        int right = query(2 * Node + 2, mid + 1, tr, l, r);

        return operation(left, right);
    }

    void update(int Node, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            tree[Node] = new_val;
        else {
            int mid = (tl + tr) >> 1;

            if (pos <= mid) // if updating index lies on the left of mid
                update(2 * Node + 1, tl, mid, pos, new_val);
            else // if updating index lies on the right of mid
                update(2 * Node + 2, mid + 1, tr, pos, new_val);

            tree[Node] = operation(tree[2 * Node + 1], tree[2 * Node + 2]); // updating node value
        }
    }

public:
    void construct(vector<int>& arr, int N) {
        this->N = N;
        tree.resize(4 * N);
        build(arr, 0, 0, N - 1);
    }

    int get_query(int l, int r) {
        return query(0, 0, N - 1, l, r);
    }

    void update_at(int pos, int new_val) {
        update(0, 0, N - 1, pos, new_val);
    }
};

///////////////////////////////// segment tree with lazy propagation ///////////////////////////
class segment_tree {
    // tl and tr are used for the tree only
    // l and r are used for the query range
    // Node is the index of the current node in the tree array
    // 0 based indexing is used here
    int N;
    vector<int> tree;
    // tree will store the data as node->left (2*i) -> right(2*i+1)
    vector<int> lazy;

    // function to change the logic
    int operation(int a, int b) { return __gcd(a, b); } // gcd is done here as example
    void lazy_operation(int& a, int& b) { a *= b; } // multiply operation is done here as example

    void build(vector<int>& arr, int Node, int tl, int tr) {
        if (tl == tr) {
            tree[Node] = arr[tl];
        }
        else {
            int mid = (tl + tr) >> 1;

            build(arr, 2 * Node + 1, tl, mid);     // left child 2*Node
            build(arr, 2 * Node + 2, mid + 1, tr); // right child 2*Node+1

            tree[Node] =
                operation(tree[2 * Node + 1],
                    tree[2 * Node + 2]); // operating the left child and
            // right child results
        }
    }

    void push(int Node) {
        lazy_operation(tree[Node * 2 + 1], lazy[Node]);
        lazy_operation(lazy[Node * 2 + 1], lazy[Node]);
        lazy_operation(tree[Node * 2 + 2], lazy[Node]);
        lazy_operation(lazy[Node * 2 + 2], lazy[Node]);
        lazy[Node] = 1;
    }

    int query(int Node, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l <= tl && tr <= r)
            return tree[Node];
        push(Node);
        int mid = (tl + tr) >> 1;
        return operation(query(Node * 2 + 1, tl, mid, l, min(r, mid)),
            query(Node * 2 + 2, mid + 1, tr, max(l, mid + 1), r));
    }

    void range_update(int Node, int tl, int tr, int l, int r, int val) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy_operation(tree[Node], val);
            lazy_operation(lazy[Node], val);
        }
        else {
            push(Node);
            int tm = (tl + tr) >> 1;
            range_update(Node * 2 + 1, tl, tm, l, min(r, tm), val);
            range_update(Node * 2 + 2, tm + 1, tr, max(l, tm + 1), r, val);
            tree[Node] = operation(tree[Node * 2 + 1], tree[Node * 2 + 2]);
        }
    }

public:
    void construct(vector<int>& arr, int N) {
        this->N = N;
        tree.clear();
        lazy.clear();
        tree.resize(4 * N);
        lazy.resize(4 * N, 1);
        build(arr, 0, 0, N - 1);
    }

    int get_query(int l, int r) { return query(0, 0, N - 1, l, r); }

    void update_range(int l, int r, int val) {
        range_update(0, 0, N - 1, l, r, val);
    }
};




/////////////////////////////////////testing testing testing///////////////////////////////////
class segment_tree {
public:
    vector<long long> tree;
    vector<long long> lazy;

    segment_tree(int n) {
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(vector<int>& arr, int Node, int tl, int tr) {
        if (tl == tr) {
            tree[Node] = arr[tl];
            return;
        }

        int mid = (tl + tr) >> 1;

        build(arr, 2 * Node + 1, tl, mid);
        build(arr, 2 * Node + 2, mid + 1, tr);
        tree[Node] = tree[2 * Node + 1] + tree[2 * Node + 2];
    }

    void range_update(int Node, int tl, int tr, int l, int r) {
        if (lazy[Node] != 0) {
            tree[Node] = (tr - tl + 1) - tree[Node];
            if (tl != tr) {
                lazy[2 * Node + 1] ^= 1;
                lazy[2 * Node + 2] ^= 1;
            }
            lazy[Node] ^= 1;
        }

        if (tr<l || tl>r || tl > tr)
            return;

        if (tl >= l && tr <= r) {
            tree[Node] = (tr - tl + 1) - tree[Node];
            if (tl != tr) {
                lazy[2 * Node + 1] ^= 1;
                lazy[2 * Node + 2] ^= 1;
            }
            return;
        }

        int mid = (tl + tr) >> 1;

        range_update(2 * Node + 1, tl, mid, l, r);
        range_update(2 * Node + 2, mid + 1, tr, l, r);
        tree[Node] = tree[2 * Node + 1] + tree[2 * Node + 2];
    }
    long long query(int Node, int tl, int tr, int l, int r) {
        if (lazy[Node] != 0) {
            tree[Node] = (tr - tl + 1) - tree[Node];
            if (tl != tr) {
                lazy[2 * Node + 1] ^= 1;
                lazy[2 * Node + 2] ^= 1;
            }
            lazy[Node] ^= 1;
        }

        if (tr<l || tl>r || tl > tr)
            return 0;

        if (tl >= l && tr <= r)
            return tree[Node];


        int mid = (tl + tr) >> 1;

        return query(2 * Node + 1, tl, mid, l, r) + query(2 * Node + 2, mid + 1, tr, l, r);
    }
};
///////////////////////////////////////testing testing testing//////////////////////////////////////////

int32_t main()
{
    return 0;
}