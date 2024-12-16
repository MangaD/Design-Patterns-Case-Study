/**
 * @brief Concrete implementation of an element, ElementA.
 */
public class ElementA extends Element {
	/**
	 * Perform ElementA-specific behavior.
	 *
	 * @return A message describing the operation.
	 */
	public String operationA() {
		return "ElementA operation.";
	}

	/**
	 * @copydoc Element#accept(Visitor)
	 */
	@Override
	public void accept(Visitor visitor) {
		visitor.visitElementA(this);
	}
}
