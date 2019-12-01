// Random using mt19937
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// For random long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Random shuffle using mt19937 as the generator
shuffle(a.begin(), a.end(), rng);

// Random range
int random(int a, int b)
{
  return uniform_int_distribution<int>(a, b)(rng);
}