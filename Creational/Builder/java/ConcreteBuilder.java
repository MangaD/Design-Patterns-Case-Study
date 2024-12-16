package Creational.Builder;

/**
 * Concrete implementation of the Builder interface.
 *
 * Constructs a specific type of product by implementing the building steps
 * defined in the Builder interface.
 */
public class ConcreteBuilder implements Builder {
	private Product product;

	/**
	 * Constructor initializes a new Product instance.
	 */
	public ConcreteBuilder() {
		this.product = new Product();
	}

	/**
	 * Builds Part A of the product.
	 *
	 * Sets Part A to a specific value defined by this builder.
	 */
	@Override
	public void buildPartA() {
		product.setPartA("Part A built by ConcreteBuilder");
	}

	/**
	 * Builds Part B of the product.
	 *
	 * Sets Part B to a specific value defined by this builder.
	 */
	@Override
	public void buildPartB() {
		product.setPartB("Part B built by ConcreteBuilder");
	}

	/**
	 * Retrieves the constructed product.
	 * @return The fully constructed Product instance.
	 */
	@Override
	public Product getResult() {
		return this.product;
	}
}
