#include <bits/stdc++.h>

using namespace std;

#define int long long 

class Fenwick {
    vector<int> bit;
    int N;

    void build(vector<int>& arr, int N)
    {
        this->N = N;
        bit.assign(N, 0);
        for (int i = 0; i < arr.size(); i++)
            add(i, arr[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < N; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

public:
    void construct(vector<int>& arr) {
        build(arr, arr.size());
    }
};

int32_t main() {
    return 0;
}