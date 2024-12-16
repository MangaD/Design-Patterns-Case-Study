/**
 * @brief Abstract base class for elements.
 */
public abstract class Element {
	/**
	 * Accept a Visitor.
	 *
	 * @param visitor The Visitor to accept.
	 */
	public abstract void accept(Visitor visitor);
}
