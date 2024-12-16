package Behavioral.Visitor;

/**
 * Concrete implementation of an element, ElementA.
 */
public class ElementA extends Element {

	/**
	 * Default constructor for ElementA.
	 */
	public ElementA() {
		super();
	}

	/**
	 * Perform ElementA-specific behavior.
	 *
	 * @return A message describing the operation.
	 */
	public String operationA() {
		return "ElementA operation.";
	}

	/**
	 * Accept a Visitor.
	 *
	 * @param visitor The Visitor to accept.
	 */
	@Override
	public void accept(Visitor visitor) {
		visitor.visitElementA(this);
	}
}
