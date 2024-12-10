/**
 * @brief Interface for creating iterators.
 * 
 * Provides a method to retrieve an iterator for a collection.
 * @param <T> The type of elements in the collection.
 */
public interface Aggregate<T> {
	/**
	 * @brief Create an iterator for the collection.
	 * @return An iterator for the collection.
	 */
	Iterator<T> createIterator();
}
