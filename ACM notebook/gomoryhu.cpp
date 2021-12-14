struct GomoryHuTree {
    // s - t cut = Minimum edge cost from s to t on tree. 0-based.
    vector<bool> vis;
    MaxFlow mf;
    void dfs(int u) {
        vis[u] = 1;
        for (int id : mf.g[u])
        {
            int v = mf.e[id].v, c = mf.e[id].remain();
            if (c && !vis[v])
                dfs(v);
        }
    }
#define pi pair<int, int>
    vector<pi> Solve(int n, vector<Edge> &e) {
        vector<pi> ret(n); // if i > 0 store <parent, cost>
        mf = MaxFlow(n);
        vis.resize(n);
        for (Edge &edge : e) {
            // Undirect edge
            mf.addEdge(edge.u, edge.v, edge.c);
        }
        for (int i = 1; i < n; ++i) {
            // Reset flow
            for (auto &edge : mf.e)
                edge.flow = 0;
            ret[i].second = mf.maxflow(i, ret[i].first);
            for (int j = 0; j < n; ++j) vis[j] = 0;
            dfs(i);
            for (int j = i + 1; j < n; ++j) {
                if (ret[j].first == ret[i].first && vis[j])
                    ret[j].first = i;
            }
        }
        return ret;
    }
};