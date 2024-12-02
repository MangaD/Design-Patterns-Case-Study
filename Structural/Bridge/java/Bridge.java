/**
 * @brief Defines the abstraction in the Bridge Pattern.
 * Works independently of the implementation.
 */
abstract class Abstraction {
	protected Implementor implementor;

	/**
	 * @brief Constructs the abstraction with a given implementor.
	 * @param implementor The concrete implementor to bridge with.
	 */
	public Abstraction(Implementor implementor) {
		this.implementor = implementor;
	}

	/**
	 * @brief Performs an operation, to be defined by subclasses.
	 */
	public abstract void operation();
}

/**
 * @brief Refined abstraction that extends the base abstraction.
 */
class RefinedAbstraction extends Abstraction {

	/**
	 * @brief Constructs the refined abstraction with a given implementor.
	 * @param implementor The concrete implementor to bridge with.
	 */
	public RefinedAbstraction(Implementor implementor) {
		super(implementor);
	}

	/**
	 * @brief Performs the operation using the implementor.
	 */
	@Override
	public void operation() {
		System.out.println("RefinedAbstraction: Delegating operation to implementor.");
		implementor.implementation();
	}
}

/**
 * @brief Defines the interface for the implementor in the Bridge Pattern.
 */
interface Implementor {
	/**
	 * @brief Defines the operation implemented by concrete implementors.
	 */
	void implementation();
}

/**
 * @brief Concrete implementor that provides a specific implementation.
 */
class ConcreteImplementorA implements Implementor {

	/**
	 * @brief Provides a concrete implementation of the operation.
	 */
	@Override
	public void implementation() {
		System.out.println("ConcreteImplementorA: Performing implementation.");
	}
}

/**
 * @brief Another concrete implementor that provides a different implementation.
 */
class ConcreteImplementorB implements Implementor {

	/**
	 * @brief Provides another concrete implementation of the operation.
	 */
	@Override
	public void implementation() {
		System.out.println("ConcreteImplementorB: Performing implementation.");
	}
}
