package Structural.Bridge;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit tests for the Bridge Pattern implementation.
 */
public class BridgePatternTest {

	@Test
	void testRefinedAbstractionWithConcreteImplementorA() {
		// Arrange
		Implementor implementor = new ConcreteImplementorA();
		Abstraction abstraction = new RefinedAbstraction(implementor);

		// Act and Assert
		assertDoesNotThrow(() -> abstraction.operation());
	}

	@Test
	void testRefinedAbstractionWithConcreteImplementorB() {
		// Arrange
		Implementor implementor = new ConcreteImplementorB();
		Abstraction abstraction = new RefinedAbstraction(implementor);

		// Act and Assert
		assertDoesNotThrow(() -> abstraction.operation());
	}

	@Test
	void testDifferentImplementations() {
		// Arrange
		Abstraction abstractionA = new RefinedAbstraction(new ConcreteImplementorA());
		Abstraction abstractionB = new RefinedAbstraction(new ConcreteImplementorB());

		// Act and Assert
		assertDoesNotThrow(() -> abstractionA.operation());
		assertDoesNotThrow(() -> abstractionB.operation());
	}
}
