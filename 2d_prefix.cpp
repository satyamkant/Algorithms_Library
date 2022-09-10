// https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
// https://codeforces.com/problemset/problem/1722/E

// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

int grid[1001][1001];

void solve()
{
    int n, q;
    cin >> n >> q;

    memset(grid, 0, sizeof(grid));

    while (n--) {
        int i, j;
        cin >> i >> j;
        grid[i][j] += i * j;
    }

    for (int i = 1;i < 1001;i++) {
        for (int j = 1;j < 1001;j++) {
            grid[i][j] += grid[i][j - 1];
        }
    }

    for (int j = 1;j < 1001;j++) {
        for (int i = 1;i < 1001;i++) {
            grid[i][j] += grid[i - 1][j];
        }
    }

    while (q--) {
        int a, b, A, B;

        cin >> a >> b >> A >> B;
        a++;
        b++;
        A--;
        B--;
        cout << grid[A][B] - grid[a - 1][B] - grid[A][b - 1] + grid[a - 1][b - 1] << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // test case...;
    int t = 1;
    cin >> t;
    // test case end...;
    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}