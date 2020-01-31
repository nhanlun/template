// faster for > 1e6
void sieve_new()
{
  for (int i = 2; i <= 1000000; ++i) 
  {
    if (!notPrime[i]) prime.push_back(i);
    for (int j = 0; i * prime[j] <= 1000000 && j < prime.size(); ++j) {
      notPrime[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
// 
void sieve_old()
{
  for (long long i = 2; i <= 1000000; ++i) 
  if (!notPrime[i]) {
    prime.push_back(i);
    for (long long j = i; j * i <= 1000000; ++j) 
      notPrime[i * j] = true;
  }
}