# UNION vs UNION ALL

Both `UNION` and `UNION ALL` are used to **combine the results of two or more SELECT queries**.

But the difference is **how they handle duplicates** 👇

***

#### 🔹 1. `UNION`

* Combines results from multiple SELECT queries.
* **Removes duplicate rows** from the final result.
* Performs an **implicit DISTINCT** operation.
* **Slightly slower** because it has to check for duplicates.

**✅ Example:**

```sql
SELECT city FROM customers
UNION
SELECT city FROM suppliers;
```

🧠 Output:

* Returns **unique cities** that appear in either table.
* If both have the same city (e.g., “Delhi”), it appears **only once**.

***

#### 🔹 2. `UNION ALL`

* Combines results **without removing duplicates**.
* Keeps **all rows**, even if they are identical.
* **Faster** because it skips the duplicate check.

**✅ Example:**

```sql
SELECT city FROM customers
UNION ALL
SELECT city FROM suppliers;
```

🧠 Output:

* Returns **all cities**, including duplicates.
* If both have “Delhi”, it appears **twice**.

***

#### ⚙️ Rules for Both

* Each `SELECT` query must have:
  * Same **number of columns**
  * Same **data types** (or compatible ones)
  * Same **column order**

***

#### ⚡ Quick Comparison

| Feature            | UNION                          | UNION ALL                      |
| ------------------ | ------------------------------ | ------------------------------ |
| Removes duplicates | ✅ Yes                          | ❌ No                           |
| Performance        | Slower (checks for dupes)      | Faster                         |
| Use case           | When unique results are needed | When duplicates are meaningful |
| Implicit DISTINCT  | Yes                            | No                             |
