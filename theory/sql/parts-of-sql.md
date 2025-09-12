# Parts of SQL

SQL (**Structured Query Language**) is used to interact with relational databases. SQL commands are grouped into categories based on their functionality.

***

### 1. Data Definition Language (DDL)

**Purpose:** Define and modify database structure (schema).

**Common Commands:**

| Command  | Description                         |
| -------- | ----------------------------------- |
| CREATE   | Create database, table, or object   |
| ALTER    | Modify structure of database/table  |
| DROP     | Delete database, table, or object   |
| TRUNCATE | Remove all rows from a table (fast) |

**Example:**\
CREATE TABLE Student (\
 ID INT PRIMARY KEY,\
 Name VARCHAR(50),\
 Age INT\
);

***

### 2. Data Manipulation Language (DML)

**Purpose:** Manage and manipulate data stored in tables.

**Common Commands:**

| Command | Description                 |
| ------- | --------------------------- |
| INSERT  | Add new records to a table  |
| UPDATE  | Modify existing records     |
| DELETE  | Remove records from a table |
| MERGE   | Merge data from two tables  |

**Example:**\
INSERT INTO Student (ID, Name, Age) VALUES (101, 'Alice', 20);\
UPDATE Student SET Age = 21 WHERE ID = 101;\
DELETE FROM Student WHERE ID = 101;

***

### 3. Data Query Language (DQL)

**Purpose:** Query and retrieve data from the database.

**Command:**

| Command | Description            |
| ------- | ---------------------- |
| SELECT  | Fetch data from tables |

**Example:**\
SELECT Name, Age FROM Student WHERE Age > 18;

***

### 4. Data Control Language (DCL)

**Purpose:** Control access and permissions to the database.

**Common Commands:**

| Command | Description                  |
| ------- | ---------------------------- |
| GRANT   | Give privileges to users     |
| REVOKE  | Remove privileges from users |

**Example:**\
GRANT SELECT, INSERT ON Student TO User1;\
REVOKE INSERT ON Student FROM User1;

***

### 5. Transaction Control Language (TCL)

**Purpose:** Manage transactions in the database (a group of operations treated as a single unit).

**Common Commands:**

| Command   | Description                |
| --------- | -------------------------- |
| COMMIT    | Save changes permanently   |
| ROLLBACK  | Undo changes               |
| SAVEPOINT | Set a point to rollback to |

**Example:**\
SAVEPOINT sp1;\
UPDATE Student SET Age = 22 WHERE ID = 101;\
ROLLBACK TO sp1;\
COMMIT;

***

### 6. Summary Table

| Category | Main Purpose            | Key Commands                  |
| -------- | ----------------------- | ----------------------------- |
| DDL      | Define/modify structure | CREATE, ALTER, DROP, TRUNCATE |
| DML      | Manipulate data         | INSERT, UPDATE, DELETE, MERGE |
| DQL      | Query data              | SELECT                        |
| DCL      | Manage permissions      | GRANT, REVOKE                 |
| TCL      | Control transactions    | COMMIT, ROLLBACK, SAVEPOINT   |

***

**Key Notes:**

* DDL changes the schema, DML changes data.
* DQL is for reading data, DCL is for controlling access.
* TCL ensures database transactions are safe and consistent.
