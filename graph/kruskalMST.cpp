//usecode of DSU.cpp
bool sortEdges(vector<ll>&edge1,vector<ll>&edge2){
    return edge1[2]<edge2[2];
}
ll kruskalMST(vector<vector<ll>> &edges, ll n) {
    sort(all(edges), sortEdges);
    vector<ll> parent(n + 1);
    vector<ll> size(n + 1);
    for (ll i = 1; i <= n; i++) {
        make_DSU(i, parent, size);
    }
    ll total = 0;
    for (auto &edge : edges) {
        if (find_DSU(edge[0], parent) == find_DSU(edge[1], parent))
            continue;
        total += edge[2];
        Union_DSU(edge[0], edge[1], parent, size);
    }
    return total;
}