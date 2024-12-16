package Creational.FactoryMethod;

/**
 * Concrete implementation of the Creator class.
 * 
 * ConcreteCreatorB is responsible for creating instances of ConcreteProductB.
 * It overrides the factory method (`createProduct`) to instantiate and return
 * the specific product type (ConcreteProductB).
 */
public class ConcreteCreatorB extends Creator {

	/**
	 * Default constructor for ConcreteCreatorB.
	 */
	public ConcreteCreatorB() {
		// Default constructor
	}

	/**
	 * Factory method implementation for creating ConcreteProductB.
	 * 
	 * This method overrides the abstract factory method in the Creator class
	 * to provide a specific implementation that returns an instance of 
	 * ConcreteProductB.
	 * 
	 * @return A new instance of ConcreteProductB.
	 */
	@Override
	public Product createProduct() {
		return new ConcreteProductB();
	}
}
