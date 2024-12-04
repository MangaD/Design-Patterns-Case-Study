/**
 * @brief Another ConcreteDecorator that adds behavior to the Component.
 */
public class ConcreteDecoratorB extends Decorator {

	/**
	 * @brief Constructor accepting a Component to wrap.
	 * @param component The Component to wrap.
	 */
	public ConcreteDecoratorB(Component component) {
		super(component);
	}

	@Override
	public String getDescription() {
		return component.getDescription() + " + Feature B";
	}

	@Override
	public double cost() {
		return component.cost() + 7.5;
	}
}
