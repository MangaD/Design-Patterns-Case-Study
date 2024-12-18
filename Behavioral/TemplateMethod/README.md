# Template Method Pattern

## **Category**
Behavioral Design Pattern

---

## **Overview**

The **Template Method Pattern** defines the skeleton of an algorithm in a base class, allowing subclasses to override specific steps of the algorithm without changing its overall structure. This pattern promotes code reuse by enabling a common algorithm structure while permitting variations in specific parts of the algorithm.

This pattern is particularly useful when:
- A sequence of steps is fixed but certain steps need customization.
- You want to enforce a standard procedure while allowing flexibility for some steps.

---

## **Key Characteristics**

1. **Algorithm Skeleton**:
   - Defines the structure of an algorithm in a base class.
   - Allows customization of specific steps by subclasses.

2. **Hooks and Template Methods**:
   - **Template Method**: Provides the overall structure of the algorithm.
   - **Hooks**: Optional methods that allow subclasses to hook into the algorithm for additional customization.

3. **Encapsulation of Invariant Behavior**:
   - Common steps are implemented in the base class to avoid duplication and ensure consistency.

4. **Polymorphism**:
   - Subclasses override specific steps to implement their variant of the algorithm.

5. **Promotes the Hollywood Principle**:
   - The **Hollywood Principle** is summarized as: **"Don’t call us; we’ll call you."** It emphasizes **inversion of control**, where a higher-level component (e.g., a base class) orchestrates the flow of execution and **delegates specific behavior** to lower-level components (e.g., subclasses or concrete implementations). 

     In the **Template Method Pattern**, this principle is evident because:

     1. The **abstract class** defines the algorithm’s structure (the "call you" part).
     2. Subclasses **override specific steps** (the "don’t call us" part) required for the algorithm without dictating the overall process.
     3. The **base class controls the execution flow**, ensuring that the algorithm remains consistent while allowing flexibility in implementation details.
     
     This principle helps maintain a **clear separation of concerns** and ensures that higher-level components stay in control of the system's behavior.

---

## **UML Diagram**

The UML diagram below illustrates the Template Method Pattern, showing how the base class defines the algorithm structure and subclasses override specific steps:

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Behavioral/TemplateMethod/template_method.puml)

---

## **Implementation Walkthrough**

### **Participants**

1. **AbstractClass**:
   - Defines the skeleton of the algorithm using a **template method**.
   - Implements common steps of the algorithm and declares abstract or optional methods for customization.

2. **ConcreteClass**:
   - Implements the specific steps of the algorithm by overriding methods in the abstract class.

---

### **Example: Preparing a Beverage**

Imagine you are creating a system to prepare beverages. The overall process is the same (boil water, brew, pour, add condiments), but specific steps like brewing and adding condiments vary depending on the beverage.

#### Abstract Class: Beverage
```java
/**
 * @brief Abstract class that defines the template method for preparing a beverage.
 */
public abstract class Beverage {
    // Template Method
    public final void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

    private void boilWater() {
        System.out.println("Boiling water...");
    }

    private void pourInCup() {
        System.out.println("Pouring into cup...");
    }

    protected abstract void brew();
    protected abstract void addCondiments();

    // Hook method
    protected boolean customerWantsCondiments() {
        return true; // Default behavior; subclasses can override
    }
}
```

---

#### Concrete Class: Tea
```java
/**
 * @brief Concrete implementation of the Beverage for Tea.
 */
public class Tea extends Beverage {
    @Override
    protected void brew() {
        System.out.println("Steeping the tea...");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Adding lemon...");
    }
}
```

---

#### Concrete Class: Coffee
```java
/**
 * @brief Concrete implementation of the Beverage for Coffee.
 */
public class Coffee extends Beverage {
    @Override
    protected void brew() {
        System.out.println("Dripping coffee through filter...");
    }

    @Override
    protected void addCondiments() {
        System.out.println("Adding sugar and milk...");
    }

    @Override
    protected boolean customerWantsCondiments() {
        return false; // No condiments for coffee in this example
    }
}
```

---

#### Client Code
```java
/**
 * @brief Demonstrates the Template Method Pattern with different beverages.
 */
public class TemplateMethodDemo {
    public static void main(String[] args) {
        Beverage tea = new Tea();
        tea.prepareBeverage();

        Beverage coffee = new Coffee();
        coffee.prepareBeverage();
    }
}
```

---

### **Output**
```
Boiling water...
Steeping the tea...
Pouring into cup...
Adding lemon...

Boiling water...
Dripping coffee through filter...
Pouring into cup...
```

---

## **Applications**

### **When to Use the Template Method Pattern**
1. When multiple subclasses share a common algorithm structure but differ in specific steps.
2. When you want to enforce a standard procedure while allowing limited flexibility.
3. When avoiding code duplication for common steps is important.

### **Common Use Cases**
1. **Frameworks and Libraries**:
   - Frameworks often use template methods to provide a common structure while allowing application-specific customizations.
2. **Report Generation**:
   - Generating reports with a common layout but different data sources.
3. **Game Development**:
   - Defining a game loop with hooks for game-specific logic.

---

## **Advantages and Disadvantages**

### **Advantages**
1. **Code Reuse**:
   - Avoids duplication by implementing common steps in a base class.
2. **Flexibility**:
   - Allows variations in behavior by overriding specific steps.
3. **Consistency**:
   - Ensures that the algorithm follows a consistent structure across implementations.
4. **Encapsulation**:
   - Encapsulates invariant behavior in the base class.

### **Disadvantages**
1. **Increased Complexity**:
   - Requires careful design of abstract and hook methods.
2. **Limited Flexibility**:
   - Subclasses must conform to the predefined structure, reducing freedom.
3. **Inheritance Dependency**:
   - Relies on inheritance, which may lead to issues in complex hierarchies.

---

## **Comparison with Related Patterns**

1. **Strategy**:
   - **Strategy Pattern** focuses on replacing an entire algorithm dynamically, while the **Template Method Pattern** allows for customization of specific steps within a fixed algorithm.
2. **State**:
   - The **State Pattern** changes behavior based on an object's state, whereas the **Template Method Pattern** enforces a consistent algorithm structure with variations in specific steps.

---

## **Key Takeaways**

- The **Template Method Pattern** provides a powerful mechanism to define a fixed algorithm structure while enabling flexibility in specific steps.
- By encapsulating invariant behavior and promoting code reuse, it ensures consistency and maintainability across implementations.
- Careful design is required to balance the flexibility of hooks with the constraints of the algorithm skeleton.