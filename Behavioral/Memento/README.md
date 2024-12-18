# Memento Pattern

## Category
Behavioral Design Pattern

---

## Overview

The **Memento Pattern** is a **behavioral design pattern** that provides the ability to restore an object to its previous state without exposing its implementation details. This is achieved by creating a **memento object** that captures and stores the internal state of another object (referred to as the originator).

This pattern is particularly useful when:
- You need to implement an undo/redo mechanism.
- You want to isolate and protect the internal state of an object from direct access by other parts of the system.

---

## Key Characteristics

1. **State Preservation**:
   - Enables saving and restoring an object’s internal state at a specific point in time.

2. **Encapsulation**:
   - Protects the internal state of the originator by encapsulating it within a memento object, which can only be accessed by the originator.

3. **Undo/Redo Operations**:
   - Commonly used in systems requiring undo/redo functionality, such as text editors or games.

4. **Role Separation**:
   - Defines three key participants: 
     - **Originator**: The object whose state needs saving.
     - **Memento**: The object storing the saved state.
     - **Caretaker**: Manages mementos and interacts with the originator to save or restore states.

5. **Non-Intrusive**:
   - The memento object does not interfere with the originator's behavior; it merely stores state data.

---

## UML Diagram

The UML diagram below illustrates the relationships between the Originator, Memento, and Caretaker in the Memento Pattern.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Behavioral/Memento/memento.puml)

---

## Implementation Walkthrough

### Participants

1. **Originator**:
   - The main object whose state needs to be saved and restored.
   - Creates and restores mementos.

2. **Memento**:
   - A storage object that holds the internal state of the originator.
   - Provides controlled access to the stored state.

3. **Caretaker**:
   - Manages mementos and coordinates the saving and restoring of the originator's state.

---

### Example: Undo/Redo in a Text Editor

#### Originator: TextEditor
```java
/**
 * @brief The Originator that maintains the state to be saved or restored.
 */
public class TextEditor {
    private String content;

    public void setContent(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    /**
     * @brief Creates a memento containing the current state.
     * @return A new Memento instance.
     */
    public Memento save() {
        return new Memento(content);
    }

    /**
     * @brief Restores the state from a given memento.
     * @param memento The memento containing the saved state.
     */
    public void restore(Memento memento) {
        this.content = memento.getContent();
    }
}
```

---

#### Memento
```java
/**
 * @brief The Memento storing the state of the Originator.
 */
public class Memento {
    private final String content;

    public Memento(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }
}
```

---

#### Caretaker: HistoryManager
```java
/**
 * @brief The Caretaker that manages the memento lifecycle.
 */
import java.util.Stack;

public class HistoryManager {
    private Stack<Memento> history = new Stack<>();

    public void save(Memento memento) {
        history.push(memento);
    }

    public Memento undo() {
        if (!history.isEmpty()) {
            return history.pop();
        }
        return null;
    }
}
```

---

#### Client Code
```java
/**
 * @brief Demonstrates the Memento Pattern with undo functionality.
 */
public class MementoPatternDemo {
    public static void main(String[] args) {
        TextEditor editor = new TextEditor();
        HistoryManager history = new HistoryManager();

        editor.setContent("Version 1");
        history.save(editor.save());

        editor.setContent("Version 2");
        history.save(editor.save());

        editor.setContent("Version 3");

        System.out.println("Current content: " + editor.getContent());
        editor.restore(history.undo());
        System.out.println("After undo: " + editor.getContent());
        editor.restore(history.undo());
        System.out.println("After another undo: " + editor.getContent());
    }
}
```

---

### Output
```
Current content: Version 3
After undo: Version 2
After another undo: Version 1
```

---

## Applications

### When to Use the Memento Pattern
1. When you need to implement undo/redo functionality.
2. When you want to save and restore the state of an object without exposing its implementation details.
3. When you want to minimize coupling between the state-saving logic and the object itself.

### Common Use Cases
1. **Text Editors**:
   - Undo/redo functionality for editing text.
2. **Games**:
   - Saving and loading game progress.
3. **Configuration Systems**:
   - Restoring system settings or configurations.

---

## Advantages and Disadvantages

### Advantages
1. **Encapsulation**:
   - Protects the originator’s internal state from external modification.
2. **Flexibility**:
   - Allows saving and restoring an object’s state at runtime.
3. **Scalability**:
   - The caretaker can manage multiple mementos, enabling complex state transitions.

### Disadvantages
1. **Memory Overhead**:
   - Maintaining multiple mementos can consume significant memory.
2. **Complexity**:
   - Managing mementos and ensuring proper lifecycle management can be challenging.
3. **Limited Access**:
   - If not designed properly, the caretaker may inadvertently expose the originator’s state.

---

## Key Takeaways

The **Memento Pattern** provides a structured way to save and restore the state of objects, enabling powerful features like undo/redo and checkpointing. While it introduces additional components and complexity, its benefits in preserving state and encapsulation make it an essential pattern in behavioral design.