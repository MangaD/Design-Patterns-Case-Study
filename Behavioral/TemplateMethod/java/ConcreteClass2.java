package behavioral.template_method;

/**
 * @brief Another concrete implementation of AbstractClass, with its own behavior.
 */
public class ConcreteClass2 extends AbstractClass {

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
