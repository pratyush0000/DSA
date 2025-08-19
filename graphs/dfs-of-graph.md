# DFS of Graph

Given a **connected undirected graph** containing **V** vertices represented by a 2-d adjacency list **`adj[][]`**, where each `adj[i]` represents the list of vertices connected to vertex `i`. Perform a **Depth First Search (DFS)** traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

**Note:** Do traverse in the **same order** as they are in the given **adjacency list**.

**Examples:**

<pre><code><strong>Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
</strong>
<strong>Output: [0, 2, 4, 3, 1]
</strong><strong>Explanation: Starting from 0, the DFS traversal proceeds as follows:
</strong>Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
</code></pre>

<pre><code><strong>Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
</strong>
<strong>Output: [0, 1, 2, 3, 4]
</strong><strong>Explanation: Starting from 0, the DFS traversal proceeds as follows: 
</strong>Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
</code></pre>

**Constraints:**\
1 ≤ V = adj.size() ≤ 10<sup>4</sup>\
1 ≤ adj\[i]\[j] ≤ 10<sup>4</sup>



## Solution.

```cpp
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        //we will be using stack for dfs
        vector<int> ans;
        vector<int> visited(adj.size(),0);
        
        dfstraversal(0,ans,visited,adj);
        
        return ans;
    }
    
    void dfstraversal(int node, vector<int>& ans, vector<int>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                dfstraversal(it,ans,visited,adj);
            }
        }
    }
};
```



sc=O(V); ans vector, visited array, recusrion stack space;

tc=O(V+2E); all vertices visited once all edges explored once from both sides;

