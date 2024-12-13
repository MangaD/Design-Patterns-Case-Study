/**
 * @brief Concrete implementation of a Subject in the Observer pattern.
 */
public class ConcreteSubject extends Subject {
	private String state;

	/**
	 * @brief Gets the state of the subject.
	 * @return The current state of the subject.
	 */
	public String getState() {
		return state;
	}

	/**
	 * @brief Sets the state of the subject and notifies observers.
	 * @param state The new state of the subject.
	 */
	public void setState(String state) {
		this.state = state;
		notifyObservers(state);
	}
}
