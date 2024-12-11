package mediator;

/**
 * @brief Abstract base class for Colleagues in the Mediator Pattern.
 *
 * Colleagues communicate with each other through the Mediator.
 */
public abstract class Colleague {
	protected Mediator mediator;

	/**
	 * @brief Constructor to associate the colleague with a mediator.
	 * @param mediator The mediator instance.
	 */
	public Colleague(Mediator mediator) {
		this.mediator = mediator;
	}

	/**
	 * @brief Sends a message via the mediator.
	 * @param message The message to send.
	 */
	public void send(String message) {
		mediator.sendMessage(this, message);
	}

	/**
	 * @brief Handles a received message.
	 * @param message The message received.
	 */
	public abstract void receive(String message);
}
