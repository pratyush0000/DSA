# Bellman-Ford

Given an weighted graph with **V** vertices numbered from 0 to V-1 and **E** edges, represented by a 2d array **edges\[]\[]**, where **edges\[i] = \[u, v, w]** represents a direct edge from node **u** to **v** having **w** edge weight. You are also given a source vertex **src**.

Your task is to compute the **shortest distances** from the **source** to all other vertices. If a vertex is unreachable from the source, its distance should be marked as **10**<sup>**8**</sup>. Additionally, if the graph contains a **negative weight cycle**, return **\[-1]** to indicate that shortest paths cannot be reliably computed.

**Examples:**

<pre><code><strong>Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
</strong>
<strong>Output: [0, 5, 6, 6, 7]
</strong><strong>Explanation: Shortest Paths:
</strong>For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4
</code></pre>

<pre><code><strong>Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
</strong>
<strong>Output: [-1]
</strong><strong>Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.
</strong></code></pre>

**Constraints:**\
1 ≤ V ≤ 100\
1 ≤ E = edges.size() ≤ V\*(V-1)\
-1000 ≤ w ≤ 1000\
0 ≤ src < V



## Solution.

```cpp
//bellman ford
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        //ans
        int INF = 1e8;
        vector<int> dist(V,INF);
        dist[src]=0;
       
        //no need to build the adj list
        for (int i = 1; i <= V-1; i++) {
            for (auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // Check for negative cycle
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return {-1}; // negative cycle detected
            }
        }
       
        return dist;
    }
};
```

### Explanation of Steps

1. **Adjacency List Construction**
   * Convert `edges[][]` into an adjacency list for efficient traversal.
   * Each entry = `(neighbor, weight)`.
2. **Distance Array**
   * `dist[i]` = shortest distance from `src` to node `i`.
   * Initialize with `INT_MAX`, except `dist[src] = 0`.
3. **Priority Queue (Min-Heap)**
   * Stores `(distance, node)`.
   * Ensures we always process the _closest_ unprocessed node first.
   * Uses `greater<>` to make it a **min-heap**.
4. **Processing Loop**
   * Pop `(d, node)` from the heap.
   * If this entry is outdated (`d > dist[node]`), skip it.
   * For each neighbor, check if going through `node` gives a shorter path.
   * If yes, update `dist[nbr]` and push `(newDist, nbr)` into the heap.

***

### Time Complexity (TC)

* Building adjacency list: **O(V + E)**
* Each edge `(u, v)` is relaxed at most once: **O(E log V)** because pushing into `pq` takes `O(log V)`.
* Total:

O((V+E)log⁡V)O((V + E) \log V)O((V+E)logV)

***

### Space Complexity (SC)

* Adjacency list: **O(V + E)**
* Distance array: **O(V)**
* Priority queue: up to **O(V)** elements in worst case
* Total:

O(V+E)O(V + E)O(V+E)

***

### Key Notes

* Works only with **non-negative weights**.
* If graph had **negative weights**, we’d need **Bellman-Ford** instead.
* Dijkstra guarantees shortest path because we always expand the closest node first.

