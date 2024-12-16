package Behavioral.Command;

/**
 * The Receiver class contains the actual business logic for the commands.
 */
public class Receiver {

	/**
	 * Default constructor for Receiver.
	 */
	public Receiver() {
		// Default constructor
	}

	/**
	 * Executes Action A.
	 */
	public void actionA() {
		System.out.println("Receiver: Performing Action A.");
	}

	/**
	 * Executes Action B.
	 */
	public void actionB() {
		System.out.println("Receiver: Performing Action B.");
	}
}
