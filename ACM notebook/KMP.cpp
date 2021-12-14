void preCalc()
{
  int cur = -1;
  pre[0] = -1;
  for (int i = 1; i <= t.length(); ++i)
  {
    while (cur >= 0 && t[i - 1] != t[cur]) cur = pre[cur];
    pre[i] = ++cur; 
  }
}

int main()
{
  cin >> s >> t;
  preCalc();
  int cur = 0;
  for (int i = 0; i < s.length(); ++i) 
  {
    while (cur >= 0 && s[i] != t[cur]) cur = pre[cur];
    ++cur;
    if (cur == t.length()) 
    {
      cout << i - t.length() + 2 << ' ';
      cur = pre[cur];
    }
  }
  return 0;
}   