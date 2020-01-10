namespace FFT
{
    using cd = complex<double>;
    const int MaxN = 1 << 18;
    const double PI = acos(-1);
    cd w[MaxN];
    int rev[MaxN];

    void FFT(vector<cd>& a, bool invert)
    {
        int n = a.size(); 
        vector<cd> b(n);
        for (int i = 0; i < n; ++i)
            b[i] = a[rev[i]];
        swap(a, b);
        w[0] = cd(1);
        for (int len = 2; len <= n; len <<= 1)
        {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));
            for (int j = 1; j < (len >> 1); ++j) w[j] = w[j - 1] * wlen;
            for (int i = 0; i < n; i += len)
            {
                for (int j = 0; j < (len >> 1); ++j)
                {
                    cd u = a[i + j], v = a[i + j + (len >> 1)] * w[j];
                    a[i + j] = u + v;
                    a[i + j + (len >> 1)] = u - v;
                }
            }
        }
        if (invert)
            for (auto& i : a) i /= n;
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
        int n = max(a.size(), b.size());
        if (__builtin_popcount(n) != 1) n = 1 << (33 - __builtin_clz(n));

        vector<cd> pa(n), pb(n);
        copy(a.begin(), a.end(), pa.begin());
        copy(b.begin(), b.end(), pb.begin());
        
        calcRev(n); // Doesn't need to call multiple times

        FFT(pa, false);
        FFT(pb, false);
        transform(pa.begin(), pa.end(), pb.begin(), pa.begin(), multiplies<cd>());
        FFT(pa, true);

        vector<long long> res(n);
        transform(pa.begin(), pa.end(), res.begin(), [&](cd& x) { return llround(x.real()); });
        return res;
    }
};