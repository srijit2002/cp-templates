//refer to macro.cpp
class SegmentTree {
    #define size(x) x.size()
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
    SegmentTree(const vector<ll> &init) : data(init) {
        tree.resize(4 * size(init));
        build(1, 0, size(data) - 1);
    }
    ll query(ll left, ll right) {
        return query(1, left, right, 0, size(data) - 1);
    }
    void update(ll index, ll val) {
        update(1, index, 0, size(data) - 1, val);
    }
};