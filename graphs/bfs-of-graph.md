# BFS of Graph

Given a **connected undirected graph** containing **V** vertices, represented by a 2-d adjacency list **`adj[][]`**, where each `adj[i]` represents the list of vertices connected to vertex `i`. Perform a **Breadth First Search (BFS)** traversal starting from vertex `0`, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

**Note:** Do traverse in the **same order** as they are in the given **adjacency list**.

**Examples:**

<pre><code><strong>Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
</strong>
<strong>Output: [0, 2, 3, 1, 4]
</strong><strong>Explanation: Starting from 0, the BFS traversal will follow these steps: 
</strong>Visit 0 → Output: 0 
Visit 2 (first neighbor of 0) → Output: 0, 2 
Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
</code></pre>

<pre><code><strong>Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
</strong>
<strong>Output: [0, 1, 2, 3, 4]
</strong><strong>Explanation: Starting from 0, the BFS traversal proceeds as follows: 
</strong>Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the next neighbor of 0) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3 
Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4
</code></pre>

**Constraints:**\
1 ≤ V = adj.size() ≤ 10<sup>4</sup>\
1 ≤ adj\[i]\[j] ≤ 10<sup>4</sup>



## Solution.

```cpp
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        //we will use a queue to traverse using bfs
        //since no start vertex is given we will push 0
        
        //ans arr
        vector<int> ans;
        //declare visited array
        vector<int> visited(adj.size(),0);
        //declare a queue for traversal
        queue<int> qq;
        
        qq.push(0);
        visited[0]=1;
        
        //main loop
        while(!qq.empty()){
            
            int node = qq.front();
            qq.pop();
            ans.push_back(node);
            
            
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                if(!visited[i]){
                    qq.push(i);
                    visited[i]=1;   
                }
            }
        }
        
        return ans;
    }
};
```



sc=O(V); ans vector, visited array, queue worst case;

tc=O(V+2E); all vertices visited once all edges explored once from both sides;

