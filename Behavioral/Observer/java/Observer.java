package Behavioral.Observer;

/**
 * Interface for all observers in the Observer pattern.
 */
public interface Observer {
	/**
	 * Notifies the observer of a change in the subject.
	 * @param state The updated state from the subject.
	 */
	void update(String state);
}
