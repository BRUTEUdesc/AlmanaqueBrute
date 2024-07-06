void floor_values(ll n) {
    ll j = 1;
    while (j <= n) {
        ll floor_now = n / j;
        ll last_j = n / floor_now;
        // j -> primeiro inteiro que tem floor_now como floor
        // last_j -> ultimo inteiro que tem floor_now como floor

        // faz algo

        j = last_j + 1;
    }
}
