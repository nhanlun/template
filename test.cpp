#include <bits/stdc++.h>

#define ll long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL(x) (x << 1)
#define RR(x) ((x << 1) + 1)
#define sqr(x) ((x) * (x))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define onbit(x,k) ((x) | (1 << (k)))
#define offbit(x,k) ((x) & (~ (1 << (k))))
#define getbit(x,k) (((x) >> (k)) & 1)
#define ALL(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,b) for (int i=0; i<(b); ++i)
#define FORD(i,a,b) for (int i=(a); i>=(b); --i)
#define REPD(i,a) for (int i=(a)-1; i>=0; --i)
#define DEBUG(x) { cerr << #x << " = " << x << '\n'; }
#define ARR(x,l,r) { cerr << #x << " = {"; FOR(_,l,r) cerr << ' ' << x[_]; cerr << " }\n"; }

#define matrix_size 2
#define base 1000000007LL
#define eps 1e-8

const int dd[] = {-1,0,1,0,-1,1,1,-1};//up,right,down,left,upright,downright,downleft,upleft
const int cc[] = {0,1,0,-1,1,1,-1,-1};

const int maxN = 0;
const int maxM = 0;
const ll MOD = 1000000007LL;

using namespace std;

ll POW(ll x, ll y, ll MOD)
{
    if (y == 0) return 1 % MOD;
    ll tmp = POW(x, y >> 1, MOD);
    return (y & 1) ? (tmp * tmp) % MOD * x % MOD : tmp * tmp % MOD;
}

ll fastmul(ll x, ll y, ll MOD)
{
    if (y == 0) return 0;
    ll tmp = fastmul(x, y >> 1, MOD);
    return (y & 1) ? ((tmp << 1) + x) % MOD : (tmp << 1) % MOD;
}

ll invMod(ll x, ll MOD) { return POW(x, MOD-2, MOD); }

template<class T> 
T min(T a,T b,T c) { return min(a,min(b,c));}

template<class T>
T max(T a,T b,T c) { return max(a,max(b,c)); }

// template ends here

void yolosmile()
{
}

int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
        double startTime = clock();
    #endif // DEBUG
    
    yolosmile();

    #ifndef ONLINE_JUDGE
        double endTime = clock();
        cerr << "Execution time: " 
            << (endTime - startTime) / CLOCKS_PER_SEC * 1000 << ".ms\n";
    #endif
    
    return 0;
}   
