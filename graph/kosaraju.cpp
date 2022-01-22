void kosaraju_dfs(vector<vector<ll>> &graph, ll vertice, stack<ll> &st, vector<bool> &visited) {
    if (visited[vertice])
        return;
    visited[vertice] = true;
    for (auto nbr : graph[vertice]) {
        kosaraju_dfs(graph, nbr, st, visited);
    }
    st.push(vertice);
}
void dfs(vector<vector<ll>> &graph, ll vertice, vector<bool> &visited) {
    if (visited[vertice])
        return;
    visited[vertice] = true;
    for (auto nbr : graph[vertice]) {
        if (!visited[nbr])
            dfs(graph, nbr, visited);
    }
}
/* 
   Kosarju algorithm to find strongly connected
   components in a directed graph
*/
ll kosaraju(vector<vector<ll>> &graph, vector<vector<ll>> &reverse_graph, ll n) {
    vector<bool> visited(n + 1, false);
    stack<ll> st;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i])
            kosaraju_dfs(graph, i, st, visited);
    }
    ll connected_components = 0;
    visited = vector<bool>(n + 1, false);
    while (!st.empty()) {
        ll vertice = st.top();
        st.pop();
        if (visited[vertice])
            continue;
        dfs(reverse_graph, vertice, visited);
        connected_components++;
    }
    return connected_components;
}