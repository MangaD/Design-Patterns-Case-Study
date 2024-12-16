package Behavioral.Strategy;

/**
 * Another Concrete Strategy that implements a different algorithm.
 */
public class ConcreteStrategyB implements Strategy {

	/**
	 * Default constructor for ConcreteStrategyB.
	 */
	public ConcreteStrategyB() {
		// Default constructor
	}

	/**
	 * Executes the algorithm specific to ConcreteStrategyB.
	 * @return The result of the algorithm as a string.
	 */
	@Override
	public String execute() {
		return "Executing strategy B.";
	}
}
