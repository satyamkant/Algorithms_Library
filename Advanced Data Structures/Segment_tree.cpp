#include <bits/stdc++.h>

using namespace std;

#define int long long

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

        return operation(left, right); // returning the sum
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

            tree[Node] = operation(tree[2 * Node + 1], tree[2 * Node + 2]); // updating the new sum values
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

int32_t main()
{
    return 0;
}