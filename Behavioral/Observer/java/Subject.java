import java.util.ArrayList;
import java.util.List;

/**
 * @brief Abstract class for subjects in the Observer pattern.
 */
public abstract class Subject {
	private final List<Observer> observers = new ArrayList<>();

	/**
	 * @brief Attaches an observer to the subject.
	 * @param observer The observer to attach.
	 */
	public void attach(Observer observer) {
		observers.add(observer);
	}

	/**
	 * @brief Detaches an observer from the subject.
	 * @param observer The observer to detach.
	 */
	public void detach(Observer observer) {
		observers.remove(observer);
	}

	/**
	 * @brief Notifies all attached observers of a change.
	 */
	protected void notifyObservers(String state) {
		for (Observer observer : observers) {
			observer.update(state);
		}
	}
}
