
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


//credits : cp-algorithms
// int lg;
// int timer;
// vector<vector<int>> adj;
// vector<vector<int>> up;  // up[a][b] = (2^b)th parent of node a
// vector<int> tin, tout;
// vector<int> depth;

// // initialise in main as :
// // adj = vector<vector<int>> (n + 5);
// // up = vector<vector<int>> (n + 5, vector<int>(24));
// // tin = vector<int> (n + 5);
// // tout = vector<int> (n + 5);
// // depth = vector<int> (n + 5);

// void dfs (int v, int p) {
//     tin[v] = ++timer;
//     up[v][0] = p;  // 1st parent is parent lol
//     for (int i = 1; i <= lg; ++i) {
//       up[v][i] = up[up[v][i-1]][i-1];
//     } 
//     for (int u : adj[v]) {
//       if (u == p) continue;
//       depth[u] = 1 + depth[v];
//       dfs(u, v);
//     }
//     tout[v] = ++timer;
// }

// bool is_ancestor (int u, int v) {   // is 'u' an ancestor of 'v' ?
//    return tin[u] <= tin[v] && tout[u] >= tout[v];
// }

// int lca (int u, int v) {
//    if (is_ancestor(u, v)) return u;
//    if (is_ancestor(v, u)) return v;
//    for (int i = lg; i >= 0; --i) {
//       if (!is_ancestor(up[u][i], v)) {
//             u = up[u][i];
//       }
//    }
//    return up[u][0];
// }

// int kth_parent (int node, int k) {
//    if (k == 0) return node;
//    int log_val = log2(k);
//    int max_power = (1 << log_val);
//    return kth_parent(up[node][log_val], k - max_power);
// }

// void preprocess(int root) {
//     lg = 21;   // lg = ceil(log2(n)) approx
//     timer = 0;
//     depth[root] = 0;
//     dfs(root, root);
// }
