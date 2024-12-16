package Structural.Proxy;

/**
 * The Proxy controls access to the RealSubject.
 * 
 * The Proxy adds additional functionality such as authentication or lazy initialization.
 */
public class Proxy implements Subject {
	private RealSubject realSubject; ///< The RealSubject instance, initialized lazily.
	private final boolean isAuthenticated; ///< Indicates if the user is authenticated.

	/**
	 * Constructs the Proxy with authentication status.
	 * 
	 * @param isAuthenticated Whether the client is authenticated.
	 */
	public Proxy(boolean isAuthenticated) {
		this.isAuthenticated = isAuthenticated;
	}

	/**
	 * Handles the request by checking authentication and delegating to RealSubject.
	 * 
	 * @param resource The resource being requested.
	 */
	@Override
	public void request(String resource) {
		if (!isAuthenticated) {
			System.out.println("Proxy: Access denied. Authentication required to access: " + resource);
			return;
		}

		if (realSubject == null) {
			System.out.println("Proxy: Initializing RealSubject.");
			realSubject = new RealSubject();
		}

		System.out.println("Proxy: Delegating request to RealSubject.");
		realSubject.request(resource);
	}
}
