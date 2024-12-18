# Builder Pattern

## Category
Creational Design Pattern

---

## Overview

The **Builder Pattern** is a creational design pattern that allows the step-by-step construction of complex objects. It separates the construction process from the representation, enabling the same construction process to create different representations.

This pattern is especially useful when creating objects that require many configuration steps or when the object’s creation involves optional or dependent attributes.

---

## Key Characteristics

1. **Separation of Construction and Representation**:
   - The pattern divides the construction of an object into discrete steps handled by a builder class.

2. **Flexibility**:
   - Different builders can produce different representations of the same object.

3. **Fluent Interface**:
   - Builders often use a fluent interface to chain method calls, improving readability.

4. **Complex Object Creation**:
   - Simplifies the creation of complex objects that have multiple parts or configurations.

---

## UML Diagram

The UML diagram below illustrates the Builder Pattern, showing how the `Director` uses a `Builder` to construct a `Product`.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Creational/Builder/builder.puml)

---

## Implementation Walkthrough

### Participants

1. **Builder**:
   - Abstract interface that defines the building steps for creating the object.

2. **Concrete Builder**:
   - Implements the `Builder` interface to construct and assemble parts of the object.

3. **Director**:
   - Orchestrates the construction process using the `Builder` interface.
   - Constructs the object step by step.

4. **Product**:
   - The complex object being built.

---

### Example: Building a House

#### Product: House
```java
/**
 * @brief The complex object being built.
 */
public class House {
    private String foundation;
    private String structure;
    private String roof;
    private boolean hasGarden;
    private boolean hasSwimmingPool;

    public void setFoundation(String foundation) {
        this.foundation = foundation;
    }

    public void setStructure(String structure) {
        this.structure = structure;
    }

    public void setRoof(String roof) {
        this.roof = roof;
    }

    public void setHasGarden(boolean hasGarden) {
        this.hasGarden = hasGarden;
    }

    public void setHasSwimmingPool(boolean hasSwimmingPool) {
        this.hasSwimmingPool = hasSwimmingPool;
    }

    @Override
    public String toString() {
        return "House [foundation=" + foundation +
               ", structure=" + structure +
               ", roof=" + roof +
               ", hasGarden=" + hasGarden +
               ", hasSwimmingPool=" + hasSwimmingPool + "]";
    }
}
```

---

#### Builder Interface
```java
/**
 * @brief Builder interface for constructing a House.
 */
public interface HouseBuilder {
    void buildFoundation();
    void buildStructure();
    void buildRoof();
    void buildGarden();
    void buildSwimmingPool();
    House getHouse();
}
```

---

#### Concrete Builder: ModernHouseBuilder
```java
/**
 * @brief Concrete implementation of the HouseBuilder.
 * Builds a modern house with specific features.
 */
public class ModernHouseBuilder implements HouseBuilder {
    private House house;

    public ModernHouseBuilder() {
        this.house = new House();
    }

    @Override
    public void buildFoundation() {
        house.setFoundation("Concrete foundation");
    }

    @Override
    public void buildStructure() {
        house.setStructure("Steel and glass structure");
    }

    @Override
    public void buildRoof() {
        house.setRoof("Flat roof with solar panels");
    }

    @Override
    public void buildGarden() {
        house.setHasGarden(true);
    }

    @Override
    public void buildSwimmingPool() {
        house.setHasSwimmingPool(true);
    }

    @Override
    public House getHouse() {
        return this.house;
    }
}
```

---

#### Director
```java
/**
 * @brief Director orchestrates the building process.
 */
public class HouseDirector {
    private HouseBuilder builder;

    public HouseDirector(HouseBuilder builder) {
        this.builder = builder;
    }

    public void constructHouse() {
        builder.buildFoundation();
        builder.buildStructure();
        builder.buildRoof();
        builder.buildGarden();
        builder.buildSwimmingPool();
    }

    public House getHouse() {
        return builder.getHouse();
    }
}
```

---

#### Client Code
```java
/**
 * @brief Client demonstrating the Builder Pattern.
 */
public class BuilderPatternDemo {
    public static void main(String[] args) {
        // Use the ModernHouseBuilder
        HouseBuilder builder = new ModernHouseBuilder();
        HouseDirector director = new HouseDirector(builder);

        // Construct the house
        director.constructHouse();
        House house = director.getHouse();

        // Output the house details
        System.out.println(house);
    }
}
```

---

### Output
```
House [foundation=Concrete foundation, structure=Steel and glass structure, roof=Flat roof with solar panels, hasGarden=true, hasSwimmingPool=true]
```

---

## Applications

### When to Use the Builder Pattern
1. When constructing complex objects with multiple optional parts or configurations.
2. When the construction process needs to be controlled and consistent.
3. When you want to create different representations of the same object.

### Common Use Cases
1. **UI Builders**:
   - Creating complex graphical user interfaces with many components.
2. **Document Creation**:
   - Constructing documents with structured layouts (e.g., HTML, PDF).
3. **Game Development**:
   - Building game characters or levels with customizable features.

---

## Advantages and Disadvantages

### Advantages
1. **Clear Construction**:
   - Separates object creation logic from its representation.
2. **Reusability**:
   - Builders can be reused for different configurations of the same object.
3. **Scalability**:
   - Easy to add new builders for different representations.

### Disadvantages
1. **Complexity**:
   - Introduces additional classes for the builder and director.
2. **Overhead**:
   - May be unnecessary for simple object creation.

---

## Key Takeaways

The Builder Pattern is ideal for constructing complex objects with multiple optional parts. It provides a structured and scalable approach to object creation while maintaining flexibility and separation of concerns.
