// usa miller_rabin.cpp!! olhar em
// matematica/primos usa pollar_rho.cpp!! olhar em
// matematica/fatoracao

vector<long long> factorize(long long n) {
    if (n == 1) {
        return {};
    }
    if (miller_rabin(n)) {
        return {n};
    }
    long long x = pollard_rho(n);
    auto l = factorize(x), r = factorize(n / x);
    l.insert(l.end(), all(r));
    return l;
}
