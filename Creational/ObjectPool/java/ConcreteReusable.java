import java.util.concurrent.atomic.AtomicBoolean;

/**
 * @brief Concrete implementation of the Reusable interface.
 *
 * Simulates a reusable object with a unique identifier and an "in-use" state.
 */
public class ConcreteReusable implements Reusable {
	private final String id;            // Unique identifier for the reusable object
	private final AtomicBoolean inUse;  // Indicates whether the object is currently in use

	/**
	 * @brief Constructor initializing the object with a unique ID.
	 * @param id The unique identifier for the object.
	 */
	public ConcreteReusable(String id) {
		this.id = id;
		this.inUse = new AtomicBoolean(false);
	}

	@Override
	public void use() {
		if (inUse.getAndSet(true)) {
			System.err.println("Object " + id + " is already in use.");
			return;
		}
		System.out.println("Using object: " + id);
	}

	@Override
	public void reset() {
		inUse.set(false);
		System.out.println("Resetting object: " + id);
	}

	@Override
	public String toString() {
		return "ConcreteReusable{id='" + id + "', inUse=" + inUse.get() + "}";
	}
}
