package Behavioral.Iterator;

import java.util.List;
import java.util.NoSuchElementException;

/**
 * Concrete Iterator for traversing a collection.
 * 
 * Implements the Iterator interface and provides traversal logic.
 * @param <T> The type of elements in the collection.
 */
public class ConcreteIterator<T> implements Iterator<T> {
	private final List<T> collection; ///< The collection being iterated.
	private int position;             ///< Current position in the collection.

	/**
	 * Constructor initializes the iterator with a collection.
	 * @param collection The collection to iterate over.
	 */
	public ConcreteIterator(List<T> collection) {
		this.collection = collection;
		this.position = 0;
	}

	@Override
	public boolean hasNext() {
		return position < collection.size();
	}

	@Override
	public T next() {
		if (!hasNext()) {
			throw new NoSuchElementException("No more elements in the iterator.");
		}
		return collection.get(position++);
	}
}
