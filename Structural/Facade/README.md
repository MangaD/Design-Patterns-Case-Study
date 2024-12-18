# Facade Pattern

## Category
Structural Design Pattern

---

## Overview

The **Facade Pattern** is a **structural design pattern** that provides a simplified interface to a complex subsystem. By creating a "facade" class that interacts with the subsystem, it allows clients to use the subsystem's functionality without needing to understand its intricacies or implementation details.

This pattern promotes **encapsulation** and **separation of concerns**, making complex systems easier to use and maintain.

---

## Key Characteristics

1. **Simplified Interface**:
   - Provides a high-level interface that simplifies access to a complex subsystem.

2. **Encapsulation**:
   - Hides the complexity of the subsystem by exposing only the relevant methods through the facade.

3. **Decoupling**:
   - Decouples the client from the subsystem, making the code easier to maintain and extend.

4. **Integration with Other Patterns**:
   - Often used alongside other patterns (e.g., Adapter, Mediator) to further simplify interactions.

5. **Improved Maintainability**:
   - Changes to the subsystem do not impact clients, as long as the facade's interface remains unchanged.

---

## UML Diagram

The UML diagram below illustrates the Facade Pattern. The **Facade** provides a simplified interface to the **Subsystems**, while the **Client** interacts with the facade without directly accessing the subsystems.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Structural/Facade/facade.puml)

---

## Implementation Walkthrough

### Participants

1. **Facade**:
   - Provides a unified interface to the subsystem.
   - Delegates client requests to the appropriate subsystem components.

2. **Subsystems**:
   - Represent the components of the system that perform the actual work.
   - The subsystems are unaware of the facade and do not depend on it.

3. **Client**:
   - Uses the facade to interact with the subsystem, avoiding direct interaction with the subsystem's components.

---

### Example: Home Theater System

Imagine you have a home theater system with multiple components (e.g., TV, speakers, DVD player). Without a facade, the client must interact with each component individually, resulting in complex code. A facade simplifies this by providing a unified interface to control the system.

#### Subsystems
```java
/**
 * @brief Represents the TV subsystem.
 */
public class TV {
    public void turnOn() {
        System.out.println("Turning on the TV.");
    }

    public void turnOff() {
        System.out.println("Turning off the TV.");
    }
}

/**
 * @brief Represents the Sound System subsystem.
 */
public class SoundSystem {
    public void turnOn() {
        System.out.println("Turning on the sound system.");
    }

    public void setVolume(int level) {
        System.out.println("Setting volume to " + level);
    }

    public void turnOff() {
        System.out.println("Turning off the sound system.");
    }
}

/**
 * @brief Represents the DVD Player subsystem.
 */
public class DVDPlayer {
    public void playMovie(String movie) {
        System.out.println("Playing movie: " + movie);
    }

    public void stopMovie() {
        System.out.println("Stopping the movie.");
    }
}
```

---

#### Facade
```java
/**
 * @brief The Facade class simplifies interaction with the subsystems.
 */
public class HomeTheaterFacade {
    private TV tv;
    private SoundSystem soundSystem;
    private DVDPlayer dvdPlayer;

    public HomeTheaterFacade(TV tv, SoundSystem soundSystem, DVDPlayer dvdPlayer) {
        this.tv = tv;
        this.soundSystem = soundSystem;
        this.dvdPlayer = dvdPlayer;
    }

    public void watchMovie(String movie) {
        System.out.println("Setting up the home theater...");
        tv.turnOn();
        soundSystem.turnOn();
        soundSystem.setVolume(20);
        dvdPlayer.playMovie(movie);
    }

    public void endMovie() {
        System.out.println("Shutting down the home theater...");
        dvdPlayer.stopMovie();
        soundSystem.turnOff();
        tv.turnOff();
    }
}
```

---

#### Client
```java
/**
 * @brief Client code demonstrating the Facade Pattern.
 */
public class FacadePatternDemo {
    public static void main(String[] args) {
        TV tv = new TV();
        SoundSystem soundSystem = new SoundSystem();
        DVDPlayer dvdPlayer = new DVDPlayer();

        HomeTheaterFacade homeTheater = new HomeTheaterFacade(tv, soundSystem, dvdPlayer);

        homeTheater.watchMovie("Inception");
        homeTheater.endMovie();
    }
}
```

---

### Output
```
Setting up the home theater...
Turning on the TV.
Turning on the sound system.
Setting volume to 20
Playing movie: Inception
Shutting down the home theater...
Stopping the movie.
Turning off the sound system.
Turning off the TV.
```

---

## Applications

### When to Use the Facade Pattern
1. **Simplify Subsystem Usage**:
   - When a system contains many components, and clients need an easy way to interact with it.
2. **Encapsulate Complexity**:
   - When exposing the full subsystem to clients would overwhelm them.
3. **Isolate Clients from Subsystem Changes**:
   - When the system's implementation may change, but you want to keep the client interface stable.

### Common Use Cases
1. **API Wrappers**:
   - Libraries that simplify access to complex systems or external APIs.
2. **Home Automation**:
   - Controlling multiple devices with a single interface.
3. **Enterprise Applications**:
   - Providing simplified access to multiple back-end systems.

---

## Advantages and Disadvantages

### Advantages
1. **Simplifies Client Code**:
   - Clients interact with a single interface rather than multiple components.
2. **Encapsulation**:
   - Hides subsystem complexities, reducing the learning curve for clients.
3. **Decoupling**:
   - Shields clients from changes in subsystem implementations.

### Disadvantages
1. **Reduced Flexibility**:
   - Clients may lose access to advanced functionality provided by individual components.
2. **Potential Overhead**:
   - The facade adds an extra layer, which may introduce slight overhead.

---

## Key Takeaways

The **Facade Pattern** simplifies complex systems by providing a unified, high-level interface. It improves usability and maintainability, making it an excellent choice when dealing with intricate subsystems. However, care should be taken to ensure that the facade remains consistent and does not obscure necessary functionality.

- **Use it when**: Simplifying complex subsystems or decoupling clients from implementation details.
- **Avoid it when**: Clients need fine-grained control over the subsystem’s components.