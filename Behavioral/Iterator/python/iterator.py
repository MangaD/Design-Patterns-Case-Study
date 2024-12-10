from typing import List, Generic, TypeVar, Iterator as TypingIterator, Optional

# Generic type for the collection
T = TypeVar("T")


class Iterator(Generic[T]):
	"""
	Defines the interface for traversing elements in a collection.
	"""

	def has_next(self) -> bool:
		"""
		Check if there are more elements to traverse.

		:return: True if more elements exist, False otherwise.
		"""
		raise NotImplementedError("has_next must be implemented in subclasses.")

	def next(self) -> T:
		"""
		Retrieve the next element in the collection.

		:return: The next element.
		:raises StopIteration: If no more elements exist.
		"""
		raise NotImplementedError("next must be implemented in subclasses.")


class Aggregate(Generic[T]):
	"""
	Defines the interface for creating an iterator.
	"""

	def create_iterator(self) -> Iterator[T]:
		"""
		Create an iterator for the collection.

		:return: An iterator instance.
		"""
		raise NotImplementedError("create_iterator must be implemented in subclasses.")


class ConcreteIterator(Iterator[T]):
	"""
	Implements the Iterator interface for traversing a list.
	"""

	def __init__(self, collection: List[T]):
		"""
		Initialize the iterator with a collection.

		:param collection: The collection to iterate over.
		"""
		self._collection = collection
		self._index = 0

	def has_next(self) -> bool:
		"""
		Check if there are more elements to traverse.

		:return: True if more elements exist, False otherwise.
		"""
		return self._index < len(self._collection)

	def next(self) -> T:
		"""
		Retrieve the next element in the collection.

		:return: The next element.
		:raises StopIteration: If no more elements exist.
		"""
		if not self.has_next():
			raise StopIteration("No more elements in the iterator.")
		element = self._collection[self._index]
		self._index += 1
		return element


class ConcreteAggregate(Aggregate[T]):
	"""
	Implements the Aggregate interface and provides a method to create an iterator.
	"""

	def __init__(self):
		"""
		Initialize an empty collection.
		"""
		self._items: List[T] = []

	def add_item(self, item: T) -> None:
		"""
		Add an item to the collection.

		:param item: The item to add.
		"""
		self._items.append(item)

	def create_iterator(self) -> ConcreteIterator[T]:
		"""
		Create an iterator for the collection.

		:return: An instance of ConcreteIterator.
		"""
		return ConcreteIterator(self._items)
