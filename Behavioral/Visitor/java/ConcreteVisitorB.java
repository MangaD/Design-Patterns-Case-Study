/**
 * @brief Another Concrete Visitor with different operations for each element type.
 */
public class ConcreteVisitorB implements Visitor {
	@Override
	public void visitElementA(ElementA elementA) {
		System.out.println("ConcreteVisitorB: " + elementA.operationA());
	}

	@Override
	public void visitElementB(ElementB elementB) {
		System.out.println("ConcreteVisitorB: " + elementB.operationB());
	}
}
