/**
 * @brief Abstract State interface defining behavior for concrete states.
 */
public interface State {
	/**
	 * Handles the context-specific behavior for this state.
	 *
	 * @param context The context object whose state is being handled.
	 */
	void handle(Context context);

	/**
	 * Gets the name of the current state for debugging purposes.
	 *
	 * @return The name of the state.
	 */
	String getName();
}
