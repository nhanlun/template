void dfs(int u) {
    child[u] = 1; // number of nodes in subtree u
    int maxChild = 0;
    for (int v : adj[u]) {
        if (v != parent[u]) {
            parent[v] = u, depth[v] = depth[u] + 1;
            dfs(v);
            child[u] += child[v];
            // save the child with maximum nodes, this helps the number of branches reduce to logn branches
            if (child[v] > maxChild)
                maxChild = child[v], heavy[u] = v; 
        }
    }
}

void decompose(int u, int r) {
    // the head array save the root of the branch
    head[u] = r, pos[u] = ++TIME;
    // the flatten array contains flatten branches and subtree are next to each other
    flatten[TIME] = u;
    tin[u] = TIME; // this is for time in
    if (heavy[u] != -1)
        decompose(heavy[u], h);
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u])
            decompose(v, v);
    }
    tout[v] = cur_pos; // this is for time out
}

void init() {
    TIME = 0;
    dfs(1);
    decompose(1, 1);
}
// example of querying max value from a to b using IT
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}