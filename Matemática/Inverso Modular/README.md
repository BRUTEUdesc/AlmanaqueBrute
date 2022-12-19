# Modular Inverse

The modular inverse of an integer `a` another integer `x` such that `a * x` is congruent to `1 (mod MOD)`.

# [Modular Inverse](modular_inverse.cpp)

Calculates the modular inverse of `a`.
Uses the [exp_mod](Matemática/Exponenciação Modular Rápida/exp_mod.cpp) algorithm, thus expects `MOD` to be prime.
Expects `MOD` to be prime.

* Time Complexity: O(log(MOD)).
* Space Complexity: O(1).

# [Modular Inverse by Extended GDC](modular_inverse_coprime.cpp)

Calculates the modular inverse of `a`.
Uses the [extended_gcd]() algorithm, thus expects `MOD` to be coprime if `a`.
Returns `-1` if this assumption is broken;

* Time Complexity: O(log(MOD)).
* Space Complexity: O(1).

# [Linear Modular Inverse](modular_inverse_linear.cpp)

Calculates the modular inverse for all numbers between `1` and `MAX`.
expects `MOD` to be prime.

* Time Complexity: O(MAX).
* Space Complexity: O(MAX).

