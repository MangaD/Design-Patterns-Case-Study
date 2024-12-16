package Behavioral.State;

/**
 * Concrete implementation of State representing State A.
 */
public class ConcreteStateA implements State {

	/**
	 * Default constructor for ConcreteStateA.
	 */
	public ConcreteStateA() {
		// Default constructor
	}

	@Override
	public void handle(Context context) {
		System.out.println("ConcreteStateA: Handling request. Switching to State B.");
		context.setState(new ConcreteStateB());
	}

	@Override
	public String getName() {
		return "ConcreteStateA";
	}
}
