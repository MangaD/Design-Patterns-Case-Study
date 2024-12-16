package Behavioral.Iterator;

import java.util.NoSuchElementException;

/**
 * Interface for traversing collections.
 * 
 * Defines methods for sequentially accessing elements.
 * @param <T> The type of elements to iterate over.
 */
public interface Iterator<T> {
	/**
	 * Check if there are more elements in the collection.
	 * @return True if there are more elements, otherwise false.
	 */
	boolean hasNext();

	/**
	 * Retrieve the next element in the collection.
	 * @return The next element.
	 * @throws NoSuchElementException if there are no more elements.
	 */
	T next();
}
