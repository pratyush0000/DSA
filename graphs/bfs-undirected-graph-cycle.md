# BFS Undirected Graph Cycle

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
                if(detectCycle(i,adj,visited)==true){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool detectCycle(int V, vector<vector<int>>& adj, vector<int>& visited){
        //mark current node visited and push to queue
        visited[V] = true;
        queue<pair<int,int>> qq;
        qq.push({V,-1});
        
        while(!qq.empty()){
            int node = qq.front().first;
            int parent = qq.front().second;
            qq.pop();
            
            for(auto nei : adj[node]){ 
                if(!visited[nei]){
                    visited[nei] = 1;
                    qq.push({nei, node});
                }
                else if(nei != parent){
                    //automatically checked that it is visited
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
```



#### 🔹 Time Complexity (TC)

1. **Building adjacency list**:
   * You loop through all `E` edges, and for each edge push into adjacency list twice (u→v, v→u).
   * Cost = **O(E)**.
2. **BFS traversal (detectCycle)**:
   * Across the whole graph, every vertex is enqueued once, and every edge is checked at most twice (once from each endpoint).
   * Cost = **O(V + E)**.

👉 **Total TC = O(V + E)**

***

#### 🔹 Space Complexity (SC)

1. **Adjacency list**:
   * Stores all edges, so **O(V + E)**.
2. **Visited array**:
   * Size = V → **O(V)**.
3. **Queue**:
   * In the worst case, all vertices of a component could be in the queue at the same time → **O(V)**.

👉 **Total SC = O(V + E)**

***

✅ **Final Answer**:

* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V + E)`

