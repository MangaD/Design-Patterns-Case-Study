/**
 * @brief Concrete Factory 2.
 * 
 * Creates products belonging to Family 2.
 */
public class ConcreteFactory2 implements AbstractFactory {
	/**
	 * @brief Creates a ConcreteProductA2 instance.
	 * @return A ConcreteProductA2 instance.
	 */
	@Override
	public ProductA createProductA() {
		return new ConcreteProductA2();
	}

	/**
	 * @brief Creates a ConcreteProductB2 instance.
	 * @return A ConcreteProductB2 instance.
	 */
	@Override
	public ProductB createProductB() {
		return new ConcreteProductB2();
	}
}