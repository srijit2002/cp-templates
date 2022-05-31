/**
 * @brief finds diameter of a tree
 * 
 * 
 */
ll diameter=0;
vector<vector<ll>>graph;
ll get_diameter(ll node,ll parent){
    ll height1=-1,height2=-1;
    for(auto &nbr:graph[node]){
        if(nbr==parent)continue;
        ll height=get_diameter(nbr,node);
        if(height>height1){
            height2=height1;
            height1=height;
        }else if(height>height2){
            height2=height;
        }
    }
    diameter=max(diameter,height1+height2+2);
    return height1+1;
}