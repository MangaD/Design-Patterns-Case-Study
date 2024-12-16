package Creational.ObjectPool;

/**
 * Interface for objects managed by the ObjectPool.
 *
 * The Reusable interface defines the contract for objects that can be managed
 * and reused by an {@link ObjectPool}. Implementing classes must provide
 * mechanisms for being used and reset to their initial state.
 */
public interface Reusable {

	/**
	 * Performs the primary action of the reusable object.
	 *
	 * This method simulates the usage of the object. Classes implementing this
	 * interface can define the specific behavior when the object is "used."
	 */
	void use();

	/**
	 * Resets the reusable object to its initial state.
	 *
	 * This method is invoked when the object is returned to the pool, ensuring
	 * that it is ready for reuse. Classes implementing this interface must
	 * define how their internal state is cleared or reinitialized.
	 */
	void reset();
}
