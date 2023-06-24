class TreeProcesssor {
    vector<ll> depth;
    vector<vector<ll>> ancestor;
    const ll MAXN = 20;
    void dfs(ll node, ll parent, ll curDepth, vector<vector<ll>> &graph) {
        depth[node] = curDepth;
        for (auto &nbr : graph[node]) {
            if (nbr == parent)
                continue;
            dfs(nbr, node, curDepth + 1, graph);
        }
    }
    void precalculate() {
        FOR(i, 1, MAXN) {
            FOR(j, 0, sz(ancestor[i])) {
                ll ancest = ancestor[i - 1][j];
                if (ancest != -1) {
                    ancest = ancestor[i - 1][ancest];
                }
                ancestor[i][j] = ancest;
            }
        }
    }

public:
    TreeProcesssor(vector<ll> &parent) {
        ll n = sz(parent);
        vector<vector<ll>> graph(n);
        FOR(i, 0, n) {
            if (parent[i] == -1)
                continue;
            graph[i].emplace_back(parent[i]);
            graph[parent[i]].emplace_back(i);
        }
        depth.resize(n);
        dfs(0, -1, 0, graph);
        ancestor = vector<vector<ll>>(MAXN, vector<ll>(n, 0));
        ancestor[0] = parent;
        precalculate();
    }
    ll get_ancestor(ll node, ll k) {
        ll ans = node;
        FOR(b, 0, MAXN) {
            if ((k & (1ll << b))) {
                ans = ancestor[b][ans];
            }
            if (ans == -1)
                break;
        }
        return ans;
    }
    ll get_lca(ll u, ll v) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        v = get_ancestor(v, depth[v] - depth[u]);
        if (u == v)
            return u;
        FORD(i, MAXN - 1, -1) {
            ll pu = get_ancestor(u, 1ll<<i);
            ll pv = get_ancestor(v, 1ll<<i);
            if (pu != pv) {
                u = pu;
                v = pv;
            }
        }
        return ancestor[0][u];
    }
};