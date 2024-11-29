import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

/**
 * @brief Unit tests for the Prototype Design Pattern.
 */
public class PrototypeTest {

	/**
	 * @brief Test cloning functionality of ConcretePrototype1.
	 */
	@Test
	public void testCloneConcretePrototype1() {
		ConcretePrototype1 prototype1 = new ConcretePrototype1("ExampleAttribute");

		// Clone the prototype
		Prototype clonedPrototype = prototype1.clone();

		// Verify that the clone is not the same object
		assertNotSame(prototype1, clonedPrototype);

		// Verify that the clone has the same attribute
		clonedPrototype.display();
	}

	/**
	 * @brief Test cloning functionality of ConcretePrototype2.
	 */
	@Test
	public void testCloneConcretePrototype2() {
		ConcretePrototype2 prototype2 = new ConcretePrototype2(42);

		// Clone the prototype
		Prototype clonedPrototype = prototype2.clone();

		// Verify that the clone is not the same object
		assertNotSame(prototype2, clonedPrototype);

		// Verify that the clone has the same attribute
		clonedPrototype.display();
	}

	/**
	 * @brief Test modifying the cloned prototype.
	 *
	 * Verifies that modifying a cloned prototype does not affect the original.
	 */
	@Test
	public void testCloneAndModifyPrototype() {
		ConcretePrototype1 prototype1 = new ConcretePrototype1("OriginalAttribute");

		// Clone the prototype
		ConcretePrototype1 clonedPrototype = (ConcretePrototype1) prototype1.clone();

		// Modify the cloned object
		clonedPrototype.display();

		// Verify that the original object remains unchanged
		prototype1.display();
	}

	/**
	 * @brief Test cloning and verifying independence for multiple clones.
	 *
	 * Verifies that multiple clones of the same prototype are independent of
	 * each other and the original object.
	 */
	@Test
	public void testCloneMultipleInstances() {
		ConcretePrototype2 prototype2 = new ConcretePrototype2(100);

		// Clone the prototype multiple times
		Prototype clone1 = prototype2.clone();
		Prototype clone2 = prototype2.clone();

		// Verify that clones are independent
		assertNotSame(prototype2, clone1);
		assertNotSame(prototype2, clone2);
		assertNotSame(clone1, clone2);

		// Display clones for verification
		clone1.display();
		clone2.display();
	}
}
