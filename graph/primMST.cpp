class Edge {
public:
    ll nbr;
    ll wgt;
};
ll getMST(vector<vector<ll>> &gp, ll n) {
    vector<vector<Edge>> graph(n + 1);
    for (auto edge : gp) {
        ll u = edge[0];
        ll v = edge[1];
        ll w = edge[2];
        Edge edge1;
        edge1.nbr = v;
        edge1.wgt = w;
        Edge edge2;
        edge2.nbr = u;
        edge2.wgt = w;
        vector<Edge> &prev1 = graph[u];
        prev1.emplace_back(edge1);
        vector<Edge> &prev2 = graph[v];
        prev2.emplace_back(edge2);
    }
    auto compare = [](Edge &x, Edge &y) { return x.wgt < y.wgt; };
    priority_queue<Edge, vector<Edge>, decltype(compare)> pq(compare);
    Edge de;
    de.wgt = 0;
    de.nbr = 1;
    pq.push(de);
    ll ans = 0;
    vector<ll> visited(n + 1, false);
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        if (visited[edge.nbr])
            continue;
        visited[edge.nbr] = true;
        ans += edge.wgt;
        for (Edge ed : graph[edge.nbr]) {
            if (visited[ed.nbr])
                continue;
            pq.push(ed);
        }
    }
    return ans;
}