/**
 * @brief Concrete implementation of an element, ElementB.
 */
public class ElementB extends Element {
	/**
	 * Perform ElementB-specific behavior.
	 *
	 * @return A message describing the operation.
	 */
	public String operationB() {
		return "ElementB operation.";
	}

	/**
	 * @copydoc Element#accept(Visitor)
	 */
	@Override
	public void accept(Visitor visitor) {
		visitor.visitElementB(this);
	}
}
