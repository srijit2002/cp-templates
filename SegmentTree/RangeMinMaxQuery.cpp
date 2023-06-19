class SegmentTree {
    int n;
    vector<pair<int, int>> tree;
    void build(int node, int start, int end, const vector<int> &data) {
        if (start == end) {
            tree[node].first = data[start];
            tree[node].second = data[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, data);
        build(2 * node + 1, mid + 1, end, data);
        tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
        tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
    }
    int maxquery(int node, int left, int right, int start, int end) {
        if (left > end || right < start)
            return INT_MIN;
        if (left <= start && right >= end)
            return tree[node].second;
        int mid = start + (end - start) / 2;
        return max(maxquery(2 * node, left, right, start, mid), maxquery(2 * node + 1, left, right, mid + 1, end));
    }
    int minquery(int node, int left, int right, int start, int end) {
        if (left > end || right < start)
            return INT_MAX;
        if (left <= start && right >= end)
            return tree[node].first;
        int mid = start + (end - start) / 2;
        return min(minquery(2 * node, left, right, start, mid), minquery(2 * node + 1, left, right, mid + 1, end));
    }
    void update(int node,int start,int end,int index,int v){
        if(start==end){
            tree[node].first=v;
            tree[node].second=tree[node].first;
            return;
        }
        int mid=start+(end-start)/2;
        if(index<=mid){
            update(2*node,start,mid,index,v);
        }else{
            update(2*node+1,mid+1,end,index,v);
        }
        tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
        tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
    }
public:
    SegmentTree(const vector<int> &data) : n(sz(data)) {
        tree.resize(4 * sz(data));
        build(1, 0, n - 1, data);
    }
    int minquery(int left, int right) {
        return minquery(1, left, right, 0, n - 1);
    }
    int maxquery(int left, int right) {
        return maxquery(1, left, right, 0, n - 1);
    }
    void update(int index,int v){
        update(1,0,n-1,index,v);
    }
};