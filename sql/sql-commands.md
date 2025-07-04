# SQL COMMANDS

## Complete SQL Commands Reference

This document provides a comprehensive guide to SQL commands, including syntax, descriptions, and examples. Suitable for beginners and intermediate users alike.

***

### 📘 Table of Contents

1. Basic Querying
2. Filtering
3. Sorting and Limiting
4. Data Manipulation (DML)
5. Data Definition (DDL)
6. Constraints
7. Joins Explained
8. Aggregations & Grouping
9. Subqueries
10. Views
11. Transactions
12. Functions
13. Case Statement
14. Tips

***

### Basic Querying

#### SELECT

Retrieves data from one or more columns in a table.

```sql
SELECT column1, column2 FROM table_name;
SELECT * FROM employees;
```

#### DISTINCT

Removes duplicate values from the result set.

```sql
SELECT DISTINCT department FROM employees;
```

***

### Filtering

#### WHERE

Filters records that meet specific criteria.

```sql
SELECT * FROM employees WHERE salary > 50000;
```

#### IN

Checks if a value matches any value in a list.

```sql
SELECT * FROM employees WHERE department IN ('HR', 'Finance');
```

#### BETWEEN

Filters values within a specific range.

```sql
SELECT * FROM employees WHERE age BETWEEN 25 AND 35;
```

#### LIKE

Used for pattern matching.

```sql
SELECT * FROM employees WHERE name LIKE 'A%';
```

#### IS NULL / IS NOT NULL

Checks for missing (null) values.

```sql
SELECT * FROM employees WHERE phone IS NULL;
```

***

### Sorting and Limiting

#### ORDER BY

Sorts the result set by one or more columns.

```sql
SELECT name, age FROM employees ORDER BY age DESC;
```

#### LIMIT / TOP

Restricts the number of returned rows.

```sql
SELECT * FROM products LIMIT 10;
-- SQL Server
SELECT TOP 10 * FROM products;
```

***

### Data Manipulation (DML)

#### INSERT

Adds new records to a table.

```sql
INSERT INTO employees (name, age, department) VALUES ('Alice', 30, 'HR');
```

#### UPDATE

Modifies existing records.

```sql
UPDATE employees SET salary = salary + 5000 WHERE department = 'HR';
```

#### DELETE

Removes records that match a condition.

```sql
DELETE FROM employees WHERE age < 25;
```

***

### Data Definition (DDL)

#### CREATE TABLE

Creates a new table in the database.

```sql
CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    department VARCHAR(50)
);
```

#### ALTER TABLE

Modifies an existing table structure.

```sql
ALTER TABLE employees ADD salary DECIMAL(10,2);
ALTER TABLE employees DROP COLUMN age;
```

#### DROP TABLE

Completely removes a table and its data.

```sql
DROP TABLE employees;
```

#### TRUNCATE TABLE

Removes all rows from a table but keeps the structure.

```sql
TRUNCATE TABLE employees;
```

***

### Constraints

Constraints define rules for data in a table.

```sql
CREATE TABLE employees (
    id INT PRIMARY KEY, -- Unique identifier
    name VARCHAR(100) NOT NULL, -- Cannot be null
    email VARCHAR(100) UNIQUE, -- Must be unique
    age INT CHECK (age >= 18), -- Must be 18 or older
    active BOOLEAN DEFAULT TRUE -- Defaults to TRUE
);
```

***

### Joins Explained

#### INNER JOIN

Returns rows with matching values in both tables.

```sql
SELECT employees.name, departments.name AS department
FROM employees
INNER JOIN departments ON employees.department_id = departments.id;
```

#### LEFT JOIN

Returns all records from the left table and matched ones from the right.

```sql
SELECT employees.name, departments.name AS department
FROM employees
LEFT JOIN departments ON employees.department_id = departments.id;
```

#### RIGHT JOIN

Returns all records from the right table and matched ones from the left.

```sql
SELECT employees.name, departments.name AS department
FROM employees
RIGHT JOIN departments ON employees.department_id = departments.id;
```

#### FULL OUTER JOIN

Returns all records from both tables, matching where possible.

```sql
SELECT employees.name, departments.name AS department
FROM employees
FULL OUTER JOIN departments ON employees.department_id = departments.id;
```

#### CROSS JOIN

Returns a Cartesian product of both tables.

```sql
SELECT a.name, b.product
FROM customers a
CROSS JOIN products b;
```

#### SELF JOIN

Joins a table to itself, useful for hierarchical data.

```sql
SELECT A.name AS Employee, B.name AS Manager
FROM employees A
JOIN employees B ON A.manager_id = B.id;
```

***

### Aggregations & Grouping

#### COUNT, SUM, AVG, MIN, MAX

Performs calculations on data.

```sql
SELECT COUNT(*) FROM employees;
SELECT AVG(salary) FROM employees;
SELECT MIN(age), MAX(age) FROM employees;
```

#### GROUP BY

Groups records by one or more columns.

```sql
SELECT department, AVG(salary)
FROM employees
GROUP BY department;
```

#### HAVING

Filters groups of data after aggregation.

```sql
SELECT department, COUNT(*)
FROM employees
GROUP BY department
HAVING COUNT(*) > 5;
```

***

### Subqueries

A query inside another query, often used in WHERE or SELECT clauses.

```sql
SELECT name FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);
```

***

### Views

Virtual tables based on SQL queries.

```sql
CREATE VIEW high_earners AS
SELECT name, salary FROM employees WHERE salary > 100000;

DROP VIEW high_earners;
```

***

### Transactions

Group multiple SQL statements as a single unit.

```sql
BEGIN;

UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;

COMMIT; -- or use ROLLBACK; to undo
```

***

### Functions

#### String Functions

```sql
SELECT UPPER(name), LOWER(name), LENGTH(name) FROM employees;
```

#### Date Functions

```sql
SELECT CURRENT_DATE, CURRENT_TIME, NOW();
```

#### Type Conversion

```sql
SELECT CAST('123' AS INT);
SELECT CONVERT(INT, '123');
```

***

### Case Statement

Conditional logic in SQL queries.

```sql
SELECT name,
  CASE
    WHEN salary > 100000 THEN 'High'
    WHEN salary > 50000 THEN 'Medium'
    ELSE 'Low'
  END AS salary_level
FROM employees;
```

***

### Tips

* Use `EXPLAIN` to understand query performance.
* Use `INDEX` on frequently searched columns.
* Avoid using `SELECT *` in production.
* Always test destructive queries (`DELETE`, `DROP`) on backups.

***

> ✅ Use this reference as a GitBook page or markdown cheat sheet to master SQL.
