#include <bits/stdc++.h>

using namespace std;

#define int long long

// number of ways to select R different elements from N different elements
// order is not important


///////////////////////// in this NCR class N and R can be very large but MOD is small //////////////////////////
class NCR {
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
        int power(int a, int b, int m) {
            return binpow(a, b, m);
        }
    };


    int mod = 1000003;
    vector<int> fac;
    vector<int> fac_inv;


    int fermat(int n, int r) {
        n %= mod, r %= mod;
        if (n < r) return 0;
        if (r == 0 || n == r) return 1;
        return (1LL * fac[n] * fac_inv[r] * fac_inv[n - r]) % mod;
    }
    long long lucas(long long n, long long r) {
        if (r == 0) return 1;
        int ni = n % mod, ri = r % mod;
        return (lucas(n / mod, r / mod) * fermat(ni, ri)) % mod;
    }

public:
    NCR() {
        fac.resize(mod);
        fac_inv.resize(mod);

        fac[0] = 1;
        for (int i = 1; i < mod; i++)
            fac[i] = (1LL * fac[i - 1] * i) % mod;

        Modulo_exponentiation modexpo;

        fac_inv[mod - 1] = modexpo.power(fac[mod - 1], mod - 2, mod);
        for (int i = mod - 2; i > 0; i--)
            fac_inv[i] = (1LL * fac_inv[i + 1] * (i + 1)) % mod;
    }

    int get_ncr(int n, int r) {
        return lucas(n, r);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////// in this NCR class N and R must not be very large ////////////////////////////////////
class NCR {
#define p 1000000007

    vector<int> fact;
    vector<int> inv;
    vector<int> invFact;

    void precompute(int n) {
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


    int computeCombinatorics(int n, int r) {
        int ans = (((fact[n] * invFact[r]) % p) * (invFact[n - r] % p)) % p;
        return ans;
    }

public:
    NCR(int n) {
        fact.resize(10001);
        inv.resize(10001);
        invFact.resize(10001);
        precompute(n);
    }

    int get_ncr(int n, int r) {
        return computeCombinatorics(n, r);
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int32_t main() {

    return 0;
}