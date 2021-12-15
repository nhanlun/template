// IT sum, vector it contain the tree, vector version contain the root of different versions
struct Node
{
  int l = -1, r = -1;
  ll sum = 0;
  Node(ll s, int _l, int _r) : sum(s), l(_l), r(_r) {}
  Node() {}
};
vector<int> ver;
vector<Node> it;
 
int build(int l = 1, int r = n)
{
  if (l == r)
  {
    it.push_back(Node(a[l], -1, -1));
    return it.size() - 1;
  }
  int mid = (l + r) >> 1;
  Node cur;
  cur.l = build(l, mid);
  cur.r = build(mid + 1, r);
  cur.sum = it[cur.l].sum + it[cur.r].sum;
  it.push_back(cur);
  return it.size() - 1;
}
 
int update(int id, int u, int v, int l = 1, int r = n)
{
  if (l == r)
  {
    it.push_back(Node(v, -1, -1));
    return it.size() - 1;
  }
  int mid = (l + r) >> 1;
  if (u <= mid)
  {
    int tmp = update(it[id].l, u, v, l, mid);
    it.push_back(Node(it[tmp].sum + it[it[id].r].sum, tmp, it[id].r));
  }
  else 
  {
    int tmp = update(it[id].r, u, v, mid + 1, r);
    it.push_back(Node(it[it[id].l].sum + it[tmp].sum, it[id].l, tmp));
  }
  return it.size() - 1;
}
 
ll get(int id, int u, int v, int l = 1, int r = n)
{
  if (r < u || l > v) return 0;
  if (l >= u && r <= v) return it[id].sum;
  int mid = (l + r) >> 1;
  return get(it[id].l, u, v, l, mid) + get(it[id].r, u, v, mid + 1, r);
}