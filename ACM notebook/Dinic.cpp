bool BFS()
{
	queue<int> q;
	for (int i=1; i<=n; i++) d[i]=0,Free[i]=true;
	q.push(s);
	d[s]=1;
	while (!q.empty())
	{
    	int u=q.front(); q.pop();
    	for (int i=0; i<DSK[u].size(); i++)
    	{
        	int v=DSK[u][i].fi;
        	if (d[v]==0 && DSK[u][i].se>f[u][v])
        	{
            	d[v]=d[u]+1;
            	q.push(v);
        	}
    	}
	}
	return d[t]!=0;
}
 
int DFS(int x,int delta)
{
	if (x==t) return delta;
	Free[x]=false;
	for (int i=0; i<DSK[x].size(); i++)
	{
    	int y=DSK[x][i].fi;
    	if (d[y]==d[x]+1 && f[x][y]<DSK[x][i].se && Free[y])
    	{
        	int tmp=DFS(y,min(delta,DSK[x][i].se-f[x][y]));
        	if (tmp>0)
        	{
            	f[x][y]+=tmp; f[y][x]-=tmp; return tmp;
        	}
    	}
	}
	return 0;
}