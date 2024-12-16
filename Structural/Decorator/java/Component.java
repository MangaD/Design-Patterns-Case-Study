package Structural.Decorator;

/**
 * The Component interface defines operations that can be dynamically modified.
 */
public interface Component {
	/**
	 * Gets the description of the component.
	 * @return A string description.
	 */
	String getDescription();

	/**
	 * Gets the cost of the component.
	 * @return The cost as a double.
	 */
	double cost();
}
