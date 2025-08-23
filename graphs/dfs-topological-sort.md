# DFS Topological sort

Given a **Directed Acyclic Graph (DAG)** of **V** (0 to V-1) vertices and **E** edges represented as a 2D list of **edges\[]\[]**, where each entry **edges\[i] = \[u, v]** denotes a directed edge u -> v. Return the **topological sort** for the given graph.

> Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge **u -> v**, vertex **u** comes before **v** in the ordering.

**Note:** As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be **true** else **false**.

**Examples:**

<pre><code><strong>Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
</strong>
<strong>Output: true
</strong><strong>Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
</strong>[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
</code></pre>

<pre><code><strong>Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]
</strong>
<strong>Output: true
</strong><strong>Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
</strong>[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
</code></pre>

**Constraints:**\
2  ≤  V  ≤  5 x 10<sup>3</sup>\
1  ≤  E = edges.size()  ≤  min\[10<sup>5</sup>, (V \* (V - 1)) / 2]



## Solution.

```cpp
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //making adj list from edge list
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        //declare stack and store nodes while returning
        stack<int> st;
        vector<int> visited(adj.size(),0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topological(i,st,visited,adj);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
    
    void topological(int node, stack<int>& st, vector<int>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        
        for(auto next : adj[node]){
            if(!visited[next]){
                topological(next,st,visited,adj);
            }
        }
        st.push(node);
    }
};
```

#### **Time Complexity**

1. **Building adjacency list**:\
   You loop over all edges → `O(E)`.
2.  **DFS traversal**:

    * Each vertex is visited once → `O(V)`.
    * Each edge is explored once (when going through adjacency list) → `O(E)`.

    So, DFS = `O(V + E)`.
3. **Stack unwinding / final answer**:\
   Popping all `V` nodes from stack → `O(V)`.

➡️ **Total Time = O(V + E)**\
(the `O(E)` for adjacency list + `O(V + E)` for DFS just collapses to `O(V + E)`).

✅ You got this correct!

***

#### **Space Complexity**

Let’s check carefully:

1. **Adjacency list**:
   * Needs space for `V` lists + `E` entries → `O(V + E)`.
2. **Visited array**:
   * Boolean/int array of size `V` → `O(V)`.
3. **Stack (for topo order)**:
   * At most `V` elements → `O(V)`.
4. **Recursion call stack** (DFS):
   * In the worst case (longest chain) depth = `O(V)`.

***

➡️ **Total Space = O(V + E)**\
(because adjacency list dominates; the rest `O(V)` fits into this bound).

***

#### ✅ Summary

* **Time Complexity**: `O(V + E)`
* **Space Complexity**: `O(V + E)`\
  (Adjacency list + visited + recursion stack + topo stack)

