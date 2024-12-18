# Mediator Pattern

## Category
Behavioral Design Pattern

---

## Overview

The **Mediator Pattern** is a **behavioral design pattern** that facilitates communication between objects (colleagues) by encapsulating their interactions within a **mediator object**. Instead of having objects refer to and interact with each other directly, they communicate through a central mediator, which promotes loose coupling and simplifies complex interactions.

This pattern is particularly useful when:
- You have multiple objects interacting in complex ways.
- You want to decouple the objects to reduce dependencies.
- You aim to centralize and manage the behavior of a group of objects.

---

## Key Characteristics

1. **Centralized Communication**:
   - The mediator encapsulates communication logic, preventing objects from referring to each other directly.

2. **Loose Coupling**:
   - Colleague objects are independent and only know about the mediator.

3. **Behavioral Encapsulation**:
   - Complex interaction logic is encapsulated within the mediator, improving maintainability.

4. **Dynamic Relationships**:
   - The mediator allows dynamic modification of object interactions at runtime.

---

## UML Diagram

The UML diagram below illustrates the Mediator Pattern, showing how colleagues communicate exclusively through the mediator.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Behavioral/Mediator/mediator.puml)

---

## Implementation Walkthrough

### Participants

1. **Mediator**:
   - Defines the interface for communication between colleagues.

2. **Concrete Mediator**:
   - Implements the mediator interface and coordinates communication between colleagues.

3. **Colleague**:
   - Represents an object that communicates with other colleagues via the mediator.

4. **Concrete Colleague**:
   - Implements specific functionality and communicates exclusively through the mediator.

---

### Example: Chat Room System

#### Mediator Interface
```java
/**
 * @brief Interface defining communication methods.
 */
public interface Mediator {
    void sendMessage(String message, Colleague sender);
    void addColleague(Colleague colleague);
}
```

---

#### Concrete Mediator: Chat Room
```java
/**
 * @brief Concrete mediator managing communication between users.
 */
public class ChatRoom implements Mediator {
    private List<Colleague> colleagues = new ArrayList<>();

    @Override
    public void sendMessage(String message, Colleague sender) {
        for (Colleague colleague : colleagues) {
            if (colleague != sender) {
                colleague.receive(message);
            }
        }
    }

    @Override
    public void addColleague(Colleague colleague) {
        colleagues.add(colleague);
    }
}
```

---

#### Colleague Interface
```java
/**
 * @brief Interface for colleagues that interact via the mediator.
 */
public abstract class Colleague {
    protected Mediator mediator;

    public Colleague(Mediator mediator) {
        this.mediator = mediator;
    }

    public abstract void send(String message);
    public abstract void receive(String message);
}
```

---

#### Concrete Colleague: User
```java
/**
 * @brief Concrete implementation of a colleague in the chat room.
 */
public class User extends Colleague {
    private String name;

    public User(String name, Mediator mediator) {
        super(mediator);
        this.name = name;
    }

    @Override
    public void send(String message) {
        System.out.println(name + ": Sending message: " + message);
        mediator.sendMessage(message, this);
    }

    @Override
    public void receive(String message) {
        System.out.println(name + ": Received message: " + message);
    }
}
```

---

#### Unit Test
```java
/**
 * @brief Test the Mediator pattern in a chat room context.
 */
public class MediatorTest {
    public static void main(String[] args) {
        Mediator chatRoom = new ChatRoom();

        Colleague user1 = new User("Alice", chatRoom);
        Colleague user2 = new User("Bob", chatRoom);
        Colleague user3 = new User("Charlie", chatRoom);

        chatRoom.addColleague(user1);
        chatRoom.addColleague(user2);
        chatRoom.addColleague(user3);

        user1.send("Hello, everyone!");
        user2.send("Hi, Alice!");
    }
}
```

---

### Output
```
Alice: Sending message: Hello, everyone!
Bob: Received message: Hello, everyone!
Charlie: Received message: Hello, everyone!
Bob: Sending message: Hi, Alice!
Alice: Received message: Hi, Alice!
Charlie: Received message: Hi, Alice!
```

---

## Applications

### When to Use the Mediator Pattern
1. **Complex Communication**:
   - When objects interact in complex ways that are difficult to manage and maintain.
2. **Decoupled Design**:
   - When you want to reduce dependencies between interacting objects.
3. **Dynamic Behavior**:
   - When interaction logic needs to change frequently or at runtime.

### Common Use Cases
1. **Chat Applications**:
   - Managing messages between multiple users in a chat room.
2. **UI Frameworks**:
   - Coordinating interactions between UI components (e.g., buttons, text fields).
3. **Control Systems**:
   - Managing communication between sensors and actuators in embedded systems.

---

## Advantages and Disadvantages

### Advantages
1. **Loose Coupling**:
   - Simplifies relationships between objects by introducing a mediator.
2. **Centralized Logic**:
   - Encapsulates complex behavior within a single class, improving maintainability.
3. **Dynamic Interactions**:
   - Supports flexible and dynamic changes to interaction logic.

### Disadvantages
1. **Potential Complexity**:
   - The mediator can become a "God object" if it grows too large or manages too much logic.
2. **Single Point of Failure**:
   - Centralizing interactions in the mediator makes it critical to system functionality.

---

## Comparison with Other Patterns

| **Pattern**           | **Purpose**                                                                                     |
|------------------------|-------------------------------------------------------------------------------------------------|
| **Mediator**           | Centralizes communication between objects.                                                     |
| **Observer**           | Establishes a one-to-many dependency for event notifications.                                  |
| **Command**            | Encapsulates a request as an object to parameterize clients.                                   |
| **Facade**             | Provides a simplified interface to a subsystem but does not manage interactions between objects. |

---

## Key Takeaways

The **Mediator Pattern** simplifies communication between objects by centralizing their interactions. This makes the system easier to maintain, extend, and modify. However, care must be taken to prevent the mediator from becoming overly complex or bloated.

- **Use it when**: Objects interact in complex ways that are difficult to manage directly.
- **Avoid it when**: Simpler solutions suffice, or the mediator risks becoming a bottleneck.