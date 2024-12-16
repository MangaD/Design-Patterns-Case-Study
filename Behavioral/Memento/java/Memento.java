package Behavioral.Memento;

/**
 * The Memento class stores the state of the Originator.
 */
public class Memento {
	private final String state; // The saved state of the Originator.

	/**
	 * Constructor to initialize the Memento with a state.
	 * @param state The state to save.
	 */
	public Memento(String state) {
		this.state = state;
	}

	/**
	 * Retrieves the saved state.
	 * @return The saved state as a string.
	 */
	public String getState() {
		return state;
	}
}
