
// Credits : codeforces user 'BROBAT'
// Tested on : https://judge.yosupo.jp/problem/lca
struct LCA {
    int n, l, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    LCA (vector<vector<int>> _adj, int root) : adj(_adj) {
        n = (int) adj.size();
        l = (int) ceil(log2(n)) + 1;
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(l));
        dfs(root, root, 0);
    }
    void dfs (int node, int prev, int d) {
        tin[node] = ++timer;
        up[node][0] = prev;
        depth[node] = d;
        for(int i = 1; i < l; i++) { up[node][i] = up[up[node][i - 1]][i - 1]; }
        for(auto next : adj[node]) { if(next != prev) dfs(next, node, d + 1); }
        tout[node] = ++timer;
    }
    bool is_ancestor (int x, int y) { return tin[x] <= tin[y] && tout[x] >= tout[y]; }
    int query (int u, int v) {
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i = l - 1; i >= 0; i--) { if(!is_ancestor(up[u][i], v)) u = up[u][i]; }
        return up[u][0];
    }
    int jump (int x, int k) {
        for(int i = l - 1; i >= 0; i--) if((k>>i) & 1) x = up[x][i];
        return x;
    }
    int parent (int x) {
        return up[x][0];
    }
    int distance (int x, int y) {
        int z = query(x, y);
        return depth[x] + depth[y] - 2 * depth[z];
    }
};
