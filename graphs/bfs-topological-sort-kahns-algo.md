# BFS Topological sort (Kahn's algo)

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
        
        //calculate indegrees for kahn's algo
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto edg : adj[i]){
                indegree[edg]++;
            }
        }
        //now we have all indegrees;
        //dcelare queue and push 0 indegrees
        
        queue<int> qq;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                qq.push(i);
            }
        }
        
        vector<int> ans;
        while(!qq.empty()){
            int node = qq.front();
            qq.pop();
            
            for(auto eges : adj[node]){
                indegree[eges]--;
                //every time an indegree is 0 push it in queue
                if(indegree[eges]==0){
                    qq.push(eges);
                }
            }
            ans.push_back(node);
            
        }
        
        return ans;
    }
};
```

#### ⏱ Time Complexity

* Building adjacency list → `O(E)`
* Computing indegree → `O(V + E)`
* Processing queue (each vertex + edge once) → `O(V + E)`

➡️ Total **O(V + E)**

***

#### 💾 Space Complexity

* Adjacency list → `O(V + E)`
* Indegree array → `O(V)`
* Queue → up to `O(V)`
* Answer vector → `O(V)`

➡️ Total **O(V + E)**

