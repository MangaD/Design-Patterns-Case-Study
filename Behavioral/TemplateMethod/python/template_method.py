from abc import ABC, abstractmethod
import logging

# Set up logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("template_method")


class AbstractClass(ABC):
	"""
	Abstract class that defines the skeleton of an algorithm.
	Subclasses must implement specific steps of the algorithm.
	"""

	def template_method(self) -> None:
		"""
		Defines the algorithm's skeleton by calling base operations,
		required steps, and hooks in a predefined order.
		"""
		self.base_operation1()
		self.required_operation1()
		self.base_operation2()
		self.required_operation2()
		self.hook()

	def base_operation1(self) -> None:
		"""
		A base operation with a default implementation.
		"""
		logger.info("AbstractClass: Base operation 1")

	def base_operation2(self) -> None:
		"""
		A base operation with a default implementation.
		"""
		logger.info("AbstractClass: Base operation 2")

	@abstractmethod
	def required_operation1(self) -> None:
		"""
		A required operation that must be implemented by subclasses.
		"""
		pass

	@abstractmethod
	def required_operation2(self) -> None:
		"""
		A required operation that must be implemented by subclasses.
		"""
		pass

	def hook(self) -> None:
		"""
		A hook that can be overridden by subclasses but provides a no-op by default.
		"""
		logger.info("AbstractClass: Default hook implementation")


class ConcreteClass1(AbstractClass):
	"""
	A concrete implementation of the abstract class with its own behavior.
	"""

	def required_operation1(self) -> None:
		logger.info("ConcreteClass1: Required operation 1")

	def required_operation2(self) -> None:
		logger.info("ConcreteClass1: Required operation 2")

	def hook(self) -> None:
		logger.info("ConcreteClass1: Overridden hook implementation")


class ConcreteClass2(AbstractClass):
	"""
	Another concrete implementation of the abstract class with its own behavior.
	"""

	def required_operation1(self) -> None:
		logger.info("ConcreteClass2: Required operation 1")

	def required_operation2(self) -> None:
		logger.info("ConcreteClass2: Required operation 2")

	# No need to override the hook; the default implementation is used.
