import java.util.ArrayList;
import java.util.List;

/**
 * @brief The Invoker class stores and executes commands.
 */
public class Invoker {
	private final List<Command> commandQueue = new ArrayList<>();

	/**
	 * Adds a command to the queue.
	 * @param command The Command to add.
	 */
	public void addCommand(Command command) {
		commandQueue.add(command);
	}

	/**
	 * Executes all commands in the queue and clears it.
	 */
	public void executeAll() {
		for (Command command : commandQueue) {
			command.execute();
		}
		commandQueue.clear();
	}
}