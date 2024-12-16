package Creational.AbstractFactory;

import static org.junit.jupiter.api.Assertions.assertEquals;
import org.junit.jupiter.api.Test;

/**
 * Unit tests for the Abstract Factory Pattern implementation.
 * 
 * These tests verify the correct creation of products by different factories
 * and ensure compatibility between products of the same family.
 */
public class AbstractFactoryTest {

	/**
	 * Tests the functionality of ConcreteFactory1.
	 * 
	 * Verifies that ConcreteFactory1 creates ConcreteProductA1 and ConcreteProductB1.
	 */
	@Test
	public void testConcreteFactory1() {
		AbstractFactory factory = new ConcreteFactory1();

		ProductA productA = factory.createProductA();
		ProductB productB = factory.createProductB();

		assertEquals("ConcreteProductA1", productA.operationA());
		assertEquals("ConcreteProductB1", productB.operationB());
	}

	/**
	 * Tests the functionality of ConcreteFactory2.
	 * 
	 * Verifies that ConcreteFactory2 creates ConcreteProductA2 and ConcreteProductB2.
	 */
	@Test
	public void testConcreteFactory2() {
		AbstractFactory factory = new ConcreteFactory2();

		ProductA productA = factory.createProductA();
		ProductB productB = factory.createProductB();

		assertEquals("ConcreteProductA2", productA.operationA());
		assertEquals("ConcreteProductB2", productB.operationB());
	}

	/**
	 * Tests compatibility of products within the same factory.
	 * 
	 * Ensures that products created by the same factory are compatible within their family.
	 */
	@Test
	public void testCompatibilityWithinFactory() {
		// Factory 1 compatibility
		AbstractFactory factory1 = new ConcreteFactory1();
		ProductA productA1 = factory1.createProductA();
		ProductB productB1 = factory1.createProductB();

		assertEquals("ConcreteProductA1", productA1.operationA());
		assertEquals("ConcreteProductB1", productB1.operationB());

		// Factory 2 compatibility
		AbstractFactory factory2 = new ConcreteFactory2();
		ProductA productA2 = factory2.createProductA();
		ProductB productB2 = factory2.createProductB();

		assertEquals("ConcreteProductA2", productA2.operationA());
		assertEquals("ConcreteProductB2", productB2.operationB());
	}
}
