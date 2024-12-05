import java.util.HashMap;
import java.util.Map;

/**
 * @brief Factory for creating and managing Flyweight objects.
 *
 * Ensures that shared Flyweight objects are reused rather than created multiple times.
 */
public class FlyweightFactory {
	private final Map<String, Flyweight> flyweights = new HashMap<>();

	/**
	 * @brief Retrieves a Flyweight object with the given intrinsic state.
	 * If the Flyweight does not exist, it is created and stored.
	 * 
	 * @param intrinsicState The shared intrinsic state of the Flyweight.
	 * @return A Flyweight object.
	 */
	public Flyweight getFlyweight(String intrinsicState) {
		flyweights.putIfAbsent(intrinsicState, new ConcreteFlyweight(intrinsicState));
		return flyweights.get(intrinsicState);
	}

	/**
	 * @brief Displays the current Flyweights managed by the factory.
	 */
	public void listFlyweights() {
		System.out.println("Flyweights in Factory:");
		flyweights.forEach((key, value) -> System.out.println(" - " + key));
	}
}
