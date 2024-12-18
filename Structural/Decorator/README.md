# Decorator Pattern

## Category
Structural Design Pattern

---

## Overview

The **Decorator Pattern** is a structural design pattern that allows behavior to be added to individual objects, dynamically and transparently, without affecting the behavior of other objects from the same class. 

This pattern is often used when the extension of functionality via inheritance is impractical or leads to an explosion of subclasses. Instead, decorators provide a flexible and reusable alternative to subclassing for extending functionality.

---

## Key Characteristics

1. **Dynamic Behavior Extension**:
   - Allows adding new behavior to an object at runtime.

2. **Open-Closed Principle**:
   - Adheres to the principle by enabling extensions without modifying existing code.

3. **Transparent to the Client**:
   - The decorator and the object being decorated share the same interface, making the decoration process seamless to the client.

4. **Composition over Inheritance**:
   - Uses composition to add behavior instead of relying on deep inheritance hierarchies.

---

## UML Diagram

The UML diagram below illustrates the Decorator Pattern. It shows how the decorator adds behavior to the component dynamically while maintaining the component interface.

![UML Diagram](http://www.plantuml.com/plantuml/proxy?src=https://raw.githubusercontent.com/MangaD/Design-Patterns-Case-Study/refs/heads/main/Structural/Decorator/decorator.puml)

---

## Implementation Walkthrough

### Participants

1. **Component**:
   - Defines the common interface for both concrete components and decorators.

2. **Concrete Component**:
   - The base implementation of the component interface to which additional behavior is added.

3. **Decorator**:
   - An abstract class that implements the component interface and contains a reference to a component.

4. **Concrete Decorators**:
   - Extend the functionality of the component by overriding methods and adding new behavior.

---

### Example: Coffee Shop

Imagine a coffee shop system where customers can order a base coffee and optionally add extra ingredients like milk, sugar, or whipped cream. The Decorator Pattern can help manage these customizations dynamically.

#### Component
```java
/**
 * @brief Component interface for a coffee beverage.
 */
public interface Beverage {
    String getDescription();
    double cost();
}
```

---

#### Concrete Component
```java
/**
 * @brief A basic coffee implementation of the Beverage interface.
 */
public class BasicCoffee implements Beverage {
    @Override
    public String getDescription() {
        return "Basic Coffee";
    }

    @Override
    public double cost() {
        return 2.00;
    }
}
```

---

#### Abstract Decorator
```java
/**
 * @brief Abstract decorator class that wraps a Beverage.
 */
public abstract class BeverageDecorator implements Beverage {
    protected Beverage beverage;

    public BeverageDecorator(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription();
    }

    @Override
    public double cost() {
        return beverage.cost();
    }
}
```

---

#### Concrete Decorators
```java
/**
 * @brief Concrete decorator for adding milk to a coffee.
 */
public class MilkDecorator extends BeverageDecorator {
    public MilkDecorator(Beverage beverage) {
        super(beverage);
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Milk";
    }

    @Override
    public double cost() {
        return beverage.cost() + 0.50;
    }
}

/**
 * @brief Concrete decorator for adding sugar to a coffee.
 */
public class SugarDecorator extends BeverageDecorator {
    public SugarDecorator(Beverage beverage) {
        super(beverage);
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Sugar";
    }

    @Override
    public double cost() {
        return beverage.cost() + 0.20;
    }
}
```

---

#### Client Code
```java
/**
 * @brief Client demonstrating the Decorator Pattern.
 */
public class CoffeeShop {
    public static void main(String[] args) {
        // Create a basic coffee
        Beverage coffee = new BasicCoffee();
        System.out.println(coffee.getDescription() + " $" + coffee.cost());

        // Add milk to the coffee
        coffee = new MilkDecorator(coffee);
        System.out.println(coffee.getDescription() + " $" + coffee.cost());

        // Add sugar to the coffee
        coffee = new SugarDecorator(coffee);
        System.out.println(coffee.getDescription() + " $" + coffee.cost());
    }
}
```

---

### Output
```
Basic Coffee $2.0
Basic Coffee, Milk $2.5
Basic Coffee, Milk, Sugar $2.7
```

---

## Applications

### When to Use the Decorator Pattern
1. **Dynamic Behavior Addition**:
   - When additional responsibilities need to be added to an object dynamically.
2. **Avoid Subclass Explosion**:
   - When using inheritance to add behavior leads to an unmanageable number of subclasses.
3. **Multiple Independent Extensions**:
   - When multiple extensions or modifications may need to be applied independently or in combination.

### Common Use Cases
1. **UI Frameworks**:
   - Adding scrollbars, borders, or shadows to UI components.
2. **Logging and Monitoring**:
   - Dynamically adding logging, monitoring, or validation behavior to objects.
3. **Data Streams**:
   - Wrapping data streams with additional processing layers (e.g., compression, encryption).
4. **Game Development**:
   - Dynamically modifying character abilities or item effects.

---

## Advantages and Disadvantages

### Advantages
1. **Dynamic Flexibility**:
   - Adds behavior dynamically at runtime.
2. **Open-Closed Principle**:
   - Extends functionality without modifying existing code.
3. **Composition over Inheritance**:
   - Avoids deep inheritance hierarchies.

### Disadvantages
1. **Complexity**:
   - Increases the number of objects and introduces a layering structure.
2. **Order-Dependent Behavior**:
   - The order in which decorators are applied can affect the final behavior.
3. **Debugging Challenges**:
   - Debugging can become complex due to multiple layers of decorators.

---

## Key Takeaways

The **Decorator Pattern** provides a flexible and reusable way to extend object behavior without resorting to inheritance. By wrapping objects with decorators, you can dynamically add or modify functionality while keeping the system modular and adhering to the Open-Closed Principle. However, careful management is required to avoid excessive complexity and unintended behavior due to layering.