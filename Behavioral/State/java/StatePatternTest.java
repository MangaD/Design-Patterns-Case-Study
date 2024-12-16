package Behavioral.State;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit tests for the State pattern implementation.
 */
public class StatePatternTest {

	@Test
	void testInitialState() {
		Context context = new Context(new ConcreteStateA());
		assertEquals("ConcreteStateA", context.getStateName());
	}

	@Test
	void testStateTransitionAtoB() {
		Context context = new Context(new ConcreteStateA());

		context.request(); // Transition to State B

		assertEquals("ConcreteStateB", context.getStateName());
	}

	@Test
	void testStateTransitionBtoA() {
		Context context = new Context(new ConcreteStateB());

		context.request(); // Transition to State A

		assertEquals("ConcreteStateA", context.getStateName());
	}

	@Test
	void testMultipleTransitions() {
		Context context = new Context(new ConcreteStateA());

		context.request(); // A -> B
		assertEquals("ConcreteStateB", context.getStateName());

		context.request(); // B -> A
		assertEquals("ConcreteStateA", context.getStateName());

		context.request(); // A -> B again
		assertEquals("ConcreteStateB", context.getStateName());
	}

	@Test
	void testNoInitialState() {
		Context context = new Context(null);

		assertEquals("No State", context.getStateName());
		context.request(); // Should not throw an exception
	}
}
