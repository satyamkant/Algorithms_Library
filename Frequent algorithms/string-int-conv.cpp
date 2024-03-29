// Author:- satyam kant//

#include<bits/stdc++.h>

using namespace std;

///////// function to convert string to integer with modulo ///////////
int Stoimod(string num, int mod)
{
    // Initialize result
    int res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % mod;
 
    return res;
}


//////// function to convert string to integer //////////
int Stoi(string s) {
    int num = 0;

    stringstream temp(s);
    temp >> num;

    return num;

}

//////// function to convert integer to string /////////
string itos(int n) {
    if (n == 0)
        return "0";
    string s = "";
    bool neg = false;
    if (n < 0) {
        neg ^= 1;
        n = -n;
    }

    while (n) {
        s += ('0' + n % 10);
        n /= 10;
    }
    if (neg)
        s += '-';
    reverse(s.begin(), s.end());

    return s;
}

int main() {

    return 0;

}