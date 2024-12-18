import pytest
from visitor import ElementA, ElementB, ConcreteVisitorA, ConcreteVisitorB, ObjectStructure

def test_element_a_visitor_a(caplog):
	"""
	Test visiting an ElementA instance with a ConcreteVisitorA.

	Checks that the correct operation is executed and the expected log message is produced.
	"""
	with caplog.at_level("INFO"):
		element = ElementA()
		visitor = ConcreteVisitorA()
		element.accept(visitor)
	assert "ConcreteVisitorA: ElementA operation." in caplog.text


def test_element_b_visitor_a(caplog):
	"""
	Test visiting an ElementB instance with a ConcreteVisitorA.

	Checks that the correct operation is executed and the expected log message is produced.
	"""
	with caplog.at_level("INFO"):
		element = ElementB()
		visitor = ConcreteVisitorA()
		element.accept(visitor)
	assert "ConcreteVisitorA: ElementB operation." in caplog.text


def test_element_a_visitor_b(caplog):
	"""
	Test visiting an ElementA instance with a ConcreteVisitorB.

	Checks that the correct operation is executed and the expected log message is produced.
	"""
	with caplog.at_level("INFO"):
		element = ElementA()
		visitor = ConcreteVisitorB()
		element.accept(visitor)
	assert "ConcreteVisitorB: ElementA operation." in caplog.text


def test_element_b_visitor_b(caplog):
	"""
	Test visiting an ElementB instance with a ConcreteVisitorB.

	Checks that the correct operation is executed and the expected log message is produced.
	"""
	with caplog.at_level("INFO"):
		element = ElementB()
		visitor = ConcreteVisitorB()
		element.accept(visitor)
	assert "ConcreteVisitorB: ElementB operation." in caplog.text


def test_object_structure_with_visitor_a(caplog):
	"""
	Test visiting elements in an ObjectStructure with a ConcreteVisitorA.

	Checks that the correct operations are executed and the expected log messages are produced.
	"""
	with caplog.at_level("INFO"):
		structure = ObjectStructure()
		structure.add_element(ElementA())
		structure.add_element(ElementB())

		visitor = ConcreteVisitorA()
		structure.accept(visitor)

	assert "ConcreteVisitorA: ElementA operation." in caplog.text
	assert "ConcreteVisitorA: ElementB operation." in caplog.text


def test_object_structure_with_visitor_b(caplog):
	"""
	Test visiting elements in an ObjectStructure with a ConcreteVisitorB.

	Checks that the correct operations are executed and the expected log messages are produced.
	"""
	with caplog.at_level("INFO"):
		structure = ObjectStructure()
		structure.add_element(ElementA())
		structure.add_element(ElementB())

		visitor = ConcreteVisitorB()
		structure.accept(visitor)

	assert "ConcreteVisitorB: ElementA operation." in caplog.text
	assert "ConcreteVisitorB: ElementB operation." in caplog.text
