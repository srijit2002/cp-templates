#define ld long double
ld ternary_search(ll l, ll r) {
    ll ans = 0;
    while (l <= r) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ld f1 = f(m1);
        ld f2 = f(m2);
        if (f1 < f2) {
            ans=l;
            r = m2 - 1;
        } else {
            ans=r;
            l = m1 + 1;
        }
    }
    // cout<<l<<endl;
    return f(ans);
}