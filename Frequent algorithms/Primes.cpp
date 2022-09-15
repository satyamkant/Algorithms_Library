#include <bits/stdc++.h>

using namespace std;

#define int long long

void primeFactors(int n)
{

    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2)
        cout << n << " ";
}


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