package Behavioral.Memento;

/**
 * The Originator class creates and restores Memento objects.
 */
public class Originator {
	private String state; // Current state of the Originator.

	/**
	 * Default constructor for Originator.
	 */
	public Originator() {
		// Default constructor
	}

	/**
	 * Sets the state of the Originator.
	 * @param state The new state.
	 */
	public void setState(String state) {
		this.state = state;
	}

	/**
	 * Retrieves the current state of the Originator.
	 * @return The current state as a string.
	 */
	public String getState() {
		return state;
	}

	/**
	 * Creates a Memento containing the current state.
	 * @return A new Memento instance with the current state.
	 */
	public Memento createMemento() {
		return new Memento(state);
	}

	/**
	 * Restores the state from a given Memento.
	 * @param memento The Memento to restore from.
	 */
	public void restoreMemento(Memento memento) {
		this.state = memento.getState();
	}
}
