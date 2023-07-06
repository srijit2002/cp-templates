class SegmentTree {
    int n;
    vector<vector<int>> tree;
    vector<int> merge(vector<int> &a, vector<int> &b) {
        vector<int> vc;
        int i = 0, j = 0;
        while (i < sz(a) and j < sz(b)) {
            if (a[i] < b[j])
                vc.emplace_back(a[i++]);
            else
                vc.emplace_back(b[j++]);
        }
        while (i < sz(a))
            vc.emplace_back(a[i++]);
        while (j < sz(b))
            vc.emplace_back(b[j++]);
        return vc;
    }
    void build(int node, int start, int end, vector<int> &data) {
        if (start == end) {
            tree[node].emplace_back(data[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, data);
        build(2 * node + 1, mid + 1, end, data);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    int find_count(vector<int> &v, int val) {
        int start = 0, end = sz(v) - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] < val) {
                ans = mid;
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return ans + 1;
    }
    int query(int node, int left, int right, int start, int end, int val) {
        if (left > end || right < start)
            return 0;
        if (left <= start && right >= end)
            return find_count(tree[node], val);
        int mid = start + (end - start) / 2;
        return query(2 * node, left, right, start, mid, val) + query(2 * node + 1, left, right, mid + 1, end, val);
    }

public:
    SegmentTree(vector<int> &data) : n(sz(data)) {
        tree.resize(4 * n);
        build(1, 0, n - 1, data);
    }
    int query(int left, int right) {
        return query(1, left, right, 0, n - 1, left);
    }
};