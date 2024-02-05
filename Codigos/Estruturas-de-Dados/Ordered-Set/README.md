# [Ordered Set](ordered_set.cpp)

Set com operações de busca por ordem e índice.

Pode ser usado como um $std::set$ normal, a principal diferença são duas novas operações possíveis:

- $find\_by\_order(k)$: retorna um iterador para o k-ésimo menor elemento no set (indexado em 0).
- $order\_of\_key(k)$: retorna o número de elementos menores que k. (ou seja, o índice de k no set)

Ambas as operações são $\mathcal{O}(log(n))$.

Também é possível criar um $ordered\_map$, funciona como um $std::map$, mas com as operações de busca por ordem e índice. $find\_by\_order(k)$ retorna um iterador para a k-ésima menor **key** no mapa (indexado em 0). $order\_of\_key(k)$ retorna o número de **keys** no mapa menores que k. (ou seja, o índice de k no map).

Para simular um $std::multiset$, há várias formas:

- Usar um $std::pair$ como elemento do set, com o primeiro elemento sendo o valor e o segundo sendo um identificador único para cada elemento. Para saber o número de elementos menores que $k$ no multiset, basta usar $order\_of\_key({k, -INF})$.

- Usar um $ordered\_map$ com a key sendo o valor e o value sendo o número de ocorrências do valor no multiset. Para saber o número de elementos menores que $k$ no multiset, basta usar $order\_of\_key(k)$.

- Criar o $ordered\_set$ substituindo o parâmetro $less<T>$ por $less\_equal<T>$. Isso faz com que o set aceite elementos repetidos, e $order\_of\_key(k)$ retorna o número de elementos menores ou iguais a $k$ no multiset. Porém esse método não é recomendado pois gera algumas inconsistências, como por exemplo: $upper\_bound$ funciona como $lower\_bound$ e vice-versa, $find$ sempre retorna $end()$ e $erase$ por valor não funciona, só por iterador. Dá pra usar se souber o que está fazendo.

Exemplo de uso do $ordered\_set$:

```cpp
ordered_set<int> X;
X.insert(1);
X.insert(2);
X.insert(4);
X.insert(8);
X.insert(16);
cout << *X.find_by_order(1) << endl; // 2
cout << *X.find_by_order(2) << endl; // 4
cout << *X.find_by_order(4) << endl; // 16
cout << (end(X) == X.find_by_order(5)) << endl; // true
cout << X.order_of_key(-5) << endl;  // 0
cout << X.order_of_key(1) << endl;   // 0
cout << X.order_of_key(3) << endl;   // 2
cout << X.order_of_key(4) << endl;   // 2
cout << X.order_of_key(400) << endl; // 5
```

Exemplo de uso do $ordered\_map$:

```cpp
ordered_map<int, int> Y;
Y[1] = 10;
Y[2] = 20;
Y[4] = 40;
Y[8] = 80;
Y[16] = 160;
cout << Y.find_by_order(1)->first << endl; // 2
cout << Y.find_by_order(1)->second << endl; // 20
cout << Y.order_of_key(5) << endl; // 3
cout << Y.order_of_key(10) << endl; // 4
cout << Y.order_of_key(4) << endl; // 2
```
