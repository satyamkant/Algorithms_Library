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

    return 0;
}