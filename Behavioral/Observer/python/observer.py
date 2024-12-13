from typing import List, Protocol
import logging

# Setup logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("observer")


class Observer(Protocol):
	"""
	Interface for observers that listen for updates from a subject.
	"""
	def update(self, state: str) -> None:
		"""
		Called by the subject to notify the observer of a state change.
		:param state: The updated state.
		"""
		pass


class Subject:
	"""
	Manages observers and notifies them of state changes.
	"""
	def __init__(self):
		self._observers: List[Observer] = []
		self._state: str = ""

	def attach(self, observer: Observer) -> None:
		"""
		Add an observer to the subject.
		:param observer: The observer to attach.
		"""
		if observer not in self._observers:
			self._observers.append(observer)
			logger.info("Attached observer: %s", observer)

	def detach(self, observer: Observer) -> None:
		"""
		Remove an observer from the subject.
		:param observer: The observer to detach.
		"""
		if observer in self._observers:
			self._observers.remove(observer)
			logger.info("Detached observer: %s", observer)

	def notify(self) -> None:
		"""
		Notify all attached observers of the current state.
		"""
		for observer in self._observers:
			observer.update(self._state)

	def set_state(self, state: str) -> None:
		"""
		Update the subject's state and notify observers.
		:param state: The new state to set.
		"""
		self._state = state
		logger.info("Subject state updated to: %s", state)
		self.notify()

	def get_state(self) -> str:
		"""
		Retrieve the current state of the subject.
		:return: The current state.
		"""
		return self._state


class ConcreteObserver:
	"""
	Concrete implementation of an observer.
	"""
	def __init__(self, name: str):
		self.name = name

	def update(self, state: str) -> None:
		"""
		Receive an update from the subject.
		:param state: The updated state.
		"""
		logger.info("Observer %s received update. New state: %s", self.name, state)

	def __str__(self) -> str:
		"""
		String representation of the observer.
		:return: Observer's name.
		"""
		return self.name
