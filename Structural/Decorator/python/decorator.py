from abc import ABC, abstractmethod


class Component(ABC):
	"""
	Defines the interface for objects that can have responsibilities added to them dynamically.
	"""

	@abstractmethod
	def get_description(self) -> str:
		"""
		Get the description of the component.

		:return: A string description.
		"""
		pass

	@abstractmethod
	def cost(self) -> float:
		"""
		Get the cost of the component.

		:return: The cost as a float.
		"""
		pass


class ConcreteComponent(Component):
	"""
	A ConcreteComponent is a base implementation of Component.
	"""

	def get_description(self) -> str:
		"""
		Returns a string description of the component.

		:return: A string representing the description.
		"""
		return "Concrete Component"

	def cost(self) -> float:
		"""
		Get the cost of the component.

		:return: The cost as a float.
		"""
		return 10.0


class Decorator(Component, ABC):
	"""
	Abstract Decorator class that wraps a Component and allows for dynamic behavior addition.
	"""

	def __init__(self, component: Component):
		"""
		Initialize the decorator with a component to wrap.

		:param component: The component to wrap.
		"""
		self._component = component

	@abstractmethod
	def get_description(self) -> str:
		"""
		Get the description of the decorated component.

		:return: A string description.
		"""
		pass

	@abstractmethod
	def cost(self) -> float:
		"""
		Get the cost of the decorated component.

		:return: The cost as a float.
		"""
		pass


class ConcreteDecoratorA(Decorator):
	"""
	Adds specific behavior (Feature A) to the Component.
	"""

	def get_description(self) -> str:
		"""
		Returns the description of the component with Feature A added.

		:return: A string description including Feature A.
		"""
		return f"{self._component.get_description()} + Feature A"

	def cost(self) -> float:
		"""
		Get the cost of the decorated component with Feature A added.

		:return: The cost as a float with Feature A added.
		"""
		return self._component.cost() + 5.0


class ConcreteDecoratorB(Decorator):
	"""
	Adds specific behavior (Feature B) to the Component.
	"""

	def get_description(self) -> str:
		"""
		Returns the description of the component with Feature B added.

		:return: A string description including Feature B.
		"""
		return f"{self._component.get_description()} + Feature B"

	def cost(self) -> float:
		"""
		Get the cost of the decorated component with Feature B added.
		
		:return: The cost as a float with Feature B added.
		"""
		return self._component.cost() + 7.5
