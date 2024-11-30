from abc import ABC, abstractmethod
from typing import Generic, TypeVar, Deque, Set
from collections import deque

# Define a generic type variable constrained to the Reusable interface.
T = TypeVar('T', bound='Reusable')

class Reusable(ABC):
	"""
	Abstract base class for reusable objects.

	This class defines a standard interface for objects that can be managed
	by an object pool. Subclasses must implement the `use` and `reset` methods
	to define the behavior for using and resetting the object.

	Responsibilities:
	- `use`: Defines the primary action or functionality of the reusable object.
	- `reset`: Resets the state of the object, preparing it for reuse.

	Classes inheriting from `Reusable` should encapsulate reusable resources
	or functionalities that can be pooled, such as database connections,
	threads, or UI components.
	"""

	@abstractmethod
	def use(self):
		"""
		Perform the primary action of the reusable object.

		This method must be implemented by subclasses to define the
		main functionality of the object when it is borrowed from the pool.
		"""
		pass

	@abstractmethod
	def reset(self):
		"""
		Reset the reusable object to its initial state.

		This method must be implemented by subclasses to clear or reset
		the object's state, preparing it for reuse when returned to the pool.
		"""
		pass


class ConcreteReusable(Reusable):
	"""
	Concrete implementation of the Reusable interface.

	This class represents a reusable object with an identifier and state.
	"""

	def __init__(self, id_: str):
		"""
		Initialize a reusable object with a unique identifier.

		:param id_: A unique identifier for the reusable object.
		"""
		self.id = id_
		self.in_use = False

	def use(self):
		"""
		Perform the primary action of the reusable object.

		:raises RuntimeError: If the object is already in use.
		"""
		if self.in_use:
			raise RuntimeError(f"Object {self.id} is already in use.")
		self.in_use = True
		print(f"Using object: {self.id}")

	def reset(self):
		"""
		Reset the reusable object to its initial state.

		Resets the `in_use` state to `False`.
		"""
		self.in_use = False
		print(f"Resetting object: {self.id}")

	def __repr__(self):
		"""
		Return a string representation of the object.

		:return: A string describing the object.
		"""
		return f"ConcreteReusable(id={self.id}, in_use={self.in_use})"

	def __eq__(self, other):
		"""
		Compare two reusable objects for equality based on their ID.

		:param other: Another reusable object to compare.
		:return: True if both objects have the same ID, False otherwise.
		"""
		if isinstance(other, ConcreteReusable):
			return self.id == other.id
		return False

	def __hash__(self):
		"""
		Generate a hash value for the reusable object based on its ID.

		This allows instances to be used in sets or as dictionary keys.

		:return: The hash value of the object.
		"""
		return hash(self.id)


class ObjectPool(Generic[T]):
	"""
	Generic Object Pool for managing reusable objects.

	Manages a pool of reusable objects, allowing objects to be borrowed,
	returned, and reused. Ensures FIFO behavior for returning and borrowing.
	"""

	def __init__(self):
		"""
		Initialize an empty object pool.
		"""
		self._pool: Deque[T] = deque()  # Queue for storing reusable objects
		self._in_pool: Set[T] = set()  # Set for tracking objects in the pool

	def add_object(self, obj: T):
		"""
		Add a reusable object to the pool.

		:param obj: The reusable object to add.
		:raises ValueError: If the object is None or already in the pool.
		"""
		if obj is None:
			raise ValueError("Cannot add a None object to the pool.")
		if obj in self._in_pool:
			raise ValueError("Object is already in the pool.")
		self._pool.append(obj)
		self._in_pool.add(obj)

	def borrow_object(self) -> T:
		"""
		Borrow an object from the pool.

		:return: A reusable object from the pool.
		:raises RuntimeError: If the pool is empty.
		"""
		if not self._pool:
			raise RuntimeError("No available objects in the pool.")
		obj = self._pool.popleft()
		self._in_pool.remove(obj)
		return obj

	def return_object(self, obj: T):
		"""
		Return a reusable object to the pool.

		:param obj: The reusable object to return.
		:raises ValueError: If the object is None or already in the pool.
		"""
		if obj is None:
			raise ValueError("Cannot return a None object to the pool.")
		if obj in self._in_pool:
			raise ValueError("Object is already in the pool.")
		obj.reset()
		self._pool.append(obj)
		self._in_pool.add(obj)

	def get_size(self) -> int:
		"""
		Get the current size of the pool.

		:return: The number of reusable objects in the pool.
		"""
		return len(self._pool)
