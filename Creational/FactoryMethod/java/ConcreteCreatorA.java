package Creational.FactoryMethod;

/**
 * Concrete implementation of the Creator class.
 * 
 * ConcreteCreatorA is responsible for creating instances of ConcreteProductA.
 * It overrides the factory method (`createProduct`) to instantiate and return
 * the specific product type (ConcreteProductA).
 */
public class ConcreteCreatorA extends Creator {

	/**
	 * Default constructor for ConcreteCreatorA.
	 */
	public ConcreteCreatorA() {
		// Default constructor
	}

	/**
	 * Factory method implementation for creating ConcreteProductA.
	 * 
	 * This method overrides the abstract factory method in the Creator class
	 * to provide a specific implementation that returns an instance of 
	 * ConcreteProductA.
	 * 
	 * @return A new instance of ConcreteProductA.
	 */
	@Override
	public Product createProduct() {
		return new ConcreteProductA();
	}
}
