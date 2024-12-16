package Structural.Facade;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

/**
 * Tests the Facade pattern to ensure the interface simplifies interaction with subsystems.
 */
public class FacadeTest {

	/**
	 * Tests the Facade's ability to simplify subsystem interactions.
	 */
	@Test
	public void testFacadeOperation() {
		// Create the Facade instance
		Facade facade = new Facade();

		// Execute the Facade operation
		String result = facade.operation();

		// Expected output
		String expected =
				"Facade: Coordinating subsystems:\n" +
				"Subsystem1: Operation 1\n" +
				"Subsystem2: Operation 2\n" +
				"Subsystem3: Operation 3\n";

		// Verify the result
		assertEquals(expected, result);
	}
}
