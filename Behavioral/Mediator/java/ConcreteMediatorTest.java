package Behavioral.Mediator;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

class ConcreteMediatorTest {
	private ByteArrayOutputStream outputStream;
	private PrintStream originalOut;

	@BeforeEach
	void setUp() {
		originalOut = System.out;
		outputStream = new ByteArrayOutputStream();
		System.setOut(new PrintStream(outputStream));
	}

	@AfterEach
	void tearDown() {
		System.setOut(originalOut);
	}

	@Test
	void testCommunicationBetweenColleagues() {
		ConcreteMediator mediator = new ConcreteMediator();

		ConcreteColleague colleague1 = new ConcreteColleague(mediator, "Colleague1");
		ConcreteColleague colleague2 = new ConcreteColleague(mediator, "Colleague2");

		mediator.addColleague(colleague1);
		mediator.addColleague(colleague2);

		colleague1.send("Hello from Colleague1");

		String output = outputStream.toString().trim();
		assertTrue(output.contains("Colleague2 received message: Hello from Colleague1"));
	}

	@Test
	void testSendMessageWithoutColleagues() {
		ConcreteMediator mediator = new ConcreteMediator();

		ConcreteColleague colleague1 = new ConcreteColleague(mediator, "Colleague1");

		colleague1.send("Message without other colleagues");

		String output = outputStream.toString().trim();
		assertEquals("", output); // No output expected since no colleagues are registered.
	}

	@Test
	void testDynamicColleagueAddition() {
		ConcreteMediator mediator = new ConcreteMediator();

		ConcreteColleague colleague1 = new ConcreteColleague(mediator, "Colleague1");
		ConcreteColleague colleague2 = new ConcreteColleague(mediator, "Colleague2");

		mediator.addColleague(colleague1);
		colleague1.send("Hello before Colleague2 is added");

		mediator.addColleague(colleague2);
		colleague1.send("Hello after Colleague2 is added");

		String output = outputStream.toString().trim();
		assertFalse(output.contains("Colleague2 received message: Hello before Colleague2 is added"));
		assertTrue(output.contains("Colleague2 received message: Hello after Colleague2 is added"));
	}
}
