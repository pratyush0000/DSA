---
description: >-
  This page is a practical, interview‑ready deep dive into Encapsulation,
  Abstraction, Inheritance, and Polymorphism with crisp definitions, C++
  examples, common pitfalls, and mini‑quizzes.
---

# OOP Pillars(C++)

TL;DR Table

| Pillar            | One‑liner                                                        | Why it matters                                                               | Typical tools                                                           |
| ----------------- | ---------------------------------------------------------------- | ---------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| **Encapsulation** | Keep data + methods that operate on it together; hide internals. | Guards invariants, reduces coupling, makes code easier to change safely.     | `private`/`protected` fields, getters/setters, immutability, namespaces |
| **Abstraction**   | Expose **what** to do, hide **how** it’s done.                   | Enables interchangeable parts & simpler APIs; shifts focus to behavior.      | Abstract classes, pure virtual functions, interfaces                    |
| **Inheritance**   | Reuse via an **is‑a** hierarchy.                                 | Code reuse + polymorphism via base types.                                    | `class Derived : public Base`, `virtual` methods                        |
| **Polymorphism**  | One interface, many implementations.                             | Write code once against an abstraction, plug new types w/o touching callers. | Virtual functions, function overloading, templates                      |

***

### 1) Encapsulation

**Definition.** Encapsulation binds state and behavior into a unit (class) and **restricts direct access** to internals. In C++, this is achieved using access specifiers (`private`, `protected`, `public`).

**Benefits**

* Protects invariants (e.g., account balance never negative)
* Limits ripple effects; easier refactoring
* Enables defensive programming and thread‑safety

**Example**

```cpp
#include <iostream>
#include <stdexcept>

class BankAccount {
private:
    long balance; // in paise to avoid floating point errors

public:
    explicit BankAccount(long opening) {
        if (opening < 0) throw std::invalid_argument("Opening balance < 0");
        balance = opening;
    }

    void deposit(long amount) {
        if (amount <= 0) throw std::invalid_argument("Invalid deposit");
        balance += amount;
    }

    void withdraw(long amount) {
        if (amount <= 0 || amount > balance) throw std::invalid_argument("Invalid withdrawal");
        balance -= amount;
    }

    long getBalance() const { return balance; }
};
```

**Gotchas**

* _Encapsulation ≠ getters/setters everywhere._ If setters expose everything, invariants can still be broken. Use meaningful methods (`deposit`, `withdraw`) instead of raw setters.
* In C++, `struct` defaults to public, `class` defaults to private.

***

### 2) Abstraction

**Definition.** Abstraction in C++ exposes **essential behavior** and hides implementation details. Done via abstract classes and pure virtual functions.

**Example**

```cpp
#include <iostream>

class PaymentGateway {
public:
    virtual bool charge(int amountPaise, const std::string& token) = 0; // pure virtual
    virtual ~PaymentGateway() = default;
};

class StripeGateway : public PaymentGateway {
public:
    bool charge(int amountPaise, const std::string& token) override {
        std::cout << "Charging via Stripe: " << amountPaise << "\n";
        return true;
    }
};

class MockGateway : public PaymentGateway {
public:
    bool charge(int amountPaise, const std::string& token) override {
        return true;
    }
};

class CheckoutService {
    PaymentGateway* gw;
public:
    CheckoutService(PaymentGateway* g) : gw(g) {}
    bool pay(int amount, const std::string& token) { return gw->charge(amount, token); }
};
```

**Key point**: Callers depend on the abstraction (`PaymentGateway`) rather than specific implementations.

**Abstraction vs Encapsulation**

* Encapsulation hides **state/implementation** inside a class.
* Abstraction hides **irrelevant detail** from **users** via interfaces/pure virtuals.

***

### 3) Inheritance

**Definition.** Inheritance allows a class to reuse or extend behavior/state from another.

**Example**

```cpp
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() const override { return M_PI * r * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() const override { return w * h; }
};
```

**Liskov Substitution Principle (LSP)**

* Subclasses must be usable wherever the base is expected **without surprising behavior**.

**Composition vs Inheritance**

```cpp
class Engine { /* ... */ };
class Car {
    Engine engine; // Car has-a Engine
};
```

Use **composition** for reuse, **inheritance** for contracts/is‑a relationships.

***

### 4) Polymorphism

**Definition.** The same operation behaves differently depending on the object type.

**Types in C++**

1. **Runtime polymorphism (overriding)** — via virtual functions.
2. **Compile‑time polymorphism** — via function overloading and templates.

**Runtime Example**

```cpp
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));
    shapes.push_back(std::make_unique<Rectangle>(3,4));

    double total = 0;
    for (const auto& s : shapes) total += s->area();

    std::cout << "Total area: " << total << "\n";
}
```

**Compile‑time Example (templates)**

```cpp
template<typename T>
T add(T a, T b) { return a + b; }

int main() {
    std::cout << add<int>(2, 3) << "\n";
    std::cout << add<double>(2.5, 3.1) << "\n";
}
```

**Duck typing in C++ (templates)**: Any type with a valid `area()` can be used.

```cpp
template<typename T>
double totalArea(const std::vector<T>& shapes) {
    double sum = 0;
    for (const auto& s : shapes) sum += s.area();
    return sum;
}
```

***

### Putting It Together: A Mini Case

Design a logging system:

* **Abstraction**: `Logger` base class with pure virtual `log` method
* **Polymorphism**: `ConsoleLogger`, `FileLogger` override `log`
* **Encapsulation**: Each logger manages its own private resources (file stream, buffer)
* **Inheritance**: `BufferedLogger` base with common buffer handling

***

### Quick Quiz (with answers)

1. Which pillar prevents invalid states? → **Encapsulation**.
2. You want to switch `FileLogger` to `ConsoleLogger` without changing callers. Which pillar is central? → **Abstraction + Polymorphism**.
3. When to avoid inheritance? → If the relationship is **has‑a** or base class is unstable; prefer **composition**.
4. In C++, what enables runtime polymorphism? → **Virtual functions** + base class pointers/references.

***

### Best Practices Cheat‑Sheet

* Use **access specifiers** to enforce encapsulation.
* Program to **abstract classes/interfaces**, not implementations.
* Prefer **composition over inheritance** for reuse.
* Use `override` keyword to avoid accidental hiding.
* Use `unique_ptr`/`shared_ptr` to manage lifetimes safely in polymorphic hierarchies.

***

### Further Reading/Keywords

* SOLID principles
* RAII (Resource Acquisition Is Initialization)
* vtable, virtual dispatch
* Templates, CRTP (Curiously Recurring Template Pattern)
* Design patterns (Strategy, Decorator, Factory)
