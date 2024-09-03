#include <bits/stdc++.h>

using namespace std;

#define int long long

class ModuloDivision {
  private:
    /////// function to get value of (a*b)%c ///////////
    int multiplyModulo(int a, int b, int c) {
        int result = 0;
        a %= c;
        b %= c;
        while (b) {
            if (b & 0x1) {
                result += a;
                result %= c;
            }
            b >>= 1;
            if (a < c - a) {
                a <<= 1;
            } else {
                a -= (c - a);
            }
        }
        return result;
    }

    // C function for extended Euclidean Algorithm (used to
    // find modular inverse.
    int gcdExtended(int a, int b, int *x, int *y) {
        // Base Case
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }

        int x1, y1; // To store results of recursive call
        int gcd = gcdExtended(b % a, a, &x1, &y1);

        // Update x and y using results of recursive
        // call
        *x = y1 - (b / a) * x1;
        *y = x1;

        return gcd;
    }

    // Function to find modulo inverse of b. It returns
    // -1 when inverse doesn't
    int modInverse(int b, int m) {
        int x, y; // used in extended GCD algorithm
        int g = gcdExtended(b, m, &x, &y);

        // Return -1 if b and m are not co-prime
        if (g != 1)
            return -1;

        // m is added to handle negative x
        return (x % m + m) % m;
    }

  public:
    // Function to compute a/b under modulo m
    int modDivide(int a, int b, int m) {
        a = a % m;
        int inv = modInverse(b, m);
        if (inv == -1)
            return -1;
        else
            return (inv * a) % m;
    }
};

void solve() {}

int32_t main() {
    solve();
    return 0;
}