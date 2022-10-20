/**
 * @brief 
 * 
 * @param a The input array which needs to be compressed
 */
void compress_coordinate(vector<ll> &a,pmap<ll, ll>& mp) {
    vector<ll> sorted(a);
    sort(all(sorted));
    ll idx = 1;
    for (auto &e : sorted) {
        if (!containsKey(mp, e)) {
            mp[e] = idx++;
        }
    }
    FOR(i, 0, sz(a)) {
        a[i] = mp[a[i]];
    }
}