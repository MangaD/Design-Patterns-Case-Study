import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

/**
 * @brief Unit tests for the Command Pattern implementation.
 */
public class CommandPatternTest {

	@Test
	void testConcreteCommandA() {
		Receiver receiver = new Receiver();
		Command commandA = new ConcreteCommandA(receiver);

		assertDoesNotThrow(commandA::execute, "Executing ConcreteCommandA should not throw any exceptions.");
	}

	@Test
	void testConcreteCommandB() {
		Receiver receiver = new Receiver();
		Command commandB = new ConcreteCommandB(receiver);

		assertDoesNotThrow(commandB::execute, "Executing ConcreteCommandB should not throw any exceptions.");
	}

	@Test
	void testInvokerExecution() {
		Receiver receiver = new Receiver();
		Invoker invoker = new Invoker();

		Command commandA = new ConcreteCommandA(receiver);
		Command commandB = new ConcreteCommandB(receiver);

		invoker.addCommand(commandA);
		invoker.addCommand(commandB);

		assertDoesNotThrow(invoker::executeAll, "Invoker should execute all commands without throwing exceptions.");
	}
}
