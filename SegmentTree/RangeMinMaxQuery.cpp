class SegmentTree {
    ll n;
    vector<pair<ll, ll>> tree;
    void build(ll node, ll start, ll end, const vector<ll> &data) {
        if (start == end) {
            tree[node].first = data[start];
            tree[node].second = data[start];
            return;
        }
        ll mid = start + (end - start) / 2;
        build(2 * node, start, mid, data);
        build(2 * node + 1, mid + 1, end, data);
        tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
        tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
    }
    ll maxquery(ll node, ll left, ll right, ll start, ll end) {
        if (left > end || right < start)
            return INT_MIN;
        if (left <= start && right >= end)
            return tree[node].second;
        ll mid = start + (end - start) / 2;
        return max(maxquery(2 * node, left, right, start, mid), maxquery(2 * node + 1, left, right, mid + 1, end));
    }
    ll minquery(ll node, ll left, ll right, ll start, ll end) {
        if (left > end || right < start)
            return INT_MAX;
        if (left <= start && right >= end)
            return tree[node].first;
        ll mid = start + (end - start) / 2;
        return min(minquery(2 * node, left, right, start, mid), minquery(2 * node + 1, left, right, mid + 1, end));
    }

public:
    SegmentTree(const vector<ll> &data) : n(sz(data)) {
        tree.resize(4 * sz(data));
        build(1, 0, n - 1, data);
    }
    ll minquery(ll left, ll right) {
        return minquery(1, left, right, 0, n - 1);
    }
    ll maxquery(ll left, ll right) {
        return maxquery(1, left, right, 0, n - 1);
    }
};