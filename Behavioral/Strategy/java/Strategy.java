package Behavioral.Strategy;

/**
 * The Strategy interface declares the common behavior for all supported algorithms.
 */
public interface Strategy {
	/**
	 * Execute the strategy's algorithm.
	 * @return The result of the algorithm as a string.
	 */
	String execute();
}
