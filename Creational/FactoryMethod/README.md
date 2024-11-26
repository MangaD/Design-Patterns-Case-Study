
# Factory Method Pattern

## Category
Creational Design Pattern

## Description
The Factory Method Pattern defines an interface for creating objects, but allows subclasses to alter the type of objects that will be created. This pattern promotes loose coupling by delegating the instantiation of objects to subclasses.

### Key Characteristics:
- **Encapsulation of Object Creation**: The creation logic is moved to a separate method or class.
- **Open-Closed Principle**: Adding new product types requires extending the creator without modifying existing code.
- **Flexibility**: Different creators can produce different product types while adhering to a common interface.

---

## Use Cases
- **Plugin Systems**: Dynamically creating and managing different types of plugins.
- **Frameworks**: Allowing users to extend and define their own products.
- **Object Pooling**: Creating and managing a pool of objects with varying configurations.

---

## UML Diagram
The UML diagram below represents the Factory Method pattern:

![UML Diagram](factory_method.png)

---

## Implementations

### **C++**
The Factory Method uses polymorphism to delegate object creation to subclasses.

- **Source Code**: [factory_method.cpp](./cpp/factory_method.cpp)
- **Unit Tests**: [test_FactoryMethod.cpp](./cpp/test_FactoryMethod.cpp)

### **Java**
The Factory Method leverages abstract classes to define a creator and its concrete implementations.

- **Source Code**: [FactoryMethod.java](./java/FactoryMethod.java)
- **Unit Tests**: [FactoryMethodTest.java](./java/FactoryMethodTest.java)

### **Python**
The Factory Method uses base classes and overrides the creation logic in subclasses.

- **Source Code**: [factory_method.py](./python/factory_method.py)
- **Unit Tests**: [test_factory_method.py](./python/test_factory_method.py)
