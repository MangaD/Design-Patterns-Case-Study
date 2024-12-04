/**
 * @brief A ConcreteDecorator that adds behavior to the Component.
 */
public class ConcreteDecoratorA extends Decorator {

	/**
	 * @brief Constructor accepting a Component to wrap.
	 * @param component The Component to wrap.
	 */
	public ConcreteDecoratorA(Component component) {
		super(component);
	}

	@Override
	public String getDescription() {
		return component.getDescription() + " + Feature A";
	}

	@Override
	public double cost() {
		return component.cost() + 5.0;
	}
}
