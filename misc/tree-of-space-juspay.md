---
description: this problem is to be done on vscode as no leetcode question exists for it
---

# Tree Of Space (JusPay)

### Problem Statement

You are given a **complete balanced N-ary tree** with `n` nodes.\
The nodes are numbered from `0` to `n-1`, with node `0` as the root.

You need to support `q` queries of three types:

#### 1. `lock(v, id)`

Lock the node `v` for user `id` **if and only if**:

* Node `v` is currently **not locked**.
* **No ancestors** of `v` are locked.
* **No descendants** of `v` are locked.

If successful, return `true` and mark `v` as locked by `id`. Otherwise, return `false`.

***

#### 2. `unlock(v, id)`

Unlock the node `v` **if and only if**:

* `v` is currently locked.
* It is locked by the **same user id**.

If successful, return `true`. Otherwise, return `false`.

***

#### 3. `upgrade(v, id)`

Upgrade the node `v` **if and only if**:

* `v` is currently **not locked**.
* At least **one descendant** of `v` is locked.
* **All locked descendants** are locked by the **same user id** (`id`).
* No ancestor of `v` is locked.

If successful:

* Unlock all locked descendants.
* Lock `v` with `id`.

Return `true`. Otherwise, return `false`.

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

* `n` → number of nodes in the tree.
* `m` → branching factor (N-ary tree degree).
* `q` → number of queries.
* The next line gives the **parent of each node** `i` (`pi`), with `-1` for the root.
* Each query is one of:
  * `lock v id`
  * `unlock v id`
  * `upgrade v id`

***

### Output Format

For each query, print `true` or `false` depending on whether the operation was successful.

***

### Example

#### Input

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

#### Output

```
true
false
false
true
true
true
true
false
true
```





