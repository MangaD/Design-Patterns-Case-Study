/**
 * @brief Context class maintaining a reference to a state instance.
 */
public class Context {
	private State currentState;

	/**
	 * Constructs a Context with an initial state.
	 *
	 * @param initialState The initial state of the context.
	 */
	public Context(State initialState) {
		this.currentState = initialState;
	}

	/**
	 * Requests the current state's handle behavior.
	 */
	public void request() {
		if (currentState != null) {
			currentState.handle(this);
		}
	}

	/**
	 * Sets the state of the context.
	 *
	 * @param state The new state to transition to.
	 */
	public void setState(State state) {
		this.currentState = state;
	}

	/**
	 * Gets the name of the current state.
	 *
	 * @return The name of the current state.
	 */
	public String getStateName() {
		return currentState != null ? currentState.getName() : "No State";
	}
}
