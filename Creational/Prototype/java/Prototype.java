/**
 * @brief Interface for the Prototype pattern.
 *
 * Defines the contract for cloning objects.
 */
public interface Prototype {
	/**
	 * @brief Creates a clone of the current object.
	 * 
	 * @return A new object that is a copy of the current object.
	 */
	Prototype clone();

	/**
	 * @brief Displays the details of the prototype.
	 */
	void display();
}
