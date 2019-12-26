int calc(int x, int y) { return (x >= 0) ? y : 0 - y; }

bool findpath()
{
	for (int i = 1; i <= n; i++) { trace[i] = 0; d[i] = inf; }
	q.push(n); d[n] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i];
			if (c[u][v] > f[u][v] && d[v] > d[u] + calc(f[u][v], cost[u][v]))
			{
				trace[v] = u;
				d[v] = d[u] + calc(f[u][v], cost[u][v]);
				if (!inq[v])
				{
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return d[t] != inf;
}

void incflow()
{
	int v = t, delta = inf;
	while (v != n)
	{
		int u = trace[v];
		if (f[u][v] >= 0)
			delta = min(delta, c[u][v] - f[u][v]);
		else
			delta = min(delta, 0 - f[u][v]);
		v = u;
	}
	v = t;
	while (v != n)
	{
		int u = trace[v];
		f[u][v] += delta;
		f[v][u] -= delta;
		v = u;
	}
}