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

