package behavioral.template_method;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/**
 * @brief Unit tests for the Template Method Pattern implementation.
 */
public class TemplateMethodTest {

	/**
	 * @brief Captures the standard output for validation.
	 */
	private String captureOutput(Runnable action) {
		ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		PrintStream originalOut = System.out;
		System.setOut(new PrintStream(outputStream));
		try {
			action.run();
		} finally {
			System.setOut(originalOut);
		}
		return outputStream.toString();
	}

	@Test
	public void testConcreteClass1Behavior() {
		AbstractClass concrete1 = new ConcreteClass1();
		String output = captureOutput(concrete1::templateMethod);

		String expected = "AbstractClass: Base operation 1\n" +
			"ConcreteClass1: Required operation 1\n" +
			"AbstractClass: Base operation 2\n" +
			"ConcreteClass1: Required operation 2\n" +
			"ConcreteClass1: Overridden hook implementation\n";

		assertEquals(expected, output, "ConcreteClass1 should follow the correct algorithm and include its specific steps.");
	}

	@Test
	public void testConcreteClass2Behavior() {
		AbstractClass concrete2 = new ConcreteClass2();
		String output = captureOutput(concrete2::templateMethod);

		String expected = "AbstractClass: Base operation 1\n" +
			"ConcreteClass2: Required operation 1\n" +
			"AbstractClass: Base operation 2\n" +
			"ConcreteClass2: Required operation 2\n" +
			"AbstractClass: Default hook implementation\n";

		assertEquals(expected, output, "ConcreteClass2 should follow the correct algorithm and use the default hook.");
	}

	@Test
	public void testHookFlexibility() {
		AbstractClass concrete1 = new ConcreteClass1();
		AbstractClass concrete2 = new ConcreteClass2();

		String output1 = captureOutput(concrete1::templateMethod);
		String output2 = captureOutput(concrete2::templateMethod);

		assertTrue(output1.contains("ConcreteClass1: Overridden hook implementation"),
			"ConcreteClass1 should override the hook.");
		assertTrue(output2.contains("AbstractClass: Default hook implementation"),
			"ConcreteClass2 should use the default hook implementation.");
	}
}
