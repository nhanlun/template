typedef complex<double> ComplexType;

const double PI = acos(-1);
const ComplexType I(0.0, 1.0);
// ceil(log2(n)) + 1
const int MAX2N = (1 << 15);

ComplexType root_unity[MAX2N + 1];

// DONT FORGET TO CALL INIT!
void init_fft() {
  for (int i = 0; i <= MAX2N; ++i)
    root_unity[i] = exp(2 * PI * i / MAX2N * -I);
}

void fft(vector<ComplexType>& a, const vector<int>& p) {
  int n = a.size();
  vector<ComplexType> b(n);
  for (int i = 0; i < n; ++i)
    b[i] = a[p[i]];
  copy(b.begin(), b.end(), a.begin());
  for (int m = 1, t = MAX2N / 2; m < n; m *= 2, t /= 2)
    for (int i = 0; i < n; i += m * 2)
      for (int j = 0; j < m; ++j) {
        int u = i + j, v = i + j + m;
        a[v] *= root_unity[j * t];
        ComplexType tmp = a[u] - a[v];
        a[u] += a[v];
        a[v] = tmp;
      }
}

vector<long long> polymul(const vector<int>& a, const vector<int>& b) {
  int n = max(a.size(), b.size());
  if (__builtin_popcount(n) != 1) n = 1 << (32 - __builtin_clz(n));
  n *= 2;
  vector<ComplexType> pa(n), pb(n);
  copy(a.begin(), a.end(), pa.begin());
  copy(b.begin(), b.end(), pb.begin());

  vector<int> p(n);
  for (int i = 1; i < n; ++i)
    if (i & 1) p[i] = p[i - 1] + n / 2;
    else p[i] = p[i / 2] / 2;

  fft(pa, p), fft(pb, p);
  transform(pa.begin(), pa.end(), pb.begin(), pa.begin(), multiplies<ComplexType>());
  // inverse FFT
  for_each(pa.begin(), pa.end(), [](ComplexType &c) { c = conj(c); });
  fft(pa, p);

  vector<long long> res(n);
  transform(pa.begin(), pa.end(), res.begin(), [&](auto c) { return lround(c.real() / n); });
  return res;
}