from abc import ABC, abstractmethod
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("command")


class Command(ABC):
	"""
	Defines the interface for commands.
	"""

	@abstractmethod
	def execute(self) -> None:
		"""
		Execute the command.
		"""
		pass


class Receiver:
	"""
	Handles the actual business logic for the commands.
	"""

	def action_a(self) -> None:
		"""
		Executes Action A.
		"""
		logger.info("Receiver: Performing Action A.")

	def action_b(self) -> None:
		"""
		Executes Action B.
		"""
		logger.info("Receiver: Performing Action B.")


class ConcreteCommandA(Command):
	"""
	Concrete implementation of a command for Action A.
	"""

	def __init__(self, receiver: Receiver) -> None:
		"""
		Initialize the ConcreteCommandA with the specified receiver.

		:param receiver: The receiver instance to operate on.
		"""
		self._receiver = receiver

	def execute(self) -> None:
		"""
		Execute the command by invoking Action A on the receiver.
		"""
		self._receiver.action_a()


class ConcreteCommandB(Command):
	"""
	Concrete implementation of a command for Action B.
	"""

	def __init__(self, receiver: Receiver) -> None:
		"""
		Initialize the ConcreteCommandB with the specified receiver.

		:param receiver: The receiver instance to operate on.
		"""
		self._receiver = receiver

	def execute(self) -> None:
		"""
		Execute the command by invoking Action B on the receiver.
		"""
		self._receiver.action_b()


class Invoker:
	"""
	Stores and executes commands in a sequence.
	"""

	def __init__(self) -> None:
		"""
		Initialize the Invoker with an empty command queue.
		"""
		self._command_queue = []

	def add_command(self, command: Command) -> None:
		"""
		Add a command to the queue.
		
		:param command: The command to add.
		"""
		self._command_queue.append(command)

	def execute_all(self) -> None:
		"""
		Execute all commands in the queue and clear it.
		"""
		for command in self._command_queue:
			command.execute()
		self._command_queue.clear()
