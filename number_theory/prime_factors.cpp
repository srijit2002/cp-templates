/**
   @brief prime factorization using sqrt(N) time 
*/

vector<pair<ll, ll>> get_prime_factors(ll num) {
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            ll count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            ans.emplace_back(pair<ll, ll>{i, count});
        }
    }
    if (num > 1)
        ans.emplace_back(pair<ll, ll>{num, 1});
    return ans;
}
