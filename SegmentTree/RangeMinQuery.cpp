//refer to macro.cpp for macros used
class SegmentTree {
    vector<ll> data;
    vector<ll> tree;
    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = data[start];
            return;
        }
        ll mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
    }
    ll query(ll node, ll left, ll right, ll start, ll end) {
        if (left > end || right < start)
            return LONG_MAX;
        if (left <= start && right >= end)
            return tree[node];
        ll mid = start + (end - start) / 2;
        return max(query(2 * node, left, right, start, mid) , query(2 * node + 1, left, right, mid + 1, end));
    }


public:
    SegmentTree(const vector<ll> &init) : data(init) {
        tree.resize(4 * size(init));
        build(1, 0, size(data) - 1);
    }
    ll query(ll left, ll right) {
        return query(1, left, right, 0, size(data) - 1);
    }
};