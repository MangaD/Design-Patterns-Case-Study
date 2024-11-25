# Design Patterns Case Study

[![CI](https://github.com/MangaD/Design-Patterns-Case-Study/actions/workflows/ci.yml/badge.svg)](https://github.com/MangaD/Design-Patterns-Case-Study/actions/workflows/ci.yml) [![pipeline status](https://gitlab.com/MangaD/design-patterns-case-study/badges/main/pipeline.svg)](https://gitlab.com/MangaD/design-patterns-case-study/-/commits/main) 

This repository contains a comprehensive study of Object-Oriented Programming (OOP) design patterns. Each pattern is implemented in **C++**, **Java**, and **Python**, accompanied by detailed explanations, UML diagrams, and unit tests.

## Patterns Included

### Creational Patterns
- Singleton
- Factory Method
- Abstract Factory
- Builder
- Prototype

### Structural Patterns
- Adapter
- Bridge
- Composite
- Decorator
- Facade
- Flyweight
- Proxy

### Behavioral Patterns
- Chain of Responsibility
- Command
- Iterator
- Mediator
- Observer
- Strategy
- Template Method

## Project Structure

The repository is organized as follows:

```
DesignPatternsCaseStudy/
├── README.md # Overview of the repository
├── .github/workflows/ # GitHub Actions CI/CD configuration
├── .gitlab-ci.yml # GitLab CI/CD configuration
├── docs/ # Generated documentation for hosting (e.g., GitHub Pages)
├── Creational/ # Creational design patterns
│ ├── Singleton/
│ ├── FactoryMethod/
│ └── AbstractFactory/
├── Structural/ # Structural design patterns
│ ├── Adapter/
│ ├── Bridge/
│ └── Composite/
├── Behavioral/ # Behavioral design patterns
│ ├── ChainOfResponsibility/
│ ├── Command/
│ └── Iterator/
```

## Languages and Tools

### **C++**
- **Build System**: CMake
- **Unit Testing**: GoogleTest

### **Java**
- **Build System**: Maven
- **Unit Testing**: JUnit

### **Python**
- **Unit Testing**: unittest

## CI/CD
- **GitHub Actions**: Automates builds and tests for all implementations.
- **GitLab CI/CD**: Equivalent pipelines for building, testing, and deploying documentation.

## Documentation
- Detailed explanations for each pattern can be found in their respective directories.
- UML diagrams are included for visual reference.

---

## How to Use

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-repo-url/DesignPatternsCaseStudy.git
   cd DesignPatternsCaseStudy
   ```

2. **Build and Run:**

- **C++**: Use CMake to build and test.
- **Java**: Use Maven to compile and run tests.
- **Python**: Use the built-in unittest framework.

3. **Explore the Patterns**: Navigate to individual pattern directories for implementations and tests.

---

## Contributing

Feel free to contribute by adding new patterns, improving implementations, or enhancing documentation. Submit a pull request, and we'll review it promptly.

---

## Resources

- [Design Patterns by Refactoring.Guru](https://refactoring.guru/design-patterns)

---

## License

This project is licensed under the MIT License.