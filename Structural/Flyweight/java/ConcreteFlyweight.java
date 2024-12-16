package Structural.Flyweight;

import java.util.Objects;

/**
 * Concrete implementation of the Flyweight interface.
 * Represents a shared object with intrinsic state.
 */
public class ConcreteFlyweight implements Flyweight {
	private final String intrinsicState;

	/**
	 * Constructor initializes the intrinsic state of the Flyweight.
	 * @param intrinsicState Shared state for the Flyweight.
	 */
	public ConcreteFlyweight(String intrinsicState) {
		this.intrinsicState = intrinsicState;
	}

	@Override
	public void operation(String extrinsicState) {
		System.out.println("ConcreteFlyweight: Intrinsic state = " + intrinsicState
			+ ", Extrinsic state = " + extrinsicState);
	}
}
