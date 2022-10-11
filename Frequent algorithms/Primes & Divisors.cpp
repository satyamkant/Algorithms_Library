// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

// to get the divisors of a number ///////
class Divisors {
    vector<int> divisor(int n) {
        vector<int> arr;
        for (int i = 1;i * i <= n;i++) {
            if (n % i == 0) {
                arr.push_back(i);
                if (n / i != i) {
                    arr.push_back(n / i);
                }
            }
        }
        return arr;
    }
public:
    vector<int> get_divisor(int n) {
        return divisor(n);
    }
};

// to precalculate divisors (factors) of numbers from 1 to 100000 //////
class precal_div {
    vector<int> divisor[100001];
    void prec() {
        divisor[1].push_back(1);
        for (int i = 2;i <= 100000;i++) {
            for (int j = i;j <= 100000;j += i) {
                divisor[j].push_back(i);
            }
        }
    }

public:
    precal_div() {
        prec();
    };

    vector<int>& get_fact(int id) {
        return divisor[id];
    }
};
/////////////////////////////////////////////////////////////

//// class to get primeFactors of a number ///////////////////
class PrimFactors {
    vector<int> get_factors(int n) {
        vector<int> arr;
        for (int x = 2; x * x <= n; x++) {
            while (n % x == 0) {
                arr.push_back(x);
                n /= x;
            }
        }
        if (n > 1) arr.push_back(n);
        return arr;
    }
public:
    vector<int> calculate(int n) {
        return get_factors(n);
    }
};
////////////////////////////////////////////////

//////// Sieve of Eratosthenes ////////////////
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
/////////////////////////////////////////////////

int32_t main() {
    return 0;
}