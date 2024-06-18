vector<int> get_divs(int n) {
    vector<int> divs;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divs.push_back(d);
            if (d * d != n) divs.push_back(n / d);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}
