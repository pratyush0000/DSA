---
description: >-
  This page is a practical, interview‑ready deep dive into Encapsulation,
  Abstraction, Inheritance, and Polymorphism with crisp definitions, examples
  (Java/C++/Python), common pitfalls, and mini‑quizzes
---

# OOP Pillars(Java)

### TL;DR Table

| Pillar            | One‑liner                                                        | Why it matters                                                               | Typical tools                                                        |
| ----------------- | ---------------------------------------------------------------- | ---------------------------------------------------------------------------- | -------------------------------------------------------------------- |
| **Encapsulation** | Keep data + methods that operate on it together; hide internals. | Guards invariants, reduces coupling, makes code easier to change safely.     | `private` fields, getters/setters, properties, modules, immutability |
| **Abstraction**   | Expose **what** to do, hide **how** it’s done.                   | Enables interchangeable parts & simpler APIs; shifts focus to behavior.      | Interfaces, abstract classes, pure virtual funcs, protocols          |
| **Inheritance**   | Reuse via an **is‑a** hierarchy.                                 | Code reuse + polymorphism via base types.                                    | `extends`/`implements`, `virtual` base, override                     |
| **Polymorphism**  | One interface, many implementations.                             | Write code once against an abstraction, plug new types w/o touching callers. | Method overriding (runtime), overloading (compile‑time), duck typing |

***

### 1) Encapsulation

**Definition.** Encapsulation binds state and behavior into a unit (class/module) and **restricts direct access** to internals. You control mutation through a narrow, validated API.

**Benefits**

* Protects invariants (e.g., balance never negative)
* Limits ripple effects; easier refactoring
* Enables defensive programming and thread‑safety

**Java example**

```java
public final class BankAccount {
  private long balance; // in paise to avoid floating errors

  public BankAccount(long opening) {
    if (opening < 0) throw new IllegalArgumentException("opening < 0");
    this.balance = opening;
  }

  public synchronized void deposit(long amount) {
    if (amount <= 0) throw new IllegalArgumentException("amount <= 0");
    balance += amount;
  }

  public synchronized void withdraw(long amount) {
    if (amount <= 0 || amount > balance) throw new IllegalArgumentException();
    balance -= amount;
  }

  public synchronized long getBalance() { return balance; }
}
```

**Python (with properties)**

```python
class Temperature:
    def __init__(self, c):
        self._c = c  # conventionally private

    @property
    def celsius(self):
        return self._c

    @celsius.setter
    def celsius(self, value):
        if value < -273.15:
            raise ValueError("Below absolute zero")
        self._c = value
```

**C++**

```cpp
class Vector {
  std::vector<int> data; // private by default in class
public:
  void push(int x) { data.push_back(x); }
  size_t size() const { return data.size(); }
};
```

**Interview gotchas**

* _Encapsulation ≠ just getters/setters._ If setters expose everything, you’ve leaked invariants. Prefer intent‑specific methods (e.g., `deposit`, `withdraw`) or immutable objects.
* Use module boundaries (packages/namespaces) + access modifiers (`private`, `protected`, `internal`).

**Checklist**

* Are fields mutable without validation? → hide them.
* Can invariants be broken from outside? → move checks inside.

***

### 2) Abstraction

**Definition.** Abstraction exposes **essential behavior** and hides implementation detail. You program to **interfaces**, not concrete classes.

**Benefits**

* Swap implementations without changing callers.
* Simplify complexity (e.g., `Storage` vs S3/Disk/Memory).

**Design sketch**

```java
public interface PaymentGateway { boolean charge(int amountPaise, String token); }

public class StripeGateway implements PaymentGateway {
  public boolean charge(int amountPaise, String token) { /* HTTP call */ return true; }
}

public class MockGateway implements PaymentGateway {
  public boolean charge(int amountPaise, String token) { return true; }
}

// Caller depends on the abstraction, not the implementation
public class CheckoutService {
  private final PaymentGateway gw;
  public CheckoutService(PaymentGateway gw) { this.gw = gw; }
  public boolean pay(int amount, String token) { return gw.charge(amount, token); }
}
```

**Abstraction vs Encapsulation**

* Encapsulation hides **state/implementation** inside a unit.
* Abstraction hides **irrelevant detail** from **users of the unit** via a simplified contract.

**Pitfalls**

* Too many abstractions → complexity. Start concrete, extract interfaces when variation appears.

***

### 3) Inheritance

**Definition.** Inheritance lets a class acquire behavior/state of another (base → derived) forming an **is‑a** relation.

**When to use**

* You truly have an **is‑a** relationship and want **polymorphism**.
* You need to share behavior/contract (e.g., a framework base class).

**When to avoid**

* If relation is **has‑a** → prefer **composition**.
* If base is unstable (fragile base class problem). Composition isolates change better.

**Java example**

```java
abstract class Shape { abstract double area(); }
class Circle extends Shape {
  private final double r;
  Circle(double r) { this.r = r; }
  @Override double area() { return Math.PI * r * r; }
}
class Rect extends Shape {
  private final double w, h;
  Rect(double w, double h) { this.w = w; this.h = h; }
  @Override double area() { return w * h; }
}
```

**C++ (virtual)**

```cpp
struct Shape { virtual double area() const = 0; virtual ~Shape() = default; };
struct Circle : Shape { double r; Circle(double r): r(r) {} double area() const override { return 3.14159*r*r; } };
```

**Liskov Substitution Principle (LSP)**

* Subclasses must be usable anywhere the base is expected **without surprising behavior**. Violations (e.g., subclass strengthening preconditions) break polymorphic code.

**Inheritance vs Composition**

* **Composition**: build complex types by combining components.

```java
class Car { private final Engine engine; /* has-a */ }
```

* Use inheritance for shared **contracts**, composition for **reuse** and **flexibility**.

***

### 4) Polymorphism

**Definition.** The same operation behaves differently on different types.

**Two common forms**

1. **Runtime polymorphism (overriding)** — dynamic dispatch via base references.
2. **Compile‑time polymorphism** — method overloading, templates/generics.

**Runtime example**

```java
List<Shape> shapes = List.of(new Circle(2), new Rect(3,4));
double total = 0;
for (Shape s : shapes) total += s.area(); // calls correct override at runtime
```

**C++ templates (compile‑time)**

```cpp
template<typename T>
T add(T a, T b) { return a + b; }
```

**Python (duck typing)**

```python
def area_total(shapes):
    return sum(s.area() for s in shapes)  # any object with .area() works
```

**Overloading vs Overriding**

* _Overloading_: same name, different signatures (compile‑time dispatch).
* _Overriding_: subclass provides its own implementation (runtime dispatch).

**Pitfalls**

* Accidental overloading/overriding mistakes (e.g., Java missing `@Override`). Always annotate overrides.

***

### Putting It Together: A Mini Case

Design a logging system:

* **Abstraction**: `Logger` interface with `log(Level, String)`
* **Polymorphism**: `ConsoleLogger`, `FileLogger`, `HttpLogger` implement `Logger`
* **Encapsulation**: loggers manage their internal buffers/streams privately
* **(Optional) Inheritance**: `BaseBufferedLogger` provides shared buffering for others to extend

Callers depend only on `Logger`, so you can swap implementations without touching business code.

***

### Common Interview Pitfalls & Clarifications

* **“Encapsulation == private + getters/setters”** — Too narrow. Use intention‑revealing methods and validate invariants.
* **“Inheritance for reuse everywhere”** — Prefer **composition** unless it’s a true is‑a. Inheritance couples subclass to base changes.
* **“Polymorphism only at runtime”** — Compile‑time polymorphism (generics/templates/overloading) is also key.
* **“Abstraction means abstract classes only”** — No. Interfaces, protocols, and even functions are abstractions.

***

### Quick Quiz (with answers)

1. Which pillar most directly prevents invalid object states? **Encapsulation**.
2. You want to switch `FileStorage` to `S3Storage` without changing callers. Which pillar is central? **Abstraction** (with polymorphism to swap implementations).
3. When would you avoid inheritance even if it seems to fit? When the relationship is **has‑a** or the base class is unstable; choose **composition**.
4. In Java, what ensures runtime polymorphism works as intended? Using **base type references** and **method overriding** (plus `@Override`).

***

### Best Practices Cheat‑Sheet

* Design to **interfaces**, not implementations.
* Prefer **composition over inheritance** for reuse.
* Keep classes **small** with a single responsibility; expose a **minimal API**.
* Validate state **inside** the class; consider **immutability** when possible.
* Use unit tests against **abstractions** to keep implementations swappable.

***

### Further Reading/Keywords (for self‑study)

* SOLID principles (SRP, OCP, LSP, ISP, DIP)
* Composition vs Inheritance
* Interface segregation and dependency inversion
* Virtual dispatch tables, dynamic binding
* Design patterns (Strategy, Decorator, Adapter, Template Method)
