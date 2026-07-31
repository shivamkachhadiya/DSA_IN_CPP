class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modinv(long long a) {
        return modpow(a, MOD - 2);
    }

    void precompute(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[n] = modinv(fact[n]);
        for (int i = n-1; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    int countValidSequences(int n, int k) {
        precompute(n);

        long long total = nCr(n-1, k-1);

        long long oddSeq = 0;
        if ((n - k) % 2 == 0 && n >= k) {
            int m = (n - k) / 2;
            oddSeq = nCr(m + k - 1, k - 1);
        }

        long long ans = (total - oddSeq + MOD) % MOD;
        return (int)ans;
    }
};
