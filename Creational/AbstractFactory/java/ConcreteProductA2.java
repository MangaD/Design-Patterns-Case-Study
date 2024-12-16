package Creational.AbstractFactory;

/**
 * Concrete implementation of ProductA for Family 2.
 */
public class ConcreteProductA2 implements ProductA {

	/**
	 * Default constructor for ConcreteProductA2.
	 */
	public ConcreteProductA2() {
		// Default constructor
	}

	/**
	 * Implementation of ProductA's operation for Family 2.
	 * @return A string identifying the operation performed by ConcreteProductA2.
	 */
	@Override
	public String operationA() {
		return "ConcreteProductA2";
	}
}
