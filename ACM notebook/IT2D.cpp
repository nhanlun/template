int Max[4096][4096];

struct dir 
{
  int ll, rr, id;
  dir (int L, int R, int X)
    { ll=L, rr=R, id=X; }
  dir le() const
    { return dir(ll, (ll+rr)/2, id*2); }
  dir ri() const
    { return dir((ll+rr)/2+1, rr, id*2+1); }
  inline bool irrelevant(int L, int R) const
    { return ll>R || L>rr || L>R; }
};

void maximize(int &a, int b)
  { a=max(a, b); }

void maximize(const dir &dx, const dir &dy, int x, int y, int k, bool only_y) 
{
  if (dx.irrelevant(x, x) || dy.irrelevant(y, y)) return;
  maximize(Max[dx.id][dy.id], k);
  if (!only_y && dx.ll != dx.rr) 
  {
    maximize(dx.le(), dy, x, y, k, false);
    maximize(dx.ri(), dy, x, y, k, false);
  }
  if (dy.ll != dy.rr) 
  {
    maximize(dx, dy.le(), x, y, k, true);
    maximize(dx, dy.ri(), x, y, k, true);
  }
}

int max_range(const dir &dx, const dir &dy, int lx, int rx, int ly, int ry) 
{
  if (dx.irrelevant(lx, rx) || dy.irrelevant(ly, ry)) return 0;
  if (lx<=dx.ll && dx.rr<=rx) 
  {
    if (ly<=dy.ll && dy.rr<=ry) return Max[dx.id][dy.id];
    int Max1 = max_range(dx, dy.le(), lx, rx, ly, ry);
    int Max2 = max_range(dx, dy.ri(), lx, rx, ly, ry);
    return max(Max1, Max2);
  } 
  else 
  {
    int Max1 = max_range(dx.le(), dy, lx, rx, ly, ry);
    int Max2 = max_range(dx.ri(), dy, lx, rx, ly, ry);
    return max(Max1, Max2);
  }
}