/**
 * @brief The Component interface defines operations that can be dynamically modified.
 */
public interface Component {
	/**
	 * @brief Gets the description of the component.
	 * @return A string description.
	 */
	String getDescription();

	/**
	 * @brief Gets the cost of the component.
	 * @return The cost as a double.
	 */
	double cost();
}
