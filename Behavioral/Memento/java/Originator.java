/**
 * @brief The Originator class creates and restores Memento objects.
 */
public class Originator {
	private String state; // Current state of the Originator.

	/**
	 * @brief Sets the state of the Originator.
	 * @param state The new state.
	 */
	public void setState(String state) {
		this.state = state;
	}

	/**
	 * @brief Retrieves the current state of the Originator.
	 * @return The current state as a string.
	 */
	public String getState() {
		return state;
	}

	/**
	 * @brief Creates a Memento containing the current state.
	 * @return A new Memento instance with the current state.
	 */
	public Memento createMemento() {
		return new Memento(state);
	}

	/**
	 * @brief Restores the state from a given Memento.
	 * @param memento The Memento to restore from.
	 */
	public void restoreMemento(Memento memento) {
		this.state = memento.getState();
	}
}
