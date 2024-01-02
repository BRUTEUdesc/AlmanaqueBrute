# [Simple DSU](dsu.cpp)
Structure for handling sets\
Verifies if two itens belong to the same group.
* Time complexity: O(1) amortized

Unifies groups.
* Time complexity: O(1) amortized

# [Bipartite DSU](bipartite_dsu.cpp)
DSU for bipartite graph, it's possible to verify if some edge is possible before adding it.\
For every operation
* Time complexity: O(1) amortized

# [DSU with Rollback](rollback_dsu.cpp)
Undo the last K unions
* Time complexity: O(K)

It's possible to use a checkpoint, then just call rollback() to go to the last checkpoint\
The rollback doesn't change the complexity, since K <= queries.\
**Only works without path compression**
* Time complexity: O(log(N))

# [Complete DSU](full_dsu.cpp)
DSU with capacity of adding and removing vertices.\
**EXTREMELY POWERFUL!**\
Works offline, receiving operations and giving the answers to the queries as return of the function run.
* Time complexity: O(Q * log(Q) * log(N)); Where Q is the number of queries and N the number of nodes.

Runs in 0,6ms for 3 * 10^5 queries and nodes with printf and scanf  
Possibly handles 10^6 in 3s.
