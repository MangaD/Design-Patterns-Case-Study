"""
@brief This module implements the Facade pattern in Python.
"""

class Subsystem1:
	"""
	Subsystem1 provides specific functionality that the Facade uses.
	"""
	def operation1(self) -> str:
		"""
		Perform operation 1.
		:return: A string describing the operation.
		"""
		return "Subsystem1: Operation 1\n"


class Subsystem2:
	"""
	Subsystem2 provides specific functionality that the Facade uses.
	"""
	def operation2(self) -> str:
		"""
		Perform operation 2.
		:return: A string describing the operation.
		"""
		return "Subsystem2: Operation 2\n"


class Subsystem3:
	"""
	Subsystem3 provides specific functionality that the Facade uses.
	"""
	def operation3(self) -> str:
		"""
		Perform operation 3.
		:return: A string describing the operation.
		"""
		return "Subsystem3: Operation 3\n"


class Facade:
	"""
	The Facade provides a simplified interface to the subsystems.

	It delegates requests from the client to the appropriate subsystems,
	abstracting their complexity.
	"""
	def __init__(self) -> None:
		"""
		Initialize the Facade with instances of the subsystems.
		"""
		self.subsystem1 = Subsystem1()
		self.subsystem2 = Subsystem2()
		self.subsystem3 = Subsystem3()

	def operation(self) -> str:
		"""
		Execute a high-level operation by coordinating subsystems.

		:return: A string describing the combined operations.
		"""
		result = []
		result.append("Facade: Coordinating subsystems:\n")
		result.append(self.subsystem1.operation1())
		result.append(self.subsystem2.operation2())
		result.append(self.subsystem3.operation3())
		return ''.join(result)
