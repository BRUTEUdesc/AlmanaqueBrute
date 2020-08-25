#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7 ;

long long sumoffloor(long long n){
    long long answer = 0, i;
    for (i = 1; i*i <= n; i++) {
        answer += n/i;
        answer %= MOD;
    }
    i--;
    for (int j = 1; n/(j+1) >= i; j++) {
        answer += (((n/j - n/(j+1)) % MOD) * j) % MOD;
        answer %= MOD;
    }
    return  answer;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", sumoffloor(n));
}
