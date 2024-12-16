package Structural.Composite;

/**
 * The Component interface declares common operations for both leaf and composite objects.
 */
public interface Component {
	/**
	 * Performs an operation on the component.
	 */
	void operation();

	/**
	 * Adds a child component.
	 * This method is optional and can throw UnsupportedOperationException for leaf nodes.
	 * 
	 * @param component The child component to add.
	 */
	default void add(Component component) {
		throw new UnsupportedOperationException("Add operation is not supported.");
	}

	/**
	 * Removes a child component.
	 * This method is optional and can throw UnsupportedOperationException for leaf nodes.
	 * 
	 * @param component The child component to remove.
	 */
	default void remove(Component component) {
		throw new UnsupportedOperationException("Remove operation is not supported.");
	}

	/**
	 * Retrieves a child component at the specified index.
	 * This method is optional and can throw UnsupportedOperationException for leaf nodes.
	 * 
	 * @param index The index of the child component to retrieve.
	 * @return The child component.
	 */
	default Component getChild(int index) {
		throw new UnsupportedOperationException("GetChild operation is not supported.");
	}
}
