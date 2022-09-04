#include <bits/stdc++.h>

using namespace std;

#define int long long

// number of ways to select R different elements from N different elements
// ordere is not important
#define p 1000000007

class NCR {

    typedef long long ll;
    int n = 100000;
    int r = 500;

    ll* fact = new ll[n]();
    ll* inv = new ll[n]();
    ll* invFact = new ll[n]();

    void precompute() {
        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % p;
        }

        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            inv[i] = ((p - (p / i)) * inv[p % i]) % p;
        }

        invFact[0] = invFact[1] = 1;

        for (int i = 2; i <= n; i++) {
            invFact[i] = (invFact[i - 1] * inv[i]) % p;
        }
    }


    ll computeCombinatorics(ll N, ll R) {
        ll ans = (((fact[N] * invFact[R]) % p) * (invFact[N - R] % p)) % p;
        return ans;
    }

public:
    NCR() {
        precompute();
    }

    int get_ncr(ll n, ll r) {
        return computeCombinatorics(n, r);
    }
};

int32_t main() {
    return 0;
}