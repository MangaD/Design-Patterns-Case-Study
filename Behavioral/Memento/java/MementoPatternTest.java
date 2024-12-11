import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Memento pattern.
 */
public class MementoPatternTest {

	/**
	 * @brief Test the Memento pattern for saving and restoring state.
	 */
	@Test
	public void testSaveAndRestoreState() {
		Originator originator = new Originator();
		Caretaker caretaker = new Caretaker();

		// Set and save initial state.
		originator.setState("State1");
		caretaker.addMemento(originator.createMemento());

		// Change state and save it.
		originator.setState("State2");
		caretaker.addMemento(originator.createMemento());

		// Verify the current state.
		assertEquals("State2", originator.getState());

		// Restore to the previous state.
		originator.restoreMemento(caretaker.getMemento(0));
		assertEquals("State1", originator.getState());
	}

	/**
	 * @brief Test the Caretaker's handling of multiple Mementos.
	 */
	@Test
	public void testCaretakerStoresMultipleMementos() {
		Originator originator = new Originator();
		Caretaker caretaker = new Caretaker();

		// Save multiple states.
		originator.setState("StateA");
		caretaker.addMemento(originator.createMemento());
		originator.setState("StateB");
		caretaker.addMemento(originator.createMemento());
		originator.setState("StateC");
		caretaker.addMemento(originator.createMemento());

		// Restore and verify each state.
		assertEquals("StateA", caretaker.getMemento(0).getState());
		assertEquals("StateB", caretaker.getMemento(1).getState());
		assertEquals("StateC", caretaker.getMemento(2).getState());
	}

	/**
	 * @brief Test the Caretaker's exception handling for invalid indices.
	 */
	@Test
	public void testInvalidMementoIndex() {
		Caretaker caretaker = new Caretaker();

		assertThrows(IndexOutOfBoundsException.class, () -> caretaker.getMemento(0));
		assertThrows(IndexOutOfBoundsException.class, () -> caretaker.getMemento(1));
	}
}
