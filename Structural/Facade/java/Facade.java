/**
 * @brief The Facade provides a simplified interface to the subsystems.
 *
 * The Facade delegates requests from the client to the appropriate subsystems,
 * hiding their complexity.
 */
public class Facade {
	private Subsystem1 subsystem1;
	private Subsystem2 subsystem2;
	private Subsystem3 subsystem3;

	/**
	 * @brief Constructs the Facade with subsystem instances.
	 */
	public Facade() {
		this.subsystem1 = new Subsystem1();
		this.subsystem2 = new Subsystem2();
		this.subsystem3 = new Subsystem3();
	}

	/**
	 * @brief Executes a high-level operation by coordinating subsystems.
	 * @return A string describing the combined operations.
	 */
	public String operation() {
		StringBuilder result = new StringBuilder();
		result.append("Facade: Coordinating subsystems:\n");
		result.append(subsystem1.operation1());
		result.append(subsystem2.operation2());
		result.append(subsystem3.operation3());
		return result.toString();
	}
}
