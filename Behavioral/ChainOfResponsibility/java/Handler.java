/**
 * @brief The interface for handling requests in the chain.
 */
public interface Handler {
	/**
	 * @brief Handles the request or forwards it to the next handler.
	 * @param request The request to handle.
	 */
	void handleRequest(String request);

	/**
	 * @brief Sets the next handler in the chain.
	 * @param next The next handler.
	 * @return The current handler for chaining.
	 */
	Handler setNext(Handler next);
}
