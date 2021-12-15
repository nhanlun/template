string manacher(string s) {
  // warning: use string can TLE, please use vector char
  vector<char> t(s.length() * 2 + 5); 
  int cnt = 0;
  t[0] = '~';
  for (int i = 0; i < s.length(); ++i) {
    t[++cnt] = '#'; t[++cnt] = s[i];
  }
  t[++cnt] = '#'; t[++cnt] = '-';

  string res; int Max = 0;
  vector<int> z(cnt, 0);
  for (int i = 2, center = 1, r = 1; i < cnt - 2; ++i) {
    int i_mirror = center * 2 - i;
    z[i] = (r > i) ? min(r - i, z[i_mirror]) : 0;
    while (t[i + z[i] + 1] == t[i - z[i] - 1]) ++z[i];
    if (i + z[i] > r) {
      r = i + z[i];
      center = i;
    }
    if (z[i] > z[Max]) Max = i;
  }
  for (int i = Max - z[Max] + 1; i <= Max + z[Max] - 1; i += 2) 
    res += t[i];
  return res;
}