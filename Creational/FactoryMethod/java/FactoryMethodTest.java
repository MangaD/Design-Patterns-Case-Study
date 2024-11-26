import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class FactoryMethodTest {
	@Test
	void testConcreteProductA() {
		Creator creatorA = new ConcreteCreatorA();
		Product productA = creatorA.createProduct();
		assertEquals("Using ConcreteProductA", productA.use());
	}

	@Test
	void testConcreteProductB() {
		Creator creatorB = new ConcreteCreatorB();
		Product productB = creatorB.createProduct();
		assertEquals("Using ConcreteProductB", productB.use());
	}
}
