// return x that satisfies a^x = b modulo MOD
template<int mod>
pair<RingMod<mod>, bool> discrete_log(RingMod<mod> a, RingMod<mod> b)
{
    const int m = 31596;    // square root of MOD
    auto table = unordered_map<int, int>{};
    RingMod<mod> e = 1;
    for (int i = 0; i < m; ++i) {
        table[int(e)] = i;      // map the values a^0, a^1, ... a^(m-1) to 0, 1, ... m - 1
        e = e * a;
    }
    const auto factor = pow(a, mod - 1 - m); // factor is a^-m
    e = b;
    for (int i = 0; i < m; ++i) {
        auto it = table.find(int(e));
        if (it != table.end()) return make_pair(i * m + it->second, true);
        e = e * factor;
    }
    return make_pair(RingMod<mod>{}, false);
}
 
// return x that satisfies x^k = a modulo MOD
template<int mod>
pair<RingMod<mod>, bool> discrete_root(RingMod<mod> k, RingMod<mod> a)
{
    if (int(a) == 0) return make_pair(0, true);
    const int g = 3;            // a primitive root modulo MOD
    auto gk = pow<mod>(g, int(k));
    auto res = discrete_log(gk, a);
    if (!res.second) return make_pair(RingMod<mod>{}, false);
    return make_pair(pow<mod>(g, int(res.first)), true);
}