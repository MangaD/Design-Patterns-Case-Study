package Creational.AbstractFactory;

/**
 * Concrete Factory 1.
 * 
 * Creates products belonging to Family 1.
 */
public class ConcreteFactory1 implements AbstractFactory {

	/**
	 * Default constructor for ConcreteFactory1.
	 */
	public ConcreteFactory1() {
		// Default constructor
	}

	/**
	 * Creates a ConcreteProductA1 instance.
	 * @return A ConcreteProductA1 instance.
	 */
	@Override
	public ProductA createProductA() {
		return new ConcreteProductA1();
	}

	/**
	 * Creates a ConcreteProductB1 instance.
	 * @return A ConcreteProductB1 instance.
	 */
	@Override
	public ProductB createProductB() {
		return new ConcreteProductB1();
	}
}
