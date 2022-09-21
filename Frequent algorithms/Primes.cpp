#include <bits/stdc++.h>

using namespace std;

#define int long long

class PrimFactors {
    vector<int> get_factors(int n) {
        vector<int> arr;
        while (n % 2 == 0)
        {
            arr.push_back(2);
            n = n / 2;
        }

        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                arr.push_back(i);
                n = n / i;
            }
        }
        if (n > 2)
            arr.push_back(n);

        return arr;
    }
public:
    vector<int> calculate(int n) {
        return get_factors(n);
    }
};

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