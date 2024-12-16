package Behavioral.Visitor;

/**
 * Concrete Visitor implementing specific operations for each element type.
 */
public class ConcreteVisitorA implements Visitor {

	/**
	 * Default constructor for ConcreteVisitorA.
	 */
	public ConcreteVisitorA() {
		// Default constructor
	}

	/**
	 * Visit an ElementA instance.
	 * 
	 * @param elementA The ElementA instance to visit.
	 */
	@Override
	public void visitElementA(ElementA elementA) {
		System.out.println("ConcreteVisitorA: " + elementA.operationA());
	}

	/**
	 * Visit an ElementB instance.
	 * 
	 * @param elementB The ElementB instance to visit.
	 */
	@Override
	public void visitElementB(ElementB elementB) {
		System.out.println("ConcreteVisitorA: " + elementB.operationB());
	}
}
