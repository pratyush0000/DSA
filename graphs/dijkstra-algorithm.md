# Dijkstra Algorithm

Given an undirected, weighted graph with **V** vertices numbered from 0 to V-1 and **E** edges, represented by 2d array **edges\[]\[]**, where edges\[i]=\[u, v, w] represents the **edge** between the nodes u and v having w **edge weight**.\
You have to find the **shortest distance** of all the vertices from the source vertex **src**, and return an array of integers where the **ith** element denotes the shortest distance between **ith** node and source vertex **src**.

**Note:** The Graph is connected and doesn't contain any negative weight edge.

**Examples:**

<pre><code><strong>Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
</strong><strong>Output: [4, 3, 0]
</strong><strong>Explanation:
</strong>
Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
</code></pre>

<pre><code><strong>Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
</strong><strong>Output: [0, 4, 8, 10, 10]
</strong><strong>Explanation: 
</strong>
Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
</code></pre>

**Constraints:**\
1 ≤ V ≤ 10<sup>5</sup>1 ≤ E = edges.size() ≤ 10<sup>5</sup>\
0 ≤ edges\[i]\[j] ≤ 10<sup>4</sup>0 ≤ src < V



## Solution.

```cpp
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //build adj list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // since graph is undirected
        }
        
        //distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        //Min-heap (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        //process
        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();

            if (d > dist[node]) continue; // Skip outdated entry

            for (auto &[nbr, wt] : adj[node]) {
                if (dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
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

