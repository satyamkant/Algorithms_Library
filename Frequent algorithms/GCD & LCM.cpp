// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

///// gcd(x,x+y) = gcd(x,y) /////
///// gcd(x,x-y) = gcd(x,y) /////

class LCM {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

public:
    int __lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};

int32_t main() {
    return 0;
}
