void dfs1(int v) {
  used[v] = true;

  for (auto u : adj[v])
    if (!used[u]) dfs1(u);

  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);

  for (auto u : adj_rev[v])
    if (!used[u]) dfs2(u);
}

int main() {
  for (;;) {
    int a, b;
    adj[a].push_back(b);
    adj_rev[b].push_back(a);
  }

  used.assign(n, false);
  for (int i = 0; i < n; i++)
    if (!used[i]) dfs1(i);

  used.assign(n, false);
  reverse(order.begin(), order.end());

  for (auto v : order)
    if (!used[v]) {
      dfs2 (v);
      // set root node for the components
      int root = component.front();
      for (auto u : component) roots[u] = root;
      root_nodes.push_back(root);

      component.clear();
    }
  // create condense graph
  for (int v = 0; v < n; v++)
    for (auto u : adj[v]) {
      int root_v = roots[v], root_u = roots[u];

      if (root_u != root_v)
        adj_scc[root_v].push_back(root_u);
    }
}