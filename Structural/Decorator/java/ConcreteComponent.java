package Structural.Decorator;

/**
 * A ConcreteComponent provides the base implementation of the Component interface.
 */
public class ConcreteComponent implements Component {

	/**
	 * Default constructor for ConcreteComponent.
	 */
	public ConcreteComponent() {
		// Default constructor
	}

	@Override
	public String getDescription() {
		return "Concrete Component";
	}

	@Override
	public double cost() {
		return 10.0;
	}
}
