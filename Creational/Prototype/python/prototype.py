"""
Prototype Pattern Implementation in Python.

This module provides an implementation of the Prototype Pattern, enabling object
creation by cloning existing instances instead of instantiating new ones.
"""

from abc import ABC, abstractmethod
import copy


class Prototype(ABC):
	"""
	Abstract base class for prototypes.

	Defines the interface for cloning and displaying objects.
	"""

	@abstractmethod
	def clone(self):
		"""
		Create a clone of the current object.

		:return: A new instance that is a copy of the current object.
		"""
		pass

	@abstractmethod
	def display(self):
		"""
		Display the details of the object.

		This method should be implemented by concrete prototypes to output their attributes.
		"""
		pass


class ConcretePrototype1(Prototype):
	"""
	A concrete implementation of the Prototype interface with a string attribute.
	"""

	def __init__(self, attribute: str):
		"""
		Initialize the prototype with a string attribute.

		:param attribute: A string representing the object's attribute.
		"""
		self.attribute = attribute

	def clone(self):
		"""
		Create a shallow clone of the current object.

		:return: A new instance of ConcretePrototype1 with the same attribute.
		"""
		return copy.copy(self) 
		# Shallow Cloning: Used Python’s copy.copy for cloning, which is sufficient for simple attributes.
		# Could be extended to copy.deepcopy for complex nested attributes.

	def display(self):
		"""
		Display the attribute of the object.
		"""
		print(f"ConcretePrototype1 with attribute: {self.attribute}")


class ConcretePrototype2(Prototype):
	"""
	A concrete implementation of the Prototype interface with an integer attribute.
	"""

	def __init__(self, attribute: int):
		"""
		Initialize the prototype with an integer attribute.

		:param attribute: An integer representing the object's attribute.
		"""
		self.attribute = attribute

	def clone(self):
		"""
		Create a shallow clone of the current object.

		:return: A new instance of ConcretePrototype2 with the same attribute.
		"""
		return copy.copy(self)
		# Shallow Cloning: Used Python’s copy.copy for cloning, which is sufficient for simple attributes.
		# Could be extended to copy.deepcopy for complex nested attributes.

	def display(self):
		"""
		Display the attribute of the object.
		"""
		print(f"ConcretePrototype2 with attribute: {self.attribute}")
