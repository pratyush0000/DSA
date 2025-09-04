---
description: this problem is to be done on vscode as no leetcode question exists for it
---

# Tree Of Space (JusPay)

### Problem Statement

You are given a **complete balanced N-ary tree** with `n` nodes.

* The nodes are numbered from `0` to `n-1`.
* Node `0` is the root of the tree.
* You need to support `q` queries of three types:

***

#### 1. **lock(v, id)**

Lock the node `v` for user `id` **if and only if**:

* Node `v` is **not already locked**.
* None of the **ancestors** of `v` are locked.
* None of the **descendants** of `v` are locked.

✅ If successful, return `true` and mark `v` as locked by `id`.\
❌ Otherwise, return `false`.

***

#### 2. **unlock(v, id)**

Unlock the node `v` **if and only if**:

* Node `v` is **currently locked**.
* It is locked by the **same user `id`**.

✅ If successful, return `true`.\
❌ Otherwise, return `false`.

***

#### 3. **upgrade(v, id)**

Upgrade the node `v` for user `id` **if and only if**:

* Node `v` is **not locked**.
* At least one **descendant** of `v` is locked.
* All locked descendants are locked by the **same user `id`**.
* None of the **ancestors** of `v` are locked.

✅ If successful:

* Unlock all locked descendants of `v`.
* Lock `v` with `id`.
* Return `true`.

❌ Otherwise, return `false`.

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

Where:

* `n` → total number of nodes.
* `m` → branching factor (N-ary tree degree).
* `q` → number of queries.
* `pi` → parent of node `i`, with `-1` for the root.
*   Each query is one of:

    ```
    lock v id
    unlock v id
    upgrade v id
    ```

***

### Output Format

For each query, print:

* `true` → if the operation was successful.
* `false` → otherwise.

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



#### Input 2

```
9 3 7
-1 0 0 0 1 1 2 2 3
lock 4 1
lock 5 1
upgrade 1 1
lock 7 2
lock 8 1
unlock 8 2
upgrade 0 1

```

#### Explanation

* `n = 9`, `m = 3` (ternary tree), `q = 7`.
*   Parent array:

    ```
    index: 0 1 2 3 4 5 6 7 8
    value: -1 0 0 0 1 1 2 2 3
    ```

    Tree structure:

    ```
               0
            /  |  \
           1   2   3
         /  \  | \   \
        4   5  6  7   8
    ```

***

#### Queries step by step

1. **lock 4 1** → true (node 4 locked by user 1)
2. **lock 5 1** → true (node 5 locked by user 1)
3. **upgrade 1 1** → true (unlocks 4 & 5, locks 1 by user 1)
4. **lock 7 2** → true (node 7 locked by user 2)
5. **lock 8 1** → true (node 8 locked by user 1)
6. **unlock 8 2** → false (wrong user, node 8 locked by user 1)
7. **upgrade 0 1** → false (fails because locked descendant 7 is owned by user 2, not 1)

#### Output 2

```
true
true
true
true
true
false
false

```







## Solution.



