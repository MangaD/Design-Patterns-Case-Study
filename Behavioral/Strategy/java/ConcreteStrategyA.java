package Behavioral.Strategy;

/**
 * A Concrete Strategy that implements an algorithm.
 */
public class ConcreteStrategyA implements Strategy {

	/**
	 * Default constructor for ConcreteStrategyA.
	 */
	public ConcreteStrategyA() {
		// Default constructor
	}

	/**
	 * Execute the algorithm defined by this concrete strategy.
	 * @return A string result of the algorithm.
	 */
	@Override
	public String execute() {
		return "Executing strategy A.";
	}
}
