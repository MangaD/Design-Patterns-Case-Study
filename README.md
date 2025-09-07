# Design Patterns Case Study

[![CI](https://github.com/MangaD/Design-Patterns-Case-Study/actions/workflows/ci.yml/badge.svg)](https://github.com/MangaD/Design-Patterns-Case-Study/actions/workflows/ci.yml) [![pipeline status](https://gitlab.com/MangaD/design-patterns-case-study/badges/main/pipeline.svg)](https://gitlab.com/MangaD/design-patterns-case-study/-/commits/main) [![Documentation Status](https://readthedocs.org/projects/design-patterns-case-study/badge/?version=latest)](https://design-patterns-case-study.readthedocs.io/en/latest/?badge=latest)


This repository is a comprehensive exploration of **Object-Oriented Design Patterns**, implemented in **C++**, **Java**, and **Python**. It is designed as a hands-on learning resource for understanding, implementing, and applying design patterns in real-world software development.

*Disclaimer: This project was built collaboratively with AI, step by step. Its primary purpose is to serve as an educational tool for studying and understanding design patterns.*

---

## What Are Design Patterns?

Design patterns are proven solutions to common problems in software design. They encapsulate best practices, providing a standardized and reusable approach to solving specific challenges. Design patterns fall into three main categories:

1. **Creational Patterns**: Focus on object creation mechanisms, aiming to provide flexibility and reuse.
2. **Structural Patterns**: Deal with object composition and relationships, ensuring that the system is easier to understand and maintain.
3. **Behavioral Patterns**: Concerned with communication between objects and responsibility delegation.

---

## Why Study Design Patterns?

Studying design patterns offers several benefits:
- **Improved Design Skills**: Helps in identifying and solving recurring software problems.
- **Code Reusability**: Promotes writing reusable and maintainable code.
- **Team Collaboration**: Provides a shared vocabulary for discussing solutions.
- **Scalability and Flexibility**: Encourages designing systems that can adapt to change.

Understanding design patterns is essential for writing robust, maintainable, and efficient code. They are a cornerstone of software engineering principles such as SOLID and DRY (Don't Repeat Yourself).

---

## Patterns Included in This Case Study

### **Creational Patterns**
- **Singleton**: Ensures a class has only one instance.
- **Factory Method**: Delegates object creation to subclasses.
- **Abstract Factory**: Creates families of related objects without specifying their concrete classes.
- **Builder**: Constructs complex objects step by step.
- **Prototype**: Creates new objects by copying existing ones.
- **Object Pool**: Manages a pool of reusable objects, reducing the overhead of creating and destroying objects frequently.

### **Structural Patterns**
- **Adapter**: Bridges incompatible interfaces.
- **Bridge**: Separates an abstraction from its implementation.
- **Composite**: Composes objects into tree structures.
- **Decorator**: Dynamically adds behavior to objects.
- **Facade**: Provides a simplified interface to a subsystem.
- **Flyweight**: Minimizes memory usage by sharing data.
- **Proxy**: Controls access to an object.

### **Behavioral Patterns**
- **Chain of Responsibility**: Passes requests along a chain of handlers.
- **Command**: Encapsulates requests as objects.
- **Interpreter**: Defines a grammatical representation for a language and provides an interpreter to deal with this grammar.
- **Iterator**: Provides sequential access to collections.
- **Mediator**: Centralizes communication between objects.
- **Memento**: Captures and restores an object's internal state.
- **Observer**: Establishes a dependency between objects for event notification.
- **State**: Allows an object to alter its behavior when its state changes.
- **Strategy**: Enables selecting algorithms at runtime.
- **Template Method**: Defines a skeleton of an algorithm.
- **Visitor**: Allows adding operations to objects without changing their structure.

---

## Project Structure

```
DesignPatternsCaseStudy/
├── README.md               # Overview of the repository
├── .github/workflows/      # GitHub Actions CI/CD configuration
├── .gitlab-ci.yml          # GitLab CI/CD configuration
├── docs/                   # Generated documentation for hosting (e.g., GitHub Pages)
├── Creational/             # Creational design patterns
│   ├── Singleton/
│   ├── FactoryMethod/
│   ├── AbstractFactory/
│   └── Builder/
├── Structural/             # Structural design patterns
│   ├── Adapter/
│   ├── Bridge/
│   ├── Composite/
│   └── Decorator/
├── Behavioral/             # Behavioral design patterns
│   ├── ChainOfResponsibility/
│   ├── Command/
|   ├── Interpreter/
│   ├── Iterator/
│   └── Mediator/
```

---

## Tools and Technologies

### **C++**
- **Build System**: CMake
- **Unit Testing**: GoogleTest
- **Documentation**: Doxygen

### **Java**
- **Build System**: Gradle
- **Unit Testing**: JUnit
- **Documentation**: JavaDocs

### **Python**
- **Unit Testing**: unittest, pytest
- **Documentation**: Sphinx

---

## How to Use This Repository

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/MangaD/Design-Patterns-Case-Study.git
   # or
   git clone https://gitlab.com/MangaD/design-patterns-case-study.git

   cd DesignPatternsCaseStudy
   ```

2. **Build and Test**:
   - **C++**: Use CMake for building and running tests.
   - **Java**: Use Gradle for building and testing.
   - **Python**: Run tests using `unittest` or `pytest`.

   Check out the CI/CD files for commands.

3. **Explore the Patterns**:
   - Each pattern has a dedicated folder containing:
     - **Source Code**: Implementations in C++, Java, and Python.
     - **Unit Tests**: Tests for validating the implementation.
     - **Documentation**: Detailed explanation and UML diagrams.

---

## Continuous Integration

- **GitHub Actions**: Automates builds and tests across all implementations.
- **GitLab CI/CD**: Equivalent pipelines for testing and deploying documentation.

---

## Resources and References

- [Design Patterns: Elements of Reusable Object-Oriented Software](https://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)
- [Head First Design Patterns: Building Extensible and Maintainable Object-Oriented Software 2nd Edition](https://www.amazon.com/Head-First-Design-Patterns-Object-Oriented/dp/149207800X)
- [Refactoring.Guru - Design Patterns](https://refactoring.guru/design-patterns)

---

## License

This project is licensed under the MIT License. Contributions are welcome. Feel free to submit pull requests to improve implementations, add patterns, or enhance documentation.