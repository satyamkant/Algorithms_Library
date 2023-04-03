// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

class Diameter_of_tree {
    /////////////// 0 based indexing /////////////////
    vector<int> dist;
    vector<int> vis;
    void dfs(vector<int> adj[], int node, int curr_dist) {
        vis[node] = 1;
        dist[node] = curr_dist;
        for (auto &it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, it, curr_dist + 1);
            }
        }
    }

  public:
    pair<int, pair<int, int>> get_dia(vector<int> adj[], int n) {
        vis = vector<int>(n, 0);
        dist = vector<int>(n, 0);
        dfs(adj, 0, 0);
        int node1 = -1;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (mx < dist[i]) {
                mx = dist[i];
                node1 = i;
            }
        }

        vis.assign(n, 0);
        dist.assign(n, 0);
        dfs(adj, node1, 0);
        int node2 = -1;
        mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (mx < dist[i]) {
                mx = dist[i];
                node2 = i;
            }
        }

        return {mx,
                {node1, node2}}; //// diameter, end points of the diameter ////
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // test case...;
    int t = 1;
    //   cin >> t;
    // test case end...;
    for (int i = 1; i <= t; i++) {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
