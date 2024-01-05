namespace DC {
    struct range { // eh preciso definir a forma
                   // de calcular o range
        vi freq;
        ll sum = 0;
        int l = 0, r = -1;
        void back_l(int v) { // Mover o 'l' do range
                             // para a esquerda
            sum += freq[v];
            freq[v]++;
            l--;
        }
        void advance_r(int v) { // Mover o 'r' do range
                                // para a direita
            sum += freq[v];
            freq[v]++;
            r++;
        }
        void advance_l(int v) { // Mover o 'l' do range
                                // para a direita
            freq[v]--;
            sum -= freq[v];
            l++;
        }
        void back_r(int v) { // Mover o 'r' do range
                             // para a esquerda
            freq[v]--;
            sum -= freq[v];
            r--;
        }
        void clear(int n) { // Limpar range
            l = 0;
            r = -1;
            sum = 0;
            freq.assign(n + 5, 0);
        }
    } s;

    vi dp_before, dp_cur;
    void compute(int l, int r, int optl, int optr) {
        if (l > r) {
            return;
        }
        int mid = (l + r) >> 1;
        pair<ll, int> best = {0, -1}; // {INF, -1} se quiser minimizar

        while (s.l < optl) {
            s.advance_l(v[s.l]);
        }
        while (s.l > optl) {
            s.back_l(v[s.l - 1]);
        }
        while (s.r < mid) {
            s.advance_r(v[s.r + 1]);
        }
        while (s.r > mid) {
            s.back_r(v[s.r]);
        }

        vi removed;
        for (int i = optl; i <= min(mid, optr); i++) {
            best =
                min(best,
                    {(i ? dp_before[i - 1] : 0) + s.sum, i}); // min() se quiser minimizar
            removed.push_back(v[s.l]);
            s.advance_l(v[s.l]);
        }
        for (int rem : removed) {
            s.back_l(v[s.l - 1]);
        }

        dp_cur[mid] = best.first;
        int opt = best.second;
        compute(l, mid - 1, optl, opt);
        compute(mid + 1, r, opt, optr);
    }

    ll solve(int n, int k) {
        dp_before.assign(n, 0);
        dp_cur.assign(n, 0);
        s.clear(n);
        for (int i = 0; i < n; i++) {
            s.advance_r(v[i]);
            dp_before[i] = s.sum;
        }
        for (int i = 1; i < k; i++) {
            s.clear(n);
            compute(0, n - 1, 0, n - 1);
            dp_before = dp_cur;
        }
        return dp_before[n - 1];
    }
};
