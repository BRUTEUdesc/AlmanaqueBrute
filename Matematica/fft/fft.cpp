#define loop(x, y, z) for(int x = y; x < z; ++x)
#define size(x) (int)x.size()

using namespace std;
 
typedef complex<double> cd;
typedef vector<cd> poly;
const double PI = acos(-1);
 
void fft(poly& a, bool invert = 0){
    int n = size(a), log_n = 0;
    while((1 << log_n) < n) log_n++;
    
    for(int i = 1, j = 0; i<n; ++i){
        int bit = n >> 1;
        for( ; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    
    double angle = 2*PI/n * (invert ? -1 : 1);
    poly root(n/2);
    loop(i, 0, n/2) root[i] = cd(cos(angle*i), sin(angle*i));
    
    for(long long len = 2; len <= n; len <<= 1){
        long long step = n/len;
        long long aux = len/2;
        for(long long i = 0; i < n; i+=len)
            loop(j, 0, aux){
                cd u = a[i+j], v = a[i+j+aux]*root[step*j];
                a[i+j] = u + v;
                a[i+j+aux] = u - v;
            }
    }
    if(invert) loop(i, 0, n) a[i] /= n;
}
 
vector<long long> convolution(vector<long long>& a, vector<long long>& b){
    int n = 1, len = size(a) + size(b);
    while(n < len) n <<= 1;
    a.resize(n); b.resize(n);
    poly fft_a(a.begin(), a.end()); fft(fft_a);
    poly fft_b(b.begin(), b.end()); fft(fft_b);
    
    poly c(n);
    loop(i, 0, n) c[i] = fft_a[i] * fft_b[i];
    fft(c, 1);
    
    vector<long long> res(n);
    loop(i, 0, n) res[i] = round(c[i].real());
    // while(size(res) > 1 && res.back() == 0) res.pop_back(); // apenas para quando os zeros direita não importarem
    return res;
}
