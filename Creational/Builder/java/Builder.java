/**
 * @brief Abstract interface for constructing a Product.
 *
 * Defines the methods for building different parts of a product
 * and retrieving the final constructed result.
 */
public interface Builder {
	/**
	 * @brief Builds Part A of the product.
	 */
	void buildPartA();

	/**
	 * @brief Builds Part B of the product.
	 */
	void buildPartB();

	/**
	 * @brief Retrieves the constructed product.
	 * @return The constructed Product instance.
	 */
	Product getResult();
}
