int inv(int a) {
    int x, y;
    int g = extended_gcd(a, MOD, x, y);
<<<<<<< HEAD:Codigos/Matemática/Inverso-Modular/modular_inverse_coprime.cpp
    if (g == 1) {
        return (x % m + m) % m;
    }
=======
    if (g == 1) {
        return (x % m + m) % m;
    }
>>>>>>> master:Codigos/Matemática/Inverso Modular/modular_inverse_coprime.cpp
    return -1;
}
