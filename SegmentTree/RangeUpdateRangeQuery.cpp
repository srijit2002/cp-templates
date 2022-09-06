class SegmentTree {
    ll n;
    vector<ll> lazy;
    vector<ll> tree;

    ll query(ll node, ll start, ll end, ll left, ll right) {
        propagate(node, start, end);
        if (end < left || right < start)
            return 0;
        if (left <= start && right >= end)
            return tree[node];
        ll mid = start + (end - start) / 2;
        return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
    }
    void propagate(ll node, ll start, ll end) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(ll node, ll start, ll end, ll left, ll right, ll val) {
        propagate(node, start, end);
        if (end < left || right < start)
            return;
        if (start >= left && end <= right) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        ll mid = start + (end - start) / 2;
        update(2 * node, start, mid, left, right, val);
        update(2 * node + 1, mid + 1, end, left, right, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

public:
    SegmentTree(ll _n) :n(_n) {
        lazy.resize(4 * n);
        tree.resize(4 * n);
    }
    ll query(ll left, ll right) {
        return query(1, 0, n - 1, left, right);
    }
    void update(ll left, ll right, ll val) {
        update(1, 0, n - 1, left, right, val);
    }
};