void dfs(vector<vector<ll>> &graph, ll vertice, vector<bool> &visited) {
    if (visited[vertice])
        return;
    visited[vertice] = true;
    for (auto nbr : graph[vertice]) {
        if (!visited[nbr])
            dfs(graph, nbr, visited);
    }
}