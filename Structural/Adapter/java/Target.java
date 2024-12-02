/**
 * @brief The Target interface defines the domain-specific interface expected by the client.
 *
 * The Target interface acts as a standard contract for clients that need to interact with
 * certain functionality. It abstracts away specific implementation details, allowing
 * clients to remain decoupled from concrete implementations.
 */
public interface Target {
	/**
	 * @brief Standard method expected by the client.
	 * 
	 * Implementations of this method provide functionality that aligns with
	 * the client's expectations.
	 *
	 * @return A string representing the response from the Target.
	 */
	String request();
}
