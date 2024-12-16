package Structural.Proxy;

/**
 * The RealSubject performs the actual work of handling requests.
 */
public class RealSubject implements Subject {

	/**
	 * Default constructor for RealSubject.
	 */
	public RealSubject() {
		// Default constructor
	}

	/**
	 * Handles the request and simulates actual processing.
	 * 
	 * @param resource The resource being accessed.
	 */
	@Override
	public void request(String resource) {
		System.out.println("RealSubject: Handling request for resource: " + resource);
	}
}
