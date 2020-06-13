typedef complex<double> cd;
typedef vector<cd> poly;
 
double PI = acos(-1);
 
int reverse(int n, int log_n){
    int res = 0;
    for(int i = 0; i < log_n; i++)
        if((1<<i) & n)
            res |= (1<<(log_n-1-i));
    return res;
}
 
void fft(poly& a, bool invert){
    int n = a.size(), log_n = 0;
    while((1 << log_n) < n) log_n++;
    
    for(int i = 0; i < n; i++){
        int j = reverse(i, log_n);
        if(i < j)
            swap(a[i], a[j]);
    }
    double angle = 2*PI/n * (invert ? -1 : 1);
    poly root(n/2);
    for(int i = 0; i < n/2; i++)
        root[i] = cd(cos(angle*i), sin(angle*i));
    
    for(int len = 2; len <= n; len <<= 1){
        int step = n/len;
        int aux = len/2;
        for(int i = 0; i < n; i+=len)
            for(int j = 0; j < aux; j++){
                cd u = a[i+j], v = a[i+j+aux]*root[step*j];
                a[i+j] = u + v;
                a[i+j+aux] = u - v;
            }
    }
    
    if(invert){
        for(int i = 0; i < n; i++)
            a[i] /= n;
    }
}
 
vector<double> solve(vector<int>& a, vector<int>& b){
    int n = 1, len = a.size() + b.size();
    while(n < len) n <<= 1;
    a.resize(n); b.resize(n);
        
    poly fft_a(a.begin(), a.end()); fft(fft_a, 0);
    poly fft_b(b.begin(), b.end()); fft(fft_b, 0);
    
    poly c(n);
    for(int i = 0; i < n; i++)
        c[i] = fft_a[i] / fft_b[i];
    
    fft(c, 1);
    vector<double> res(n);
    while(res.size() > 1 && fabs(res.back()) <= 0.0000002) res.pop_back();
    return res;
}
