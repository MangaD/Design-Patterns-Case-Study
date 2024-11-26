/**
 * @brief Concrete implementation of the Product interface.
 * 
 * ConcreteProductB represents a specific type of product that implements
 * the behavior defined in the Product interface. It provides a unique
 * implementation for the `use` method.
 */
public class ConcreteProductB implements Product {
	/**
	 * @brief Implements the behavior for ConcreteProductB.
	 * 
	 * This method returns a string that describes the behavior of
	 * ConcreteProductB when used.
	 * 
	 * @return A string indicating the specific behavior of ConcreteProductB.
	 */
	@Override
	public String use() {
		return "Using ConcreteProductB";
	}
}
