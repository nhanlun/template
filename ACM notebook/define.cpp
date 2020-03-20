#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ctime>

#define cross(A, B) (A.x * B.y - A.y * B.x)
#define dot(A, B) (A.x * B.x + A.y * B.y)
#define ccw(A, B, C) (-(A.x * (C.y - B.y) + B.x * (A.y - C.y) + C.x * (B.y - A.y))) // positive when ccw
#define CROSS(a, b, c, d) (a * d - b * c)

#define fi first
#define se second
#define LL(x) (x << 1)
#define RR(x) ((x << 1) + 1)
#define mp make_pair
 
using namespace std;
const int N = 1000005;
const int M = 30000;
 
const int Bases = 2;
const long long base[] = {137, 37};
const long long mod = 1000000007LL;
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> iiii;

long long addi(long long a, long long b, long long m = mod) { a += b; if (a < 0) a += m; if (a >= m) a -= m; return a; }
long long subt(long long a, long long b, long long m = mod) { a -= b; if (a < 0) a += m; if (a >= m) a -= m; return a; }
long long mult(long long a, long long b, long long m = mod) { return a * b % m; }
long long power(long long a, long long b, long long m = mod) 
{
    long long tmp = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1LL) tmp = mult(tmp, a, m);
        a = mult(a, a, m);
    }
    return tmp;
}
long long inv(long long a, long long m = mod) { return power(a, m - 2, m); }