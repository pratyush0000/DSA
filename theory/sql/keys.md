# Keys

In **Database Management Systems (DBMS)**, a **key** is an attribute (or a set of attributes) that helps uniquely identify a record (tuple) in a table (relation). Keys are essential for ensuring data integrity, avoiding duplication, and establishing relationships between tables.

***

### 1. Super Key

A **super key** is a set of one or more attributes that can uniquely identify a tuple in a relation.

**Characteristics:**

* Can have extra attributes (not minimal).
* Every relation has at least one super key (all attributes combined).

**Example:**\
For a `Student(ID, Name, Email)` table:\
`{ID}`, `{ID, Name}`, `{ID, Email}`, `{ID, Name, Email}` → all are super keys.

***

### 2. Candidate Key

A **candidate key** is a **minimal super key**—it uniquely identifies tuples and contains no unnecessary attributes.

**Characteristics:**

* No subset of the candidate key can uniquely identify a tuple.
* A table can have multiple candidate keys.

**Example:**\
For `Student(ID, Email, Name)` table:

* `{ID}` → candidate key
* `{Email}` → candidate key
* `{ID, Email}` → super key but **not** candidate key (not minimal).

***

### 3. Primary Key

A **primary key** is a candidate key chosen by the database designer to uniquely identify tuples in a table.

**Characteristics:**

* Must be **unique** and **not null**.
* Only one primary key per table.

**Example:**\
In `Student(ID, Email, Name)`, if `ID` is chosen as the primary key, no two students can have the same `ID`.

***

### 4. Alternate Key

An **alternate key** is a candidate key that is **not chosen** as the primary key.

**Characteristics:**

* Can still uniquely identify records.
* Can be used for uniqueness constraints.

**Example:**\
If `ID` is the primary key in `Student(ID, Email)`, then `{Email}` is an alternate key.

***

### 5. Composite Key

A **composite key** (or **compound key**) is a key that consists of **two or more attributes** that together uniquely identify a tuple.

**Characteristics:**

* Individual attributes may not be unique.
* Useful when single attribute uniqueness is not sufficient.

**Example:**\
For a `Course_Registration(StudentID, CourseID)` table:\
`{StudentID, CourseID}` → composite key.

***

### 6. Foreign Key

A **foreign key** is an attribute (or set of attributes) in one table that refers to the **primary key** in another table.

**Characteristics:**

* Maintains referential integrity between tables.
* Can have duplicate values (unless constrained).

**Example:**\
`Enrollment(StudentID, CourseID)`

* `StudentID` in `Enrollment` references `ID` in `Student`.

***

### 7. Unique Key

A **unique key** is similar to a primary key but **can accept one null value**.

**Characteristics:**

* Enforces uniqueness for a column or set of columns.
* A table can have multiple unique keys.

**Example:**\
`Student(ID PRIMARY KEY, Email UNIQUE)`

* `Email` must be unique but can have one null.

***

### Summary Table of Keys

| Key Type      | Unique? | Can be Null? | Minimal? | Number per Table |
| ------------- | ------- | ------------ | -------- | ---------------- |
| Super Key     | Yes     | Yes          | No       | Multiple         |
| Candidate Key | Yes     | No           | Yes      | Multiple         |
| Primary Key   | Yes     | No           | Yes      | 1                |
| Alternate Key | Yes     | No           | Yes      | Multiple         |
| Composite Key | Yes     | No           | Yes      | Multiple         |
| Foreign Key   | No      | Yes          | No       | Multiple         |
| Unique Key    | Yes     | Yes (1)      | Yes      | Multiple         |

***

**Key Notes:**

* Choosing appropriate keys ensures **data integrity** and **efficient database design**.
* Primary keys and foreign keys are crucial for **relational constraints**.
* Composite and alternate keys help handle **complex uniqueness requirements**.
