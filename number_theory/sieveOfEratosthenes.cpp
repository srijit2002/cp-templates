#include <vector>
#define ll long long int
using namespace std;
vector<bool> prime;
void SieveOfEratosthenes(ll n) {
    prime.resize(n+1,false);
    prime[0] = false;
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}