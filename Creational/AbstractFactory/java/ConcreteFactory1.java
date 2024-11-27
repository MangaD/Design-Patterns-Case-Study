/**
 * @brief Concrete Factory 1.
 * 
 * Creates products belonging to Family 1.
 */
public class ConcreteFactory1 implements AbstractFactory {
	/**
	 * @brief Creates a ConcreteProductA1 instance.
	 * @return A ConcreteProductA1 instance.
	 */
	@Override
	public ProductA createProductA() {
		return new ConcreteProductA1();
	}

	/**
	 * @brief Creates a ConcreteProductB1 instance.
	 * @return A ConcreteProductB1 instance.
	 */
	@Override
	public ProductB createProductB() {
		return new ConcreteProductB1();
	}
}
