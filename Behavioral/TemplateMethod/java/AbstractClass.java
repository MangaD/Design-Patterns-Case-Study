package Behavioral.TemplateMethod;

/**
 * Abstract class defining the template method and the structure of the algorithm.
 *
 * The template method defines a skeleton of the algorithm, deferring some steps to subclasses.
 * Subclasses must implement the required operations and can optionally override hooks.
 */
public abstract class AbstractClass {

	/**
	 * Default constructor for AbstractClass.
	 */
	public AbstractClass() {
		// Default constructor
	}

	/**
	 * Template method defining the algorithm structure.
	 *
	 * This method contains base operations and calls to abstract methods
	 * that must be implemented by subclasses.
	 */
	public final void templateMethod() {
		baseOperation1();
		requiredOperation1();
		baseOperation2();
		requiredOperation2();
		hook();
	}

	/**
	 * Base operation implemented in the abstract class.
	 * This is part of the common algorithm structure.
	 */
	private void baseOperation1() {
		System.out.println("AbstractClass: Base operation 1");
	}

	/**
	 * Base operation implemented in the abstract class.
	 * This is part of the common algorithm structure.
	 */
	private void baseOperation2() {
		System.out.println("AbstractClass: Base operation 2");
	}

	/**
	 * Abstract method that subclasses must implement.
	 */
	protected abstract void requiredOperation1();

	/**
	 * Abstract method that subclasses must implement.
	 */
	protected abstract void requiredOperation2();

	/**
	 * Hook method that can be optionally overridden by subclasses.
	 *
	 * By default, it provides a no-op implementation.
	 */
	protected void hook() {
		System.out.println("AbstractClass: Default hook implementation");
	}
}
