---
description: this problem is to be done on vscode as no leetcode question exists for it
---

# Tree Of Space (JusPay)

Locking & Unlocking an N-ary Tree

### Problem

You are given a **complete, balanced N-ary tree** with `n` nodes, numbered `0 … n-1`.\
Node `0` is the root. You must process `q` queries of three types:

#### 1) `lock(v, id)`

Lock node `v` for user `id` **iff**:

* `v` is **not already locked**,
* **no ancestor** of `v` is locked,
* **no descendant** of `v` is locked.

On success, mark `v` locked by `id` and print `true`, otherwise print `false`.

#### 2) `unlock(v, id)`

Unlock node `v` **iff**:

* `v` is currently **locked**, and
* it is locked by the **same user `id`**.

On success print `true`, otherwise `false`.

#### 3) `upgrade(v, id)`

Upgrade node `v` **iff**:

* `v` is **not locked**,
* `v` has **at least one locked descendant**,
* **every locked descendant** of `v` is locked by **the same `id`**,
* **no ancestor** of `v` is locked.

On success:

* unlock all locked descendants of `v`,
* lock `v` with `id`,
* print `true`; otherwise print `false`.

> 💡 Note: This problem **disallows locking** a node if **any** ancestor **or** descendant is locked (by **any** user).\
> `unlock` requires the same `id`.\
> `upgrade` both checks the uniform `id` among locked descendants and performs the bulk unlock + lock.

***

### Input Format

```
n m q
p0 p1 p2 ... p(n-1)
<query1>
<query2>
...
<queryq>
```

* `n` — number of nodes (0 to n-1)
* `m` — branching factor (tree arity); included for completeness (you can build from `parent[]`)
* `q` — number of queries
* `pi` — parent of node `i` (`-1` for the root)
*   Each query is one of:

    ```
    lock v id
    unlock v id
    upgrade v id
    ```

### Output Format

For each query, print `true` or `false` on its own line.

***

### Sample A (Binary tree)

**Input**

```
7 2 9
-1 0 0 1 1 2 2
lock 2 1
lock 2 2
unlock 2 2
unlock 2 1
lock 4 2
upgrade 1 2
lock 4 2
lock 5 3
upgrade 0 2
```

Tree from parent array (m=2):

```
        0
      /   \
     1     2
    / \   / \
   3  4  5   6
```

**Output**

```
true
false
false
true
true
true
false
true
false
```

**Why (high level)**

* Lock 2 by 1 ✅
* Lock 2 by 2 ❌ (already locked)
* Unlock 2 by 2 ❌ (wrong user)
* Unlock 2 by 1 ✅
* Lock 4 by 2 ✅
* Upgrade 1 by 2 ✅ (descendants {4} all by 2 → unlock 4, lock 1)
* Lock 4 by 2 ❌ (ancestor 1 is locked)
* Lock 5 by 3 ✅
* Upgrade 0 by 2 ❌ (locked descendants have ids {2,3} → mixed)

***

### Sample B (Ternary tree)

**Input**

```
9 3 9
-1 0 0 0 1 1 2 2 3
lock 4 1
lock 5 1
upgrade 1 1
lock 7 2
lock 8 1
unlock 8 2
upgrade 0 1
unlock 7 2
upgrade 0 1
```

Tree from parent array (m=3):

```
            0
         /  |  \
        1   2   3
      /  \  | \   \
     4   5  6  7   8
```

**Output**

```
true
true
true
true
true
false
false
true
true
```

**Why (high level)**

* Lock 4 by 1 ✅
* Lock 5 by 1 ✅
* Upgrade 1 by 1 ✅ (unlock {4,5}, lock 1)
* Lock 7 by 2 ✅
* Lock 8 by 1 ✅
* Unlock 8 by 2 ❌ (wrong user)
* Upgrade 0 by 1 ❌ (locked descendants include id 2 at node 7 → mixed)
* Unlock 7 by 2 ✅
* Upgrade 0 by 1 ✅ (now all locked descendants are id 1 → unlock 1, lock 0)





## Solution.

```cpp
#include <bits/stdc++.h>
using namespace std;

//struct of the node
struct Node{ 
    int val; //stores value of the node
    int lockedBy; //stores who locked the node(if any)
    bool isLocked; //bool to return if it is locked or not
    Node* parent; //whos the parent?
    vector<Node*> children; //vector filled with children nodes

    Node(int v){
        val = v;
        lockedBy = -1;
        isLocked = false;
        parent = nullptr;
    }
};


class Tree{
    vector<Node*> nodes;
public:
    Tree(int n, vector<int>& parent) {
        nodes.resize(n);
        //making all nodes
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        //connecting to parents
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                nodes[i]->parent = nodes[parent[i]];
                nodes[parent[i]]->children.push_back(nodes[i]);
            }
        }
    }


    bool lock(int v, int id){
        //condition check
        //v is not already locked
        if(nodes[v]->isLocked==true) return false;
        
        //no ancestor of v is locked
        Node* cur = nodes[v]->parent;
        while (cur != nullptr) {
            if (cur->isLocked) return false;  // found locked ancestor
            cur = cur->parent;               // go one level up
        }

        //no descendant of v is locked
        queue<Node*> qq;
        for (Node* child : nodes[v]->children) {
            qq.push(child); //start from children as node is already checked
        }
        while(!qq.empty()){
            Node* curr = qq.front();
            qq.pop();

            if(curr->isLocked) return false;
            for(int i=0; i<curr->children.size(); i++){
                qq.push(curr->children[i]);
            }
        }

        //lock
        nodes[v]->isLocked=true;
        nodes[v]->lockedBy=id;
        return true;
    }

    bool unlock(int v, int id){
        //condition check
        //v is locked
        if(nodes[v]->isLocked==false) return false;

        //it is locked by the same user id.
        if(nodes[v]->lockedBy!=id) return false;

        //unlock
        nodes[v]->isLocked=false;
        nodes[v]->lockedBy=-1;
        return true;
    }

    bool upgrade(int v, int id){
        //condition check
        //v is not locked
        if(nodes[v]->isLocked) return false;

        //v has at least one locked descendant
        //every locked descendant of v is locked by the same id
        queue<Node*> qq;
        for (Node* child : nodes[v]->children) {
            qq.push(child); //start from children as node is already checked
        }
        int lockedcount=0;
        while(!qq.empty()){
            Node* curr = qq.front();
            qq.pop();

            if(curr->isLocked){
                if(curr->lockedBy!=id) return false;
                lockedcount++;
            }
            for (auto child : curr->children) {
                qq.push(child);
            }
        }
        if(lockedcount==0) return false;

        //no ancestor of v is locked
        Node* cur = nodes[v]->parent;
        while (cur != nullptr) {
            if (cur->isLocked) return false;  // found locked ancestor
            cur = cur->parent;               // go one level up
        }

        //if you have reached this part you are successful
        //On success:
        //unlock all locked descendants of v
        queue<Node*> upgradeQ;
        for (Node* child : nodes[v]->children) {
            upgradeQ.push(child); //start from children as node is already checked
        }
        while(!upgradeQ.empty()){
            Node* curr = upgradeQ.front();
            upgradeQ.pop();

            if(curr->isLocked){
                curr->isLocked = false;
                curr->lockedBy = -1;
            }
            for (auto child : curr->children) {
                upgradeQ.push(child);
            }
        }

        //lock v with id
        nodes[v]->isLocked=true;
        nodes[v]->lockedBy=id;

        return true;
    }

    ~Tree() {
        for (auto node : nodes) {
            delete node;
        }
    }
};



int main() {
    int n,m,q;
    cin>>n>>m>>q;

    //build tree
    vector<int> parent(n);
    for (int i = 0; i < n; i++) cin >> parent[i];
    Tree tree(n, parent);

    //process queries
    for(int i=0; i<q; i++){
        string op;
        int v,id;

        cin>>op>>v>>id;
        bool res = false;
        if (op == "lock") res = tree.lock(v, id);
        else if (op == "unlock") res = tree.unlock(v, id);
        else if (op == "upgrade") res = tree.upgrade(v, id);

        cout << (res ? "true" : "false") << "\n";
    }

    return 0;
}
```



#### ⏱ **Time Complexity**

* **`lock(v, id)`**
  * Checks ancestors → at most `O(height)` = `O(n)` in worst case.
  * Checks all descendants with BFS → `O(descendants)` = `O(n)` in worst case.
  * ✅ So overall: **`O(n)`**.
* **`unlock(v, id)`**
  * Just a couple of checks and assignments → **`O(1)`**.
* **`upgrade(v, id)`**
  * Checks descendants with BFS → `O(n)` in worst case.
  * Checks ancestors → `O(height)` = `O(n)` in worst case.
  * Unlocks descendants (another BFS) → `O(n)` in worst case.
  * ✅ So overall: **`O(n)`**.
* **For `q` queries**
  * Worst case: every query is a `lock` or `upgrade`.
  * ✅ Total = **`O(q * n)`**.

***

#### 🗂 **Space Complexity**

* Each `Node` stores: value, lock info, parent, children list → `O(n)`.
* BFS queues in `lock`/`upgrade` → at most `O(n)`.
* ✅ So overall: **`O(n)`**.

***



