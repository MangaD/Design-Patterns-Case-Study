package Behavioral.ChainOfResponsibility;

/**
 * Another concrete handler that processes different requests.
 */
public class ConcreteHandlerB extends AbstractHandler {

	/**
	 * Default constructor for ConcreteHandlerB.
	 */
	public ConcreteHandlerB() {
		// Default constructor
	}

	@Override
	public void handleRequest(String request) {
		if ("B".equals(request)) {
			System.out.println("ConcreteHandlerB handled request: " + request);
		} else {
			System.out.println("ConcreteHandlerB passing request: " + request);
			super.handleRequest(request);
		}
	}
}
