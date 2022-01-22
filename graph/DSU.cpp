void make_DSU(ll v, vector<ll> &parent, vector<ll> &size) {
    parent[v] = v;
    size[v] = 1;
}
ll find_DSU(ll v, vector<ll> &parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = find_DSU(parent[v], parent);
}
void Union_DSU(ll a, ll b, vector<ll> &parent, vector<ll> &size) {
    a = find_DSU(a, parent);
    b = find_DSU(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}