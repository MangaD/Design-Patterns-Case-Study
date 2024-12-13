import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @brief Unit tests for the Observer Pattern implementation.
 */
class ObserverPatternTest {
	private ConcreteSubject subject;
	private ConcreteObserver observer1;
	private ConcreteObserver observer2;
	private ByteArrayOutputStream outputStream;

	/**
	 * @brief Sets up the test environment.
	 *
	 * Creates a subject, two observers, and redirects system output
	 * to capture console logs for assertions.
	 */
	@BeforeEach
	void setUp() {
		subject = new ConcreteSubject();
		observer1 = new ConcreteObserver("Observer1");
		observer2 = new ConcreteObserver("Observer2");

		// Redirect system output to capture log messages
		outputStream = new ByteArrayOutputStream();
		System.setOut(new PrintStream(outputStream));
	}

	/**
	 * @brief Tests attaching observers and verifying they are notified.
	 */
	@Test
	void testAttachAndNotifyObservers() {
		subject.attach(observer1);
		subject.attach(observer2);

		subject.setState("State1");

		String output = outputStream.toString();
		assertTrue(output.contains("Observer Observer1 received update. New state: State1"));
		assertTrue(output.contains("Observer Observer2 received update. New state: State1"));
	}

	/**
	 * @brief Tests detaching an observer and verifying it no longer receives updates.
	 */
	@Test
	void testDetachObserver() {
		subject.attach(observer1);
		subject.attach(observer2);
		subject.detach(observer2);

		subject.setState("State2");

		String output = outputStream.toString();
		assertTrue(output.contains("Observer Observer1 received update. New state: State2"));
		assertFalse(output.contains("Observer Observer2 received update. New state: State2"));
	}

	/**
	 * @brief Tests that the system behaves correctly when no observers are attached.
	 */
	@Test
	void testNoObservers() {
		subject.setState("State3");

		String output = outputStream.toString();
		assertTrue(output.isEmpty(), "No output should be generated when there are no observers.");
	}

	/**
	 * @brief Tests attaching the same observer multiple times.
	 */
	@Test
	void testAttachSameObserverMultipleTimes() {
		subject.attach(observer1);
		subject.attach(observer1);

		subject.setState("State4");

		String output = outputStream.toString();
		long count = output.lines().filter(line -> line.contains("Observer Observer1 received update. New state: State4")).count();
		assertEquals(2, count, "Observer should receive updates for each time it was attached.");
	}

	/**
	 * @brief Tests detaching an observer that was not attached.
	 */
	@Test
	void testDetachNonexistentObserver() {
		subject.attach(observer1);
		subject.detach(observer2); // observer2 was never attached

		subject.setState("State5");

		String output = outputStream.toString();
		assertTrue(output.contains("Observer Observer1 received update. New state: State5"));
		assertFalse(output.contains("Observer Observer2 received update. New state: State5"));
	}

	/**
	 * @brief Tests attaching and detaching all observers in sequence.
	 */
	@Test
	void testAttachAndDetachAllObservers() {
		subject.attach(observer1);
		subject.attach(observer2);

		subject.setState("Initial State");
		subject.detach(observer1);
		subject.detach(observer2);

		subject.setState("Final State");

		String output = outputStream.toString();
		assertTrue(output.contains("Observer Observer1 received update. New state: Initial State"));
		assertTrue(output.contains("Observer Observer2 received update. New state: Initial State"));
		assertFalse(output.contains("Final State"), "No updates should be sent after all observers are detached.");
	}

	/**
	 * @brief Tests subject state retrieval after updates.
	 */
	@Test
	void testSubjectStateAfterUpdate() {
		subject.attach(observer1);

		subject.setState("State6");
		assertEquals("State6", subject.getState(), "Subject should retain the last set state.");

		subject.setState("State7");
		assertEquals("State7", subject.getState(), "Subject should update to the latest state.");
	}
}
