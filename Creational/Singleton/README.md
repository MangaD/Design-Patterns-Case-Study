# Singleton Pattern

## Category
Creational Design Pattern

---

## Overview

The **Singleton Pattern** is a **creational design pattern** that ensures a class has only **one instance** throughout the lifetime of an application. It provides a **global point of access** to that instance, ensuring consistency and centralized control over shared resources or global states.

This pattern is particularly useful when:
- A shared resource needs to be accessed globally.
- It is critical to maintain a single state across the application.

---

## Key Characteristics

1. **Global Access**:
   - Provides a single access point to the instance through a static method.

2. **Controlled Instantiation**:
   - Ensures that only one instance exists by making the constructor private.

3. **Lazy or Eager Initialization**:
   - Controls when the instance is created:
     - **Lazy Initialization**: The instance is created only when accessed for the first time.
     - **Eager Initialization**: The instance is created during class loading.

4. **Thread Safety**:
   - Ensures that the Singleton instance is safely shared across threads using synchronization or modern static initialization techniques.

5. **Encapsulation**:
   - The Singleton class encapsulates its own instantiation logic, adhering to the **Single Responsibility Principle**.

---

## UML Diagram

The UML diagram below illustrates the Singleton Pattern. The static `getInstance` method ensures a single instance of the class is created and shared.

![UML Diagram](singleton.png)

---

## Implementation Variations

### 1. Eager Initialization
The instance is created at the time of class loading, ensuring simplicity but potentially wasting resources if unused.

```java
public class EagerSingleton {
    private static final EagerSingleton INSTANCE = new EagerSingleton();

    private EagerSingleton() {}

    public static EagerSingleton getInstance() {
        return INSTANCE;
    }
}
```

---

### 2. Lazy Initialization
The instance is created only when it is first accessed, saving resources if it is not immediately needed.

```java
public class LazySingleton {
    private static LazySingleton instance;

    private LazySingleton() {}

    public static LazySingleton getInstance() {
        if (instance == null) {
            instance = new LazySingleton();
        }
        return instance;
    }
}
```

---

### 3. Thread-Safe Initialization
Ensures that the Singleton instance is safely shared across multiple threads.

#### Double-Checked Locking
```java
public class ThreadSafeSingleton {
    private static volatile ThreadSafeSingleton instance;

    private ThreadSafeSingleton() {}

    public static ThreadSafeSingleton getInstance() {
        if (instance == null) {
            synchronized (ThreadSafeSingleton.class) {
                if (instance == null) {
                    instance = new ThreadSafeSingleton();
                }
            }
        }
        return instance;
    }
}
```

---

### 4. Enum Singleton
Provides a thread-safe and serialization-safe Singleton implementation. This approach is unique to Java.

```java
public enum EnumSingleton {
    INSTANCE;

    public void doSomething() {
        System.out.println("Enum Singleton is working!");
    }
}
```

---

## Example: Logging System

A **logger** is a common use case for the Singleton Pattern. It ensures that all parts of the application log messages through the same instance.

### Implementation
```java
public class Logger {
    private static Logger instance;

    private Logger() {}

    public static Logger getInstance() {
        if (instance == null) {
            synchronized (Logger.class) {
                if (instance == null) {
                    instance = new Logger();
                }
            }
        }
        return instance;
    }

    public void log(String message) {
        System.out.println("Log: " + message);
    }
}
```

### Client Code
```java
Logger logger = Logger.getInstance();
logger.log("Singleton logger example.");
```

### Output
```
Log: Singleton logger example.
```

---

## Use Cases

1. **Logging Service**:
   - A single logging instance ensures consistent formatting and centralized log output.

2. **Configuration Manager**:
   - Centralized access to application settings or configuration.

3. **Resource Management**:
   - Manages shared resources such as database connections or thread pools.

4. **State Tracking**:
   - Centralizes and maintains a global state, such as an application session or cache.

---

## Advantages and Disadvantages

### Advantages
1. **Controlled Access**:
   - Simplifies and centralizes access to a shared resource or state.
2. **Resource Efficiency**:
   - Prevents redundant object creation.
3. **Global Consistency**:
   - Ensures a single, shared instance across the application.
4. **Thread Safety**:
   - Modern implementations ensure safe access in concurrent environments.

### Disadvantages
1. **Global State Dependency**:
   - Overuse can lead to tightly coupled code, making testing and maintenance more challenging.
2. **Difficulty in Testing**:
   - Mocking or replacing Singletons in unit tests can be complex.
3. **Potential Resource Waste**:
   - An eagerly initialized Singleton may consume resources even if it’s never used.

---

## Key Takeaways

The **Singleton Pattern** is a powerful tool for ensuring global consistency and controlled access to shared resources. However, it should be used judiciously to avoid pitfalls like tightly coupled code or hidden dependencies.

- **Use it when**: A single instance is needed to manage a shared resource or maintain a global state.
- **Avoid it when**: Simpler solutions suffice, or when testing flexibility is paramount.
