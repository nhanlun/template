bool BFS()
{
	queue<int> q;
	// reset array
	memset(d, 0, sizeof(d));
	memset(Free, true, sizeof(Free));
	q.push(s);
	d[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].fi;
			if (d[v] == 0 && adj[u][i].se > f[u][v])
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return d[t] != 0;
}

int DFS(int x, int delta)
{
	if (x == t)
		return delta;
	Free[x] = false;
	for (int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i].fi;
		if (d[y] == d[x] + 1 && f[x][y] < adj[x][i].se && Free[y])
		{
			int tmp = DFS(y, min(delta, adj[x][i].se - f[x][y]));
			if (tmp > 0)
			{
				f[x][y] += tmp;
				f[y][x] -= tmp;
				return tmp;
			}
		}
	}
	return 0;
}