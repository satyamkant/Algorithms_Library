#include <bits/stdc++.h>

using namespace std;

#define int long long

class Sieve {
    vector <bool> isPrime;
public:
    Sieve(int n = 1000006) {
        isPrime.resize(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i] && i * i <= n) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
    }

    bool check_prime(int id) {
        return isPrime[id];
    }
};

int32_t main() {
    return 0;
}