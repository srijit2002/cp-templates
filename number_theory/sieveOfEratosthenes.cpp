class Sieve {
    vector<int> sieve; // isPrime or not
    int n;
public:
    Sieve(int _n) : n(_n) {
        sieve = vector<int>(n + 1, true); // is prime or not
        sieve[0] = sieve[1] = false;
        for (int i = 2; i <= n; i++) {
            if (sieve[i]) {
                for (int j = i + i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
    bool isPrime(int v){
        return sieve[v];        
    }
};