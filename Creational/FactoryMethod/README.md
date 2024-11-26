# Factory Method Pattern

## Category
Creational Design Pattern

---

## Description

The **Factory Method Pattern** defines an interface for creating objects, allowing subclasses to alter the type of objects that will be created. This pattern encapsulates the instantiation logic, delegating the responsibility of object creation to specific factories.

Unlike simple object creation techniques, the Factory Method ensures that the client code relies only on the interface, not the concrete implementations, promoting **loose coupling** and adherence to the **Open-Closed Principle**.

---

### Key Characteristics

1. **Encapsulation of Object Creation**:
   - The creation logic is centralized within factory classes, isolating it from the client code.

2. **Open-Closed Principle**:
   - Adding new product types requires extending the factory without modifying existing client code.

3. **Flexibility**:
   - Different creators can produce different product types adhering to the same interface, enabling dynamic and runtime polymorphism.

4. **Decoupling**:
   - The client depends only on the abstract product interface, not specific implementations.

5. **Polymorphic Behavior**:
   - Products can be used interchangeably as long as they implement the shared interface.

---

## Use Cases

The Factory Method Pattern is ideal when:
- A class cannot anticipate the type of objects it needs to create.
- You want to delegate the responsibility of instantiation to subclasses.
- Adding new product types should not require changes in the client code.

### Common Applications
- **Plugin Frameworks**: Allowing dynamic instantiation of plugins based on user or runtime configuration.
- **UI Component Libraries**: Creating different UI elements (e.g., buttons, dropdowns) that adhere to a common interface but behave differently depending on the platform.
- **Parsing Engines**: Creating appropriate parsers (e.g., XML, JSON) depending on the file format.
- **Game Development**: Spawning different types of enemies or objects during gameplay, based on level or context.

---

## Advantages

1. **Code Reusability**:
   - Centralized creation logic enables reusing the same logic across multiple client classes.

2. **Ease of Maintenance**:
   - Adding or modifying product types involves extending the factory without impacting the client code.

3. **Improved Testability**:
   - Dependency injection through factory methods makes testing simpler by allowing mock products to be used.

---

## Disadvantages

1. **Increased Complexity**:
   - Introducing additional classes for factories can lead to more boilerplate code.

2. **Overhead for Simple Scenarios**:
   - The pattern might be overkill for straightforward object creation needs.

---

## UML Diagram

The UML diagram below represents the Factory Method pattern, illustrating the relationships between the Creator, Product, and their respective concrete implementations:

![UML Diagram](factory_method.png)