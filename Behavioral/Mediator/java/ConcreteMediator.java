package mediator;

import java.util.ArrayList;
import java.util.List;

/**
 * @brief Concrete implementation of the Mediator interface.
 *
 * Facilitates communication between registered colleagues.
 */
public class ConcreteMediator implements Mediator {
	private final List<Colleague> colleagues = new ArrayList<>();

	@Override
	public void sendMessage(Colleague sender, String message) {
		for (Colleague colleague : colleagues) {
			if (colleague != sender) {
				colleague.receive(message);
			}
		}
	}

	@Override
	public void addColleague(Colleague colleague) {
		colleagues.add(colleague);
	}
}
