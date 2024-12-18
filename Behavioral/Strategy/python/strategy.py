from typing import Protocol

class Strategy(Protocol):
	"""
	Strategy interface that declares a common behavior for all supported algorithms.
	"""

	def execute(self) -> str:
		"""
		Execute the strategy's algorithm.

		:return: A string result of the algorithm.
		"""
		pass


class ConcreteStrategyA:
	"""
	A concrete strategy implementing a specific algorithm.
	"""

	def execute(self) -> str:
		"""
		Execute ConcreteStrategyA's algorithm.

		:return: A string result indicating the execution.
		"""
		return "Executing strategy A."


class ConcreteStrategyB:
	"""
	A concrete strategy implementing another algorithm.
	"""

	def execute(self) -> str:
		"""
		Execute ConcreteStrategyB's algorithm.

		:return: A string result indicating the execution.
		"""
		return "Executing strategy B."


class Context:
	"""
	Context class that maintains a reference to a strategy object.
	"""

	def __init__(self) -> None:
		"""
		Initialize the context without a strategy.
		"""
		self._strategy: Strategy | None = None

	def set_strategy(self, strategy: Strategy) -> None:
		"""
		Set the current strategy.

		:param strategy: The strategy to use.
		"""
		self._strategy = strategy

	def execute_strategy(self) -> str:
		"""
		Execute the current strategy's algorithm.
		
		:return: The result of the algorithm as a string.
		:raises ValueError: If no strategy is set.
		"""
		if self._strategy is None:
			raise ValueError("No strategy set!")
		return self._strategy.execute()
