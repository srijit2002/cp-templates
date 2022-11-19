struct Node {
    ll total_sum, max_sum, prefix_sum, suffix_sum;
    Node(ll v = 0) : total_sum(v), max_sum(v), prefix_sum(v), suffix_sum(v) {}
    Node(ll ts, ll ms, ll ps, ll ss) : total_sum(ts), max_sum(ms), prefix_sum(ps), suffix_sum(ss) {
    }
};

const int N = 1e6+5;
Node segtree[N];
ll vc[N];

void build(ll node, ll start, ll end) {
    if (start == end) {
        segtree[node] = Node(vc[start]);
        return;
    }
    ll mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    Node cnode = Node();
    cnode.total_sum=segtree[2*node].total_sum+segtree[2*node+1].total_sum;
    cnode.max_sum = max({segtree[2 * node].max_sum, segtree[2 * node + 1].max_sum, segtree[2 * node].suffix_sum + segtree[2 * node + 1].prefix_sum,cnode.total_sum});
    cnode.prefix_sum=max(segtree[2*node].prefix_sum,segtree[2*node].total_sum+segtree[2*node+1].prefix_sum);
    cnode.suffix_sum=max(segtree[2*node+1].suffix_sum,segtree[2*node+1].total_sum+segtree[2*node].suffix_sum);
    segtree[node]=cnode;
}

Node query(ll node,ll start,ll end,ll left,ll right){
    if(start>right||end<left)return Node(0);
    if(left<=start&&right>=end)return segtree[node];
    ll mid=start+(end-start)/2;
    auto leftv=query(2*node,start,mid,left,right);
    auto rightv=query(2*node+1,mid+1,end,left,right);
    Node cnode = Node();
    cnode.total_sum=leftv.total_sum+rightv.total_sum;
    cnode.max_sum = max({leftv.max_sum, rightv.max_sum, leftv.suffix_sum + rightv.prefix_sum,cnode.total_sum});
    cnode.prefix_sum=max(leftv.prefix_sum,leftv.total_sum+rightv.prefix_sum);
    cnode.suffix_sum=max(rightv.suffix_sum,rightv.total_sum+leftv.suffix_sum);
    return cnode;
}