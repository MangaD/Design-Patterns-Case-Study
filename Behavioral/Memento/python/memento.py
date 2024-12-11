from typing import List


class Memento:
	"""
	Stores the state of the Originator.
	"""
	def __init__(self, state: str):
		"""
		Initializes the Memento with the state.
		:param state: The state to save.
		"""
		self._state = state

	def get_state(self) -> str:
		"""
		Retrieves the stored state.
		:return: The saved state.
		"""
		return self._state


class Originator:
	"""
	Creates and restores Mementos to manage its state.
	"""
	def __init__(self):
		"""
		Initializes the Originator with no state.
		"""
		self._state = ""

	def set_state(self, state: str):
		"""
		Sets the state of the Originator.
		:param state: The new state.
		"""
		self._state = state

	def get_state(self) -> str:
		"""
		Gets the current state of the Originator.
		:return: The current state.
		"""
		return self._state

	def create_memento(self) -> Memento:
		"""
		Creates a Memento with the current state.
		:return: A Memento containing the current state.
		"""
		return Memento(self._state)

	def restore_memento(self, memento: Memento):
		"""
		Restores the state from a Memento.
		:param memento: The Memento to restore from.
		"""
		self._state = memento.get_state()


class Caretaker:
	"""
	Manages Mementos to track the history of the Originator's states.
	"""
	def __init__(self):
		"""
		Initializes the Caretaker with an empty list of Mementos.
		"""
		self._mementos: List[Memento] = []

	def add_memento(self, memento: Memento):
		"""
		Adds a Memento to the history.
		:param memento: The Memento to add.
		"""
		self._mementos.append(memento)

	def get_memento(self, index: int) -> Memento:
		"""
		Retrieves a Memento by index.
		:param index: The index of the desired Memento.
		:return: The Memento at the specified index.
		:raises IndexError: If the index is out of bounds.
		"""
		if index < 0 or index >= len(self._mementos):
			raise IndexError("Memento index out of range.")
		return self._mementos[index]
