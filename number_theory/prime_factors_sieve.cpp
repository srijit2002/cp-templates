/**
    @brief sieve function for getting  prime factorization in o(nloglogn)
*/
vector<ll> sieve_prime_factor;
void sieve_prime(ll MAXN = 1e7) {
    sieve_prime_factor = vector<ll>(MAXN + 1);
    sieve_prime_factor[1] = 1;
    for (ll i = 2; i <= MAXN; i++) {
        sieve_prime_factor[i] = i;
    }
    for (ll i = 4; i <= MAXN; i += 2) {
        sieve_prime_factor[i] = 2;
    }
    for (ll i = 3; i * i <= MAXN; i++) {
        if (sieve_prime_factor[i] == i) {
            for (ll j = i * i; j <= MAXN; j += i)
                if (sieve_prime_factor[j] == j)
                    sieve_prime_factor[j] = i;
        }
    }
}
/**
 * @brief A O(log n) function returning primefactorization
   by dividing by smallest prime factor at every step
*/
vector<ll> get_factorization(ll x) {
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(sieve_prime_factor[x]);
        x = x / sieve_prime_factor[x];
    }
    return ret;
}