struct Hungarian {
  long  c[N][N], fx[N], fy[N], d[N];
  int mx[N], my[N], trace[N], arg[N];
  queue<int> q;
  int start, finish, n, m;
  const long inf = 1e18;

  void Init(int _n, int _m) {
    n = _n, m = _m;
    FOR(i, 1, n) {
      mx[i] = my[i] = 0;
      FOR(j, 1, n) c[i][j] = inf;
    }
  }
  void addEdge(int u, int v, long cost) { c[u][v] = min(c[u][v], cost); }
  inline long getC(int u, int v) { return c[u][v] - fx[u] - fy[v]; }

  void initBFS() {
    while (!q.empty()) q.pop();
    q.push(start);
    FOR(i, 0, n) trace[i] = 0;
    FOR(v, 1, n) {
      d[v] = getC(start, v), arg[v] = start;
    }
    finish = 0;
  }

  void findAugPath() {
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      FOR(v, 1, n) if (!trace[v]) {
        long w = getC(u, v);
        if (!w) {
          trace[v] = u;
          if (!my[v]) { finish = v; return; }
          q.push(my[v]);
        }
        if (d[v] > w) { d[v] = w; arg[v] = u; }
      }
    }
  }

  void subX_addY(){
    long delta = inf;
    FOR(v, 1, n) if (trace[v] == 0 && d[v] < delta) delta = d[v];  
    fx[start] += delta;
    FOR(v, 1, n) if (trace[v]) {
      int u = my[v];
      fy[v] -= delta, fx[u] += delta;
    } else d[v] -= delta;

    FOR(v, 1, n) if (!trace[v] && !d[v]) {
      trace[v] = arg[v];
      if (!my[v]) { finish = v; return; }
      q.push(my[v]);
    }
  }

  void Enlarge() {
    do {
      int u = trace[finish], nxt = mx[u];
      mx[u] = finish, my[finish] = u, finish = nxt;
    } while (finish);
  }

  long minCost() {
    FOR(u, 1, n) {
      fx[u] = c[u][1];
      FOR(v, 1, n) fx[u] = min(fx[u], c[u][v]);
    }
    FOR(v, 1, n) {
      fy[v] = c[1][v] - fx[1];
      FOR(u, 1, n) fy[v] = min(fy[v], c[u][v] - fx[u]);
    }

    FOR(u, 1, n) {
      start = u;
      initBFS();
      while (finish == 0) {
        findAugPath();
        if (!finish) subX_addY();
      }
      Enlarge();
    }

    int res = 0;
    FOR(i, 1, n) res += c[i][mx[i]];
    return res;
  }
};