# Prototype Pattern

## Category
Creational Design Pattern

---

## Overview

The **Prototype Pattern** is a creational design pattern that enables the creation of new objects by cloning existing ones. Instead of instantiating objects from scratch, this pattern uses a prototype (an existing object) to create copies, allowing for efficient and flexible object creation.

This pattern is particularly useful when the cost of creating new objects is high, when objects share common configurations, or when object types need to be determined dynamically at runtime.

---

## Key Characteristics

1. **Cloning Mechanism**:
   - New objects are created by copying an existing prototype using a cloning method (e.g., `clone()`).
   - Supports shallow and deep copying.

2. **Dynamic Object Creation**:
   - Enables runtime creation of new objects without relying on constructors or class definitions.

3. **Encapsulation of Initialization Logic**:
   - The prototype encapsulates complex initialization, making object creation easier for the client.

4. **Customizability**:
   - Cloned objects can be independently modified without affecting the original prototype.

---

## UML Diagram

The UML diagram below illustrates the Prototype Pattern, showing how a client clones objects using the prototype interface:

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Creational/Prototype/prototype.puml)

---

## Implementation Walkthrough

### Participants

1. **Prototype**:
   - Defines the interface for cloning objects, typically through a `clone()` method.

2. **Concrete Prototype**:
   - Implements the `Prototype` interface and provides specific cloning behavior.

3. **Client**:
   - Creates new objects by cloning prototypes instead of instantiating them directly.

---

### Example: Game Character Prototypes

#### Prototype Interface
```java
/**
 * @brief Defines the interface for cloning game characters.
 */
public interface GameCharacter {
    GameCharacter clone();
}
```

---

#### Concrete Prototypes
```java
/**
 * @brief Concrete prototype representing a Knight character.
 */
public class Knight implements GameCharacter {
    private String weapon;

    public Knight(String weapon) {
        this.weapon = weapon;
    }

    @Override
    public GameCharacter clone() {
        return new Knight(this.weapon);
    }

    @Override
    public String toString() {
        return "Knight with weapon: " + weapon;
    }
}

/**
 * @brief Concrete prototype representing an Archer character.
 */
public class Archer implements GameCharacter {
    private String bowType;

    public Archer(String bowType) {
        this.bowType = bowType;
    }

    @Override
    public GameCharacter clone() {
        return new Archer(this.bowType);
    }

    @Override
    public String toString() {
        return "Archer with bow type: " + bowType;
    }
}
```

---

#### Client Code
```java
/**
 * @brief Client demonstrating the Prototype Pattern.
 */
public class PrototypePatternDemo {
    public static void main(String[] args) {
        // Create prototypes
        GameCharacter knightPrototype = new Knight("Sword");
        GameCharacter archerPrototype = new Archer("Longbow");

        // Clone prototypes to create new characters
        GameCharacter knight1 = knightPrototype.clone();
        GameCharacter knight2 = knightPrototype.clone();
        GameCharacter archer1 = archerPrototype.clone();

        // Display the characters
        System.out.println(knight1);
        System.out.println(knight2);
        System.out.println(archer1);
    }
}
```

---

### Output
```
Knight with weapon: Sword
Knight with weapon: Sword
Archer with bow type: Longbow
```

---

## Applications

### When to Use the Prototype Pattern
1. **Efficient Object Creation**:
   - When creating new instances is computationally expensive.
2. **Common Object Configurations**:
   - When objects share a similar structure or configuration.
3. **Dynamic Object Creation**:
   - When new object types must be created dynamically at runtime.
4. **Encapsulation of Initialization Logic**:
   - When initialization details should be encapsulated within the prototype.

### Common Use Cases
1. **Game Development**:
   - Cloning game characters, enemies, or objects with similar attributes.
2. **UI Libraries**:
   - Reusing UI components with slight variations.
3. **Document Templates**:
   - Creating new documents based on preconfigured templates.
4. **Prototyping Systems**:
   - Quickly creating new prototypes for testing purposes.

---

## Advantages and Disadvantages

### Advantages
1. **Efficiency**:
   - Reduces the cost of object creation by reusing existing prototypes.
2. **Flexibility**:
   - Supports runtime object creation without relying on constructors or class definitions.
3. **Encapsulation**:
   - Encapsulates complex initialization logic within prototypes.
4. **Customizability**:
   - Allows customization of cloned objects without affecting the original prototype.

### Disadvantages
1. **Complexity**:
   - Implementing cloning can be challenging, especially for deep copying of objects with nested references.
2. **Overhead**:
   - Cloning large or deeply nested objects can consume significant memory and processing time.
3. **Maintenance**:
   - Changes to the prototype require updates to the cloning logic.

---

## Key Takeaways

The Prototype Pattern simplifies object creation by cloning existing instances. It is particularly effective when creating new objects is costly, objects share similar configurations, or new object types need to be defined at runtime. While it introduces complexity in managing cloning mechanisms, it is a powerful tool for systems requiring dynamic and efficient object creation.
