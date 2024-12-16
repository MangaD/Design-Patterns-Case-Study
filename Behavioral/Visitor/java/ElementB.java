package Behavioral.Visitor;

/**
 * Concrete implementation of an element, ElementB.
 */
public class ElementB extends Element {

	/**
	 * Default constructor for ElementB.
	 */
	public ElementB() {
		super();
	}

	/**
	 * Perform ElementB-specific behavior.
	 *
	 * @return A message describing the operation.
	 */
	public String operationB() {
		return "ElementB operation.";
	}

	/**
	 * Accept a Visitor.
	 *
	 * @param visitor The Visitor to accept.
	 */
	@Override
	public void accept(Visitor visitor) {
		visitor.visitElementB(this);
	}
}
