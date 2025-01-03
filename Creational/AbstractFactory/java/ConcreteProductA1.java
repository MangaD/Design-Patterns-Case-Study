package Creational.AbstractFactory;

/**
 * Concrete implementation of ProductA for Family 1.
 */
public class ConcreteProductA1 implements ProductA {

	/**
	 * Default constructor for ConcreteProductA1.
	 */
	public ConcreteProductA1() {
		// Default constructor
	}

	/**
	 * Implementation of ProductA's operation for Family 1.
	 * @return A string identifying the operation performed by ConcreteProductA1.
	 */
	@Override
	public String operationA() {
		return "ConcreteProductA1";
	}
}
