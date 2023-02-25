/**
    @brief sieve function for getting  prime factorization in o(nloglogn)
*/
const int N=1e7+1;
int sieve_prime_factor[N];

void sieve_prime(int MAXN = 1e7) {
    sieve_prime_factor[1] = 1ll;
    for (int i = 2; i <= MAXN; i++) {
        sieve_prime_factor[i] = i;
    }
    for (int i = 4; i <= MAXN; i += 2) {
        sieve_prime_factor[i] = 2;
    }
    for (int i = 3; i * i <= MAXN; i++) {
        if (sieve_prime_factor[i] == i) {
            for (int j = i * i; j <= MAXN; j += i)
                if (sieve_prime_factor[j] == j)
                    sieve_prime_factor[j] = i;
        }
    }
}
/**
 * @brief A O(log n) function returning primefactorization
   by dividing by smallest prime factor at every step
*/
vector<pair<int,int>> get_factorization(int x) {
    vector<pair<int,int>> ret;
    while (x != 1) {
        if (ret.empty() or ret.back().first != sieve_prime_factor[x]) {
            ret.emplace_back(make_pair(sieve_prime_factor[x], 1));
        } else {
            ret.back().second++;
        }
        x = x / sieve_prime_factor[x];
    }
    return ret;
}