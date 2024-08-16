const int L = 60;
struct Basis {
    ll B[L], R, last_bit;
    Basis() { memset(B, 0, sizeof B), R = 0; }
    ll reduce(ll x) {
        for (int i = L - 1; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (B[i] != 0) {
                    x ^= B[i];
                } else {
                    last_bit = i;
                    return x;
                }
            }
        }
        // assert(x == 0); 
        return 0;
    }
    bool insert(ll x) {
        x = reduce(x);
        if (x > 0) {
            R++;
            B[last_bit] = x;
            return true;
        }
        return false;
    }
    ll kth_smallest(ll k) {
        ll ans = 0;
        ll half = 1LL << (R - 1);
        for (int i = L - 1; i >= 0; i--) {
            if (B[i] != 0) {
                if ((ans >> i) & 1) {
                    if (k > half) {
                        k -= half;
                    } else {
                        ans ^= B[i];
                    }
                } else {
                    if (k > half) {
                        ans ^= B[i];
                        k -= half;
                    }
                }
                half >>= 1;
            }
        }
        return ans;
    }
    ll kth_greatest(ll k) {
        return kth_smallest((1LL << R) - k + 1);
    }
};
