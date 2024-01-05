typedef complex<double> cd;
typedef vector<cd> poly;
const double PI = acos(-1);

void fft(poly &a, bool invert = 0) {
    int n = a.size(), log_n = 0;
<<<<<<< HEAD
    while ((1 << log_n) < n) {
        log_n++;
    }

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
=======
    while ((1 << log_n) < n) {
        log_n++;
    }

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
>>>>>>> master
    }

    double angle = 2 * PI / n * (invert ? -1 : 1);
    poly root(n / 2);
<<<<<<< HEAD
    for (int i = 0; i < n / 2; ++i) {
        root[i] = cd(cos(angle * i), sin(angle * i));
    }
=======
    for (int i = 0; i < n / 2; ++i) {
        root[i] = cd(cos(angle * i), sin(angle * i));
    }
>>>>>>> master

    for (long long len = 2; len <= n; len <<= 1) {
        long long step = n / len;
        long long aux = len / 2;
        for (long long i = 0; i < n; i += len) {
            for (int j = 0; j < aux; ++j) {
                cd u = a[i + j], v = a[i + j + aux] * root[step * j];
                a[i + j] = u + v;
                a[i + j + aux] = u - v;
            }
        }
    }
    if (invert) {
<<<<<<< HEAD
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
=======
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
>>>>>>> master
    }
}

vector<long long> convolution(vector<long long> &a, vector<long long> &b) {
    int n = 1, len = a.size() + b.size();
<<<<<<< HEAD
    while (n < len) {
        n <<= 1;
    }
=======
    while (n < len) {
        n <<= 1;
    }
>>>>>>> master
    a.resize(n);
    b.resize(n);
    poly fft_a(a.begin(), a.end());
    fft(fft_a);
    poly fft_b(b.begin(), b.end());
    fft(fft_b);

    poly c(n);
<<<<<<< HEAD
    for (int i = 0; i < n; ++i) {
        c[i] = fft_a[i] * fft_b[i];
    }
=======
    for (int i = 0; i < n; ++i) {
        c[i] = fft_a[i] * fft_b[i];
    }
>>>>>>> master
    fft(c, 1);

    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
<<<<<<< HEAD
        res[i] = round(c[i].real()); //  res = c[i].real();
                                     //  se for vector de
                                     //  double
    }
    // while(size(res) > 1 && res.back() == 0)
    // res.pop_back(); // apenas para quando os
    // zeros direita nao importarem
=======
        res[i] = round(c[i].real()); //  res = c[i].real(); se for vector de double
    }
    // while(size(res) > 1 && res.back() == 0) res.pop_back(); // apenas para quando os zeros direita nao importarem
>>>>>>> master
    return res;
}
