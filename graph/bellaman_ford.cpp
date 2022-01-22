/*
    Finds sortest path in terms of edge weight from a vertices to another
    vertice with negative edge or returns 2e18 if that path does not exists
*/
ll bellmanFord(vector<vector<ll>>& edges, ll n, ll src, ll dest) {
    vector<ll> weights(n + 1, INF);
    weights[0] = INF;
    weights[src] = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < n; j++) {
            if (weights[edges[j][0]] == INF)
                continue;
            if (weights[edges[j][0]] + edges[j][2] < weights[edges[j][1]]) {
                weights[edges[j][1]] = weights[edges[j][0]] + edges[j][2];
            }
        }
    }
    return *min_element(all(weights));
}