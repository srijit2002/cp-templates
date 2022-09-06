ll powll(ll base, ll power) {
    ll res = 1;
    while (power) {
        if (power % 2 == 1) {
            res = res* base ;
            power--;
        }
        else {
            base = base * base;
            power /= 2;
        }
    }
    return res;
}