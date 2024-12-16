package Behavioral.Iterator;

import java.util.ArrayList;
import java.util.List;

/**
 * Concrete Aggregate that holds a collection of items.
 * 
 * Implements the Aggregate interface and provides a method to create iterators.
 * @param <T> The type of elements in the collection.
 */
public class ConcreteAggregate<T> implements Aggregate<T> {
	private final List<T> items; ///< Collection of items.

	/**
	 * Constructor initializes an empty collection.
	 */
	public ConcreteAggregate() {
		this.items = new ArrayList<>();
	}

	/**
	 * Add an item to the collection.
	 * @param item The item to add.
	 */
	public void addItem(T item) {
		items.add(item);
	}

	@Override
	public Iterator<T> createIterator() {
		return new ConcreteIterator<>(items);
	}
}
