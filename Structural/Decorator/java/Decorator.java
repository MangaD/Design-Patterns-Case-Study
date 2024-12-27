package Structural.Decorator;

/**
 * The Decorator class wraps a Component and adds functionality dynamically.
 */
public abstract class Decorator implements Component {
	/**
	 * The wrapped Component.
	 */
	protected Component component;

	/**
	 * Constructor accepting a Component to wrap.
	 * @param component The Component to wrap.
	 */
	public Decorator(Component component) {
		this.component = component;
	}

	@Override
	public String getDescription() {
		return component.getDescription();
	}

	@Override
	public double cost() {
		return component.cost();
	}
}
