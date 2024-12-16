package Behavioral.Observer;

import java.util.ArrayList;
import java.util.List;

/**
 * Abstract class for subjects in the Observer pattern.
 */
public abstract class Subject {
	private final List<Observer> observers = new ArrayList<>();

	/**
	 * Default constructor for Subject.
	 */
	public Subject() {
		// Default constructor
	}

	/**
	 * Attaches an observer to the subject.
	 * @param observer The observer to attach.
	 */
	public void attach(Observer observer) {
		observers.add(observer);
	}

	/**
	 * Detaches an observer from the subject.
	 * @param observer The observer to detach.
	 */
	public void detach(Observer observer) {
		observers.remove(observer);
	}

	/**
	 * Notifies all attached observers of a change.
	 * @param state The updated state from the subject.
	 */
	protected void notifyObservers(String state) {
		for (Observer observer : observers) {
			observer.update(state);
		}
	}
}
