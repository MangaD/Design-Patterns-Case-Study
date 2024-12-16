package Creational.AbstractFactory;

/**
 * Concrete implementation of ProductB for Family 1.
 */
public class ConcreteProductB1 implements ProductB {

	/**
	 * Default constructor for ConcreteProductB1.
	 */
	public ConcreteProductB1() {
		// Default constructor
	}

	/**
	 * Implementation of ProductB's operation for Family 1.
	 * @return A string identifying the operation performed by ConcreteProductB1.
	 */
	@Override
	public String operationB() {
		return "ConcreteProductB1";
	}
}
