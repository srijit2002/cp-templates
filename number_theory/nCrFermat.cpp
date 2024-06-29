#define ll long long int
#define FOR(index, lower, upper) for (ll index = lower; index < upper; index++)

ll binExp(ll base, ll power, ll MOD) {
    ll res = 1 % MOD;
    while (power) {
        if ((power % 2) == 1) {
            res = ((res % MOD) * (base % MOD)) % MOD;
            power--;
        } else {
            base = ((base % MOD) * (base % MOD)) % MOD;
            power /= 2;
        }
    }
    return res;
}

ll modInverse(ll n, ll p) {
    return binExp(n, p - 2, p);
}
/**
 * @brief returns nCr % p using fermat's little theorem
 *
 * @param n
 * @param r
 * @param p
 * @return ll
 */
ll NCR(ll n, ll r, ll p) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    FOR(i, 1, n + 1) {
        fac[i] = (fac[i - 1] * i) % p;
    }

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}