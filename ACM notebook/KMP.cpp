// SUBSTR spoj
string s, t;int pos[N];
void build()
{
  pos[0] = -1;
  int pre = -1, cur = 0;
  while (cur < t.length())
  {
    while (pre >= 0 && t[cur] != t[pre])
    {
      pre = pos[pre];
    }
    pos[++cur] = ++pre;
  }
}
 
int main()
{
  cin >> s; cin >> t;
  build();
  int cur = 0;
  for (int i = 0; i < (int)s.length(); ++i)
  {
    while (cur >= 0 && s[i] != t[cur])
    {
      cur = pos[cur];
    }
    ++cur;
    if (cur == (int)t.length())
    {
      cout << i - (int)t.length() + 2 << ' ';
      cur = pos[cur];
    }
  }
 
  return 0;
} 