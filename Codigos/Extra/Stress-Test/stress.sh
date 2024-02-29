#!/bin/bash
set -e

g++ -O2 gen.cpp -o gen # pode fazer o gerador em python se preferir
g++ -O2 brute.cpp -o brute
g++ -O2 code.cpp -o code

for((i = 1; ; ++i)); do
    ./gen $i > in
    ./code < in > out
    ./brute < in > ok
    diff -w out ok || break
    echo "Passed test: " $i
done

echo "WA no seguinte teste:"
cat in
echo "Sua resposta eh:"
cat out
echo "A resposta correta eh:"
cat ok