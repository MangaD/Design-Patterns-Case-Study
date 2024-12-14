/**
 * @brief The Context class maintains a reference to a Strategy object and delegates the execution to it.
 */
public class Context {
	private Strategy strategy;

	/**
	 * Set the current strategy.
	 * @param strategy The strategy to use.
	 */
	public void setStrategy(Strategy strategy) {
		this.strategy = strategy;
	}

	/**
	 * Execute the current strategy's algorithm.
	 * @return The result of the algorithm as a string.
	 * @throws IllegalStateException if no strategy is set.
	 */
	public String executeStrategy() {
		if (strategy == null) {
			throw new IllegalStateException("No strategy set!");
		}
		return strategy.execute();
	}
}
