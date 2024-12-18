from abc import ABC, abstractmethod


class AbstractProductA(ABC):
	"""Abstract interface for ProductA."""

	@abstractmethod
	def operation_a(self) -> str:
		"""Perform an operation specific to ProductA."""
		pass


class AbstractProductB(ABC):
	"""Abstract interface for ProductB."""

	@abstractmethod
	def operation_b(self) -> str:
		"""Perform an operation specific to ProductB."""
		pass


class ConcreteProductA1(AbstractProductA):
	"""Concrete implementation of ProductA for Family 1."""

	def operation_a(self) -> str:
		"""Implement operation A for ConcreteProductA1."""
		return "ConcreteProductA1"


class ConcreteProductA2(AbstractProductA):
	"""Concrete implementation of ProductA for Family 2."""

	def operation_a(self) -> str:
		"""Implement operation A for ConcreteProductA2."""
		return "ConcreteProductA2"


class ConcreteProductB1(AbstractProductB):
	"""Concrete implementation of ProductB for Family 1."""

	def operation_b(self) -> str:
		"""Implement operation B for ConcreteProductB1."""
		return "ConcreteProductB1"


class ConcreteProductB2(AbstractProductB):
	"""Concrete implementation of ProductB for Family 2."""

	def operation_b(self) -> str:
		"""Implement operation B for ConcreteProductB2."""
		return "ConcreteProductB2"


class AbstractFactory(ABC):
	"""Abstract Factory interface."""

	@abstractmethod
	def create_product_a(self) -> AbstractProductA:
		"""Create a product of type A."""
		pass

	@abstractmethod
	def create_product_b(self) -> AbstractProductB:
		"""Create a product of type B."""
		pass


class ConcreteFactory1(AbstractFactory):
	"""Concrete Factory 1: Creates products belonging to Family 1."""

	def create_product_a(self) -> AbstractProductA:
		"""Create a product of type A (ConcreteProductA1)."""		
		return ConcreteProductA1()

	def create_product_b(self) -> AbstractProductB:
		"""Create a product of type B (ConcreteProductB1)."""
		return ConcreteProductB1()


class ConcreteFactory2(AbstractFactory):
	"""Concrete Factory 2: Creates products belonging to Family 2."""

	def create_product_a(self) -> AbstractProductA:
		"""Create a product of type A (ConcreteProductA2)."""		
		return ConcreteProductA2()

	def create_product_b(self) -> AbstractProductB:
		"""Create a product of type B (ConcreteProductB2)."""
		return ConcreteProductB2()
