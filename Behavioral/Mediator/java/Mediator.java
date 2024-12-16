package Behavioral.Mediator;

import java.util.ArrayList;
import java.util.List;

/**
 * Interface for the Mediator in the Mediator Pattern.
 *
 * The Mediator facilitates communication between different colleagues.
 */
public interface Mediator {
	/**
	 * Sends a message from one colleague to others.
	 * @param sender The colleague sending the message.
	 * @param message The message to send.
	 */
	void sendMessage(Colleague sender, String message);

	/**
	 * Registers a colleague with the mediator.
	 * @param colleague The colleague to register.
	 */
	void addColleague(Colleague colleague);
}
