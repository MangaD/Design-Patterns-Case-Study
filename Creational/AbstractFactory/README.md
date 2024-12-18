# Abstract Factory Pattern

## Category
Creational Design Pattern

---

## Overview

The **Abstract Factory Pattern** is a **creational design pattern** that provides an interface for creating families of related or dependent objects without specifying their concrete classes. This pattern ensures that objects from the same family are compatible and simplifies client code by decoupling it from specific product implementations.

The Abstract Factory encapsulates the creation logic for groups of related objects, making it easy to add new families of products without modifying existing code.

---

## Key Characteristics

1. **Encapsulation of Object Families**:
   - Encapsulates the creation of related or dependent objects into a single factory interface.

2. **Consistency**:
   - Guarantees that objects created by the factory are compatible within the same family.

3. **Polymorphism**:
   - Abstract factories return abstract products, allowing the client to use products interchangeably.

4. **Scalability**:
   - Adding new product families is straightforward by implementing new concrete factories and product classes.

---

## UML Diagram

The UML diagram below illustrates the Abstract Factory Pattern. Each concrete factory creates multiple products that belong to the same family.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Creational/AbstractFactory/abstract_factory.puml)

---

## Implementation Walkthrough

### 1. Abstract Factory Interface
Defines methods to create each product in the family.

```java
public interface UIFactory {
    Button createButton();
    Checkbox createCheckbox();
}
```

### 2. Abstract Products
Defines the common behavior for all products in a family.

```java
public interface Button {
    void render();
}

public interface Checkbox {
    void render();
}
```

### 3. Concrete Products
Specific implementations of the abstract products.

#### For Windows
```java
public class WindowsButton implements Button {
    @Override
    public void render() {
        System.out.println("Rendering a Windows button.");
    }
}

public class WindowsCheckbox implements Checkbox {
    @Override
    public void render() {
        System.out.println("Rendering a Windows checkbox.");
    }
}
```

#### For macOS
```java
public class MacButton implements Button {
    @Override
    public void render() {
        System.out.println("Rendering a Mac button.");
    }
}

public class MacCheckbox implements Checkbox {
    @Override
    public void render() {
        System.out.println("Rendering a Mac checkbox.");
    }
}
```

### 4. Concrete Factories
Implements the abstract factory interface to produce products for a specific family.

#### Windows Factory
```java
public class WindowsFactory implements UIFactory {
    @Override
    public Button createButton() {
        return new WindowsButton();
    }

    @Override
    public Checkbox createCheckbox() {
        return new WindowsCheckbox();
    }
}
```

#### macOS Factory
```java
public class MacFactory implements UIFactory {
    @Override
    public Button createButton() {
        return new MacButton();
    }

    @Override
    public Checkbox createCheckbox() {
        return new MacCheckbox();
    }
}
```

### 5. Client Code
The client uses the abstract factory and does not depend on specific product classes.

```java
public class Application {
    private Button button;
    private Checkbox checkbox;

    public Application(UIFactory factory) {
        this.button = factory.createButton();
        this.checkbox = factory.createCheckbox();
    }

    public void render() {
        button.render();
        checkbox.render();
    }

    public static void main(String[] args) {
        UIFactory factory = new WindowsFactory();
        Application app = new Application(factory);
        app.render();

        factory = new MacFactory();
        app = new Application(factory);
        app.render();
    }
}
```

---

## Example Output

```
Rendering a Windows button.
Rendering a Windows checkbox.
Rendering a Mac button.
Rendering a Mac checkbox.
```

---

## Applications

### When to Use Abstract Factory
1. When you need to create groups of related objects.
2. When the system should remain independent of how products are created or represented.
3. When you anticipate adding new product families frequently.

### Common Use Cases
1. **Cross-Platform UI Libraries**:
   - Create UI components (e.g., buttons, text boxes) for different platforms (e.g., Windows, macOS).

2. **Game Development**:
   - Generate enemies, weapons, or other objects based on the game's level or theme.

3. **Database Systems**:
   - Abstract connections and queries for different database types (e.g., MySQL, PostgreSQL).

---

## Advantages and Disadvantages

### Advantages
1. **Encapsulation**:
   - Centralizes the creation of related products, simplifying the client code.

2. **Consistency**:
   - Guarantees compatibility between objects in the same family.

3. **Scalability**:
   - Adding new product families requires implementing new factories without modifying existing code.

---

### Disadvantages
1. **Increased Complexity**:
   - Requires more classes and interfaces, leading to a more complex design.

2. **Overhead**:
   - Adds additional layers of abstraction, which might be unnecessary for simple use cases.

---

## Comparison with Factory Method

| Feature              | Factory Method                          | Abstract Factory                       |
|----------------------|------------------------------------------|----------------------------------------|
| Focus               | Creates a single product at a time.      | Creates families of related products.  |
| Client Interaction  | Relies on a factory method in the creator. | Relies on a factory interface.         |
| Flexibility         | Suitable for single product hierarchies. | Suitable for multiple product families.|

---

## Key Takeaways

- The Abstract Factory Pattern is ideal for systems that need to work with families of related objects.
- It decouples client code from concrete implementations, making the system more flexible and scalable.
- While it adds complexity, the pattern ensures consistency and maintainability in systems where related products are created frequently.
