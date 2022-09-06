/**
 * @brief 
 * 
 * @param a The input array which need to be compressed
 */
void compress_coordinate(vector<ll> &a) {
    vector<ll> sorted(a);
    sort(all(sorted));
    pmap<ll, ll> mp;
    ll idx = 1;
    for (auto &e : sorted) {
        if (!containsKey(mp, e)) {
            mp[e] = idx++;
        }
    }
    FOR(i, 0, size(a)) {
        a[i] = mp[a[i]];
    }
}