# Bridge Pattern

## Category
Structural Design Pattern

---

## **Overview**

The **Bridge Pattern** is a **structural design pattern** that separates an abstraction from its implementation, allowing them to evolve independently. It achieves this by introducing an interface as a bridge between high-level abstractions and low-level implementations. 

This pattern is especially useful when a class hierarchy grows too large due to multiple variations of abstractions and implementations. By decoupling the abstraction from its implementation, the pattern promotes flexibility, scalability, and maintainability.

---

## **Key Characteristics**

1. **Decoupling**:
   - Separates the abstraction (high-level) from the implementation (low-level).
   - Reduces dependency between components, improving modularity.

2. **Bridge Interface**:
   - Acts as a communication layer between abstractions and implementations.

3. **Independent Evolution**:
   - Abstractions and implementations can be extended or modified independently.

4. **Composition Over Inheritance**:
   - Uses composition to share implementations rather than inheritance, avoiding an explosion of subclasses.

---

## **UML Diagram**

The UML diagram below illustrates the Bridge Pattern, showing how an abstraction uses a bridge to communicate with an implementation.

![UML Diagram](bridge.png)

- **Abstraction**: Defines the high-level control logic.
- **Refined Abstraction**: Extends the `Abstraction` to add specific behaviors.
- **Implementor**: Provides an interface for low-level operations.
- **Concrete Implementor**: Implements the operations defined by the `Implementor`.

---

## **Implementation Walkthrough**

### **Participants**

1. **Abstraction**:
   - Defines the high-level interface for the client to use.
   - Contains a reference to the `Implementor` interface.

2. **Refined Abstraction**:
   - Extends `Abstraction` to add additional functionality or logic.

3. **Implementor**:
   - Defines the low-level interface for concrete implementations.

4. **Concrete Implementor**:
   - Implements the operations defined in the `Implementor` interface.

---

### **Example: Device Remote Control**

Imagine you are building a remote control system for devices such as TVs and radios. Each device (TV, radio) has its specific implementation, but the remote control abstraction remains consistent across all devices.

#### **Abstraction: RemoteControl**
```java
/**
 * @brief High-level abstraction for remote controls.
 */
public abstract class RemoteControl {
    protected Device device;

    public RemoteControl(Device device) {
        this.device = device;
    }

    public abstract void togglePower();
    public abstract void volumeUp();
    public abstract void volumeDown();
}
```

#### **Refined Abstraction: AdvancedRemoteControl**
```java
/**
 * @brief A refined abstraction adding advanced functionalities.
 */
public class AdvancedRemoteControl extends RemoteControl {

    public AdvancedRemoteControl(Device device) {
        super(device);
    }

    public void mute() {
        device.setVolume(0);
        System.out.println("Device muted.");
    }

    @Override
    public void togglePower() {
        device.setPower(!device.getPower());
        System.out.println("Power toggled.");
    }

    @Override
    public void volumeUp() {
        device.setVolume(device.getVolume() + 1);
        System.out.println("Volume increased.");
    }

    @Override
    public void volumeDown() {
        device.setVolume(device.getVolume() - 1);
        System.out.println("Volume decreased.");
    }
}
```

#### **Implementor: Device**
```java
/**
 * @brief Interface for device operations.
 */
public interface Device {
    boolean getPower();
    void setPower(boolean power);
    int getVolume();
    void setVolume(int volume);
}
```

#### **Concrete Implementors**
```java
/**
 * @brief Concrete implementation for a TV.
 */
public class Television implements Device {
    private boolean power;
    private int volume;

    @Override
    public boolean getPower() {
        return power;
    }

    @Override
    public void setPower(boolean power) {
        this.power = power;
    }

    @Override
    public int getVolume() {
        return volume;
    }

    @Override
    public void setVolume(int volume) {
        this.volume = volume;
    }
}

/**
 * @brief Concrete implementation for a Radio.
 */
public class Radio implements Device {
    private boolean power;
    private int volume;

    @Override
    public boolean getPower() {
        return power;
    }

    @Override
    public void setPower(boolean power) {
        this.power = power;
    }

    @Override
    public int getVolume() {
        return volume;
    }

    @Override
    public void setVolume(int volume) {
        this.volume = volume;
    }
}
```

#### **Client Code**
```java
public class BridgePatternDemo {
    public static void main(String[] args) {
        Device tv = new Television();
        Device radio = new Radio();

        RemoteControl basicRemote = new AdvancedRemoteControl(tv);
        basicRemote.togglePower();
        basicRemote.volumeUp();
        ((AdvancedRemoteControl) basicRemote).mute();

        RemoteControl advancedRemote = new AdvancedRemoteControl(radio);
        advancedRemote.togglePower();
        advancedRemote.volumeDown();
    }
}
```

---

## **Applications**

### **When to Use the Bridge Pattern**
1. When you need to decouple an abstraction from its implementation.
2. When both abstractions and implementations are likely to change independently.
3. When you want to avoid a large class hierarchy caused by combining multiple dimensions of variations.

### **Common Use Cases**
1. **UI Frameworks**:
   - Decoupling platform-specific rendering from high-level UI components.
2. **File Management**:
   - Abstracting file handling logic (e.g., CSV, JSON) from storage backends (e.g., local, cloud).
3. **Device Management**:
   - Managing different devices (e.g., printers, scanners) with consistent abstractions.

---

## **Advantages and Disadvantages**

### **Advantages**
1. **Flexibility**:
   - Abstractions and implementations can vary independently.
2. **Modularity**:
   - Simplifies the codebase by separating responsibilities.
3. **Scalability**:
   - Makes it easy to add new abstractions or implementations without affecting existing code.
4. **Reduces Class Explosion**:
   - Avoids subclass combinations by replacing inheritance with composition.

### **Disadvantages**
1. **Complexity**:
   - Introduces additional layers, making the design more complex.
2. **Overhead**:
   - May add extra indirection, impacting performance in some scenarios.

---

## **Key Takeaways**

- The **Bridge Pattern** is a powerful structural design pattern for decoupling abstraction and implementation.
- It promotes scalability, flexibility, and maintainability by allowing independent extensions of both dimensions.
- While it introduces complexity, its advantages in modularity and scalability outweigh the trade-offs in most scenarios.