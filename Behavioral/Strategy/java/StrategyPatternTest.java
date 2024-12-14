import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Strategy Pattern implementation.
 */
public class StrategyPatternTest {

	/**
	 * Test setting and executing ConcreteStrategyA.
	 */
	@Test
	public void testConcreteStrategyA() {
		Context context = new Context();
		context.setStrategy(new ConcreteStrategyA());

		String result = context.executeStrategy();
		assertEquals("Executing strategy A.", result, "ConcreteStrategyA should execute correctly.");
	}

	/**
	 * Test setting and executing ConcreteStrategyB.
	 */
	@Test
	public void testConcreteStrategyB() {
		Context context = new Context();
		context.setStrategy(new ConcreteStrategyB());

		String result = context.executeStrategy();
		assertEquals("Executing strategy B.", result, "ConcreteStrategyB should execute correctly.");
	}

	/**
	 * Test handling the case where no strategy is set.
	 */
	@Test
	public void testNoStrategySet() {
		Context context = new Context();

		Exception exception = assertThrows(IllegalStateException.class, context::executeStrategy);
		assertEquals("No strategy set!", exception.getMessage(), "Context should throw if no strategy is set.");
	}
}
