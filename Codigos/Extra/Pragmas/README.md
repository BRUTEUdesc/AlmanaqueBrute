# Pragmas de Otimização

Os pragmas são diretivas para o compilador que podem otimizar o código.

## Pragmas de Otimização

- `#pragma GCC optimize("O2")`: Otimizações padrão de competições
- `#pragma GCC optimize("O3")`: Otimizações mais agressivas (seguro)
- `#pragma GCC optimize("Ofast")`: Otimizações muito agressivas (perigoso!)
- `#pragma GCC optimize("unroll-loops")`: Desenrola loops (pode causar cache misses)

## Pragmas de Target

- `#pragma GCC target("avx2")`: Instruções AVX2
- `#pragma GCC target("sse4")`: Instruções SSE4
- `#pragma GCC target("popcnt")`: Otimiza popcount
- `#pragma GCC target("lzcnt")`: Otimiza leading zero count
- `#pragma GCC target("bmi")`: Bit manipulation instructions
- `#pragma GCC target("bmi2")`: BMI2 instructions

## Combinação Recomendada

```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
```

**Atenção:** Use com moderação. Nem sempre melhora a performance e pode até piorar em alguns casos.
