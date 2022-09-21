// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

// link:- https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
// link:- https://codeforces.com/problemset/problem/1722/E

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

    int get_sum(int x1, int y1, int x2, int y2) {
        return  sum[x1][y1] - sum[x2][y1] - sum[x1][y2] + sum[x2][y2];
    }
};

int32_t main()
{
    return 0;
}