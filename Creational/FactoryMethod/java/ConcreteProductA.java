package Creational.FactoryMethod;

/**
 * Concrete implementation of the Product interface.
 * 
 * ConcreteProductA represents a specific type of product that implements
 * the behavior defined in the Product interface. It provides a unique
 * implementation for the `use` method.
 */
public class ConcreteProductA implements Product {

	/**
	 * Default constructor for ConcreteProductA.
	 */
	public ConcreteProductA() {
		// Default constructor
	}

	/**
	 * Implements the behavior for ConcreteProductA.
	 * 
	 * This method returns a string that describes the behavior of
	 * ConcreteProductA when used.
	 * 
	 * @return A string indicating the specific behavior of ConcreteProductA.
	 */
	@Override
	public String use() {
		return "Using ConcreteProductA";
	}
}
