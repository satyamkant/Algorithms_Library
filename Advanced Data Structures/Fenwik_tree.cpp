// Author:- satyam kant//

#include <bits/stdc++.h>
///////////////////////!!!!!!!!!!!!!!!!///////////////////////////
using namespace std;

#define int long long 

class Fenwick {
    vector<int> bit;
    int N;

    int operation(int a, int b) {
        // you can't do minimum or maximum range query only [0,r] can be done in this case
        return a + b;
    }

    void build(vector<int>& arr, int N)
    {
        this->N = N;
        bit.assign(N, 0);
        for (int i = 0; i < arr.size(); i++)
            do_operation(i, arr[i]);
    }

    int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = operation(ret, bit[r]);
        return ret;
    }

    void do_operation(int idx, int val) {
        for (; idx < N; idx = idx | (idx + 1))
            bit[idx] = operation(bit[idx], val);
    }

public:
    void construct(vector<int>& arr) {
        build(arr, arr.size());
    }

    int get_query(int l, int r) {
        return query(r) - query(l - 1);
    }

};

int32_t main() {
    return 0;
}