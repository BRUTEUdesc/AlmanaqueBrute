void all_submasks(int mask) {
    for (int sub = mask; sub; sub = (sub - 1) & mask) {
        // faz algo com sub (a submascara vazia, 0, nao eh visitada)
    }
}
