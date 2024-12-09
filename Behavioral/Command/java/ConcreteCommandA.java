/**
 * @brief A concrete implementation of the Command interface for Action A.
 */
public class ConcreteCommandA implements Command {
	private final Receiver receiver;

	/**
	 * @param receiver The Receiver instance to operate on.
	 */
	public ConcreteCommandA(Receiver receiver) {
		this.receiver = receiver;
	}

	@Override
	public void execute() {
		receiver.actionA();
	}
}
