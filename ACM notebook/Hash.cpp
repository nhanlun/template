long long POW[Bases][N];

struct Hash
{
  long long a[Bases];
  Hash operator+(const Hash& src)
  {
    Hash tmp;
    for (int i = 0; i < Bases; ++i) tmp.a[i] = addi(a[i], src.a[i]);
    return tmp;
  }
  Hash operator-(const Hash& src)
  {
    Hash tmp;
    for (int i = 0; i < Bases; ++i) tmp.a[i] = subt(a[i], src.a[i]);
    return tmp;
  }
  Hash operator*(int x)
  {
    Hash tmp;
    for (int i = 0; i < Bases; ++i) tmp.a[i] = mult(a[i], POW[i][x]);
    return tmp;
  }
  Hash operator+(char c) 
  { 
    Hash tmp;
    for (int i = 0; i < Bases; ++i) tmp.a[i] = addi(a[i], c); 
    return tmp;
  }
  bool operator==(const Hash& src)
  {
    for (int i = 0; i < Bases; ++i) if (a[i] != src.a[i]) return false;
    return true;
  }
};

bool operator<(const Hash& a, const Hash& b)
{
  for (int i = 0; i < Bases; ++i) 
    if (a.a[i] < b.a[i]) return true;
    else if (a.a[i] > b.a[i]) return false;
    return false;
}

Hash hash1[N], hash2[N]; 
void initHash(int n)
{
  for (int j = 0; j < Bases; ++j) POW[j][0] = 1;
  for (int j = 0; j < Bases; ++j) for (int i = 1; i <= n; ++i) POW[j][i] = mult(POW[j][i - 1], base[j]);
}

void calcHash(int n)
{
  for (int j = 0; j < Bases; ++j) hash1[0].a[j] = 0;
  for (int i = 1; i <= n; ++i) hash1[i] = hash1[i - 1] * 1 + (s[i] - 'a');
}

void calcHashRev(int n)
{
  for (int j = 0; j < Bases; ++j) hash2[j].a[n + 1] = 0;
  for (int i = n; i >= 0; --i) hash2[i] = hash2[i + 1] * 1 + (s[i] - 'a');
}

Hash getHash(int l, int r) { return hash1[r] - hash1[l - 1] * (r - l + 1); }
Hash getHashRev(int l, int r) { return hash2[l] - hash2[r + 1] * (r - l + 1); }