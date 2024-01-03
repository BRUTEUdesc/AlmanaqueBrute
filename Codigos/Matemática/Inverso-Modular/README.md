# Modular Inverse

The modular inverse of an integer `a` is another integer `x` such that `a * x` is congruent to `1 (mod MOD)`.

# [Modular Inverse](modular_inverse.cpp)

Calculates the modular inverse of `a`.

Uses the [exp_mod](/Matemática/Exponenciação%20Modular%20Rápida/exp_mod.cpp) algorithm, thus expects `MOD` to be prime.

* Time Complexity: O(log(MOD)).
* Space Complexity: O(1).

# [Modular Inverse by Extended GDC](modular_inverse_coprime.cpp)

Calculates the modular inverse of `a`.

Uses the [extended_gcd](/Matemática/GCD/extended_gcd.cpp) algorithm, thus expects `MOD` to be coprime with `a`.

Returns `-1` if this assumption is broken.

* Time Complexity: O(log(MOD)).
* Space Complexity: O(1).

# [Modular Inverse for 1 to MAX](modular_inverse_linear.cpp)

Calculates the modular inverse for all numbers between `1` and `MAX`.

expects `MOD` to be prime.

* Time Complexity: O(MAX).
* Space Complexity: O(MAX).

# [Modular Inverse for all powers](modular_inverse_pow.cpp)

Let `b` be any integer.

Calculates the modular inverse for all powers of `b` between `b^0` and `b^MAX`.

Needs you calculate beforehand the modular inverse of `b`, for 2 it is always `(MOD+1)/2`.

expects `MOD` to be coprime with `b`.

* Time Complexity: O(MAX).
* Space Complexity: O(MAX).
