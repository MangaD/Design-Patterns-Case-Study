import logging
from abc import ABC, abstractmethod
from typing import List

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class Component(ABC):
	"""
	The Component interface declares common operations for both leaf and composite objects.
	"""

	@abstractmethod
	def operation(self) -> None:
		"""
		Perform an operation on the component.
		"""
		pass

	def add(self, component: 'Component') -> None:
		"""
		Optionally, add a child component to the composite.
		Raises NotImplementedError for leaf components.

		:param component: The child component to add.
		"""
		raise NotImplementedError("Add operation is not supported for this component.")

	def remove(self, component: 'Component') -> None:
		"""
		Optionally, remove a child component from the composite.
		Raises NotImplementedError for leaf components.

		:param component: The child component to remove.
		"""
		raise NotImplementedError("Remove operation is not supported for this component.")

	def get_child(self, index: int) -> 'Component':
		"""
		Optionally, retrieve a child component at a specific index.
		Raises NotImplementedError for leaf components.

		:param index: The index of the child component.
		:return: The child component.
		"""
		raise NotImplementedError("Get child operation is not supported for this component.")


class Leaf(Component):
	"""
	Represents the Leaf object in the Composite pattern.
	A Leaf has no children and defines behavior for primitive objects.
	"""

	def __init__(self, name: str):
		"""
		Initialize the Leaf with a name.

		:param name: The name of the leaf.
		"""
		self.name = name

	def operation(self) -> None:
		"""
		Perform the operation specific to the leaf.
		"""
		logger.info(f"Leaf {self.name} operation.")


class Composite(Component):
	"""
	Represents the Composite object in the Composite pattern.
	A Composite can contain both Leaf and other Composite objects.
	"""

	def __init__(self, name: str):
		"""
		Initialize the Composite with a name.

		:param name: The name of the composite.
		"""
		self.name = name
		self.children: List[Component] = []

	def operation(self) -> None:
		"""
		Perform the operation on the composite and its children.
		"""
		logger.info(f"Composite {self.name} operation.")
		for child in self.children:
			child.operation()

	def add(self, component: Component) -> None:
		"""
		Add a child component to the composite.

		:param component: The child component to add.
		"""
		self.children.append(component)

	def remove(self, component: Component) -> None:
		"""
		Remove a child component from the composite.

		:param component: The child component to remove.
		"""
		self.children.remove(component)

	def get_child(self, index: int) -> Component:
		"""
		Retrieve a child component at a specific index.

		:param index: The index of the child component.
		:return: The child component.
		"""
		return self.children[index]
