package Behavioral.ChainOfResponsibility;

/**
 * Abstract base class that implements the chaining mechanism.
 */
public abstract class AbstractHandler implements Handler {
	private Handler nextHandler; // The next handler in the chain

	/**
	 * Default constructor for AbstractHandler.
	 */
	public AbstractHandler() {
		// Default constructor
	}

	@Override
	public Handler setNext(Handler next) {
		this.nextHandler = next;
		return this;
	}

	@Override
	public void handleRequest(String request) {
		if (nextHandler != null) {
			nextHandler.handleRequest(request);
		}
	}
}
