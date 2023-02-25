// refer to macro.cpp
class SegmentTree {
    ll n;
    vector<ll> tree;
    void build(ll node, ll start, ll end, vector<ll> &data) {
        if (start == end) {
            tree[node] = data[start];
            return;
        }
        ll mid = start + (end - start) / 2;
        build(2 * node, start, mid, data);
        build(2 * node + 1, mid + 1, end, data);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    ll query(ll node, ll left, ll right, ll start, ll end) {
        if (left > end || right < start)
            return 0;
        if (left <= start && right >= end)
            return tree[node];
        ll mid = start + (end - start) / 2;
        return query(2 * node, left, right, start, mid) + query(2 * node + 1, left, right, mid + 1, end);
    }
    void update(ll node, ll index, ll start, ll end, ll val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        ll mid = start + (end - start) / 2;
        if (index <= mid) {
            update(2 * node, index, start, mid, val);
        } else {
            update(2 * node + 1, index, mid + 1, end, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(vector<ll> &data) : n(sz(data)) {
        tree.resize(4 * n);
        build(1, 0, n - 1, data);
    }
    ll query(ll left, ll right) {
        return query(1, left, right, 0, n - 1);
    }
    void update(ll index, ll val) {
        update(1, index, 0, n - 1, val);
    }
};