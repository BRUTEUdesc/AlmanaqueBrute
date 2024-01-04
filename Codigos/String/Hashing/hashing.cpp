struct hashing {
    const long long LIM = 1000006;
    long long p, m;
    vector<long long> pw, hsh;
    hashing(long long _p, long long _m) : p(_p), m(_m) {
        pw.resize(LIM);
        hsh.resize(LIM);
        pw[0] = 1;
        for (int i = 1; i < LIM; i++) {
            pw[i] = (pw[i - 1] * p) % m;
        }
    }
    void set_string(string &s) {
        hsh[0] = s[0];
        for (int i = 1; i < s.size(); i++) {
            hsh[i] = (hsh[i - 1] * p + s[i]) % m;
        }
    }
    long long range(int esq, int dir) {
        long long ans = hsh[dir];
        if (esq > 0) {
            ans = (ans - (hsh[esq - 1] * pw[dir - esq + 1] % m) + m) % m;
        }
        return ans;
    }
};
