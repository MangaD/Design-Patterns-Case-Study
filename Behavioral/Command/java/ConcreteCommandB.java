package Behavioral.Command;

/**
 * A concrete implementation of the Command interface for Action B.
 */
public class ConcreteCommandB implements Command {
	private final Receiver receiver;

	/**
	 * Constructs a ConcreteCommandB instance.
	 * @param receiver The Receiver instance to operate on.
	 */
	public ConcreteCommandB(Receiver receiver) {
		this.receiver = receiver;
	}

	@Override
	public void execute() {
		receiver.actionB();
	}
}
