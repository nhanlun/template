using cd = complex<double>;

const int MaxN = 1 << 18;
const double PI = acos(-1);
const cd I = (0, 1);

void FFT(vector<cd>& a, const vector<int>& rev, bool invert)
{
  int n = a.size(); 
  vector<cd> b(n);
  for (int i = 0; i < n; ++i)
    b[i] = a[rev[i]];
  swap(a, b);
  for (int len = 2; len <= n; len <<= 1)
  {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len)
    {
      cd w(1);
      for (int j = 0; j < (len >> 1); ++j)
      {
        cd u = a[i + j], v = a[i + j + (len >> 1)] * w;
        a[i + j] = u + v;
        a[i + j + (len >> 1)] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (auto& i : a) 
      i /= n;
}

vector<long long> polymul(const vector<int>& a, const vector<int>& b)
{
  int n = max(a.size(), b.size());
  if (__builtin_popcount(n) != 1) n = 1 << (33 - __builtin_clz(n));

  vector<cd> pa(n), pb(n);
  copy(a.begin(), a.end(), pa.begin());
  copy(b.begin(), b.end(), pb.begin());

  vector<int> rev(n);
  rev[0] = 0;
  for (int i = 1; i < n; ++i) 
    if (i & 1) rev[i] = rev[i - 1] + (n >> 1);
    else rev[i] = rev[i >> 1] >> 1;
  
  FFT(pa, rev, false);
  FFT(pb, rev, false);

  transform(pa.begin(), pa.end(), pb.begin(), pa.begin(), multiplies<cd>());
  FFT(pa, rev, true);

  vector<long long> res(n);
  transform(pa.begin(), pa.end(), res.begin(), [&](cd& x) { return llround(x.real()); });
  return res;
}