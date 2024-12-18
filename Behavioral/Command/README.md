# Command Pattern

## Category
Behavioral Design Pattern

---

## Overview

The **Command Pattern** is a **behavioral design pattern** that encapsulates a request or an operation as an object, thereby allowing you to:

1. Parameterize objects with operations.
2. Queue or log operations for later execution.
3. Support undoable operations.

This pattern is particularly useful for decoupling the **invoker** (the object making the request) from the **receiver** (the object performing the request). It enables more flexible designs by allowing requests to be dynamically modified, queued, or stored.

---

## Key Characteristics

1. **Encapsulation of Requests**:
   - Encapsulates a request as an object, enabling its execution, undo, or reuse later.

2. **Decoupling of Sender and Receiver**:
   - The invoker of the request doesn't need to know the details of how the request will be handled.

3. **Undo/Redo Functionality**:
   - Commands can store the necessary state to reverse their operations.

4. **Macro Commands**:
   - Commands can be composed into sequences to execute multiple operations.

5. **Dynamic Execution**:
   - Requests can be dynamically created and passed around as objects.

---

## UML Diagram

The UML diagram below illustrates the Command Pattern, showing how the `Invoker` interacts with `Command` objects to execute requests on `Receiver` objects.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Behavioral/Command/command.puml)

- **Command**: Declares the interface for executing an operation.
- **ConcreteCommand**: Implements the `Command` interface and defines the relationship between the `Receiver` and the action.
- **Receiver**: Knows how to perform the operations associated with carrying out a request.
- **Invoker**: Asks the command to execute the request.
- **Client**: Creates and configures the command objects.

---

## Implementation Walkthrough

### Participants

1. **Command Interface**:
   - Declares a method for executing a command.

2. **ConcreteCommand**:
   - Implements the command by invoking specific actions on the receiver.

3. **Receiver**:
   - The object that performs the actual work when the command is executed.

4. **Invoker**:
   - Stores a reference to a command object and triggers its execution.

5. **Client**:
   - Configures the command and binds it to an invoker.

---

### Example: Smart Home Automation

#### Command Interface
```java
/**
 * @brief Command interface for all smart home operations.
 */
public interface Command {
    void execute();
    void undo();
}
```

---

#### Concrete Commands
```java
/**
 * @brief Command to turn on the light.
 */
public class LightOnCommand implements Command {
    private Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.turnOn();
    }

    @Override
    public void undo() {
        light.turnOff();
    }
}

/**
 * @brief Command to turn off the light.
 */
public class LightOffCommand implements Command {
    private Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.turnOff();
    }

    @Override
    public void undo() {
        light.turnOn();
    }
}
```

---

#### Receiver
```java
/**
 * @brief The light (receiver) knows how to perform specific operations.
 */
public class Light {
    public void turnOn() {
        System.out.println("The light is ON.");
    }

    public void turnOff() {
        System.out.println("The light is OFF.");
    }
}
```

---

#### Invoker
```java
/**
 * @brief Remote control (Invoker) stores and executes commands.
 */
public class RemoteControl {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void pressButton() {
        command.execute();
    }

    public void pressUndo() {
        command.undo();
    }
}
```

---

#### Client Code
```java
public class CommandPatternDemo {
    public static void main(String[] args) {
        Light livingRoomLight = new Light();

        Command lightOn = new LightOnCommand(livingRoomLight);
        Command lightOff = new LightOffCommand(livingRoomLight);

        RemoteControl remote = new RemoteControl();

        // Turn the light on
        remote.setCommand(lightOn);
        remote.pressButton();

        // Undo the action
        remote.pressUndo();

        // Turn the light off
        remote.setCommand(lightOff);
        remote.pressButton();

        // Undo the action
        remote.pressUndo();
    }
}
```

---

### Output
```
The light is ON.
The light is OFF.
The light is OFF.
The light is ON.
```

---

## Applications

### When to Use the Command Pattern
1. **Decoupling Sender and Receiver**:
   - When you want to parameterize objects with operations.
2. **Undo/Redo Functionality**:
   - When commands need to be undoable.
3. **Macro Commands**:
   - When you want to execute a series of commands as a single operation.
4. **Queue Requests**:
   - When requests need to be queued or logged for later execution.

### Common Use Cases
1. **UI Buttons and Menus**:
   - Assigning commands to buttons or menu items.
2. **Task Scheduling**:
   - Queuing tasks for execution at a later time.
3. **Undo/Redo in Text Editors**:
   - Reversing user actions.
4. **Game Development**:
   - Replaying sequences of actions.

---

## Advantages and Disadvantages

### Advantages
1. **Decoupling**:
   - Separates invoker and receiver, making the system more flexible.
2. **Command Composition**:
   - Commands can be composed into macros.
3. **Undo/Redo Support**:
   - Simplifies implementation of undoable operations.
4. **Extensibility**:
   - Adding new commands is straightforward.

### Disadvantages
1. **Complexity**:
   - Introduces additional layers of abstraction.
2. **Overhead**:
   - May increase memory usage when storing command histories.

---

## Key Takeaways

The **Command Pattern** encapsulates requests as objects, decoupling the invoker from the receiver and enabling advanced functionality like undo/redo, macros, and request queuing.

- **Use it when**: You need to decouple request senders from request executors or support undoable operations.
- **Avoid it when**: The additional abstraction is unnecessary, and simpler designs suffice.