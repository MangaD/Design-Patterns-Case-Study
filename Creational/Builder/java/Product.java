/**
 * @brief Represents the complex product being built.
 *
 * The Product class includes parts `partA` and `partB`, representing
 * different components of the product. It provides methods to set these
 * parts and to retrieve a string representation of the constructed product.
 */
public class Product {
	private String partA; // Represents Part A of the product
	private String partB; // Represents Part B of the product

	/**
	 * @brief Sets Part A of the product.
	 * @param partA A string representing Part A.
	 */
	public void setPartA(String partA) {
		this.partA = partA;
	}

	/**
	 * @brief Sets Part B of the product.
	 * @param partB A string representing Part B.
	 */
	public void setPartB(String partB) {
		this.partB = partB;
	}

	/**
	 * @brief Provides a string representation of the product.
	 * @return A string describing the product's parts.
	 */
	@Override
	public String toString() {
		return "Product [PartA: " + partA + ", PartB: " + partB + "]";
	}
}
