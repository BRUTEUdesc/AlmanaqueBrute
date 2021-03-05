# [Sparse Table](sparse_table.cpp)
Answers queries in an efficient way on a set of static data.\
Does a preprocessing to reduce the time of each query.
* Time complexity (Preprocessing): O(N * log(N))
* Time complexity (Query for non overlap friendly operations): O(N * log(N))
* Time complexity (Query for overlap friendly operations): O(1)
* Space complexity: O(N * log(N))

Example of overlap friendly operations: max(), min(), gcd(), f(x, y) = x
