# Visitor Pattern

## Category
Behavioral Design Pattern

---

## Overview

The **Visitor Pattern** is a **behavioral design pattern** that allows you to separate algorithms from the objects on which they operate. It enables you to define a new operation for a group of objects without modifying their structures.

This pattern involves two main participants:
- **Visitor**: Defines a set of operations that can be applied to elements in the object structure.
- **Element**: Accepts a visitor and allows it to perform operations defined in the visitor.

The Visitor Pattern is particularly useful when:
- You need to perform multiple unrelated operations on objects without cluttering their code.
- Object structures are stable, but new behaviors need to be added frequently.

---

## Key Characteristics

1. **Separation of Concerns**:
   - Encapsulates operations in a visitor class, separating them from the object structure.

2. **Open/Closed Principle**:
   - Allows adding new operations without modifying existing element classes.

3. **Double Dispatch**:
   - Ensures that the correct visitor operation is executed for the given element by utilizing both the type of the visitor and the element.

4. **Complexity Management**:
   - Ideal for operations that span multiple classes, reducing code duplication and improving maintainability.

5. **Scalability**:
   - Facilitates the addition of new operations (via new visitors) without changing the object structure.

---

## UML Diagram

The UML diagram below illustrates the Visitor Pattern, showcasing how the Visitor interacts with Elements and their structure.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Behavioral/Visitor/visitor.puml)

---

## Implementation Walkthrough

### Participants

1. **Visitor**:
   - Declares operations for each type of element in the object structure.
   
2. **Concrete Visitor**:
   - Implements specific behavior for each element type.

3. **Element**:
   - Declares an `accept` method that accepts a visitor and delegates the operation to it.

4. **Concrete Element**:
   - Implements the `accept` method and provides additional behavior specific to the element.

5. **Object Structure**:
   - A collection of elements that can be visited.

---

### Example: A File System Scanner

Imagine a system where files and folders need to be processed differently for operations like:
- Calculating total size.
- Checking permissions.
- Logging details.

The Visitor Pattern separates these operations into distinct visitor classes without modifying the file and folder structures.

#### Element Interface
```java
/**
 * @brief Represents an element in the file system.
 */
public interface FileSystemElement {
    void accept(Visitor visitor);
}
```

---

#### Concrete Elements
```java
/**
 * @brief Represents a File element in the file system.
 */
public class File implements FileSystemElement {
    private String name;
    private int size;

    public File(String name, int size) {
        this.name = name;
        this.size = size;
    }

    public String getName() {
        return name;
    }

    public int getSize() {
        return size;
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}

/**
 * @brief Represents a Folder element in the file system.
 */
public class Folder implements FileSystemElement {
    private String name;
    private List<FileSystemElement> children = new ArrayList<>();

    public Folder(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public List<FileSystemElement> getChildren() {
        return children;
    }

    public void add(FileSystemElement element) {
        children.add(element);
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}
```

---

#### Visitor Interface
```java
/**
 * @brief Declares operations for each element type in the file system.
 */
public interface Visitor {
    void visit(File file);
    void visit(Folder folder);
}
```

---

#### Concrete Visitors
```java
/**
 * @brief Visitor to calculate the total size of the file system.
 */
public class SizeCalculatorVisitor implements Visitor {
    private int totalSize = 0;

    @Override
    public void visit(File file) {
        totalSize += file.getSize();
    }

    @Override
    public void visit(Folder folder) {
        for (FileSystemElement child : folder.getChildren()) {
            child.accept(this);
        }
    }

    public int getTotalSize() {
        return totalSize;
    }
}

/**
 * @brief Visitor to log details of the file system.
 */
public class LoggerVisitor implements Visitor {
    @Override
    public void visit(File file) {
        System.out.println("File: " + file.getName() + ", Size: " + file.getSize());
    }

    @Override
    public void visit(Folder folder) {
        System.out.println("Folder: " + folder.getName());
        for (FileSystemElement child : folder.getChildren()) {
            child.accept(this);
        }
    }
}
```

---

#### Client Code
```java
public class VisitorPatternDemo {
    public static void main(String[] args) {
        // Build file system
        Folder root = new Folder("root");
        File file1 = new File("file1.txt", 100);
        File file2 = new File("file2.txt", 200);
        Folder subFolder = new Folder("subFolder");
        File file3 = new File("file3.txt", 300);

        root.add(file1);
        root.add(file2);
        subFolder.add(file3);
        root.add(subFolder);

        // Use SizeCalculatorVisitor
        SizeCalculatorVisitor sizeVisitor = new SizeCalculatorVisitor();
        root.accept(sizeVisitor);
        System.out.println("Total size: " + sizeVisitor.getTotalSize());

        // Use LoggerVisitor
        LoggerVisitor loggerVisitor = new LoggerVisitor();
        root.accept(loggerVisitor);
    }
}
```

---

### Output
```
Total size: 600
Folder: root
File: file1.txt, Size: 100
File: file2.txt, Size: 200
Folder: subFolder
File: file3.txt, Size: 300
```

---

## Applications

### When to Use the Visitor Pattern
1. **Multiple Operations**:
   - When you need to perform multiple unrelated operations on objects in a structure.
2. **Stable Structure**:
   - When the object structure is unlikely to change but new operations are frequently required.
3. **Separation of Concerns**:
   - To separate operations from the data structures they act upon.

### Common Use Cases
1. **Compilers**:
   - Traversing and interpreting abstract syntax trees.
2. **File Systems**:
   - Performing operations like size calculation, permission checking, or logging.
3. **Graphics Editors**:
   - Applying filters or effects to objects in a scene graph.

---

## Advantages and Disadvantages

### Advantages
1. **Simplifies Object Structures**:
   - Moves unrelated operations out of the object structure.
2. **Open/Closed Principle**:
   - New operations can be added by creating new visitors.
3. **Flexibility**:
   - Supports different operations without modifying the elements.

### Disadvantages
1. **Violation of Encapsulation**:
   - Visitors may access internal state, breaking encapsulation.
2. **Complexity**:
   - Adding a new element requires updating all visitors.
3. **Coupling**:
   - Tightly couples visitors with element classes.

---

## Key Takeaways

The **Visitor Pattern** decouples algorithms from the objects they operate on, promoting flexibility and adherence to the Open/Closed Principle. It is ideal for stable object structures requiring frequent addition of new operations. However, careful consideration is needed to manage its potential complexity and coupling.