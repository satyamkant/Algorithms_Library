#include <bits/stdc++.h>

using namespace std;

#define int long long 

class Modulo_exponentiation {
    int binpow(int a, int b, int m) {
        a %= m;
        int res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
public:
    int power(int a, int b, int m = 1e9 + 7) {
        return binpow(a, b, m);
    }
};

int32_t main() {
    return 0;
}