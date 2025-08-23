# DFS Undirected Graph Cycle

Given an **undirected graph** with **V** vertices and **E** edges, represented as a 2D vector **edges\[]\[]**, where each entry **edges\[i] = \[u, v]** denotes an edge between vertices **u** and **v**, determine whether the graph contains a **cycle** or not. The graph can have multiple component.![](file:///C:/Users/Mukul%20kumar/Desktop/GFG_PIC.JPG)

**Examples:**

<pre><code><strong>Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
</strong><strong>Output: true
</strong><strong>Explanation: 
</strong> 
1 -> 2 -> 0 -> 1 is a cycle.
</code></pre>

<pre><code><strong>Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
</strong><strong>Output: false
</strong><strong>Explanation: 
</strong> 
No cycle in the graph.
</code></pre>

**Constraints:**\
1 ≤ V ≤ 10<sup>5</sup>\
1 ≤ E = edges.size() ≤ 10<sup>5</sup>



## Solution.

```cpp
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        //build adj list from edge list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //do the check
        vector<int> visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(detectCycleDFS(i,-1,adj,visited)==true){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool detectCycleDFS(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        //mark current node visited and push to queue
        visited[node] = true;
        
        for(auto nei : adj[node]){ 
            if(!visited[nei]){
                if(detectCycleDFS(nei, node, adj, visited)==true){
                    return true;
                }
            }
            else if(nei != parent){
                return true;
            }
        }
        return false;
    }
};
```



* **Time Complexity**:
  * Visit each node once → `O(V)`
  * Explore each edge twice (undirected) → `O(E)`\
    ✅ `O(V + E)`
* **Space Complexity**:
  * Adjacency list: `O(V + E)`
  * Visited array: `O(V)`
  * **Recursion stack**: up to `O(V)` in the worst case (chain graph).\
    ✅ `O(V + E)`

***

✅ **Final Answer**:

* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V + E)`

