#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = ((k + 1) / n);
    printf("%d\n", ans - 1);
}
