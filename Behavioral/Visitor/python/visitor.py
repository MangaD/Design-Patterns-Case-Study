import logging
from abc import ABC, abstractmethod
from typing import List

# Configure the logger
logger = logging.getLogger("visitor")
logger.setLevel(logging.INFO)

class Visitor(ABC):
	"""
	Visitor interface declaring operations for different element types.
	"""
	@abstractmethod
	def visit_element_a(self, element: "ElementA") -> None:
		"""
		Visit an ElementA instance.
		
		:param element: The ElementA instance.
		"""
		pass

	@abstractmethod
	def visit_element_b(self, element: "ElementB") -> None:
		"""
		Visit an ElementB instance.
		
		:param element: The ElementB instance.
		"""
		pass


class Element(ABC):
	"""
	Abstract base class for elements.
	"""
	@abstractmethod
	def accept(self, visitor: Visitor) -> None:
		"""
		Accept a Visitor.
		
		:param visitor: The Visitor to accept.
		"""
		pass


class ElementA(Element):
	"""
	Concrete implementation of an element, ElementA.
	"""
	def operation_a(self) -> str:
		"""
		Perform ElementA-specific behavior.
		
		:return: A message describing the operation.
		"""
		return "ElementA operation."

	def accept(self, visitor: Visitor) -> None:
		"""
		Accept a Visitor.
		
		:param visitor: The Visitor to accept.
		"""
		visitor.visit_element_a(self)


class ElementB(Element):
	"""
	Concrete implementation of an element, ElementB.
	"""
	def operation_b(self) -> str:
		"""
		Perform ElementB-specific behavior.
		
		:return: A message describing the operation.
		"""
		return "ElementB operation."

	def accept(self, visitor: Visitor) -> None:
		"""
		Accept a Visitor.
		
		:param visitor: The Visitor to accept.
		"""
		visitor.visit_element_b(self)


class ConcreteVisitorA(Visitor):
	"""
	Concrete Visitor implementing specific operations for each element type.
	"""
	def visit_element_a(self, element: ElementA) -> None:
		"""
		Visit an ElementA instance.
		
		:param element: The ElementA instance to visit.
		"""
		logger.info(f"ConcreteVisitorA: {element.operation_a()}")

	def visit_element_b(self, element: ElementB) -> None:
		"""
		Visit an ElementB instance.
		
		:param element: The ElementB instance to visit.
		"""
		logger.info(f"ConcreteVisitorA: {element.operation_b()}")


class ConcreteVisitorB(Visitor):
	"""
	Another Concrete Visitor with different operations for each element type.
	"""
	def visit_element_a(self, element: ElementA) -> None:
		"""
		Visit an ElementA instance.
		
		:param element: The ElementA instance to visit.
		"""
		logger.info(f"ConcreteVisitorB: {element.operation_a()}")

	def visit_element_b(self, element: ElementB) -> None:
		"""
		Visit an ElementB instance.

		:param element: The ElementB instance to visit.
		"""
		logger.info(f"ConcreteVisitorB: {element.operation_b()}")


class ObjectStructure:
	"""
	ObjectStructure manages a collection of elements and processes them with visitors.
	"""
	def __init__(self) -> None:
		"""
		Default constructor.

		Initializes an empty list to store elements.
		"""
		self._elements: List[Element] = []

	def add_element(self, element: Element) -> None:
		"""
		Add an element to the structure.

		:param element: The Element to add.
		"""
		self._elements.append(element)

	def accept(self, visitor: Visitor) -> None:
		"""
		Accept a visitor for all elements.

		Iterates over all elements in the structure and calls their accept method with
		the given visitor.

		:param visitor: The Visitor to accept.
		"""
		for element in self._elements:
			element.accept(visitor)
