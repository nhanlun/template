namespace HopcroftKarp // O(sqrt(n) * m)
{
    vector<int> adj[N]; int match[N], d[N];
    bool BFS()
    {
        queue<int> q;
        memset(d, -1, sizeof(d));
        for (int i = 1; i <= n; ++i) if (!match[i])
        {
            d[i] = 0;
            q.push(i);
        }
        bool flag = false;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int v : adj[u])
            {
                if (match[v] == 0) 
                {
                    flag = true;
                    continue;
                }
                if (d[match[v]] == -1)
                {
                    d[match[v]] = d[u] + 1;
                    q.push(match[v]);
                }
            }
        }
        return flag;
    }
    bool DFS(int x)
    {
        for (int y : adj[x])
        {
            if (match[y] == 0 || (d[match[y]] == d[x] + 1 && DFS(match[y])))
            {
                match[y] = x;
                match[x] = y;
                return true;
            }
        }
        d[x] = -1;
        return false;
    }
    long long maxMatching() // From x to y
    {
        long long matching = 0;
        while (BFS())
        {
            for (int i = 1; i <= n; ++i) if (!match[i] && DFS(i))
                ++matching;
        }
        return matching;
    }
};