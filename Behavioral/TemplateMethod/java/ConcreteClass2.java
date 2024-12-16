package Behavioral.TemplateMethod;

/**
 * Another concrete implementation of AbstractClass, with its own behavior.
 */
public class ConcreteClass2 extends AbstractClass {

	/**
	 * Default constructor for ConcreteClass2.
	 */
	public ConcreteClass2() {
		super();
	}

	@Override
	protected void requiredOperation1() {
		System.out.println("ConcreteClass2: Required operation 1");
	}

	@Override
	protected void requiredOperation2() {
		System.out.println("ConcreteClass2: Required operation 2");
	}

	// No need to override the hook; the default implementation is used.
}
