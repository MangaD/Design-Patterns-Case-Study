package Behavioral.TemplateMethod;

/**
 * Concrete implementation of AbstractClass, providing specific behavior.
 */
public class ConcreteClass1 extends AbstractClass {

	/**
	 * Default constructor for ConcreteClass1.
	 */
	public ConcreteClass1() {
		super();
	}

	@Override
	protected void requiredOperation1() {
		System.out.println("ConcreteClass1: Required operation 1");
	}

	@Override
	protected void requiredOperation2() {
		System.out.println("ConcreteClass1: Required operation 2");
	}

	@Override
	protected void hook() {
		System.out.println("ConcreteClass1: Overridden hook implementation");
	}
}
