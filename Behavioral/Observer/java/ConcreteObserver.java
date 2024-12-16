package Behavioral.Observer;

/**
 * Concrete implementation of an Observer in the Observer pattern.
 */
public class ConcreteObserver implements Observer {
	private final String name;

	/**
	 * Constructor for ConcreteObserver.
	 * @param name The name of the observer.
	 */
	public ConcreteObserver(String name) {
		this.name = name;
	}

	/**
	 * Handles updates from the subject.
	 * @param state The updated state from the subject.
	 */
	@Override
	public void update(String state) {
		System.out.println("Observer " + name + " received update. New state: " + state);
	}

	/**
	 * Gets the name of the observer.
	 * @return The name of the observer.
	 */
	public String getName() {
		return name;
	}
}
