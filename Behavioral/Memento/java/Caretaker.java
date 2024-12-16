package Behavioral.Memento;

import java.util.ArrayList;
import java.util.List;

/**
 * The Caretaker class manages Memento objects.
 */
public class Caretaker {
	private final List<Memento> mementos = new ArrayList<>(); // List of saved Mementos.

	/**
	 * Default constructor for Caretaker.
	 */
	public Caretaker() {
		// Default constructor
	}

	/**
	 * Adds a Memento to the list.
	 * @param memento The Memento to add.
	 */
	public void addMemento(Memento memento) {
		mementos.add(memento);
	}

	/**
	 * Retrieves a Memento by index.
	 * @param index The index of the desired Memento.
	 * @return The Memento at the specified index.
	 * @throws IndexOutOfBoundsException if the index is invalid.
	 */
	public Memento getMemento(int index) {
		if (index < 0 || index >= mementos.size()) {
			throw new IndexOutOfBoundsException("Index out of range");
		}
		return mementos.get(index);
	}
}
