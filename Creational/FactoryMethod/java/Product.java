/**
 * @brief The Product interface defines a common interface for all products
 * that can be created by the factory method.
 * 
 * This interface enforces a contract that all concrete products must
 * implement the `use` method, which defines the behavior of the product.
 */
public interface Product {
	/**
	 * @brief Defines the behavior of the product.
	 * 
	 * Concrete products implement this method to provide their specific
	 * functionality or behavior.
	 * 
	 * @return A string describing the product's behavior.
	 */
	String use();
}
