ll binExp(ll a, ll n, ll d) {
    ll res = 1;

    while (n) {
        if (n % 2 == 1) {
            res = ((res % d) * (a % d)) % d;
            n--;
        }

        else {
            a = ((a % d) * (a % d)) % d;
            n /= 2;
        }
    }

    return res;
}