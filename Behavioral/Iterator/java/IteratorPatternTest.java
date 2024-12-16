package Behavioral.Iterator;

import org.junit.jupiter.api.Test;

import java.util.NoSuchElementException;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Unit tests for the Iterator pattern.
 */
public class IteratorPatternTest {

	@Test
	public void testIteratorTraversal() {
		ConcreteAggregate<String> aggregate = new ConcreteAggregate<>();
		aggregate.addItem("Element 1");
		aggregate.addItem("Element 2");
		aggregate.addItem("Element 3");

		Iterator<String> iterator = aggregate.createIterator();

		assertTrue(iterator.hasNext());
		assertEquals("Element 1", iterator.next());

		assertTrue(iterator.hasNext());
		assertEquals("Element 2", iterator.next());

		assertTrue(iterator.hasNext());
		assertEquals("Element 3", iterator.next());

		assertFalse(iterator.hasNext());
		assertThrows(NoSuchElementException.class, iterator::next);
	}

	@Test
	public void testAddAndIterate() {
		ConcreteAggregate<Integer> aggregate = new ConcreteAggregate<>();
		aggregate.addItem(10);
		aggregate.addItem(20);
		aggregate.addItem(30);

		Iterator<Integer> iterator = aggregate.createIterator();

		assertTrue(iterator.hasNext());
		assertEquals(10, iterator.next());

		assertTrue(iterator.hasNext());
		assertEquals(20, iterator.next());

		assertTrue(iterator.hasNext());
		assertEquals(30, iterator.next());

		assertFalse(iterator.hasNext());
	}

	@Test
	public void testEmptyCollection() {
		ConcreteAggregate<Integer> aggregate = new ConcreteAggregate<>();
		Iterator<Integer> iterator = aggregate.createIterator();

		assertFalse(iterator.hasNext());
		assertThrows(NoSuchElementException.class, iterator::next);
	}
}
