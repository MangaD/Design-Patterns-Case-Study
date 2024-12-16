package Creational.AbstractFactory;

/**
 * Concrete implementation of ProductB for Family 2.
 */
public class ConcreteProductB2 implements ProductB {

	/**
	 * Default constructor for ConcreteProductB2.
	 */
	public ConcreteProductB2() {
		// Default constructor
	}

	/**
	 * Implementation of ProductB's operation for Family 2.
	 * @return A string identifying the operation performed by ConcreteProductB2.
	 */
	@Override
	public String operationB() {
		return "ConcreteProductB2";
	}
}
