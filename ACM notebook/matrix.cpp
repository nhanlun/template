struct Mat
{
  vector<vector<ll>> a;
  Mat(int n) : a(n, vector<ll>(n, 0)) {}
  Mat(int n, bool x) : Mat(n)
  {
    for (int i = 0; i < n; ++i) a[i][i] = 1;
  }
};

Mat matmul(const Mat& a, const Mat& b, long long m = mod)
{
  int n = a.a.size();
  Mat res(n);
  for (int ii = 0; ii < n; ++ii) for (int jj = 0; jj < n; ++jj)
  {
    res.a[ii][jj] = 0;
    for (int kk = 0; kk < n; ++kk) 
      res.a[ii][jj] = addi(res.a[ii][jj], mult(a.a[ii][kk], b.a[kk][jj], m), m);
  }
  return res;
}

Mat matpow(const Mat& a, long long n, long long m = mod)
{
  if (n == 0) return Mat(true);
  Mat tmp = matpow(a, n >> 1, m);
  return (n & 1) ? matmul(matmul(tmp, tmp, m), a, m) : matmul(tmp, tmp, m);
}