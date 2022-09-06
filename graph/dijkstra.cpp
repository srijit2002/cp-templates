
#define ll long long int
using namespace std;
class Edge {
public:
    ll vertex;
    ll wgt;
};

ll dijkstra(vector<vector<Edge>>&graph,ll src,ll dest){
    auto compare = [](Edge &x, Edge &y) { return x.wgt > y.wgt; };
    priority_queue<Edge, vector<Edge>, decltype(compare)> pq(compare);
    Edge e1;
    e1.vertex=src;
    e1.wgt=0;

    pq.push(e1);
    vector<bool>visited(dest+1,false);
    while(!pq.empty()){
       Edge e=pq.top();
       pq.pop();
       if(visited[e.vertex])continue;
       visited[e.vertex]=true;
       if(e.vertex==dest)return e.wgt;
       for(auto &child:graph[e.vertex]){
           if(visited[child.vertex])continue;
           Edge ne;
           ne.vertex=child.vertex;
           ne.wgt=child.wgt+e.wgt;
           pq.push(ne);
       }
    }
    return -1;
}