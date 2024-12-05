import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Flyweight Pattern.
 */
public class FlyweightTest {

	@Test
	/**
	 * @brief Test FlyweightFactory ensures shared Flyweights for identical intrinsic states.
	 */
	public void testFlyweightFactoryReusesFlyweights() {
		FlyweightFactory factory = new FlyweightFactory();

		// Retrieve Flyweights with the same intrinsic state
		Flyweight flyweight1 = factory.getFlyweight("SharedState");
		Flyweight flyweight2 = factory.getFlyweight("SharedState");

		// Verify that the same Flyweight instance is reused
		assertSame(flyweight1, flyweight2, "Flyweight instances should be reused for the same intrinsic state.");
	}

	@Test
	/**
	 * @brief Test Flyweight operation with extrinsic state.
	 */
	public void testFlyweightOperation() {
		FlyweightFactory factory = new FlyweightFactory();

		// Retrieve a Flyweight
		Flyweight flyweight = factory.getFlyweight("State");

		// Capture console output for verification
		java.io.ByteArrayOutputStream outContent = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outContent));

		// Perform operation with extrinsic state
		flyweight.operation("ExtrinsicState");

		// Verify the output
		String expectedOutput = "ConcreteFlyweight: Intrinsic state = State, Extrinsic state = ExtrinsicState\n";
		assertEquals(expectedOutput, outContent.toString(), "Flyweight operation should correctly display intrinsic and extrinsic states.");

		// Restore standard output
		System.setOut(System.out);
	}

	@Test
	/**
	 * @brief Test FlyweightFactory stores and lists Flyweights correctly.
	 */
	public void testFlyweightFactoryList() {
		FlyweightFactory factory = new FlyweightFactory();

		// Add multiple Flyweights
		factory.getFlyweight("State1");
		factory.getFlyweight("State2");
		factory.getFlyweight("State1"); // Reuses existing Flyweight

		// Capture console output for verification
		java.io.ByteArrayOutputStream outContent = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outContent));

		// List Flyweights
		factory.listFlyweights();

		// Verify the output
		String expectedOutput = """
			Flyweights in Factory:
			 - State1
			 - State2
			""";
		assertEquals(expectedOutput.strip(), outContent.toString().strip(), "FlyweightFactory should list all stored Flyweights.");

		// Restore standard output
		System.setOut(System.out);
	}
}
