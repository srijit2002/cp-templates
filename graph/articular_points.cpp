void articular_dfs(vector<vector<ll>> &graph, ll vertice, ll parent, ll&time, vector<ll> &timeofinsertion, vector<ll> &mintimeofinsertion, vector<bool> &visited,vector<bool>&is_articular_point) {
    visited[vertice] = true;
    ll child_count = 0;
    timeofinsertion[vertice] = mintimeofinsertion[vertice] = time++;
    for (auto nbr : graph[vertice]) {
        if (nbr == parent)
            continue;
        if (!visited[nbr]) {
            articular_dfs(graph, nbr, vertice, time, timeofinsertion, mintimeofinsertion, visited,is_articular_point);
            mintimeofinsertion[vertice] = min(mintimeofinsertion[vertice], mintimeofinsertion[nbr]);
            child_count++;
            if(parent!=-1&&mintimeofinsertion[nbr]>=timeofinsertion[vertice]){
                is_articular_point[vertice]=true;
            }
        }
        else{
            mintimeofinsertion[vertice]=min(mintimeofinsertion[vertice],timeofinsertion[nbr]);
        }
    }
    if(parent==-1&&child_count>1){
        is_articular_point[vertice]=true;
    }
}
vector<ll>get_articulation_points(vector<vector<ll>>&graph,ll n){
    vector<ll> tin(n, -1);
    vector<ll> low(n, -1);
    vector<bool> vis(n, false);
    vector<bool> isArticulation(n, false);
    ll timer = 0;
    FOR(i,0,n){
        if (!vis[i]) {
            articular_dfs(graph,i,-1,timer,tin,low,vis,isArticulation);
        }
    }
    vector<ll>ans;
    FOR(i,0,n){
        if(isArticulation[i]){
            ans.emplace_back(i);
        }
    }
    return ans;
}