# [Seg Tree](seg_tree.cpp)
Standard implementation of Segment Tree.
* Time complexity (Preprocessing): O(N)
* Time complexity (Query): O(log(N))
* Time complexity (Update): O(log(N))
* Space complexity: 4 * N = O(N)

# [Seg Tree with Lazy Propagation](seg_tree_lazy.cpp)
Standard implementation of Segment Tree with Lazy Propagation Updates.
* Time complexity (Preprocess): O(N)
* Time complexity (Query): O(log(N))
* Time complexity (Node update): O(log(N))
* Time complexity (Range update): O(log(N))
* Complexidade de espaço: 2 * 4 * N = O(N)

# [Seg Tree Beats](seg_tree_beats.cpp)
Seg Tree that supports max update and sum query.
* Complexidade de tempo (Pré-processamento): O(N)
* Complexidade de tempo (Query): O(log(N))
* Complexidade de tempo (Node update): O(log(N))
* Complexidade de tempo (Range update): O(log(N))
* Complexidade de espaço: 2 * 4 * N = O(N)

# [Seg Tree Beats Max and Sum update](seg_tree_beats_max_and_sum_update.cpp)
Seg Tree that supports max and sum update. Also supports sum query.
Uses a lazy queue to differentiate updates.
* Complexidade de tempo (Preprocess): O(N)
* Complexidade de tempo (Query): O(log(N))
* Complexidade de tempo (Node update): O(log(N))
* Complexidade de tempo (Range update): O(log(N))
* Complexidade de espaço: 2 * 4 * N = O(N)
