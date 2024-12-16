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
		pass

	@abstractmethod
	def visit_element_b(self, element: "ElementB") -> None:
		pass


class Element(ABC):
	"""
	Abstract base class for elements.
	"""
	@abstractmethod
	def accept(self, visitor: Visitor) -> None:
		pass


class ElementA(Element):
	"""
	Concrete implementation of an element, ElementA.
	"""
	def operation_a(self) -> str:
		return "ElementA operation."

	def accept(self, visitor: Visitor) -> None:
		visitor.visit_element_a(self)


class ElementB(Element):
	"""
	Concrete implementation of an element, ElementB.
	"""
	def operation_b(self) -> str:
		return "ElementB operation."

	def accept(self, visitor: Visitor) -> None:
		visitor.visit_element_b(self)


class ConcreteVisitorA(Visitor):
	"""
	Concrete Visitor implementing specific operations for each element type.
	"""
	def visit_element_a(self, element: ElementA) -> None:
		logger.info(f"ConcreteVisitorA: {element.operation_a()}")

	def visit_element_b(self, element: ElementB) -> None:
		logger.info(f"ConcreteVisitorA: {element.operation_b()}")


class ConcreteVisitorB(Visitor):
	"""
	Another Concrete Visitor with different operations for each element type.
	"""
	def visit_element_a(self, element: ElementA) -> None:
		logger.info(f"ConcreteVisitorB: {element.operation_a()}")

	def visit_element_b(self, element: ElementB) -> None:
		logger.info(f"ConcreteVisitorB: {element.operation_b()}")


class ObjectStructure:
	"""
	ObjectStructure manages a collection of elements and processes them with visitors.
	"""
	def __init__(self) -> None:
		self._elements: List[Element] = []

	def add_element(self, element: Element) -> None:
		self._elements.append(element)

	def accept(self, visitor: Visitor) -> None:
		for element in self._elements:
			element.accept(visitor)
