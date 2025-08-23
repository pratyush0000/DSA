# DFS Directed Graph Cycle

Given a Directed Graph with **V** vertices (Numbered from **0** to **V-1**) and **E** edges, check whether it contains any **cycle** or not.\
The graph is represented as a 2D vector **edges\[]\[]**, where each entry **edges\[i] = \[u, v]** denotes an edge from verticex **u** to **v.**

**Examples:**

<pre><code><strong>Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]
</strong>
<strong>Output: true
</strong><strong>Explanation: The diagram clearly shows a cycle 0 → 2 → 0
</strong></code></pre>

<pre><code><strong>Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]
</strong>
<strong>Output: false
</strong><strong>Explanation: no cycle in the graph
</strong></code></pre>

**Constraints:**\
1 ≤ V, E ≤ 10<sup>5</sup>\
u ≠ v



## Solution.

```cpp
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(V,false);
        vector<int> path(V,false);
        for(int i=0; i<adj.size(); i++){
            if(!visited[i]){
                if(checkCycleDFS(i,adj,visited,path)==true){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool checkCycleDFS(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path){
        //mark that node as visited
        visited[node]=true;
        path[node]=true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                if(checkCycleDFS(neighbour,adj,visited,path)==true){
                    return true;
                }
            }
            else if (path[neighbour]) {
                // neighbour already in current recursion stack => cycle
                return true;
            }
        }
        path[node]=false;
        return false;
        
    }
};
```

#### ⏱️ **Time Complexity**

* Building adjacency list: `O(E)` (iterate over all edges once).
* DFS traversal: each node visited once, each edge explored once → `O(V + E)`.
* Total: **`O(V + E)`**

***

#### 🗂️ **Space Complexity**

* Adjacency list: `O(V + E)`
* `visited[]`: `O(V)`
* `path[]`: `O(V)`
* Recursion stack: `O(V)` (in worst case of a deep DFS).
* Total: **`O(V + E)`**

