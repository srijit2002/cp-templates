vector<ll> topological_sort(vector<vector<ll>>&graph,ll n,vector<ll>&visited){
    queue<ll>queue;
    FOR(i,1,n+1){
        if(visited[i]==0)queue.push(i);
    }
    vector<ll>ans;
    while(!queue.empty()){
        ll node=queue.front();
        ans.emplace_back(node);
        queue.pop();
        for(auto nbr:graph[node]){
            if(visited[nbr]==1)queue.push(nbr);
            visited[nbr]--;
        }
    }
    return ans;
}