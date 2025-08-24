---
icon: puzzle-piece
---

# Topological Sort (DFS + Kahn’s Algorithm)

### 🔹 What is Topological Sort?

* A **linear ordering of vertices** in a **Directed Acyclic Graph (DAG)**.
* For every directed edge `u → v`, `u` comes **before** `v` in the ordering.
* Works **only on DAGs** (Directed Acyclic Graphs).

***

### 🔹 Why is it useful?

* Used in:
  * **Task scheduling** (order of jobs with dependencies)
  * **Course prerequisites** (finish course A before course B)
  * **Build systems / compilers** (compile dependencies first)

***

### 🔹 Methods to find Topological Sort

There are **two main ways**:

***

#### 1. DFS Based Approach

* Do a **DFS** traversal.
* When a node finishes (all its neighbors explored), push it into a **stack**.
* At the end, popping from the stack gives topological order.

**Steps:**

1. Build adjacency list.
2. Maintain a `visited` array.
3. Perform DFS:
   * Mark current node visited.
   * Recursively DFS on neighbors.
   * Push node into stack after exploring all neighbors.
4. Pop elements from stack → topological order.

**Time Complexity:** `O(V + E)`\
**Space Complexity:** `O(V + E)`

***

#### 2. Kahn’s Algorithm (BFS Based)

* Works using **indegree** of nodes.
* Nodes with `indegree = 0` (no incoming edges) can appear first in topo order.

**Steps:**

1. Build adjacency list.
2. Compute `indegree` of every node.
3. Push all nodes with `indegree = 0` into a queue.
4. While queue not empty:
   * Pop a node → add it to topo order.
   * Reduce indegree of its neighbors by 1.
   * If any neighbor’s indegree becomes 0 → push into queue.
5. Result = Topological order.

⚠️ If topo order does **not contain all nodes**, the graph has a **cycle** (not a DAG).

**Time Complexity:** `O(V + E)`\
**Space Complexity:** `O(V + E)`

***

### 🔹 Key Difference

| DFS Approach                           | Kahn’s Algorithm (BFS)                   |
| -------------------------------------- | ---------------------------------------- |
| Uses recursion + stack                 | Uses queue + indegree array              |
| Push nodes after exploring neighbors   | Process nodes when indegree becomes 0    |
| Order from stack pop                   | Order from queue sequence                |
| Detect cycle? ❌ (needs extra handling) | Detect cycle? ✅ (if topo sort < V nodes) |

***

✅ **Conclusion:**\
Both methods work in `O(V + E)` time and space.

* **DFS** is simpler when recursion is okay.
* **Kahn’s (BFS)** is better if you also need **cycle detection**.
