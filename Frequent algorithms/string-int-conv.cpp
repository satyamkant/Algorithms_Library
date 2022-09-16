#include<bits/stdc++.h>

using namespace std;


//////// function to convert string to integer //////////
int stoi(string s) {
    int num;

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