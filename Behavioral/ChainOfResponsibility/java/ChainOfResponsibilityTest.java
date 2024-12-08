import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Test cases for the Chain of Responsibility Pattern.
 */
public class ChainOfResponsibilityTest {
	@Test
	public void testHandlesRequestsProperly() {
		// Create handlers
		Handler handlerA = new ConcreteHandlerA();
		Handler handlerB = new ConcreteHandlerB();

		// Chain the handlers
		handlerA.setNext(handlerB);

		// Capture output for testing
		java.io.ByteArrayOutputStream outContent = new java.io.ByteArrayOutputStream();
		System.setOut(new java.io.PrintStream(outContent));

		// Test requests
		handlerA.handleRequest("A");
		handlerA.handleRequest("B");
		handlerA.handleRequest("C");

		// Restore original System.out
		System.setOut(System.out);

		// Expected output
		String expectedOutput =
			"ConcreteHandlerA handled request: A\n" +
			"ConcreteHandlerA passing request: B\n" +
			"ConcreteHandlerB handled request: B\n" +
			"ConcreteHandlerA passing request: C\n" +
			"ConcreteHandlerB passing request: C\n";

		// Assert output matches expected
		assertEquals(expectedOutput, outContent.toString());
	}
}
