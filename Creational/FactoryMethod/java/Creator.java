package Creational.FactoryMethod;

/**
 * Abstract Creator class in the Factory Method design pattern.
 * 
 * The Creator class declares the factory method `createProduct`, which
 * must be implemented by concrete subclasses to create specific types of
 * products. It also provides a common operation `someOperation` that
 * utilizes the product created by the factory method.
 */
public abstract class Creator {

	/**
	 * Default constructor for Creator.
	 */
	public Creator() {
		// Default constructor
	}

	/**
	 * Factory method to create a product.
	 * 
	 * This method is abstract and must be overridden by subclasses to
	 * specify the type of product to be created. The factory method
	 * promotes flexibility by delegating the creation logic to concrete
	 * creators.
	 * 
	 * @return A product created by the factory method.
	 */
	public abstract Product createProduct();

	/**
	 * A common operation that demonstrates the use of the product.
	 * 
	 * This method creates a product using the factory method and performs
	 * an operation on it. This demonstrates the separation of product
	 * creation (handled by `createProduct`) from the logic that uses the
	 * product (handled here).
	 */
	public void someOperation() {
		Product product = createProduct();
		System.out.println(product.use());
	}
}
