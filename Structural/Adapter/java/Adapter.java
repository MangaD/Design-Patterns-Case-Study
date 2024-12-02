/**
 * @brief The Adapter class makes the Adaptee compatible with the Target interface.
 *
 * The Adapter implements the Target interface and translates calls from the client
 * to the Adaptee's methods. This enables the client to work seamlessly with Adaptee
 * without being aware of its specific implementation.
 */
public class Adapter implements Target {
	private final Adaptee adaptee; // Composition: Adapter holds a reference to Adaptee.

	/**
	 * @brief Constructs the Adapter with an Adaptee instance.
	 *
	 * @param adaptee The Adaptee instance to adapt.
	 * @throws IllegalArgumentException if the adaptee is null.
	 */
	public Adapter(Adaptee adaptee) {
		if (adaptee == null) {
			throw new IllegalArgumentException("Adaptee cannot be null");
		}
		this.adaptee = adaptee;
	}

	/**
	 * @brief Implements the Target interface by delegating to the Adaptee.
	 *
	 * This method translates the Target's `request()` call into a call
	 * to the Adaptee's `specificRequest()` method.
	 *
	 * @return A string response translated by the Adapter.
	 */
	@Override
	public String request() {
		return "Adapter: Translating request to Adaptee's specificRequest().\n" + adaptee.specificRequest();
	}
}
