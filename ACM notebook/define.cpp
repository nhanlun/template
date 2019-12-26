#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ctime>

#define N
#define matrix_size 2
#define mod 1000000007LL
#define eps 1e-8
#define base 137 // Or 37

#define cross(A, B) (A.x * B.y - A.y * B.x)
#define dot(A, B) (A.x * B.x + A.y * B.y)
#define ccw(A, B, C) (-(A.x * (C.y - B.y) + B.x * (A.y - C.y) + C.x * (B.y - A.y))) // positive when ccw
#define CROSS(a, b, c, d) (a * d - b * c)