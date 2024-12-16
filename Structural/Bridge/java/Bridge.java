package Structural.Bridge;

/**
 * Defines the abstraction in the Bridge Pattern.
 * Works independently of the implementation.
 */
abstract class Abstraction {
	protected Implementor implementor;

	/**
	 * Constructs the abstraction with a given implementor.
	 * @param implementor The concrete implementor to bridge with.
	 */
	public Abstraction(Implementor implementor) {
		this.implementor = implementor;
	}

	/**
	 * Performs an operation, to be defined by subclasses.
	 */
	public abstract void operation();
}

/**
 * Refined abstraction that extends the base abstraction.
 */
class RefinedAbstraction extends Abstraction {

	/**
	 * Constructs the refined abstraction with a given implementor.
	 * @param implementor The concrete implementor to bridge with.
	 */
	public RefinedAbstraction(Implementor implementor) {
		super(implementor);
	}

	/**
	 * Performs the operation using the implementor.
	 */
	@Override
	public void operation() {
		System.out.println("RefinedAbstraction: Delegating operation to implementor.");
		implementor.implementation();
	}
}

/**
 * Defines the interface for the implementor in the Bridge Pattern.
 */
interface Implementor {
	/**
	 * Defines the operation implemented by concrete implementors.
	 */
	void implementation();
}

/**
 * Concrete implementor that provides a specific implementation.
 */
class ConcreteImplementorA implements Implementor {

	/**
	 * Provides a concrete implementation of the operation.
	 */
	@Override
	public void implementation() {
		System.out.println("ConcreteImplementorA: Performing implementation.");
	}
}

/**
 * Another concrete implementor that provides a different implementation.
 */
class ConcreteImplementorB implements Implementor {

	/**
	 * Provides another concrete implementation of the operation.
	 */
	@Override
	public void implementation() {
		System.out.println("ConcreteImplementorB: Performing implementation.");
	}
}
