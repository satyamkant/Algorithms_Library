class StringHashing {
  private:
    const int MOD = 1000000007;
    int hashs[300005], pows[300005];
    int p = 331;

  public:
    StringHashing() {

        pows[0] = 1;
        for (int i = 1; i < 300005; i++) {
            pows[i] = (pows[i - 1] * p) % MOD;
        }
    }

    void init(string s, int n) {
        for (int i = 0; i < n; i++) {
            hashs[i + 1] = (hashs[i] * p + s[i]) % MOD;
        }
    }
    int getHash(int l, int r) {
        return ((hashs[r + 1] - (hashs[l] * pows[r - l + 1]) % MOD) + MOD) %
               MOD;
    }
};

StringHashing sth;
