// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {

    int bits[32];
    int curr = 1020293;
    // storing the bits of the number curr ///
    for (int i = 0;i < 32;i++) {
        bits[i] = ((curr >> i) & 1);
    }

    // setting and unsetting ith bit /////////
    for (int i = 0;i < 32;i++) {
        curr |= (1 << i);
        curr &= ~(1 << i);
    }

    // represent a number as power of k //
    /// a number can be represented as num = c1*k^0 + c2*k^1 + c3*k^2 + .... ///////
    ////////////////////////////////////// here c1,c2,c3 can be 0 also /////////////
    int n,k;
    while (n) {
        cout << n % k << " ";
        n /= k;
    }

    return 0;
}