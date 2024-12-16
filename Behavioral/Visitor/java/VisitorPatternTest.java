import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/**
 * @brief Unit tests for the Visitor pattern implementation.
 */
public class VisitorPatternTest {

	@Test
	void testVisitorOperations() {
		// Redirect standard output for testing
		ByteArrayOutputStream output = new ByteArrayOutputStream();
		PrintStream originalOut = System.out;
		System.setOut(new PrintStream(output));

		// Create elements
		ElementA elementA = new ElementA();
		ElementB elementB = new ElementB();

		// Create visitors
		Visitor visitorA = new ConcreteVisitorA();
		Visitor visitorB = new ConcreteVisitorB();

		// Test ElementA with VisitorA
		elementA.accept(visitorA);

		// Test ElementB with VisitorA
		elementB.accept(visitorA);

		// Test ElementA with VisitorB
		elementA.accept(visitorB);

		// Test ElementB with VisitorB
		elementB.accept(visitorB);

		// Restore standard output
		System.setOut(originalOut);

		String expectedOutput =
			"ConcreteVisitorA: ElementA operation.\n" +
			"ConcreteVisitorA: ElementB operation.\n" +
			"ConcreteVisitorB: ElementA operation.\n" +
			"ConcreteVisitorB: ElementB operation.\n";

		assertEquals(expectedOutput, output.toString());
	}

	@Test
	void testObjectStructure() {
		// Redirect standard output for testing
		ByteArrayOutputStream output = new ByteArrayOutputStream();
		PrintStream originalOut = System.out;
		System.setOut(new PrintStream(output));

		// Create object structure
		ObjectStructure structure = new ObjectStructure();
		structure.addElement(new ElementA());
		structure.addElement(new ElementB());

		// Create a visitor
		Visitor visitorA = new ConcreteVisitorA();

		// Accept the visitor for the object structure
		structure.accept(visitorA);

		// Restore standard output
		System.setOut(originalOut);

		String expectedOutput =
			"ConcreteVisitorA: ElementA operation.\n" +
			"ConcreteVisitorA: ElementB operation.\n";

		assertEquals(expectedOutput, output.toString());
	}
}
