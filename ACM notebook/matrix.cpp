struct matrix
{
  static const int MATRIX_SIZE = 2;
  long long a[MATRIX_SIZE][MATRIX_SIZE];
  matrix() 
  {
    for (int i = 0; i < MATRIX_SIZE; ++i)
      for (int j = 0; j < MATRIX_SIZE; ++j)
        a[i][j] = 0;
  }
  matrix(bool x) : matrix()
  {
    for (int i = 0; i < MATRIX_SIZE; ++i) a[i][i] = 1;
  }
};

matrix matmul(const matrix& a, const matrix& b, long long m = mod)
{
  int n = a.MATRIX_SIZE;
  matrix res;
  for (int ii = 0; ii < n; ++ii) for (int jj = 0; jj < n; ++jj)
  {
    res.a[ii][jj] = 0;
    for (int kk = 0; kk < n; ++kk) 
      res.a[ii][jj] = addi(res.a[ii][jj], mult(a.a[ii][kk], b.a[kk][jj], m), m);
  }
  return res;
}

matrix matpow(const matrix& a, long long n, long long m = mod)
{
  if (n == 0) return matrix(true);
  matrix tmp = matpow(a, n >> 1, m);
  return (n & 1) ? matmul(matmul(tmp, tmp, m), a, m) : matmul(tmp, tmp, m);
}