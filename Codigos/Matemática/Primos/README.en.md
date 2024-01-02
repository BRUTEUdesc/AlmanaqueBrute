# Primes

# [Sieve of Eratosthenes](sieve.cpp)
Computes primality of all numbers up to N, almost as fast as the linear sieve.
* Time complexity: O(N * log(log(N)))

Takes 1 second for LIM equals to 3 * 10^7

# [Miller-Rabin](miller_rabin.cpp)
Primality test guaranteed for numbers up to 2^64.
* Time complexity: O(log(N))

# [Naive test](naive_is_prime.cpp)
Computes primality of a number N
* Time complexity: O(N^(1/2))
