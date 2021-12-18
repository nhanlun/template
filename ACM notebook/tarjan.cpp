void dfs(int x)
{
    num[x] = low[x] = ++cnt;
    for (int y : adj[x])
    {
        if (y == p[x]) continue;
        if (num[y] == 0)
        {
            child[x]++;
            p[y] = x;
            dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], num[y]);
    }    
}

int main()
{
    for (int i = 1; i <= n; ++i) if (num[i] == 0) 
    {
        p[i] = -1;
        dfs(i);
    }
    vector<pii> res1;
    vector<int> res2;
    for (int i = 1; i <= n; ++i)
    {
        int u = p[i];
        if (u != -1 && low[i] >= num[i]) 
            res1.push_back({u, i});
        if (u != -1 && low[i] >= num[u]) 
            arti[u] = arti[u] || p[u] != -1 || child[u] >= 2;
    }
    for (int i = 1; i <= n; ++i) if (arti[i]) res2.push_back(i);
}