package mediator;

/**
 * @brief Concrete implementation of the Colleague class.
 *
 * Represents a participant in the communication facilitated by the mediator.
 */
public class ConcreteColleague extends Colleague {
	private final String name;

	/**
	 * @brief Constructor to create a named colleague.
	 * @param mediator The mediator instance.
	 * @param name The name of the colleague.
	 */
	public ConcreteColleague(Mediator mediator, String name) {
		super(mediator);
		this.name = name;
	}

	@Override
	public void receive(String message) {
		System.out.println(name + " received message: " + message);
	}

	/**
	 * @brief Gets the name of the colleague.
	 * @return The name.
	 */
	public String getName() {
		return name;
	}
}
