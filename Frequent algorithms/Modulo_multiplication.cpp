// Author:- satyam kant//

#include<bits/stdc++.h>

using namespace std;

/////// function to get value of (a*b)%c ///////////
int multiplyModulo(int a, int b, int c)
{
    int result = 0;
    a %= c;
    b %= c;
    while(b) {
        if(b & 0x1) {
            result += a;
            result %= c;
        }
        b >>= 1;
        if(a < c - a) {
            a <<= 1;
        } else {
            a -= (c - a);
        }
    }
    return result;
}

int main() {

    return 0;

}