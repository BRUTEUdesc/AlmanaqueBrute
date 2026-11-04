namespace parallel_binary_search {
    // Para cada query i em [0, q), encontra o menor x em [lo, hi] tal que check(i)
    // eh verdadeiro depois de aplicar os eventos lo, lo + 1, ..., x (check precisa ser
    // monotono em x). Se nenhum x satisfaz, a resposta eh hi + 1.
    // - reset(): limpa a estrutura (chamado no inicio de cada rodada)
    // - apply(x): aplica o evento x na estrutura
    // - check(i): testa a query i com os eventos aplicados ate agora
    vector<long long>
    solve(int q, long long lo, long long hi, auto &&reset, auto &&apply, auto &&check) {
        vector<long long> L(q, lo), R(q, hi + 1);
        while (true) {
            vector<pair<long long, int>> ord; // {mid, query}
            for (int i = 0; i < q; i++)
                if (L[i] < R[i]) ord.emplace_back((L[i] + R[i]) / 2, i);
            if (ord.empty()) break;
            sort(ord.begin(), ord.end());
            reset();
            long long cur = lo - 1;
            for (auto [mid, i] : ord) {
                while (cur < mid) apply(++cur);
                if (check(i)) R[i] = mid;
                else L[i] = mid + 1;
            }
        }
        return L;
    }
}
