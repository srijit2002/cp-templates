class DSU {
public:
    vector<long long int> parent, size;
    long long int connected_components;
    DSU(long long int n):connected_components(n) {
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    long long int find_parent(long long int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = find_parent(parent[v]);
    }
    bool Union(long long int a, long long int b) {
        a = find_parent(a);
        b = find_parent(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            connected_components--;
            return true;
        }
        return false;
    }
    bool is_connected(long long int a,long long int b){
        return find_parent(a)==find_parent(b);
    }
};