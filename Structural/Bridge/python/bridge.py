import logging
from abc import ABC, abstractmethod

# Configure the logging module
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class Implementor(ABC):
	"""
	Defines the interface for the implementation in the Bridge Pattern.
	"""

	@abstractmethod
	def implementation(self) -> None:
		"""
		Defines the operation implemented by concrete implementors.
		"""
		pass

class ConcreteImplementorA(Implementor):
	"""
	Provides a specific implementation of the Implementor interface.
	"""

	def implementation(self) -> None:
		"""
		Provides a concrete implementation of the operation.
		"""
		logger.info("ConcreteImplementorA: Performing implementation.")

class ConcreteImplementorB(Implementor):
	"""
	Provides another specific implementation of the Implementor interface.
	"""

	def implementation(self) -> None:
		"""
		Provides a concrete implementation of the operation.
		"""
		logger.info("ConcreteImplementorB: Performing implementation.")

class Abstraction:
	"""
	Defines the abstraction in the Bridge Pattern.
	Works independently of the implementation.
	"""

	def __init__(self, implementor: Implementor) -> None:
		"""
		Initializes the abstraction with a given implementor.

		:param implementor: The concrete implementor to bridge with.
		"""
		self._implementor = implementor

	def operation(self) -> None:
		"""
		Performs an operation using the implementor.
		"""
		logger.info("Abstraction: Delegating operation to implementor.")
		self._implementor.implementation()

class RefinedAbstraction(Abstraction):
	"""
	Extends the base abstraction to add more behavior.
	"""

	def operation(self) -> None:
		"""
		Adds additional behavior before or after delegating to the implementor.
		"""
		logger.info("RefinedAbstraction: Additional behavior before delegation.")
		super().operation()
		logger.info("RefinedAbstraction: Additional behavior after delegation.")
