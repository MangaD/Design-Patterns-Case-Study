package Behavioral.Mediator;

/**
 * Abstract base class for Colleagues in the Mediator Pattern.
 *
 * Colleagues communicate with each other through the Mediator.
 */
public abstract class Colleague {
	/// Reference to the Mediator
	protected Mediator mediator;

	/**
	 * Constructor to associate the colleague with a mediator.
	 * @param mediator The mediator instance.
	 */
	public Colleague(Mediator mediator) {
		this.mediator = mediator;
	}

	/**
	 * Sends a message via the mediator.
	 * @param message The message to send.
	 */
	public void send(String message) {
		mediator.sendMessage(this, message);
	}

	/**
	 * Handles a received message.
	 * @param message The message received.
	 */
	public abstract void receive(String message);
}
