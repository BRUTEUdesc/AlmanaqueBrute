
double eval(double mid) {
    // implement the evaluation
}

double ternary_search(double l, double r) {
    int k = 100;
    while (k--) {
        double step = (l + r) / 3;
        double mid_1 = l + step;
        double mid_2 = r - step;

        // minimizing. To maximize use >= to compare
        if (eval(mid_1) <= eval(mid_2)) {
            r = mid_2;
        } else {
            l = mid_1;
        }
    }
    return l;
}
