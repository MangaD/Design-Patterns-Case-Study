/**
 * @brief The Subject interface defines the common operations for the Proxy and RealSubject.
 */
public interface Subject {
	/**
	 * Handles the request in a format expected by the client.
	 * 
	 * @param resource The resource being requested.
	 */
	void request(String resource);
}
