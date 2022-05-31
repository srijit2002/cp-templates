#define ll long long int
ll binExp(ll base, ll power, ll MOD) {
    ll res = 1;
    while (power) {
        if (power % 2 == 1) {
            res = ((res % MOD) * (base % MOD)) % MOD;
            power--;
        }
        else {
            base = ((base % MOD) * (base % MOD)) % MOD;
            power /= 2;
        }
    }
    return res;
}