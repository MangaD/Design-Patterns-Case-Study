package Structural.Composite;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit tests for the Composite Design Pattern implementation.
 */
public class CompositePatternTest {

	/**
	 * Test the operation of a Leaf object.
	 */
	@Test
	public void testLeafOperation() {
		Leaf leaf = new Leaf("Leaf1");
		assertDoesNotThrow(leaf::operation);
	}

	/**
	 * Test adding and retrieving children in a Composite.
	 */
	@Test
	public void testCompositeAddAndGetChild() {
		Composite composite = new Composite("Composite1");
		Leaf leaf1 = new Leaf("Leaf1");
		Leaf leaf2 = new Leaf("Leaf2");

		composite.add(leaf1);
		composite.add(leaf2);

		assertEquals(leaf1, composite.getChild(0));
		assertEquals(leaf2, composite.getChild(1));
	}

	/**
	 * Test removing a child from a Composite.
	 */
	@Test
	public void testCompositeRemoveChild() {
		Composite composite = new Composite("Composite1");
		Leaf leaf = new Leaf("Leaf1");

		composite.add(leaf);
		composite.remove(leaf);

		assertThrows(IndexOutOfBoundsException.class, () -> composite.getChild(0));
	}

	/**
	 * Test the operation of a Composite with children.
	 */
	@Test
	public void testCompositeOperation() {
		Composite root = new Composite("Root");
		Composite childComposite = new Composite("ChildComposite");
		Leaf leaf1 = new Leaf("Leaf1");
		Leaf leaf2 = new Leaf("Leaf2");

		childComposite.add(leaf1);
		childComposite.add(leaf2);
		root.add(childComposite);

		assertDoesNotThrow(root::operation);
	}
}
