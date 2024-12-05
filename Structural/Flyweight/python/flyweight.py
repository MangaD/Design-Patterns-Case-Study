import logging
from typing import Dict
from abc import ABC, abstractmethod

# Set up logging configuration
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("flyweight")


class Flyweight(ABC):
	"""
	Abstract base class that defines the Flyweight interface.
	"""

	@abstractmethod
	def operation(self, extrinsic_state: str) -> None:
		"""
		Perform an operation that uses both intrinsic and extrinsic states.

		:param extrinsic_state: The state provided by the client.
		"""
		pass


class ConcreteFlyweight(Flyweight):
	"""
	Represents a Flyweight with intrinsic state that is shared.
	"""

	def __init__(self, intrinsic_state: str) -> None:
		"""
		Initialize the Flyweight with its intrinsic state.

		:param intrinsic_state: The shared intrinsic state of the Flyweight.
		"""
		self._intrinsic_state = intrinsic_state

	def operation(self, extrinsic_state: str) -> None:
		"""
		Perform an operation using both intrinsic and extrinsic states.

		:param extrinsic_state: The state provided by the client.
		"""
		logger.info(
			f"ConcreteFlyweight: Intrinsic state = {self._intrinsic_state}, Extrinsic state = {extrinsic_state}"
		)


class FlyweightFactory:
	"""
	Manages Flyweight objects to ensure they are shared properly.
	"""

	def __init__(self) -> None:
		"""
		Initialize the factory with an empty pool of Flyweights.
		"""
		self._flyweights: Dict[str, Flyweight] = {}

	def get_flyweight(self, intrinsic_state: str) -> Flyweight:
		"""
		Get a Flyweight with the given intrinsic state.

		:param intrinsic_state: The shared intrinsic state of the Flyweight.
		:return: The Flyweight object with the requested intrinsic state.
		"""
		if intrinsic_state not in self._flyweights:
			self._flyweights[intrinsic_state] = ConcreteFlyweight(intrinsic_state)
			logger.info(f"FlyweightFactory: Created new Flyweight for state '{intrinsic_state}'")
		else:
			logger.info(f"FlyweightFactory: Reusing existing Flyweight for state '{intrinsic_state}'")
		return self._flyweights[intrinsic_state]

	def list_flyweights(self) -> None:
		"""
		List all Flyweights managed by the factory.
		"""
		logger.info("Flyweights in Factory:")
		for intrinsic_state in self._flyweights:
			logger.info(f" - {intrinsic_state}")
