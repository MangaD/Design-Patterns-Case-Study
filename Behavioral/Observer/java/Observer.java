/**
 * @brief Interface for all observers in the Observer pattern.
 */
public interface Observer {
	/**
	 * @brief Notifies the observer of a change in the subject.
	 */
	void update(String state);
}
