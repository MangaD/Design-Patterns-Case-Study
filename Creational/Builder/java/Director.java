/**
 * @brief Orchestrates the construction process.
 *
 * The Director class uses a Builder to construct a Product in a predefined sequence.
 */
public class Director {
	private Builder builder;

	/**
	 * @brief Constructs a Director with the given builder.
	 * @param builder The Builder instance to use for constructing the product.
	 */
	public Director(Builder builder) {
		this.builder = builder;
	}

	/**
	 * @brief Constructs the product by invoking the builder's methods in sequence.
	 */
	public void construct() {
		builder.buildPartA();
		builder.buildPartB();
	}

	/**
	 * @brief Retrieves the constructed product from the builder.
	 * @return The constructed Product instance.
	 */
	public Product getProduct() {
		return builder.getResult();
	}
}
