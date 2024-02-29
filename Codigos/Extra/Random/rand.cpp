mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
