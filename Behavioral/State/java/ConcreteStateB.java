/**
 * @brief Concrete implementation of State representing State B.
 */
public class ConcreteStateB implements State {

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
