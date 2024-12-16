package Structural.Decorator;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit tests for the Decorator Pattern.
 */
public class DecoratorPatternTest {

	@Test
	public void testConcreteComponent() {
		Component component = new ConcreteComponent();
		assertEquals("Concrete Component", component.getDescription());
		assertEquals(10.0, component.cost());
	}

	@Test
	public void testConcreteDecoratorA() {
		Component component = new ConcreteComponent();
		Component decoratorA = new ConcreteDecoratorA(component);

		assertEquals("Concrete Component + Feature A", decoratorA.getDescription());
		assertEquals(15.0, decoratorA.cost());
	}

	@Test
	public void testConcreteDecoratorB() {
		Component component = new ConcreteComponent();
		Component decoratorB = new ConcreteDecoratorB(component);

		assertEquals("Concrete Component + Feature B", decoratorB.getDescription());
		assertEquals(17.5, decoratorB.cost());
	}

	@Test
	public void testMultipleDecorators() {
		Component component = new ConcreteComponent();
		Component decoratorA = new ConcreteDecoratorA(component);
		Component decoratorB = new ConcreteDecoratorB(decoratorA);

		assertEquals("Concrete Component + Feature A + Feature B", decoratorB.getDescription());
		assertEquals(22.5, decoratorB.cost());
	}
}
