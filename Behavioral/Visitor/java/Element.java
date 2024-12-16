package Behavioral.Visitor;

/**
 * Abstract base class for elements.
 */
public abstract class Element {

	/**
	 * Default constructor for Element.
	 */
	public Element() {
		// Default constructor
	}

	/**
	 * Accept a Visitor.
	 *
	 * @param visitor The Visitor to accept.
	 */
	public abstract void accept(Visitor visitor);
}
