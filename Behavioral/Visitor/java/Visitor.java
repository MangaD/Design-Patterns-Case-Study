package Behavioral.Visitor;

/**
 * Visitor interface declaring operations for different element types.
 */
public interface Visitor {
	/**
	 * Visit an ElementA instance.
	 *
	 * @param elementA The ElementA instance.
	 */
	void visitElementA(ElementA elementA);

	/**
	 * Visit an ElementB instance.
	 *
	 * @param elementB The ElementB instance.
	 */
	void visitElementB(ElementB elementB);
}
