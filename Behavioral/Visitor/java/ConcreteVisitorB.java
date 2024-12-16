package Behavioral.Visitor;

/**
 * Another Concrete Visitor with different operations for each element type.
 */
public class ConcreteVisitorB implements Visitor {

	/**
	 * Default constructor for ConcreteVisitorB.
	 */
	public ConcreteVisitorB() {
		// Default constructor
	}

	/**
	 * Visit an ElementA instance.
	 * 
	 * @param elementA The ElementA instance to visit.
	 */
	@Override
	public void visitElementA(ElementA elementA) {
		System.out.println("ConcreteVisitorB: " + elementA.operationA());
	}

	/**
	 * Visit an ElementB instance.
	 * 
	 * @param elementB The ElementB instance to visit.
	 */
	@Override
	public void visitElementB(ElementB elementB) {
		System.out.println("ConcreteVisitorB: " + elementB.operationB());
	}
}
