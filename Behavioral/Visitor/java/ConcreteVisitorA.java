/**
 * @brief Concrete Visitor implementing specific operations for each element type.
 */
public class ConcreteVisitorA implements Visitor {
	@Override
	public void visitElementA(ElementA elementA) {
		System.out.println("ConcreteVisitorA: " + elementA.operationA());
	}

	@Override
	public void visitElementB(ElementB elementB) {
		System.out.println("ConcreteVisitorA: " + elementB.operationB());
	}
}
