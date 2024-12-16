package Behavioral.State;

/**
 * Concrete implementation of State representing State B.
 */
public class ConcreteStateB implements State {

	/**
	 * Default constructor for ConcreteStateB.
	 */
	public ConcreteStateB() {
		// Default constructor
	}

	@Override
	public void handle(Context context) {
		System.out.println("ConcreteStateB: Handling request. Switching to State A.");
		context.setState(new ConcreteStateA());
	}

	@Override
	public String getName() {
		return "ConcreteStateB";
	}
}
