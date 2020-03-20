namespace FFT
{
  struct cd
  {
    double real, img;
    cd(double x = 0, double y = 0) : real(x), img(y) {}
    cd operator+(const cd& src) { return cd(real + src.real, img + src.img); }
    cd operator-(const cd& src) { return cd(real - src.real, img - src.img); }
    cd operator*(const cd& src) { return cd(real * src.real - img * src.img, real * src.img + src.real * img); }
  };
  cd conj(const cd& x) { return cd(x.real, -x.img); }
  const int MaxN = 1 << 15;
  const double PI = acos(-1);
  cd w[MaxN]; int rev[MaxN];

  void initFFT()
  {
    for (int i = 0; i < MaxN; ++i) 
      w[i] = cd(cos(2 * PI * i / MaxN), sin(2 * PI * i / MaxN));
  }
  void FFT(vector<cd>& a)
  {
    int n = a.size(); 
    for (int i = 0; i < n; ++i) 
      if (rev[i] < i) swap(a[i], a[rev[i]]);
    
    for (int len = 2; len <= n; len <<= 1)
      for (int i = 0; i < n; i += len)
        for (int j = 0; j < (len >> 1); ++j)
        {
          cd u = a[i + j], v = a[i + j + (len >> 1)] * w[MaxN / len * j];
          a[i + j] = u + v;
          a[i + j + (len >> 1)] = u - v;
        }
  }
  void calcRev(int n)
  {
    rev[0] = 0;
    for (int i = 1; i < n; ++i) 
      if (i & 1) rev[i] = rev[i - 1] + (n >> 1);
      else rev[i] = rev[i >> 1] >> 1;
  }
  vector<long long> polymul(const vector<int>& a, const vector<int>& b)
  {
    int n = a.size() + b.size() - 1;
    if (__builtin_popcount(n) != 1) n = 1 << (32 - __builtin_clz(n));

    vector<cd> pa(a.begin(), a.end()); pa.resize(n);
    vector<cd> pb(b.begin(), b.end()); pb.resize(n);
    
    calcRev(n); // Doesn't need to call multiple times

    FFT(pa); FFT(pb);
    for (int i = 0; i < n; ++i) pa[i] = conj(pa[i] * pb[i]);
    FFT(pa);
    //output of pa will be conj of the real answer
    vector<long long> res(n);
    for (int i = 0; i < n; ++i) res[i] = llround(pa[i].real / n);
    return res;
  }
};