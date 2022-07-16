// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

struct comp
{
    bool operator()(/*take the argument here ex:- int a,int b*/) //////// add const here if not working /////////
    {
        /////// write the code here /////////////
        /*
        return a>b;
        */
        /////////////////////////////////////////
    }
};

void solve()
{
    /*
    ////////////// Notice the comp in both these declaration ////////////


    priority_queue<type,vector<type>,comp> pq;


    vector<type> arr;


    sort(arr.begin(),arr.end(),comp());
    */
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