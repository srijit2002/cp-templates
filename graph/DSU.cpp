class DSU {
public:
    vector<ll> parent, size;
    DSU(ll n) {
        parent.resize(n);
        size.resize(n);
        FOR(i, 0, n) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    ll find_parent(ll v) {
        if (parent[v] == v)
            return v;
        return parent[v] = find_parent(parent[v]);
    }
    void Union(ll a, ll b) {
        a = find_parent(a);
        b = find_parent(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};