class Edge {
public:
    ll nbr;
    ll wgt;
};

ll dijkstra(vector<vector<Edge>>&graph,ll src,ll dest){
    auto compare = [](Edge &x, Edge &y) { return x.wgt > y.wgt; };
    priority_queue<Edge, vector<Edge>, decltype(compare)> pq(compare);
    Edge e1;
    e1.nbr=src;
    e1.wgt=0;

    pq.push(e1);
    vector<bool>visited(dest+1,false);
    while(!pq.empty()){
       Edge e=pq.top();
       pq.pop();
       if(visited[e.nbr])continue;
       visited[e.nbr]=true;
       if(e.nbr==dest)return e.wgt;
       for(auto &child:graph[e.nbr]){
           if(visited[child.nbr])continue;
           Edge ne;
           ne.nbr=child.nbr;
           ne.wgt=child.wgt+e.wgt;
           pq.push(ne);
       }
    }
    return -1;
}