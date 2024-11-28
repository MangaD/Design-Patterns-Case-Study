import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Builder Pattern implementation.
 */
public class BuilderPatternTest {

	/**
	 * @brief Test full product construction using ConcreteBuilder and Director.
	 *
	 * Verifies that the Director correctly orchestrates the ConcreteBuilder
	 * to construct a complete Product with all parts built.
	 */
	@Test
	public void testFullProductConstruction() {
		Builder builder = new ConcreteBuilder();
		Director director = new Director(builder);

		// Construct the product
		director.construct();
		Product product = director.getProduct();

		// Verify the constructed product
		assertEquals("Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]",
		             product.toString());
	}

	/**
	 * @brief Test partial product construction directly through the ConcreteBuilder.
	 *
	 * Verifies that the ConcreteBuilder can construct a product incrementally
	 * without the involvement of the Director.
	 */
	@Test
	public void testPartialProductConstruction() {
		Builder builder = new ConcreteBuilder();

		// Build Part A only
		builder.buildPartA();
		Product product = builder.getResult();

		// Verify that only Part A is built
		assertEquals("Product [PartA: Part A built by ConcreteBuilder, PartB: null]",
		             product.toString());
	}

	/**
	 * @brief Test reusing a ConcreteBuilder for multiple products.
	 *
	 * Verifies that the ConcreteBuilder can be reused to construct multiple products
	 * by resetting its internal state.
	 */
	@Test
	public void testBuilderReuse() {
		ConcreteBuilder builder = new ConcreteBuilder();
		Director director = new Director(builder);

		// First product
		director.construct();
		Product product1 = director.getProduct();

		// Verify the first product
		assertEquals("Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]",
		             product1.toString());

		// Reuse the builder for a new product
		builder = new ConcreteBuilder();
		director = new Director(builder);
		director.construct();
		Product product2 = director.getProduct();

		// Verify the second product
		assertEquals("Product [PartA: Part A built by ConcreteBuilder, PartB: Part B built by ConcreteBuilder]",
		             product2.toString());
	}
}
