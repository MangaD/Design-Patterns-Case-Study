package Behavioral.Mediator;

import java.util.ArrayList;
import java.util.List;

/**
 * Concrete implementation of the Mediator interface.
 *
 * Facilitates communication between registered colleagues.
 */
public class ConcreteMediator implements Mediator {
	private final List<Colleague> colleagues = new ArrayList<>();

	/**
	 * Default constructor for ConcreteMediator.
	 */
	public ConcreteMediator() {
		// Default constructor
	}

	/**
	 * Sends a message from one colleague to all other colleagues.
	 * The message is forwarded to all colleagues except the sender.
	 * @param sender The colleague sending the message.
	 * @param message The message to send.
	 */
	@Override
	public void sendMessage(Colleague sender, String message) {
		for (Colleague colleague : colleagues) {
			if (colleague != sender) {
				colleague.receive(message);
			}
		}
	}

	/**
	 * Adds a colleague to the mediator.
	 * @param colleague The colleague to add.
	 */
	@Override
	public void addColleague(Colleague colleague) {
		colleagues.add(colleague);
	}
}
