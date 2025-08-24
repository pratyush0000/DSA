# Kosaraju’s Algorithm — Strongly Connected Components (SCC)

A **Strongly Connected Component** in a directed graph is a maximal set of vertices where each vertex is reachable from every other vertex in the set.

Kosaraju’s algorithm finds all SCCs in **3 clean steps**:

***

### 0) Setup

* Input: directed graph `G(V, E)` as adjacency list.
* Data:
  * `visited[V]` (bool/int)
  * a stack/list `order` to store vertices by **finish time** (postorder)
  * `G^T` = transpose graph (all edges reversed)

***

### 1) DFS to get finishing order (Topo-by-finish-time)

**Goal:** push nodes to `order` _after_ exploring all their outgoing edges.

**Process:**

* Initialize `visited = 0`.
* For each vertex `u` from `0..V-1`:
  * If `!visited[u]`, run `dfs1(u)`:
    * mark visited
    * for each `v` in `adj[u]`, if unvisited, recurse `dfs1(v)`
    * after the loop, **push `u` into `order`**

This records vertices by **decreasing finish time** (the last finished on top).

***

### 2) Build the transpose graph `G^T`

Reverse every edge: for each directed edge `u -> v` in `G`, add `v -> u` in `G^T`.

***

### 3) DFS on the transpose in reverse finish order

**Goal:** each DFS tree now yields one SCC.

**Process:**

* Reset `visited = 0`.
* Traverse vertices in **reverse of `order`** (i.e., pop from stack or iterate from back).
* For each vertex `u` in that order:
  * If `!visited[u]`, run `dfs2(u)` on `G^T`:
    * collect all reached nodes → that set is **one SCC**
    * (store/print this component as needed)

***

### Why it works (intuition)

* In the original graph, finishing times ensure that when you start from a node in some SCC, you finish exploring **all edges inside or forward from it** before pushing.
* Reversing edges makes all edges **between SCCs** point _toward_ previously finished components.
* Processing vertices by decreasing finish time guarantees that when you start a DFS on `G^T`, you **can’t escape** your SCC to a not-yet-visited one—so the DFS stays exactly within one SCC and captures it fully.

***

### Complexity

* Building/using adjacency lists: **O(V + E)**
* First DFS pass: **O(V + E)**
* Transpose build: **O(V + E)**
* Second DFS pass: **O(V + E)**
* **Total:** **O(V + E)** time, **O(V + E)** space

***

### Common pitfalls

* Don’t forget to **reset `visited`** before the second pass.
* Push to `order` **after** exploring neighbors (postorder).
* Be careful with **recursion depth** on very large graphs (use iterative DFS if needed).
* Make sure to **reverse all edges** correctly when building `G^T`.
