// https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
// https://codeforces.com/problemset/problem/1722/E

// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

class Pref_suff_2d {
    int sum[1001][1001];
public:
    void build(int n, int m, vector<vector<int>>& arr) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i - 1][j - 1];
            }
        }
    }

    int get_sum(int u, int v, int i, int j) {
        return  sum[u][v] - sum[i][v] - sum[u][j] + sum[i][j];
    }
};

int32_t main()
{
    return 0;
}