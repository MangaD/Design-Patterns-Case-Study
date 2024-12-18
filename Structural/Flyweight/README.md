# Flyweight Pattern

## **Category**
Structural Design Pattern

---

## **Overview**

The **Flyweight Pattern** is a structural design pattern that focuses on reducing memory consumption and improving performance by sharing as much data as possible among similar objects. Instead of creating multiple objects with the same intrinsic properties, the Flyweight Pattern allows those properties to be shared, while extrinsic properties unique to each object are stored externally.

This pattern is particularly useful when:
- A large number of objects share common data.
- Object creation and memory usage need optimization.
- The intrinsic state of an object is immutable and can be shared.

---

## **Key Characteristics**

1. **Intrinsic and Extrinsic State**:
   - **Intrinsic State**: Shared among objects and remains immutable.
   - **Extrinsic State**: Varies between objects and is passed externally.

2. **Memory Optimization**:
   - Reduces the number of objects in memory by sharing instances of objects with similar intrinsic state.

3. **Object Factory**:
   - A central factory ensures the reuse of existing flyweights or creates new ones if needed.

4. **Immutability**:
   - Flyweight objects typically have immutable intrinsic state, making them thread-safe.

5. **Scalability**:
   - Effectively handles large datasets where many objects have similar data.

---

## **UML Diagram**

The UML diagram below illustrates the Flyweight Pattern. A `Flyweight` interface defines common operations, and a `FlyweightFactory` manages shared instances.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Structural/Flyweight/flyweight.puml)

---

## **Implementation Walkthrough**

### **Participants**

1. **Flyweight**:
   - Defines the interface for objects that can share intrinsic state.

2. **Concrete Flyweight**:
   - Implements the Flyweight interface and contains intrinsic state.

3. **Flyweight Factory**:
   - Manages the creation and sharing of flyweight objects.

4. **Client**:
   - Uses flyweights and manages extrinsic state.

---

### **Example: Reusing Tree Objects in a Forest**

#### Flyweight Interface
```java
/**
 * @brief Flyweight interface for tree types.
 */
public interface TreeType {
    void draw(int x, int y);
}
```

---

#### Concrete Flyweight
```java
/**
 * @brief Concrete implementation of the TreeType flyweight.
 *
 * Stores intrinsic state shared by all trees of this type.
 */
public class ConcreteTreeType implements TreeType {
    private final String name;
    private final String color;
    private final String texture;

    public ConcreteTreeType(String name, String color, String texture) {
        this.name = name;
        this.color = color;
        this.texture = texture;
    }

    @Override
    public void draw(int x, int y) {
        System.out.println("Drawing tree [" + name + ", " + color + ", " + texture + "] at (" + x + ", " + y + ")");
    }
}
```

---

#### Flyweight Factory
```java
/**
 * @brief Factory for managing and reusing TreeType instances.
 */
public class TreeFactory {
    private static final Map<String, TreeType> treeTypes = new HashMap<>();

    public static TreeType getTreeType(String name, String color, String texture) {
        String key = name + "_" + color + "_" + texture;
        return treeTypes.computeIfAbsent(key, k -> new ConcreteTreeType(name, color, texture));
    }
}
```

---

#### **Tree Class (Client-Side Object)**
```java
/**
 * @brief Client-side object that combines intrinsic and extrinsic state.
 */
public class Tree {
    private final int x;
    private final int y;
    private final TreeType type;

    public Tree(int x, int y, TreeType type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }

    public void draw() {
        type.draw(x, y);
    }
}
```

---

#### **Client Code: Forest**
```java
/**
 * @brief Manages a collection of trees and utilizes the Flyweight pattern.
 */
public class Forest {
    private final List<Tree> trees = new ArrayList<>();

    public void plantTree(int x, int y, String name, String color, String texture) {
        TreeType type = TreeFactory.getTreeType(name, color, texture);
        trees.add(new Tree(x, y, type));
    }

    public void draw() {
        for (Tree tree : trees) {
            tree.draw();
        }
    }
}
```

---

#### **Client Code Example**
```java
public class FlyweightPatternDemo {
    public static void main(String[] args) {
        Forest forest = new Forest();

        // Plant trees with shared TreeType
        forest.plantTree(1, 1, "Oak", "Green", "Rough");
        forest.plantTree(2, 3, "Pine", "Dark Green", "Smooth");
        forest.plantTree(4, 5, "Oak", "Green", "Rough"); // Reuses the "Oak" type

        // Draw the forest
        forest.draw();
    }
}
```

---

### **Output**
```
Drawing tree [Oak, Green, Rough] at (1, 1)
Drawing tree [Pine, Dark Green, Smooth] at (2, 3)
Drawing tree [Oak, Green, Rough] at (4, 5)
```

---


## **Applications**

### **When to Use the Flyweight Pattern**
1. **Memory Optimization**:
   - When an application needs to manage a large number of similar objects.
2. **Shared Data**:
   - When objects share significant portions of data.
3. **Immutable State**:
   - When the shared state is constant and can be reused safely.

### **Common Use Cases**
1. **Game Development**:
   - Representing large numbers of entities (e.g., trees, characters) with shared attributes.
2. **Text Editors**:
   - Managing character formatting where glyph shapes are shared.
3. **Data Caching**:
   - Reusing objects in data-intensive applications.

---

## **Advantages and Disadvantages**

### **Advantages**
1. **Memory Efficiency**:
   - Reduces memory consumption by sharing objects with the same intrinsic state.
2. **Improved Performance**:
   - Reduces the cost of creating and managing large numbers of similar objects.
3. **Scalability**:
   - Enables the handling of large datasets with minimal resource overhead.

### **Disadvantages**
1. **Increased Complexity**:
   - Requires additional code to manage the flyweight objects and their states.
2. **Limited Flexibility**:
   - Intrinsic state must be immutable, which can limit object behavior.
3. **Coupling**:
   - Introduces dependency on a centralized factory.

---

## **Key Takeaways**

The **Flyweight Pattern** is a powerful solution for managing memory and optimizing performance when dealing with a large number of objects that share common data. While it introduces complexity through its use of intrinsic and extrinsic states, it is invaluable in resource-constrained or performance-critical applications.