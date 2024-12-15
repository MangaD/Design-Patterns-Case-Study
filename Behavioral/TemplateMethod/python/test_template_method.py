import pytest
from template_method import AbstractClass, ConcreteClass1, ConcreteClass2


def test_concrete_class1_behavior(caplog):
	"""
	Test the behavior of ConcreteClass1, ensuring the template method is executed correctly.
	"""
	concrete = ConcreteClass1()

	with caplog.at_level("INFO"):
		concrete.template_method()

	expected = [
		"AbstractClass: Base operation 1",
		"ConcreteClass1: Required operation 1",
		"AbstractClass: Base operation 2",
		"ConcreteClass1: Required operation 2",
		"ConcreteClass1: Overridden hook implementation",
	]

	for message in expected:
		assert message in caplog.text, f"Expected log message not found: {message}"


def test_concrete_class2_behavior(caplog):
	"""
	Test the behavior of ConcreteClass2, ensuring the template method is executed correctly.
	"""
	concrete = ConcreteClass2()

	with caplog.at_level("INFO"):
		concrete.template_method()

	expected = [
		"AbstractClass: Base operation 1",
		"ConcreteClass2: Required operation 1",
		"AbstractClass: Base operation 2",
		"ConcreteClass2: Required operation 2",
		"AbstractClass: Default hook implementation",
	]

	for message in expected:
		assert message in caplog.text, f"Expected log message not found: {message}"


def test_hook_flexibility(caplog):
	"""
	Test the flexibility of hooks in both concrete classes.
	"""
	concrete1 = ConcreteClass1()
	concrete2 = ConcreteClass2()

	with caplog.at_level("INFO"):
		concrete1.template_method()
		concrete2.template_method()

	assert "ConcreteClass1: Overridden hook implementation" in caplog.text, (
		"ConcreteClass1 should override the hook."
	)
	assert "AbstractClass: Default hook implementation" in caplog.text, (
		"ConcreteClass2 should use the default hook implementation."
	)
