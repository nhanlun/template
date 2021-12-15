void dfs(int x)
{
  for (; start[x] < adj[x].size(); ++start[x]) if (!ban[adj[x][start[x]]])
  {
    ban[adj[x][start[x]]] = true;
    int y = edge[adj[x][start[x]]].first;
    if (y == x) y = edge[adj[x][start[x]]].second;
    dfs(y);
  }
  path.push_back(x);
}
// inside main
while (m--)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(edge.size());
    adj[v].push_back(edge.size());
    edge.push_back({u, v});
    deg[u]++;
    deg[v]++;
  }