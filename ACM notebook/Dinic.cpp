namespace Dinic // really fast, O(n^2 m) or O(sqrt(n)m) if bipartite
{
    vector<int> adj[N];
    long long c[N][N], f[N][N];
    int s = 0, t = 0, d[N], ptr[N];
    bool BFS()
    {
        queue<int> q;
        memset(d, -1, sizeof(d));
        d[s] = 0; q.push(s);
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int v : adj[u])
            {
                if (d[v] == -1 && c[u][v] > f[u][v])
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    }
    long long DFS(int x, long long delta)
    {
        if (x == t) return delta;
        for (; ptr[x] < adj[x].size(); ++ptr[x]) // Skip the used edge
        {
            int y = adj[x][ptr[x]];
            if (d[y] == d[x] + 1 && c[x][y] > f[x][y])
            {
                long long push = DFS(y, min(delta, c[x][y] - f[x][y]));
                if (push)
                {
                    f[x][y] += push;
                    f[y][x] -= push;
                    return push;
                }
            }
        }
        return 0;
    }
    long long maxFlow(int x, int y) // From x to y
    {
        long long flow = 0;
        s = x; t = y;
        while (BFS())
        {
            memset(ptr, 0, sizeof(ptr)); 
            while (long long tmp = DFS(s, 1e9))
                flow += 1LL * tmp;
        }
        return flow;
    }
};