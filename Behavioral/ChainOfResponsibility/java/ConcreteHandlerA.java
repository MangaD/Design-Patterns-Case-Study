package Behavioral.ChainOfResponsibility;

/**
 * A concrete handler that processes specific requests.
 */
public class ConcreteHandlerA extends AbstractHandler {

	/**
	 * Default constructor for ConcreteHandlerA.
	 */
	public ConcreteHandlerA() {
		// Default constructor
	}

	@Override
	public void handleRequest(String request) {
		if ("A".equals(request)) {
			System.out.println("ConcreteHandlerA handled request: " + request);
		} else {
			System.out.println("ConcreteHandlerA passing request: " + request);
			super.handleRequest(request);
		}
	}
}
