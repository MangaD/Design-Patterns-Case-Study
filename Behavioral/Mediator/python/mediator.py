from abc import ABC, abstractmethod
from typing import List, Protocol
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("mediator")


class Mediator(Protocol):
	"""
	Defines the interface for the Mediator.

	A mediator facilitates communication between different Colleagues.
	"""

	def send_message(self, sender: 'Colleague', message: str) -> None:
		"""
		Sends a message from one colleague to others.
		:param sender: The colleague sending the message.
		:param message: The message to send.
		"""
		pass

	def add_colleague(self, colleague: 'Colleague') -> None:
		"""
		Registers a colleague with the mediator.
		:param colleague: The colleague to register.
		"""
		pass


class Colleague(ABC):
	"""
	Abstract base class for Colleagues in the Mediator pattern.

	Colleagues communicate with each other through a Mediator.
	"""

	def __init__(self, mediator: Mediator) -> None:
		self._mediator = mediator

	def send(self, message: str) -> None:
		"""
		Sends a message via the Mediator.
		:param message: The message to send.
		"""
		self._mediator.send_message(self, message)

	@abstractmethod
	def receive(self, message: str) -> None:
		"""
		Handles a received message.
		:param message: The message received.
		"""
		pass


class ConcreteMediator(Mediator):
	"""
	Concrete implementation of the Mediator interface.

	Facilitates communication between registered colleagues.
	"""

	def __init__(self) -> None:
		self._colleagues: List[Colleague] = []

	def send_message(self, sender: Colleague, message: str) -> None:
		for colleague in self._colleagues:
			if colleague != sender:
				colleague.receive(message)

	def add_colleague(self, colleague: Colleague) -> None:
		self._colleagues.append(colleague)


class ConcreteColleague(Colleague):
	"""
	Concrete implementation of the Colleague class.

	Represents a participant in communication facilitated by the Mediator.
	"""

	def __init__(self, mediator: Mediator, name: str) -> None:
		super().__init__(mediator)
		self._name = name

	def receive(self, message: str) -> None:
		"""
		Handles a received message by logging it.
		:param message: The message received.
		"""
		logger.info(f"{self._name} received message: {message}")

	@property
	def name(self) -> str:
		"""
		Returns the name of the colleague.
		"""
		return self._name
