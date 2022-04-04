#define ll long long int
#define FOR(index, lower, upper) for (ll index = lower; index < upper; index++)




ll power(ll x,ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}


ll modInverse(ll n,ll p) {
    return power(n, p - 2, p);
}
/**
 * @brief returns nCr % p using fermat's little theorem
 * 
 * @param n 
 * @param r 
 * @param p 
 * @return ll 
 */
ll nCrModPFermat(ll n, ll r, ll p) {
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