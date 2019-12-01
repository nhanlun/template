void update(int x, int val)
{
  for (; x <= n; x += x & ~x) BIT[x] = min(BIT[x], val);
}

int get(int x)
{
  int res = 1e9;
  for (; x > 0; x -= x & ~x) res = min(res, BIT[x]);
  return res;
}