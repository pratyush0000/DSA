# Normalization

**Normalization** is the process of organizing a database to **reduce redundancy** and **improve data integrity**. It ensures that data is stored logically, avoids duplicate data, and makes updating the database easier.

***

### Why Normalize?

* To **eliminate redundancy** (duplicate data)
* To **avoid update anomalies**:
  * **Insertion anomaly:** Can't add data without unnecessary nulls
  * **Update anomaly:** Updating in one place requires updates in multiple rows
  * **Deletion anomaly:** Deleting a record might remove other important data
* To **ensure data consistency** and **integrity**

***

### Normal Forms (NFs)

Normalization is usually done step by step, moving a table through **normal forms**:

***

#### 1. First Normal Form (1NF)

**Requirement:**

* Each column must have **atomic (indivisible) values**
* No repeating groups or arrays

**Check for 1NF:**

* Remove multi-valued attributes
* Ensure each field contains a single value

**Example:**

| StudentID | Courses       |
| --------- | ------------- |
| 101       | Math, Physics |

**Convert to 1NF:**

| StudentID | Course  |
| --------- | ------- |
| 101       | Math    |
| 101       | Physics |

***

#### 2. Second Normal Form (2NF)

**Requirement:**

* Must be in **1NF**
* **No partial dependency**: every non-key attribute depends on the **whole primary key**

**Check for 2NF:**

* If primary key is composite, ensure no non-key attribute depends on just part of it

**Example:**

* Primary key = `{StudentID, CourseID}`
* `CourseName` depends only on `CourseID` → violates 2NF

**Fix:**

* Split into two tables:
  1. Student\_Course(StudentID, CourseID)
  2. Course(CourseID, CourseName)

***

#### 3. Third Normal Form (3NF)

**Requirement:**

* Must be in **2NF**
* **No transitive dependency**: non-key attributes should not depend on other non-key attributes

**Check for 3NF:**

* If A → B and B → C, move C to a separate table

**Example:**

* `DeptName` depends on `DeptID`, not `EmpID` → violates 3NF

**Fix:**

* Split into:
  1. Employee(EmpID, DeptID)
  2. Department(DeptID, DeptName)

***

#### 4. Boyce-Codd Normal Form (BCNF)

**Requirement:**

* Must be in **3NF**
* For every **functional dependency X → Y**, X must be a **super key**

**Check for BCNF:**

* If a non-super key determines part of the table, decompose

**Example:**\
\| CourseID | Instructor | TimeSlot |

* If `TimeSlot → Instructor` but `TimeSlot` is not a key, violates BCNF

***

#### 5. Higher Normal Forms

* **4NF (Fourth Normal Form):** Handles **multi-valued dependencies**
* **5NF (Fifth Normal Form):** Handles **join dependencies**

***

### Steps to Normalize

1. Start with **un-normalized table (UNF)**
2. Convert to **1NF** → ensure atomicity
3. Move to **2NF** → remove partial dependencies
4. Move to **3NF** → remove transitive dependencies
5. Optionally, check for **BCNF, 4NF, 5NF** for advanced normalization

***

### Summary Table

| Normal Form | Requirement                            | Main Goal                           |
| ----------- | -------------------------------------- | ----------------------------------- |
| 1NF         | Atomic values, no repeating groups     | Remove multi-valued fields          |
| 2NF         | No partial dependency on composite key | Eliminate partial dependencies      |
| 3NF         | No transitive dependency               | Eliminate transitive dependencies   |
| BCNF        | Every determinant is a super key       | Stronger version of 3NF             |
| 4NF         | No multi-valued dependencies           | Eliminate multi-valued dependencies |
| 5NF         | No join dependencies                   | Ensure lossless joins               |
